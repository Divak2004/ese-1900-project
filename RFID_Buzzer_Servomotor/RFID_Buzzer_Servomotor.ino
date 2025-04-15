/*
 * 
 * All the resources for this project: https://randomnerdtutorials.com/
 * Modified by Jiwoong Park
 * 
 * Created by FILIPEFLOP
 * 
 */

// #include <SPI.h>
#include <Servo.h>
int sensorState = 0;
// Define pins
#define trigPin 13
#define echoPin 12
#define pirPin 7

// #define SS_PIN 10
// #define RST_PIN 9
Servo myservo;

// int redpin = /* SET THIS PIN*/
// int bluepin = /* SET THIS PIN*/
// int greenpin = /* SET THIS PIN*/

// int buzzpin = /* SET THIS PIN*/

int pos = 0;  // variable to store the servo position

void setup() {
  Serial.begin(9600);  // Initiate a serial communication
  // SPI.begin();      // Initiate  SPI bus
  myservo.attach(9);  // attaches the servo on pin 9 to the servo and latter two arguments will give us a full 180-degree servo range

  // define pin modes
  pinMode(pirPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.println("Start");
  Serial.println();
  myservo.writeMicroseconds(1480);  
}
void loop() {
  long duration , distance;
  digitalWrite (trigPin , LOW ); // start trig at 0
  delayMicroseconds (2);
  digitalWrite (trigPin , HIGH ); //The rising edge of trig pulse
  delayMicroseconds (10); // decides duration of trig pulse
  digitalWrite (trigPin , LOW ); //falling edge of the trig pulse
  // NOTE: echo pin reads HIGH till it receives the reflected signal
  duration = pulseIn (echoPin , HIGH ); // Reading the duration for which echoPin was HIGH gives
  //you the time the sensor receives a reflected signal at the echo pin
  distance = (duration / 2) / 29.1; //Calculate the distance of the reflecting surface in cm

  Serial.print("distance:");
  Serial.println(distance);

  // sensorState = digitalRead(pirPin);
  // Serial.println(sensorState);


  // //delay(5000);
  // myservo.writeMicroseconds(1425);  
  // delay(2000); // rotate for 2 seconds
  //   // Stop
  // myservo.writeMicroseconds(1480);  
  // delay(2000); // stay still for 2 seconds
  
  // // Rotate counterclockwise
  // myservo.writeMicroseconds(1530);  
  // delay(2000); // rotate for 2 seconds
  
  // // Stop again
  // myservo.writeMicroseconds(1480);  
  // delay(2000);
    // pos= 90;
    // myservo.write(pos); // Move the servo to its new position (either 95 or 0)
    // Serial.println();
    // delay(1000);
    // pos= 96;
    // myservo.write(pos); // Move the servo to its new position (either 95 or 0)
    // delay(1000);
  

  // Change this so that if the IR detects something we turn the servo motor
  if (distance < 10)
  {
    // for (int i = 0; i < 90; i++) {
    //   myservo.write(i);
    //   delay(10);
    // }
    // for (int i = 90; i >= 0; i++) {
    //   myservo.write(i);
    //   delay(10);
    // }
    myservo.writeMicroseconds(1435);  
    delay(2000); // rotate for 2 seconds
      // Stop
    Serial.println("Rotate clockwise");
    myservo.writeMicroseconds(1480);  
    delay(2000); // stay still for 2 seconds
  
    
    // Rotate counterclockwise
    myservo.writeMicroseconds(1530);  
    delay(2000); // rotate for 2 seconds
    Serial.println("Rotate counterclockwise");
    // Stop again
    myservo.writeMicroseconds(1480);  
    delay(2000);
  }

  delay(2000);
}
