#include <Servo.h>

Servo servoTop;
Servo servoBottom;

int xPin = A1;
int yPin = A0;
int buttonPin = 4;
int laserPin = 2;
int servoTopPin = A2;
int servoBottomPin = A3;


int xPosition = 0;
int yPosition = 0;
int buttonState = 0;

int servoTopMove = 90;
int servoBottomMove = 90;

int xPositionValue = 0;             
int yPositionValue = 0;

void setup() {

  Serial.begin(9600); 

  servoTop.attach(servoTopPin, 1000, 1100);
  servoBottom.attach(servoBottomPin, 700, 1200);
  
  servoTop.write(servoTopMove);
  servoBottom.write(servoBottomMove);
  
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);

  pinMode(buttonPin, INPUT_PULLUP); 
  pinMode(laserPin, OUTPUT); 
  
  digitalWrite(laserPin, LOW);
  
}


void loop() {
  
  xPosition = analogRead(xPin);
  yPosition = analogRead(yPin);
  buttonState = digitalRead(buttonPin);

  servoTopMove = map(yPosition, 2, 1018, 0, 180);
  servoBottomMove = (float)map(xPosition, 1018, 2, 0, 180);

  servoTop.write(servoTopMove);
  servoBottom.write(servoBottomMove);

  if (buttonState == LOW) {
    digitalWrite(laserPin, HIGH);
    Serial.print("PRESSED ");
  } else {
    digitalWrite(laserPin, LOW);
    Serial.print("not pressed ");
  }
  
  Serial.print("X: ");
  Serial.print(xPosition);
  Serial.print("servoTopMove: ");
  Serial.print(servoTopMove);
  Serial.print(" | Y: ");
  Serial.print(yPosition);
  Serial.print("servoBottomMove: ");
  Serial.print(servoBottomMove);
  Serial.print(" | Button: ");
  Serial.println(buttonState);

  delay(100);
}
