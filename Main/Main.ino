//US defintions
#include <Ultrasonic.h>
#define TRIGGER_PIN  12
#define ECHO_PIN     11
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

//SERVO definitions
#include <Servo.h> //include servo libs
Servo leftServo;  //create servo object to control a servo 
Servo rightServo; //create servo object to control a servo 
int leftServo_Pin = 2; //connected to digital out 2
int rightServo_Pin = 3; //connected to digital out 3

//LINE defintions 
int frontLine_Pin = 0; //connected to analog in 0
int frontLine_Led = 13;
int frontLine_Value;

//GLOBAL definitions
//arena official diameter micro category: 38.5 cm
float trigDist = 20.0f;
boolean trigToken;
float t1, t2, t3;
float maxTime;
boolean noBreak;

void setup()
{
  pinMode(frontLine_Led, OUTPUT); //frontLine associated LED
  
  Serial.begin(9600);

  //startup delay
  Serial.println("Welcome to NeoThug 1.2");
  Serial.println("Starting in 5 seconds...");
  delay(5000);
  AttachServos();
  Serial.println("Motors enabled");
  Stop();
}

void loop2(){
  US();
  Serial.print("FrontLine Sensor: ");
  Serial.println(analogRead(frontLine_Pin));
  Stop();
}

void loop()
{  
  //FrontLine true when white, false when black in real conditions
  Serial.print("FrontLine Sensor: ");
  Serial.println(analogRead(frontLine_Pin));
  if (FrontLine()){
    //led ON
    digitalWrite(frontLine_Led, HIGH);
  }
  else{
    //led OFF
    digitalWrite(frontLine_Led, LOW);
  }

  //main code

  //get current values
  if(!trigToken){
    t1 = US();
    delay(5);
    t2 = US();
    delay(5);
    t3 = US();
    delay(5);
  }
  
  if(!FrontLine()){
    if ((t1 < trigDist && t2 < trigDist && t3 < trigDist) || trigToken){ 
      trigToken = false; 
      maxTime = millis() + 3500.0f;
      while(!FrontLine() && millis() < maxTime){
        Forward();
      }

      
//      noBreak = true;
//      while(!FrontLine() && noBreak){
//        EvasiveManeuver();
//      }
    }
    else{
      while(!FrontLine() && US() > trigDist){
        RotateCW();
      }
      Stop();
      if (US() < trigDist){
        trigToken = true;
      }
    }
  }
  
  if(FrontLine()){
    Stop();
    AvoidBorder();
  }
}


float US()
  {
  //US
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();

  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  Serial.print("MS: ");
  Serial.print(microsec);
  Serial.print(", Distance (cm): ");
  Serial.println(cmMsec);
  return cmMsec;
  }

boolean FrontLine()
  {
  //frontLine get data
  frontLine_Value = analogRead(frontLine_Pin);
  if(frontLine_Value < 52){
    //actual condtions
    //return true;
    //testing
    return true;
  }
  else{
    //actual conditions
    //return false;
    //testing
    return false;
    
  }
  
  }

void AttachServos(){
  leftServo.attach(leftServo_Pin);  //attaches the servo on pin to the servo object 
  rightServo.attach(rightServo_Pin); //attaches the servo on pin to the servo object 
}

void Stop(){
  //left: 82 == full stop
  //offset to 90: -8
  //leftServo.write(82);
  leftServo.write(90);
  //right: 81 == full stop
  //offset to 90: -9
  //rightServo.write(81);
  rightServo.write(94);
}

void Backward(){
  rightServo.write(126);
  leftServo.write(37);
}

void Forward(){
  rightServo.write(36);
  leftServo.write(127);
}

void RotateCW(){
  leftServo.write(105);
  rightServo.write(111);
}

void RotateCCW(){
  rightServo.write(36);
  leftServo.write(36);
}

void RotateCWSlow(){
  leftServo.write(92);
  rightServo.write(92);
}

void RotateCCWSlow(){
  rightServo.write(72);
  leftServo.write(72);
}

void RotateCWavg(){
  leftServo.write(115);
  rightServo.write(115);
}

void AvoidBorder(){
  Stop();
  delay(75);
  RotateCWavg();
  delay(275);
  Stop();
  delay(75);
  Forward();
  delay(350);
  Stop();
  delay(75);
}

//not used 
void EvasiveManeuver(){
  //when facing enemy for too long
  Stop();
  delay(75);
  RotateCW();
  delay(700);
  Stop();
  delay(75);
  noBreak = false;
}




