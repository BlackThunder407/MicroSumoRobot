/*
 * Micro Sumo Robot - Project B1-T3
 *
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

/* Each sensor and each servo has an associated LED indicating if it detects something or if it is active
 * That leaves us with 3 remaining LEDs - we might choose to implement a 3-bit up counter visualization allowing to count from 0 to 7
 * 0 000 
 * 1 001 HUNT MODE: looking for opponents | not at the edge - not sensing enemies - sweeps across arena looking for opponent
 * 2 010 TARGET MODE: aiming to face found opponent | opponent sensed - aiming to face opponent AND moving towards opponent
 * 3 011 ATTACK MODE: pushing opponent ahead | opponent sensed - aiming complete - moving at full power to push opponent
 * 4 100 SURVIVE MODE: staying in arena at all costs | rotating to stay in arena
 * 5 101 STOP MODE: ending operations on user request
 * 6 110 CURRENTLY ROTATING
 * 7 111 PRGM ERROR
 */
 
/* HUNT MODE CONDITIONS
 * frontLine.detection() == False;
 * backLine.detection() == False;
 * frontSonic.proximityLevel() == 0;
 * backIR.proximityLevel() == 0;
 */

/* TARGET MODE CONDITIONS
 * frontLine.detection() == False;
 * backLine.detection() == False;
 * frontSonic.proximityLevel() == 1;
 * backIR.proximityLevel() == 1;
 */
 
/* ATTACK MODE CONDITIONS
 * frontLine.detection() == False;
 * backLine.detection() == False;
 * frontSonic.proximityLevel() > 1;
 * backIR.proximityLevel() > 1;
 */
 
/* SURVIVE MODE CONDITIONS
 * frontLine.detection() == True;
 * backLine.detection() == True;
 */
 
/* SURVIVE MODE CONDITIONS
 * TODO: implement STOP button
 */
 
/* TO IMPLEMENT: 
 * one object for frontSonic and backIR with the following methods:
 * frontSonic.distance(); returning distance to detected object as float, returning -1 if no detection
 * frontSonic.detection(); returning True if object is detected and False otherwise
 * frontSonic.proximityLevel(); returning integer 0, 1, 2, 3 where 0 is no alert (no detection) and 3 is maximum alert (distance related)
 * one object for frontLine and backLine with the following methods:
 * frontLine.detection(); returning True if the edge is detected and False otherwise
 * frontLine.edge(); returning True is frontline.detection(); occurs long enough
 * one object for each servo with the following methods:
 * leftServo.speed(maxForward);
 * leftServo.speed(medForward);
 * leftServo.speed(minForward);
 * leftServo.speed(maxBackward);
 * leftServo.speed(medBackward);
 * leftServo.speed(minBackward);
 */
 
//////////////////
// LIBS INCLUDE //
//////////////////

#include <Servo.h> //include servo libs

/////////////////
// GLOBAL VARS //
/////////////////

//public String globalState;

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

  //leftServo.write(100);

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
  //mid 80
  rightServo.write(70);
  leftServo.write(90);

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

//String globalStateAnalyst(){
//  //DESCRIPTION: globalStateAnalyst collects data and returns the best possible rehavior 
//} 
