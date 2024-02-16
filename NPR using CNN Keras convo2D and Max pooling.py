import cv2
import imutils
import pytesseract
import serial
import time
import os
import numpy as np
from keras.models import Sequential
from keras.layers import Conv2D, MaxPooling2D, Flatten, Dense

pytesseract.pytesseract.tesseract_cmd = 'C:\Program Files\Tesseract-OCR\\tesseract'

# Load images from directory
folder_path = 'C:/img_dataset'
images = []

for file_name in os.listdir(folder_path):
    if file_name.endswith('.jpg') or file_name.endswith('.jpeg') or file_name.endswith('.png'):
        image_path = os.path.join(folder_path, file_name)
        image = cv2.imread(image_path)
        images.append(image)

# Define CNN model
model = Sequential()
model.add(Conv2D(32, (3, 3), input_shape=(100, 100, 3), activation='relu'))
model.add(MaxPooling2D(pool_size=(2, 2)))
model.add(Flatten())
model.add(Dense(256, activation='sigmoid'))
model.add(Dense(128, activation='relu'))
model.add(Dense(1, activation='sigmoid'))
model.compile(optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'])

# Train the model
X_train = []
y_train = []
for image in images:
    resized_image = cv2.resize(image, (100, 100))
    X_train.append(resized_image)
    y_train.append(1)  # assuming all images contain license plates

X_train = np.array(X_train)
y_train = np.array(y_train)
model.fit(X_train, y_train, epochs=10)

# Use the model to detect license plates
cap = cv2.VideoCapture(0)
number_plate_dataset = {
    "BIK 1234": "COM8",
    "ATM 2341": "COM8",
    "FFT 4567": "COM8"
}

while True:
    ret, frame = cap.read()
    frame = imutils.resize(frame, width=600)
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    gray = cv2.bilateralFilter(gray, 11, 17, 17)
    edged = cv2.Canny(gray, 30, 200)
    cnts, hierarchy = cv2.findContours(edged.copy(), cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
    image1 = frame.copy()
    cv2.drawContours(image1, cnts, -1, (0, 255, 0), 3)
    cv2.imshow("Contours", image1)
    cnts = sorted(cnts, key=cv2.contourArea, reverse=True)[:30]
    screenCnt = None
    for c in cnts:
        perimeter = cv2.arcLength(c, True)
        approx = cv2.approxPolyDP(c, 0.018 * perimeter, True)
        if len(approx) == 4:
            screenCnt = approx
            x, y, w, h = cv2.boundingRect(c)
            new_img = frame[y:y + h, x:x + w]
            cv2.imshow("Cropped Image", new_img)
            break
    if screenCnt is not None:
        cv2.drawContours(frame, [screenCnt], -1, (0, 255, 0), 3)
        cropped = cv2.cvtColor(new_img, cv2.COLOR_BGR2GRAY)
        cropped = cv2.threshold(cropped, 0, 255, cv2.THRESH_BINARY | cv2.THRESH_OTSU)[1]
        plate = pytesseract.image_to_string(cropped, lang='eng')
        print("Number plate is:", plate)
        if plate.strip() in number_plate_dataset:
            SerialObj = serial.Serial('COM8')
            SerialObj.baudrate = 9600
            SerialObj.bytesize = 8
            SerialObj.parity = 'N'
            SerialObj.stopbits = 1
            time.sleep(3)
            SerialObj.write(plate.encode())
            SerialObj.close()
            exit()
    cv2.imshow("Original Image", frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
