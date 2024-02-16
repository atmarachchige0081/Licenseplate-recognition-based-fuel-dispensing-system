
ABSTRACT
The project “NPR Based Fuel Dispensing System” presents with the technology of image 
detection and Optical Character recognition and Microcontroller Programming. The 
project was presented as a solution for the modern quota-based fuel dispensing system used 
in Sri Lanka. The Primary Objective of this project was Designing an efficient and reliable 
fuel dispensing system which has reduced labor costs and reduced thefts within the system. 
The primary functions of the project include numberplate recognition, authentication of 
users, designing an automated fuel dispensing system and increasing Safety to the System. 
The convolutional neural network contained a dataset of 100 images of numberplates in 
the format of “BIK 1234” assuming that all characters are in a single row and adhere to the 
following format. The implementation of a CNN increased the accuracy of the system and 
the capability of the system was improved. The system was equipped with a webcam for 
numberplate recognition which then transfers data serially to Arduino. Microcontroller 
handles the functions of controlling the modules and the pumping of fuel. Additionally, 
each user was given a password of 6 characters to increase the security of the unmanned 
fuel station. 12V DC Motor was used for the fuel pumping purposes and to measure the 
pumped fuel a flow sensor was used. The system provides with real time data to user about 
the amount of dispensed, the total cost for the pumped fuel and the remaining quota of fuel. 
Project represented a significant step towards automated fuel stations, aiming to increase 
efficiency, reduce errors, and enhance user experience. The future developments will 
include an integrated payment system to make the process entirely automated and seamless.

CHAPTER 1: INTRODUCTION
As the society continues to digitize and automate systems with streamline flows 
and security features, they are high in demand. Automated systems have a huge 
impact on human lives. Therefore, a need for an automated fuel dispensing 
system is no exception. By integrating technologies such as number plate 
recognition and microcontroller programming, I aimed to develop an automated 
fuel dispensing system that is not only efficient but theft free but also secure 
and user-friendly.

1.1 BACKGROUND IMPORTNCE OF THE STUDY
Despite being functional, traditional fuel delivery systems have a number of drawbacks. 
They require a lot of labor and are vulnerable to fraud and human mistake. These problems 
are made worse by the growing number of vehicles on the road. It follows that a more 
effective and secure fuel dispensing system is clearly needed. Automation and digitization 
are continual trends in our society. This tendency has created several opportunities for 
technical advancements meant to make life simpler, safer, and more effective. Such 
developments can have a significant positive impact on the fuel distribution service sector. 
Fuel distribution systems that are automated have the potential to transform the sector by
lowering the risk of human mistake, boosting productivity, and enhancing safety measures.


1.1 PROJECT OVERVIEW AND SCOPE
The project is an ambitious endeavor to create an Automated Fuel Dispensing System 
that uses technologies like Convolutional Neural Networks (CNN), Optical Character 
Recognition (OCR), and microcontroller programming. By automating the process of 
fuel dispensing, I aimed to address some of the primary concerns associated with 
traditional fuel dispensing systems. At the heart of the project is the integration of a 
webcam-based number plate recognition system. The number plate data is processed 
using Tesseract for OCR and is transferred serially to an Arduino Uno via a USB cable. 
Once the Arduino identifies the user, it requests a password for additional security. After 
successful authentication, the user inputs the amount of fuel needed, and the system 
dispenses the requested fuel amount. The implications of this project are broad, and its 
successful implementation could greatly enhance the fuel service industry's efficiency 
and customer satisfaction.


