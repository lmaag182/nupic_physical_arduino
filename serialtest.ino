/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */

int value = 0;
int analogPin = 0;
     
int val = 0;           

String inString = "";    // string to hold input

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(2, OUTPUT);
  //digitalWrite(2,HIGH);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  //Serial.println("init");
}

// the loop function runs over and over again forever
void loop() {
  
  //Serial.println("start");
  //digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  //delay(100);              // wait for a second
  //digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  
  //delayg(1000);              // wait for a second
  //Serial.println("done");
  for (int i=0; i <= 5; i++){
      val = analogRead(analogPin);    // read the input pin
      //analogWrite(9, val / 4);
      //Serial.print("0:");
      Serial.print(val);
      Serial.print(",");
      //Serial.print("1:");
      Serial.print(analogRead(1));
      Serial.print(",");
      //Serial.print("2:");
      Serial.print(analogRead(2));
      Serial.print(",");
      //Serial.print("3:");
      Serial.print(analogRead(3));
      Serial.println();
      //Serial.print(";");
      //analog
      //Write(PWMpin, i);
      while (Serial.available() > 0) {
        int inChar = Serial.read();
        if (isDigit(inChar)) {
          // convert the incoming byte to a char
          // and add it to the string:
          inString += (char)inChar;
        }
        // if you get a newline, print the string,
        // then the string's value:
        if (inChar == '\n') {
          //Serial.print("Value:");
          //Serial.println(inString.toInt());
          value = inString.toInt();
          //Serial.print("String: ");
          //Serial.println(inString);
          // clear the string for new input:
          inString = "";
          //analogWrite(9, int(inString.toInt()));
          analogWrite(9, value/4);
        }
      }
      //analogWrite(9, val / 4);
      delay(500);
   } 
}
