import pytesseract
from PIL import Image
pytesseract.pytesseract.tesseract_cmd = r'C:\Program Files\Tesseract-OCR\\tesseract'
def extract_sinhala_text(image_path):
    try:
        img = Image.open(image_path)
        text = pytesseract.image_to_string(img, lang='sin')
        return text
    except Exception as e:
        print(f"Error: {e}")
        return None
image_path = ''
extracted_text = extract_sinhala_text(image_path)
if extracted_text:
    print("Extracted Text:")
    print(extracted_text)
else:
    print("No text could be extracted.")