CHAPTER 2: PRODUCT SURVEY
The product survey was done by conducting a market survey on the existing 
product on the market. The existing product is a manual, human-operated 
system where one worker needs to scan the QR code and another worker 
pumps fuel. The results of the market survey conducted regarding the existing 
product are given below.
2.1. FEATUERS OF THE PRESENST SYSTEM
- Manual Operation by an attendant
- Need additional labor/Worker to scan the QR code
- Time Consuming
- Possible human errors Within the system.
2.2. SPECIFICATIONS OF THE SELECTED PRODUCT.
- Mechanical metering system
- Manual dispensing nozzle with a trigger
- Electrical control system to manage the fuel flow
Diagram 01 Diagram 02
10 | P a g e
2.3 MAIN DRAWBACKS OF THE PRESENET SYSTEM
- Possible of Human errors
- Time consuming
- Increased labor cost
- Susceptible to theft that leads to corruption
- Low efficiency due to human involvement
2.4 BUDGET
Table 1
11 | P a g e
CHAPTER 3: OBJECTIVES AND AIMS
3.1 AIM
Designing an efficient and reliable fuel dispensing system which has reduced labor costs 
and reduced thefts within the system.
3.2 OBJECTIVES
- Designing an effective fuel Dispensing System.
- Reducing Thefts associated in fuel dispensing systems.
- Reducing the labor cost.
- Gaining the customers trust towards the system.
- Designing a reliable fuel dispensing system.
In order to cut labor expenses and prevent theft inside the system, the goal of this project 
was to build a dependable and efficient fuel dispensing system. The key goals involved 
developing an efficient system that makes use of cutting-edge technology for simplicity 
of use and accuracy in fuel measurement. The project also included cutting-edge security 
measures to reduce theft related to conventional fuel dispensing systems. By automating 
the fuel dispensing process and removing the need for ongoing physical intervention, it 
was also intended to lower labor expenses. By fulfilling these goals, I hoped to increase 
customer confidence in the system by giving them access to a fuel delivery service that 
was more effective, safe, and affordable.
12 | P a g e
CHAPTER 4: METHODOLOGY
4.1 SELECTING THE REQUIRED COMPONENTS
4.1.1. WEB CAMERA
A web camera, or webcam, is a digital camera that's connected to a computer or 
computer network, often through a USB connection or wirelessly. The primary function 
of a webcam is to transmit video over the internet or a computer network in real-time, 
also known as streaming. Webcams vary in their specifications and capabilities. Some 
important factors to consider when assessing a webcam include its resolution, frame rate, 
and the quality of its lens and sensor.
- This was used in My project to scan the number plate of the Car.
4.1.2. ARDUINO UNO*2 
The Arduino Uno is an open-source microcontroller board based on the ATmega328P 
chip. It has 14 digital input/output pins, 6 analog inputs, a 16 MHz quartz crystal, a USB 
connection, a power jack, and a reset button. It can be programmed with the Arduino 
Software (IDE) using a language similar to C++. The board can be powered via the USB 
connection or with an external power supply, with automatic source selection. It comes 
with 32KB of flash memory, 2KB of SRAM, and 1KB of EEPROM. Its versatility makes 
it a popular choice for a wide array of projects, from simple to complex applications
- This was the microcontroller used to control the components in the project.
4.1.3. SIM800L GSM MODULE
The SIM800L GSM module is a compact communication module that enables GSM 
(Global System for Mobile Communications) functionality in devices. It allows devices 
13 | P a g e
to connect to the cellular network, enabling features such as voice calls, SMS messaging, 
and data transmission.
– This was used to Send the Summary of the Fuel pumping Quota and total price to the 
Users mobile phone as a SMS.
4.1.4. 16*2 LCD SCREEN *2
A 16x2 LCD (Liquid Crystal Display) screen is a commonly used alphanumeric display 
module with 16-character positions in each of its two rows. The screen is composed of 
multiple segments or pixels that can display characters, symbols, and simple graphics. 
The 16x2 LCD screen can display a wide range of characters, including letters, numbers, 
punctuation marks, and special symbols. It is capable of displaying both static and 
scrolling text, making it useful for showing dynamic information.
– One of the LCDs were used to give instructions to the user of the process and other 
were used to displayed the amount pumped measured through the Flow Sensor.
4.1.5. 5V 2A SMPS POWER ADAPTER
A 5V 2A SMPS (Switched-Mode Power Supply) power adapter is a type of power supply 
that converts high voltage AC (alternating current) input from a wall outlet to a lower 
voltage DC (direct current) output.
– This was used to supply the required power to GSM module to get it into the ideal 
operating conditions.
4.1.6. 12V DC SUBMERSIBLE PUMP
These pumps are typically compact in size and constructed with materials that can 
withstand submersion and the corrosive effects of liquids. They often have built-in safety 
14 | P a g e
features such as overload protection and can handle a specific flow rate and head 
pressure, depending on the model and intended application
- This was used to pump the fuel into the vehicle, the motor pumps 600L/H.
4.1.7. FLOW SENSOR
The YF flow sensor is a type of flow sensor that measures the flow rate of a fluid, such as 
water, passing through it. It typically uses a mechanical turbine or paddle wheel to detect 
the flow and generates electrical pulses as output
– Flow sensor was used to measure the amount of pumped fuel. The sensor uses the hall 
effect to measure the flown amount.
4.1.8. 12V DC ELECTRIC SOLENOID VALVE
A 12V DC electric solenoid valve is a type of valve that is controlled by an electric 
current and operates on a 12-volt direct current (DC) power source. It consists of a 
solenoid coil, a plunger, and a valve mechanism. When the 12V DC power is applied to 
the solenoid coil, it generates a magnetic field, which moves the plunger inside the valve. 
This movement opens or closes the valve mechanism, allowing or blocking the flow of 
fluid (liquid or gas) through the valve
– This was used to control the flow of the incoming fuel pumped by the DC motor.
4.1.9. KEYPAD 4 BY 4 MODULE
A 4x4 keypad module is an input device that consists of a grid of 16 buttons arranged in a 
4x4 matrix. Each button represents a specific character or function. When a button is 
pressed, it creates a unique electrical connection between a particular row and column in 
the matrix
15 | P a g e
– This was used Enter the amount of fuel desired by the User and enter the password 
assigned for each user.
4.1.10. RELAY *2
A relay is an electrical switch that is operated by an electromagnet. It is commonly used 
to control larger electrical currents or voltages using a smaller control signal. The basic 
principle of a relay involves an input signal (control signal) that energizes the 
electromagnet inside the relay. This causes a mechanical switch (usually referred to as the 
contacts) to close or open, allowing or interrupting the flow of current in the circuit 
connected to the relay.
– One of the relays were used to Control the DC motor through uno and the other was 
used to control the 12V Solenoid valve.
4.1.11. I2C MODULE *2
An I2C (Inter-Integrated Circuit) module is a communication module that allows devices 
to communicate with each other using the I2C protocol. I2C is a serial communication 
protocol that enables multiple devices to be connected on the same bus, using only two 
wires: a data line (SDA) and a clock line (SCL)
– This was used to transfer data to the 2 LCDs.
4.1.12. 18650 RECHARGABLE BATTERIES*3 
18650 rechargeable batteries are a type of lithium-ion battery that gets its name from its 
dimensions: 18mm in diameter and 65mm in length
– This was the main power Source which was used for the pumping process.
16 | P a g e
4.1.13. USB CABLE
A USB (Universal Serial Bus) cable is a common type of cable used for connecting 
various devices to a computer or power source. USB cables are designed to transmit data 
and provide power to connected devices.
– This was used to transfer the scanned numberplate data to the Arduino Uno.
4.2 CIRCUIT DEVELOPMENT AND SOFTWARES USED
The Software’s used for this project was,
1. Arduino IDE – To program the microcontroller this Software was used.
2. Fritzing – To Draw the Circuit related to the project.
3. PyCharm. – The Code related to Numberplate scanning was developed 
and simulated in this Software.
4. Mermaid Live editor – To draw and visualize the procedure using the 
flow charts of the systems.
The Circuit Diagrams Developed Using Fritzing is Given Below.
17 | P a g e
Diagram 3
Diagram 4
18 | P a g e
4.3 WORKING PRINCIPLE
The Fuel Dispensing System operates on a combination of machine learning, image 
processing, and microcontroller programming principles. The system starts with the 
recognition of a vehicle's number plate. It leverages a Convolutional Neural Network 
(CNN) - a type of deep learning algorithm specifically designed for image processing tasks. 
CNN was trained using a dataset of 100 images of number plates in a specific format such 
that (BIK1234,FFT4567,ATM 2341 where the numberplate is assumed to be in a One row), 
allowing the system to accurately identify the characters on the plates. Once the image of 
the number plate is captured using a webcam, the image is processed for Optical Character 
Recognition (OCR). OCR is a technology that extracts text from images. Here, the 
Tesseract OCR engine is used. Tesseract transforms the image of the number plate into text 
data, which is then transferred serially to the Arduino Uno microcontroller via a USB cable.
Once the data is received, the Arduino Uno identifies the user using the pre-fed user data. 
To enhance the security of the system, the Arduino then prompts the user to input a 
password. If the password is verified, the user is allowed to input the required amount of 
fuel. The Arduino Uno, upon receiving the user's input for the fuel amount, activates a relay 
which in turn powers a 12V DC motor. The DC motor drives the fuel pump to dispense 
fuel. The rate of fuel flow is controlled by a solenoid valve which can be manipulated based 
on the user's requirements (Using a push button). In the final stage, the Arduino Uno (2)
calculates the amount of fuel dispensed. This information is then sent to the user's phone 
via the GSM module SIM800L including information of the remining quota and the total 
fuel cost. This complex, yet efficient process represents the seamless interaction of multiple 
technologies working in sync to create an advanced fuel dispensing system.
19 | P a g e
4.4 ARCHITECHTURE AND THE DESIGN DIAGRAMS.
4.4.1 FLOW CHART OF THE ALGORITHM
Table 2
20 | P a g e
4.4.2 FLOW CHART OF THE PROCESS IN THE MICROCONTROLLER
Table 3
21 | P a g e
4.4.3 ARCHITECHTURE OF THE CNN
Table 4
22 | P a g e
4.4.4. DESIGN DIAGRAM
Diagram 5
Diagram 6
23 | P a g e
4.5 MATERIAL SELECTION AND PROTOTYPE DESIGN
The creation of the system required a careful consideration of material choice and 
prototype design. The design and material selection have an impact on the system's 
usability, robustness, and overall efficacy. Medium Density Fiberboard (MDF) was 
chosen for this project's structure's construction. MDF is a kind of engineered wood 
renowned for its sturdiness and toughness. It could be cut and shaped without splintering 
or chipping, making it easy to work with. This was the perfect material to use for building 
a solid and dependable framework for the project.
On a Vero dot board, the circuit's component parts were put together. Vero boards are a 
sort of prototyping board that is frequently used and is distinguished by a grid of holes 
joined by parallel strips of metal. They provide a flexible and reliable framework for 
putting together electronic circuit prototypes. Vero boards are a sensible solution for this 
project since they enable simple tweaks and revisions to the circuit design when it was
necessary. Finally, I was able to construct a prototype that is both strong and adaptable 
using MDF for the framework and Vero boards for the circuit assembly. This allowed me
to match the functional specifications of the Automated Fuel Dispensing System while 
also leaving room for potential future improvements. Additionally, Bolt Screws were 
used to attach the Vero board and the LCD Displays in the MDF board.

