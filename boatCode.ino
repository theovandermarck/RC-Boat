#include <Servo.h>
const String input1 = "A4";
const String input2 = "A5";
const int servo = 8;
int servoAngle = 90;
Servo myServo;

void setup() {
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  myServo.attach(servo);
  myServo.write(90);
  Serial.begin(9600);
}

void loop() {
  int stateButton1 = analogRead(A4);
  int stateButton2 = analogRead(A5);
  if (stateButton1 == 0){
    if (myServo.read()<180){
      myServo.write(myServo.read()+1);
    }
  }else if(stateButton2 == 0){
    if (myServo.read()>0){
      myServo.write(myServo.read()-1);
    }
  }else if (myServo.read()!=90){
      myServo.write(90);
  }
  Serial.println(myServo.read());
}