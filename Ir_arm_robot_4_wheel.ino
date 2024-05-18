#include <AFMotor.h>//**********5 Channel IR Sensor Connection**********//
#define ir1 A1
#define ir2 A2
#define ir3 A3
#define ir4 A4
#define ir5 A5
//defining motors
AF_DCMotor motor1(1); // Left Side First Motor
//AF_DCMotor motor2(2); // Left Side Second Motor
AF_DCMotor motor3(3); // Right Side First Motor
//AF_DCMotor motor4(4); // RIght Side Second Motor
void setup() {
 //setting the speed of motors
 motor1.setSpeed(60);
 //motor2.setSpeed(90);
 motor3.setSpeed(60);
 //motor4.setSpeed(90);
 pinMode(ir1, INPUT);
 pinMode(ir2, INPUT);
 pinMode(ir3, INPUT);
 pinMode(ir4, INPUT);
 pinMode(ir5, INPUT);
 Serial.begin(9600);
}
void loop() {
 //Reading Sensor Values
 int s1 = digitalRead(ir1); //Left Most Sensor
 int s2 = digitalRead(ir2); //Left Sensor
 int s3 = digitalRead(ir3); //Middle Sensor
 int s4 = digitalRead(ir4); //Right Sensor
 int s5 = digitalRead(ir5); //Right Most Sensor
 //if only middle sensor detects black line
 if ((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 1) && (s5 == 1))
 {
 //going forward with full speed
 motor1.run(FORWARD);
 //motor2.run(FORWARD);
 motor3.run(FORWARD);
 //motor4.run(FORWARD);
 Serial.println("s3=1");
 }
 //if only left sensor detects black line
 if ((s1 == 1) && (s2 == 0) && (s3 == 1) && (s4 == 1) && (s5 == 1))
 {
 //going right with full speed
 motor1.run(FORWARD);
 //motor2.run(FORWARD);
 motor3.run(RELEASE);
 //motor4.run(RELEASE);
 Serial.println("s2=1");
 }
 //if only left most sensor detects black line
 if ((s1 == 0) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 1))
 {
 //going right with full speed
 motor1.run(FORWARD);
 //motor2.run(FORWARD);
 motor3.run(BACKWARD);
// motor4.run(BACKWARD);
 Serial.println("s1=1");
 }
 //if only right sensor detects black line
 if ((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 0) && (s5 == 1))
 {
 //going left with full speed
 motor1.run(RELEASE);
// motor2.run(RELEASE);
 motor3.run(FORWARD);
// motor4.run(FORWARD);
 Serial.println("s4=1");
 }
 //if only right most sensor detects black line
 if ((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 0))
 {
 //going left with full speed
 motor1.run(BACKWARD);
 //motor2.run(BACKWARD);
 motor3.run(FORWARD);
 //motor4.run(FORWARD);
 Serial.println("s5=1");
 }
 //if middle and right sensor detects black line
 if ((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 1))
 {

 //going left with full speed
 motor1.run(RELEASE);
// motor2.run(RELEASE);
 motor3.run(FORWARD);
 //motor4.run(FORWARD);
 }
 //if middle and left sensor detects black line
 if ((s1 == 1) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 1))
 {
 //going right with full speed
 motor1.run(FORWARD);
 //motor2.run(FORWARD);
 motor3.run(RELEASE);
 //motor4.run(RELEASE);
 }
 //if middle, left and left most sensor detects black line
 if ((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 1))
 {
 //going right with full speed
 motor1.run(FORWARD);
// motor2.run(FORWARD);
 motor3.run(RELEASE);
 //motor4.run(RELEASE);
 }
 //if middle, right and right most sensor detects black line
 if ((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 0))
 {
 //going left with full speed
 motor1.run(RELEASE);
 //motor2.run(RELEASE);
 motor3.run(FORWARD);
 //motor4.run(FORWARD);
 }
 //if all sensors are on a black line
 if ((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 1))
 {
 //stop
 motor1.run(FORWARD);
 //motor2.run(RELEASE);
 motor3.run(FORWARD);
 //motor4.run(RELEASE);
 }
}
