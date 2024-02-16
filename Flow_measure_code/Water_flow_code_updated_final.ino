#include <Wire.h> // include the I2C library
#include <LiquidCrystal_I2C.h> // include the LCD library
float vol = 0.0,l_minute;
unsigned char flowsensor = 2; // Sensor Input
unsigned long currentTime;
unsigned long cloopTime;
LiquidCrystal_I2C lcd(0x27,16,2);  // Set the LCD address and size
volatile int flow_frequency;
const int switchPin = 9; // define the input pin for the switch
const int solenoidPin = 7;
void flow () // Interrupt function to increment flow
{
   flow_frequency++;
}

void setup()
{
    // Measures flow sensor pulses
   Serial.begin(9600);
   pinMode(flowsensor, INPUT);
   digitalWrite(flowsensor, HIGH); // Optional Internal Pull-Up
   attachInterrupt(digitalPinToInterrupt(flowsensor), flow, RISING); // Setup Interrupt
   pinMode(switchPin, INPUT_PULLUP); // set the switch pin as an input with pull-up resistor
   pinMode(solenoidPin, OUTPUT);
   lcd.begin();
   lcd.begin();// initialize the LCD
   lcd.backlight(); // turn on the backlight
   lcd.setCursor(0,0);
   lcd.print("ATM Fuel Station");
   lcd.setCursor(0,1);
   lcd.print("Welcome");
   currentTime = millis();
   cloopTime = currentTime;
}

void loop ()
{
  int switchState = digitalRead(switchPin); // read the state of the switch

  if (switchState == LOW) { // if the switch is pressed
    digitalWrite(solenoidPin, HIGH); // turn on the solenoid valve
  } else { // if the switch is not pressed
    digitalWrite(solenoidPin, LOW); // turn off the solenoid valve
  }
   currentTime = millis();
   // Every second, calculate and print litres/hour
   if(currentTime >= (cloopTime + 1000))
   {
    cloopTime = currentTime; // Updates cloopTime
    if(flow_frequency != 0)
    {
       l_minute = (flow_frequency / 7.5); // (Pulse frequency x 60 min) / 7.5Q = flowrate in L/hour
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Pumped Amount :  ");
      //lcd.print(l_minute);
      //lcd.print(" L/M");
      l_minute = l_minute/60;
      lcd.setCursor(0,1);
      vol = vol +l_minute;
      //lcd.print("Vol:");
      lcd.print(vol);
      lcd.print(" L");
      flow_frequency = 0; // Reset Counter
      Serial.print(l_minute, DEC); // Print litres/hour
      Serial.println(" L/Sec");
    }
    else {
      Serial.println(" flow rate = 0 ");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Pumped Amount : ");
      lcd.print( flow_frequency );
      //lcd.print(" L/M");
      lcd.setCursor(0,1);
      //lcd.print("Vol:");
      lcd.print(vol);
      lcd.print(" L");
    }
   }
}