CHAPTER 5: FINAL OUTCOME AND DISCUSSION
5.1. FINAL OUTCOME
- The final outcome of the product can be shown as the diagrams given 
above. It can successfully scan Numberplates and retrieve user 
information and proceed with the Fuel dispensing process.
Diagram 8 Diagram 9
25 | P a g e
5.2. DISCUSSION
The development process was complicated by issues with precise number plate 
recognition, safe user authentication, accurate fuel flow regulation, and real-time data 
transfer. We put into practice successful strategies to deal with these problems. The 
accuracy of number plate recognition was dramatically increased after training the CNN 
model with a broadened dataset. The system's capacity to extract characters from the 
license plates was improved by the integration of Tesseract for OCR. The Arduino code's
implementation of a safe password authentication method ensured user authentication and 
improved security. I was able to precisely control the fuel flow by utilizing relays, solenoid 
valves, and motor control. With the help of the GSM module SIM800L, users could receive 
real-time data transfer that informed them of the amount of fuel that had been dispensed, 
their remaining quota, and the overall cost.
Despite the Fuel Dispensing System's effective adoption, some shortcomings were found. 
The existing design's limited ability to scale for bigger fuel stations is one drawback. 
Additional improvements would be required to handle increased fuel consumption and 
larger infrastructure. In addition, as real-time data transmission requires a steady network 
connection, the system may have limitations in places with low connectivity. Additionally, 
human handling of payments is necessary due to the absence of an interconnected payment 
system, providing a possible area for future development.
The project allowed for the gaining of important knowledge and abilities. Gaining 
knowledge of machine learning and computer vision applications through the training and 
use of CNN models for image recognition tasks. OCR technology integration increased 
knowledge of text extraction from photographs. Programming and interacting with the Uno 
board improved programming skills for microcontrollers. Implementing communication 
modules like the GSM SIM800L module gave users hands-on data transmission 
26 | P a g e
experience. These newfound abilities can be put to use in initiatives involving similar 
systems and technology in the future.
The Unmanned fuel Dispensing System showed substantial advancement toward a reliable 
and safe automated fuel station, in sum. The problems were successfully solved by the 
applied solutions, which also enhanced the system's functionality, security, and accuracy. 
However, additional improvements can include the capacity to scale for bigger stations, 
seamless payment system integration, and improved real-time data transfer capabilities. 
Future efforts in the field of automation and fuel management systems will surely benefit 
from the information gained from this project in the areas of machine learning, 
microcontroller programming, and system integration.
5.2.1. PROBLEMS ENCOUNTERD AND SOLUTIONS
During the development of the project, several challenges were encountered and 
addressed. Some common problems included:
- Ensuring accurate number plate recognition and character extraction.
Solution - Training the CNN model with a dataset of 100 images to improve number 
plate recognition.
- Establishing a secure authentication process.
Solution - Implementing a secure password authentication system in the Arduino code.
- Controlling and regulating the flow of fuel accurately.
Solution - Using a relay, solenoid valve, and motor control to accurately control the flow 
of fuel.
- Integrating real-time data transmission via the GSM module.
Solution - Configuring the GSM module to transmit real-time data to the user
 - Welding the Components to the Vero Board.
