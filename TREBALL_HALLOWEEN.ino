/*
 Skull 
 Usoso Academics 
 Grup: 201
 Maria Casas & Joan Conill
 
*/


#include <Servo.h> // We specify which servo we will use, and we let the system know that we will use a servo motor. 

Servo myservo; // We give a name to the servo. 
const int pir = 2; // We used a sensor, so we let the program know in witch pin is conected on the Arduino. 


// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600); // it begins to start the functions of the sensor. 
  // make the pushbutton's pin an input:
  pinMode(pir, INPUT); // We set the sensor as a Input, because it gives information to the system. 
  pinMode (12, OUTPUT); // For the LED's, we first set them as an Output, because projects information out of the system. We also set the exact pin number. 
  pinMode (11, OUTPUT); // For the LED's, we first set them as an Output, because projects information out of the system. We also set the exact pin number.
  myservo.attach (9); // We attach the servo to an exact pin number, number 9 in this case. 
}

// the loop routine runs over and over again forever:
void loop() {
  if (digitalRead (pir) ) { // We set a condition, so when the sensor detacts a movemnt, it does the following.
    myservo.write(60); // The final position of the servo.
    digitalWrite (11, HIGH); // When the sensor recievs movemnt, it lights the LED. 
    digitalWrite (12, HIGH); // When the sensor recievs movemnt, it lights the LED. 
   
  }
  else { // So when the sensor doesn't percive any data, it does the following. 
    myservo.write (180); // Start position of the servo. 
    digitalWrite (11, LOW); // It tourns off the LED light, when the sensor is not operative. 
    digitalWrite (12, LOW); // It tourns off the LED light, when the sensor is not operative.
    
  }
  Serial.println(digitalRead(pir)); // It prints the data revived by the sensor on the Monitor sèrie. 
  delay(30); // delay in between reads for stability in this case 0,3s. 

}
