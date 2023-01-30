/*
  Title:        APSC 101 U-1 Module 5 Arduino Program Template
  Date:         Jan 5th, 2023
  Description:  This template includes all necessary headers for the arduino headers, as well as the setup.
                To configure your arduino, see the schematic.pdf or device_connection.png located at the root of this repository.
                Only modify the loop() part of this program. Add new functions as necessary. DO NOT MODIFY THE TEMPLATE.
                Please create a new file to make edits.
 */

#include <NewPing.h>      //NewPing library for ultrasonic sensor
#include <Servo.h>        //servo library for servo motor

Servo myservo;            //create servo object to control servo motor

//Ultrasonic definitions
#define ULTRASONIC_GND      10
#define ULTRASONIC_ECHO     11
#define ULTRASONIC_TRIGGER  12
#define ULTRASONIC_VCC      13
#define MAX_DISTANCE        200                                   //maximum distance set to 200 cm
NewPing sonar(ULTRASONIC_TRIGGER, ULTRASONIC_ECHO, MAX_DISTANCE); //initialize NewPing

//Servo Pin definitions
#define SERVO 9

//Switch Pin definitions
#define SWITCH 8

void setup() {
  //Serial Debug Setup
  Serial.begin(9600);
  
  //Ultrasonic Setup
  pinMode(ULTRASONIC_ECHO, INPUT);  
  pinMode(ULTRASONIC_TRIGGER, OUTPUT);
  pinMode(ULTRASONIC_GND, OUTPUT);
  pinMode(ULTRASONIC_VCC, OUTPUT);
  digitalWrite(ULTRASONIC_GND,LOW);
  digitalWrite(ULTRASONIC_VCC, HIGH);

  //Servo Motor Setup
  myservo.attach(SERVO);

  //Switch Setup
  pinMode(SWITCH, INPUT);
}

void loop() {
  int val = 1;
  while (val == 1) {
    myservo.write(60);                          //The (60) here and the (150) below can be changed to the desired servo motor angles
    int distance = sonar.ping_cm();
    if (distance > 0 && distance < 7) {         //distance (7) can be changed to the desired sensor height
      break;
    }
  }
  
  myservo.write(150);
  delay(3000);                                  //Delay before opening again can be extended or shortened
  
  
}
