import cv2
import imutils
import pytesseract
import serial
import time

pytesseract.pytesseract.tesseract_cmd = 'C:\Program Files\Tesseract-OCR\\tesseract'
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

