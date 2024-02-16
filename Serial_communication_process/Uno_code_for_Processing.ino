#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial mySerial(2, 3); // RX, TX
SoftwareSerial sms(10, 9);

const byte ROWS = 4;
const byte COLS = 4;
int d = 0;
String np = "";
int pump_st = 1;
int relay = A2;
String password, litters;
int price = 370;
String User1 = "123456#";
int User1_quote = 10;
int User1_usage = 0;
int pass_count = 0;
String User2 = "321456#";
int User2_quote = 10;
int User2_usage = 0;

String User3 = "321654#";
int User3_quote = 10;
int User3_usage = 0;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {13, 12, 11, 8};
byte colPins[COLS] = {7, 6, 5, 4};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {

  Serial.begin(9600);
  mySerial.begin(9600);
  sms.begin(9600);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   Welcome To");
  lcd.setCursor(0, 1);
  lcd.print("  ATM Station");
  delay(5000);

}

void loop() {
  //char customKey = customKeypad.getKey();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Waiting For NP..");
  delay(1000);
  Serial.begin(9600);
  if (Serial.available() > 0) {
    np = Serial.readStringUntil('\n');
    Serial.print("ID : ");
    Serial.println(np);
    lcd.clear();
    lcd.setCursor(0, 0);
    //lcd.print(np);
    //delay(10000);
    //Serial.end();
    if (np.equals("BIK 1234")) {
      Serial.println("OK");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Number Plate :");
      lcd.setCursor (0,1);
      lcd.print(np);
      delay(3000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Available Fuel");
      lcd.setCursor(0, 1);
      lcd.print("Count :");
      lcd.print(User1_quote);
      delay(5000);
      lcd.clear();
      while (pump_st) {
        char customKey = customKeypad.getKey();
        lcd.setCursor(0, 0);
        lcd.print("Please Enter The");
        lcd.setCursor(0, 1);
        lcd.print("Password :");
        if (customKey) {
          Serial.print(customKey);
          password = password + customKey ;
          lcd.print(password);
          if (customKey == '*') {
            password = "";
            lcd.clear();
          }
          if (customKey == '#') {
            if (password.equals(User1)) {
              Serial.println("password : " + password);
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("Password Correct");
              delay(3000);
              lcd.clear();
              while (pump_st) {
                char customKey = customKeypad.getKey();
                lcd.setCursor(0, 0);
                lcd.print("Enter fuel ");
                lcd.setCursor(0, 1);
                lcd.print("Amount : ");
                if (customKey) {
                  Serial.print(customKey);
                  litters = litters + customKey ;
                  lcd.print(litters);
                  int sta = litters.toInt();
                  if (customKey == '*') {
                    litters = "";
                    lcd.clear();
                  }
                  if (customKey == '#') {
                    if (sta <= User1_quote) {
                      lcd.clear();
                      lcd.setCursor(0, 0);
                      lcd.print("Fuel Pumping...");
                      digitalWrite(relay, LOW);
                      Serial.println(litters.length());
                      litters = litters.substring(0, litters.length() - 1);
                      Serial.println("litters : " + litters);
                      User1_usage = litters.toInt();
                      int timed = User1_usage * 6000;
                      d = User1_usage * price;
                      User1_quote = User1_quote - litters.toInt();
                      Serial.println("Time : " + (String)timed);
                      Serial.println("Price : " + (String)d);
                      Serial.println("Usage : " + (String)User1_usage);
                      Serial.println("Available fuel : " + (String)User1_quote);
                      delay(timed);
                      digitalWrite(relay, HIGH);
                      lcd.clear();
                      lcd.setCursor(0, 0);
                      lcd.print("Price : Rs.");
                      lcd.print(d);
                      lcd.setCursor(0, 1);
                      lcd.print("Usage :");
                      lcd.print(User1_usage);
                      lcd.print(" L");
                      buttonRead();
                      delay(5000);
                      pump_st = 0;
                    } else {
                      lcd.clear();
                      lcd.setCursor(0, 0);
                      lcd.print("Please Enter");
                      lcd.setCursor(0, 1);
                      lcd.print("Valid Amount");
                      delay(2000);
                      lcd.clear();
                      litters = "";
                    }
                  }
                }
              }
            } else {
              pass_count++;
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("Password wrong ");
              delay(3000);
              lcd.clear();
              password = "";
              if (pass_count > 2) {
                pump_st = 0;
                pass_count = 0;
              }
            }
          }
        }
      }
      pump_st = 1;
      np = "";
      password = "";
      litters = "";
    } else if (np.equals("FFT 4567")) {
      Serial.println("QR OK");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("NP :");
      lcd.print(np);
      delay(3000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Available Fuel : ");
      lcd.setCursor(0, 1);
      lcd.print("Count :");
      lcd.print(User2_quote);
      delay(5000);
      lcd.clear();
      while (pump_st) {
        char customKey = customKeypad.getKey();
        lcd.setCursor(0, 0);
        lcd.print("Please Enter The");
        lcd.setCursor(0, 1);
        lcd.print("Password :");
        if (customKey) {
          Serial.print(customKey);
          password = password + customKey ;
          lcd.print(password);
          if (customKey == '*') {
            password = "";
            lcd.clear();
          }
          if (customKey == '#') {
            if (password.equals(User2)) {
              Serial.println("password : " + password);
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("Password Correct");
              delay(3000);
              lcd.clear();
              while (pump_st) {
                char customKey = customKeypad.getKey();
                lcd.setCursor(0, 0);
                lcd.print("Enter Needed ");
                lcd.setCursor(0, 1);
                lcd.print("Amount : ");
                if (customKey) {
                  Serial.print(customKey);
                  litters = litters + customKey ;
                  lcd.print(litters);
                  int sta = litters.toInt();
                  if (customKey == '*') {
                    litters = "";
                    lcd.clear();
                  }
                  if (customKey == '#') {
                    if (sta <= User2_quote) {
                      lcd.clear();
                      lcd.setCursor(0, 0);
                      lcd.print("Fuel Pumping...");
                      digitalWrite(relay, LOW);
                      Serial.println(litters.length());
                      litters = litters.substring(0, litters.length() - 1);
                      Serial.println("litters : " + litters);
                      User2_usage = litters.toInt();
                      int timed = User2_usage * 6000;
                      d = User2_usage * price;
                      User2_quote = User2_quote - litters.toInt();
                      Serial.println("Time : " + (String)timed);
                      Serial.println("Price : " + (String)d);
                      Serial.println("Usage : " + (String)User2_usage);
                      Serial.println("Available fule : " + (String)User2_quote);
                      delay(timed);
                      digitalWrite(relay, HIGH);
                      lcd.clear();
                      lcd.setCursor(0, 0);
                      lcd.print("Price : Rs.");
                      lcd.print(d);
                      lcd.setCursor(0, 1);
                      lcd.print("Usage :");
                      lcd.print(User2_usage);
                      lcd.print(" L");
                      delay(5000);
                      buttonRead1();
                      pump_st = 0;
                    } else {
                      lcd.clear();
                      lcd.setCursor(0, 0);
                      lcd.print("Please Enter");
                      lcd.setCursor(0, 1);
                      lcd.print("Valid Amount");
                      delay(2000);
                      lcd.clear();
                      litters = "";
                    }
                  }
                }
              }
            } else {
              pass_count++;
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("Password wrong ");
              delay(3000);
              lcd.clear();
              password = "";
              if (pass_count > 2) {
                pump_st = 0;
                pass_count = 0;
              }
            }
          }
        }
      }
      pump_st = 1;
      np = "";
      password = "";
      litters = "";
    } else if (np.equals("ATM 2341")) {
      Serial.println("NP OK");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("NP :");
      lcd.print(np);
      delay(3000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Available Fule");
      lcd.setCursor(0, 1);
      lcd.print("Count :");
      lcd.print(User3_quote);
      delay(5000);
      lcd.clear();
      while (pump_st) {
        char customKey = customKeypad.getKey();
        lcd.setCursor(0, 0);
        lcd.print("Please Enter The");
        lcd.setCursor(0, 1);
        lcd.print("Password :");
        if (customKey) {
          Serial.print(customKey);
          password = password + customKey ;
          lcd.print(password);
          if (customKey == '*') {
            password = "";
            lcd.clear();
          }
          if (customKey == '#') {
            if (password.equals(User3)) {
              Serial.println("password : " + password);
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("Password Correct");
              delay(3000);
              lcd.clear();
              while (pump_st) {
                char customKey = customKeypad.getKey();
                lcd.setCursor(0, 0);
                lcd.print("Enter Fuel");
                lcd.setCursor(0, 1);
                lcd.print("Amount : ");
                if (customKey) {
                  Serial.print(customKey);
                  litters = litters + customKey ;
                  lcd.print(litters);
                  int sta = litters.toInt();
                  if (customKey == '*') {
                    litters = "";
                    lcd.clear();
                  }
                  if (customKey == '#') {
                    if (sta <= User3_quote) {
                      lcd.clear();
                      lcd.setCursor(0, 0);
                      lcd.print("Fuel Pumping...");
                      digitalWrite(relay, LOW);
                      Serial.println(litters.length());
                      litters = litters.substring(0, litters.length() - 1);
                      Serial.println("litters : " + litters);
                      User3_usage = litters.toInt();
                      int timed = User3_usage * 6000;
                      d = User3_usage * price;
                      User3_quote = User3_quote - litters.toInt();
                      Serial.println("Time : " + (String)timed);
                      Serial.println("Price : " + (String)d);
                      Serial.println("Usage : " + (String)User3_usage);
                      Serial.println("Available fule : " + (String)User3_quote);
                      delay(timed);
                      digitalWrite(relay, HIGH);
                      lcd.clear();
                      lcd.setCursor(0, 0);
                      lcd.print("Price : Rs.");
                      lcd.print(d);
                      lcd.setCursor(0, 1);
                      lcd.print("Usage :");
                      lcd.print(User3_usage);
                      lcd.print(" L");
                      delay(5000);
                      buttonRead2();
                      pump_st = 0;
                    } else {
                      lcd.clear();
                      lcd.setCursor(0, 0);
                      lcd.print("Please Enter");
                      lcd.setCursor(0, 1);
                      lcd.print("Valid Amount");
                      delay(2000);
                      lcd.clear();
                      litters = "";
                    }
                  }
                }
              }
            } else {
              pass_count++;
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("Password InCorrect");
              delay(3000);
              lcd.clear();
              password = "";
              if (pass_count > 2) {
                pump_st = 0;
                pass_count = 0;
              }
            }
          }
        }
      }
      pump_st = 1;
      np = "";
      password = "";
      litters = "";
    }
  }
}
void updateSerial() {
  //sms.listen();
  delay(500);
  while (Serial.available()) {
    sms.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while (sms.available()) {
    Serial.write(sms.read());//Forward what Software Serial received to Serial Port
  }
}
void buttonRead() {
  sms.println("AT");
  updateSerial();
  sms.println("AT+CMGF=1");
  updateSerial();
  sms.println("AT+CMGS=\"+94705223221\"");
  updateSerial();
  sms.print("Fuel Quota : Remaining Fuel quota : " + (String)User1_quote + " " " Total Bill : Rs " + (String)(d) + """/= Thank you and Have a Nice Day.");
  updateSerial();
  sms.write(26);
  d = 0;
}
void buttonRead1() {
  sms.println("AT");
  updateSerial();
  sms.println("AT+CMGF=1");
  updateSerial();
  sms.println("AT+CMGS=\"+94705223221\"");
  updateSerial();
  sms.print(" Fuel Quota : Remaining Fuel quota : " + (String)User2_quote + " " " Total Bill : Rs " + (String)(d) + """/= Thank You.");
  updateSerial();
  sms.write(26);
  d = 0;
}
void buttonRead2() {
  sms.println("AT");
  updateSerial();
  sms.println("AT+CMGF=1");
  updateSerial();
  sms.println("AT+CMGS=\"+94705223221\"");
  updateSerial();
  sms.print("National Fuel Quota : Available Fuel Count: " + (String)User3_quote + " " "Today Total Bill : " + (String)(d) + "");
  updateSerial();
  sms.write(26);
  d = 0;
}
