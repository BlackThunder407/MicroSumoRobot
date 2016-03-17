/*
 * Inputs:
 * frontSonic
 * backIR
 * frontLine
 * backLine
 * 
 * Outputs:
 * leftServo
 * rightServo
 */

//////////////////
// LIBS INCLUDE //
//////////////////

#include <Servo.h> //include servo libs

/////////////////
// GLOBAL VARS //
/////////////////

public String globalState;

///////////////////
// OBJECTS SETUP //
///////////////////

Servo leftServo;  //create servo object to control a servo 
Servo rightServo; //create servo object to control a servo 

//////////////////
// INPUTS SETUP //
//////////////////

int frontSonic_Pin = 0; //connected to analog in
int backIR_Pin = 1; //connected to analog in
int frontLine_Pin = 2; //connected to analog in
int backLine_Pin = 3; //connected to analog in

////////////////
// LEDS SETUP //
////////////////

int frontSonic_Led = 12;
int backIR_Led = 11;
int frontLine_Led = 10;
int backLine_Led = 9;

int leftServo_Led = 8;
int rightServo_Led = 7;

///////////////////
// OUTPUTS SETUP //
///////////////////

int leftServo_Pin = 2; //connected to digital out
int rightServo_Pin = 3; //connected to digital out

///////////////
// RUN SETUP //
///////////////

void setup(){
  Serial.begin(9600); //enables serial monitor
  
  //SONIC
  pinMode(frontSonic_Led, OUTPUT); //Sonic associated LED
  
  //IR
  pinMode(backIR_Led, OUTPUT); //IR associated LED
  
  //FRONT LINE
  pinMode(frontLine_Led, OUTPUT); //frontLine associated LED

  //BACK LINE
  pinMode(backLine_Led, OUTPUT); //backLine associated LED
  
  //LEFT SERVO
  leftServo.attach(leftServo_Pin);  //attaches the servo on pin to the servo object 
  pinMode(leftServo_Led, OUTPUT); //leftServo associated LED

  //RIGHT SERVO
  rightServo.attach(rightServo_Pin); //attaches the servo on pin to the servo object 
  pinMode(rightServo_Led, OUTPUT); //rightServo associated LED
}

///////////////
// MAIN LOOP //
///////////////

void loop(){
  test();
  Serial.println(frontSonic_Distance());
}

void test(){
  
  ///////////
  // SONIC //
  ///////////
  
  ////////
  // IR //
  ////////

  int backIR_Value = analogRead(backIR_Pin);
  //Serial.println(val);

  //just to slow down the output - remove if trying to catch an object passing by
  //delay(100);

  if(backIR_Value < 100){
    digitalWrite(backIR_Led, HIGH);
    Serial.println("IR: object close");
  }
  else{
    digitalWrite(backIR_Led, LOW);
  }
  
  ////////////////
  // FRONT LINE //
  ////////////////

  int frontLine_Value = analogRead(frontLine_Pin);
  
  if(frontLine_Value < 200){
	  digitalWrite(frontLine_Led, HIGH);
	}
	else{
		digitalWrite(frontLine_Led, LOW);
	}
 
  ///////////////
  // BACK LINE //
  ///////////////

  int backLine_Value = analogRead(backLine_Pin);

  if(backLine_Value < 200){
    digitalWrite(backLine_Led, HIGH);
  }
  else{
    digitalWrite(backLine_Led, LOW);
  }
  
  ////////////////
  // LEFT SERVO //
  ////////////////

  leftServo.write(100);

  //  myservo.write(45);                  // rotate counterclockwise full speed
  //  delay(2000);                           
  //  myservo.write(90);                  // stop
  //  delay(100);
  //  myservo.write(135);                 // rotate clockwise full speed
  //  delay(2000);
  //  myservo.write(90);                  // stop
  //  delay(100);
  //  myservo.write(80);                  // rotate very slowly counterclockwise
  //  delay(2000);
  //  myservo.write(90);                  // stop
  //  delay(100);
  //  myservo.write(100);                 // rotate very slowly clockwise
  //  delay(2000);
  
  ////////////////
  // RIGHT SERVO //
  ////////////////

  rightServo.write(100);
}

float frontSonic_Distance(){
  //TODO: add distance code for frontSonic
  return -1.0f;
}

float backIR_Distance(){
  //TODO: add distance code
  return -1.0f;
}

float frontLine_Distance(){
  //TODO: add distance code
  return -1.0f;
}

float backLine_Distance(){
  //TODO: add distance code
  return -1.0f;
}

String globalStateAnalyst(){
  //DESCRIPTION: globalStateAnalyst collects data and returns the best possible rehavior 
}

