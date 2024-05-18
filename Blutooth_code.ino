#include <AFMotor.h>
#include <SoftwareSerial.h>
SoftwareSerial robotBT(A3,A4);//Rx and Tx configured using software robotBT..NOTE->Do not use A5. It won't work.
//creates two objects to control the terminal 3 and 4 of motor shield 
AF_DCMotor motor1(1); // Left Side First Motor
AF_DCMotor motor2(2); // Left Side Second Motor 
AF_DCMotor motor3(3); // Right Side First Motor
AF_DCMotor motor4(4); // Right Side Second Motor
char command; 
void setup() 
{ 
robotBT.begin(9600); //Set the baud rate to your Bluetooth module.
Serial.begin(9600);
}
void loop(){
 if(robotBT.available() > 0){ 
 command = robotBT.read(); 
 //Change pin mode only if new command is different from previous. 
 Serial.println(command);
 switch(command){
 case 'F': 
 forward();
 break;
 case 'B': 
 backward();
 break;
 case 'L': 
 left();
 break;
 case 'R':
 right();
 break;
 }
 } 
}
void forward()
{
 motor1.setSpeed(255); //Define maximum velocity
 motor1.run(FORWARD); //rotate the motor clockwise
 motor2.setSpeed(255); //Define maximum velocity
 motor2.run(FORWARD); //rotate the motor clockwise
 motor3.setSpeed(255); //Define maximum velocity
 motor3.run(FORWARD); //rotate the motor clockwise
 motor4.setSpeed(255); //Define maximum velocity
 motor4.run(FORWARD); //rotate the motor clockwise
}
void backward()
{
 motor1.setSpeed(255); 
 motor1.run(BACKWARD); //rotate the motor counterclockwise
 motor2.setSpeed(255); 
 motor2.run(BACKWARD); //rotate the motor counterclockwise
 motor3.setSpeed(255); 
 motor3.run(BACKWARD); //rotate the motor counterclockwise
 motor4.setSpeed(255); 
 motor4.run(BACKWARD); //rotate the motor counterclockwise
}
void left()
{
 motor1.setSpeed(255); 
 motor1.run(FORWARD); 
 motor2.setSpeed(255);
 motor2.run(FORWARD); 
 motor3.setSpeed(0); 
 motor3.run(RELEASE); 
 motor4.setSpeed(0);
 motor4.run(RELEASE); 
}
void right()
{
 motor1.setSpeed(0);
 motor1.run(RELEASE); 
 motor2.setSpeed(0); 
 motor2.run(RELEASE); 
 motor3.setSpeed(255);
 motor3.run(FORWARD); 
 motor4.setSpeed(255); 
motor4.run(FORWARD); 
}
void Stop()
{
 motor1.setSpeed(0);
 motor1.run(RELEASE); 
 motor2.setSpeed(0);
 motor2.run(RELEASE); 
 motor3.setSpeed(0);
 motor3.run(RELEASE); 
 motor4.setSpeed(0);
 motor4.run(RELEASE); 
}