Solution – Welding Components with the help of copper wires in the Vero board.

CHAPTER 6: CONCLUSIONS AND FUTURE WORKS
6.1 CONCLUSION
In conclusion, the creation and deployment of the Controlled Fuel Dispensing System has 
demonstrated success in meeting its main goals of precise number plate identification, user 
authorization, and controlled fuel dispensing. The accuracy, security, and functionality of 
the system have been improved by the combination of Convolutional Neural Network 
(CNN), optical recognition of characters (OCR), and microcontroller programming. The 
system has shown its potential as an effective and secure automated fuel station via the use 
of a webcam for license plate recognition, Tesseract for OCR, an Arduino Uno for user 
identification and control, and a GSM module SIM800L for real-time data transfer.
Numerous advantages of the Fuel Dispensing System include increased effectiveness, 
decreased errors, and improved user experience. The device streamlines the fueling
procedure and reduces the possibility of human error and labor costs by doing away with 
the necessity for manual intervention. Real-time data transmission to the user offers 
useful data on the amount of fuel supplied, the remaining amount available in the quota
and the overall cost, enabling better control and monitoring. The potential for automation 
in fuel management systems is indicated by the effective integration of numerous 
components and technologies.

6.2 FUTURE WORKS
While the Fuel Dispensing System has achieved notable success, there are opportunities 
for future improvements and enhancements for the system. The following areas can be 
explored for further development.
Scalability: Developing the system's scalability such that to accommodate larger fuel 
stations and higher fuel demands.
Payment System Integration: Incorporating an integrated payment system to automate 
the transaction process, allowing for seamless and secure payment handling within the 
system.
Real-Time Data Transmission: Exploring alternative communication protocols or 
backup systems to ensure reliable data transmission, particularly in areas with poor 
connectivity.
Automatic fuel tank finder: Implementing a system such that it could find the tank of the 
car automatically with the help of sensors and Computer vision techniques and use of 
proximity sensors to identify the opening of the tank.
Refinement: Further refining the CNN model by training it with more diverse datasets and 
implementing advanced image recognition techniques to improve number plate recognition 
accuracy in various conditions and formats.
Creating a Software interface with a Database: Integrating the system with a Software 
interface such that the owners of the fuel station can customize it in their own way and 
creating an app with a database which would be user friendly when obtaining these types 
of services.

Maintenance and Support: Establishing a comprehensive maintenance and support 
methodologies to ensure the long-term sustainability and optimal performance of the 
system. Regular updates, bug fixes, and system enhancements should be implemented to 
address any vulnerabilities and improve overall reliability
By addressing these aspects, the Fuel Dispensing System can evolve into a more robust 
and efficient solution and paving the way for a future where fuel management is seamless, 
secure, and user-friendly.

REFERENCES
[1] L. L. C. Technotrade, “Gas pumps automation - Technotrade LLC,” Technotrade.ua. [Online]. 
Available: https://www.technotrade.ua/fuel-dispensers-automation. [Accessed: 03-Jun-2023].
[2] N. Lang, “Breaking down Convolutional Neural Networks: Understanding the Magic behind 
Image Recognition,” Towards Data Science, 04-Dec-2021. [Online]. Available: 
https://towardsdatascience.com/using-convolutional-neural-network-for-image-classification5997bfd0ede4. [Accessed: 03-Jun-2023].
[3] “OpenCV: Introduction,” Opencv.org. [Online]. Available: 
https://docs.opencv.org/4.x/d1/dfb/intro.html. [Accessed: 04-Jun-2023].
[4] J. Johnson, “Python Numpy Tutorial (with Jupyter and Colab),” Github.io. [Online]. Available: 
https://cs231n.github.io/python-numpy-tutorial/. [Accessed: 04-Jun-2023].
[5] Last Minute Engineers, “Send receive SMS & call with SIM800L GSM Module & arduino,” Last 
Minute Engineers, 01-Aug-2018. .
[6] “What’s inside a 4x4 membrane keypad and how to interface it with an 
Arduino?,” Circuitdigest.com. [Online]. Available: https://circuitdigest.com/microcontrollerprojects/interface-4x4-membrane-keypad-with-arduino. [Accessed: 04-Jun-2023].
IMAGE REFERENCES
[1] Lankasara.com. [Online]. Available: https://lankasara.com/news/fuel-shortage-is-looming-andlines-are-forming-outside-gas-stations/. [Accessed: 04-Jun-2023].
[2] “Energy Minister says only QR Code quota system for fuel from Aug. 01,” Adaderana.lk. 
[Online]. Available: http://www.adaderana.lk/news/83861/energy-minister-says-only-qr-codequota-system-for-fuel-from-aug-01. [Accessed: 04-Jun-2023].
