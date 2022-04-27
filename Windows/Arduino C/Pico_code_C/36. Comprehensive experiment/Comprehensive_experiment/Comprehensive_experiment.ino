/*
   Keyestudio 24 in 1 Starter Kit for Raspberry Pi Pico
   lesson 36
   Comprehensive experiment
   http://www.keyestudio.com
*/
#include"rgb.h"//the library of 6812
#include"ir.h"//the library of IR

//rgb6812 is connected to GP15
RGB rgb(15,4);  //rgb(pin, num);  num = 0-100

//IR receiver is connected to GP11
IR IRreceive(11);

//the pin of the joystick module
int X = 26;
int Y = 27;
int KEY = 22;

//analog port 28 of the potentiometer
int resPin = 28;

//LED is linked with GP14
int LED = 14;

//the pin of the ultrasonic sensor
int Trig = 6;
int Echo = 7;

//the pin of the button module
int button = 16;

int PushCounter = 0;//save the number of pressing the button
int State = 1;//the status of the button
int LastState = 1;//for last state, press or release
int PushCounter1 = 0;//

void setup() {
  Serial.begin(9600);//set baud rate to 9600
  rgb.setBrightness(80);   //rgb.setBrightness(0-255);
  rgb.clear();   //Turn off all leds  
  delay(10);
  pinMode(KEY, INPUT);//the button of the joystick module
  pinMode(button, INPUT);//button module

  pinMode(Trig, OUTPUT);//ultrasonic sensor
  pinMode(Echo, INPUT);
  delay(1000);
}

void loop() {
  State = digitalRead(button);//read the state of the button
  if (LastState != State) { //the status of the button changes    if (State == 0) { //press the button
      PushCounter = PushCounter + 1;  //add 1 by accumulated of numbers of being pressed
    }
  }
  LastState = State;//refresh the last state
  PushCounter1 = PushCounter % 5; //press five time to restart
  if (PushCounter1 == 0) {  //remainder is 0
    yushu_0();  //6812 display
  } else if (PushCounter1 == 1) {  //remainder is 1
    yushu_1();  //display the signal of IR remote control
  } else if (PushCounter1 == 2) {  //remainder is 2
    yushu_2();  //display the value of joystick
  } else if (PushCounter1 == 3) {  //remainder is 3
    yushu_3();  //potentiometer controls LED
  } else if (PushCounter1 == 4) {  //remainder is 4
    yushu_4();  //show the distance detected by the ultrasonic sensor
  }
}

//6812
void yushu_0() {
  int R = random(0, 255);
  int G = random(0, 255);
  int B = random(0, 255);
  for(int i=0; i<4; i++){
    rgb.setPixelColor(i, R, G, B);
    rgb.show();
  }
  delay(300);
}

//IR receiver
void yushu_1() {
  bool flag = 1;
  while(flag){
    int key = IRreceive.getKey();
    if(key != -1){
      Serial.println(key); 
      if(key == 74){
        PushCounter = 2;
        Serial.print(PushCounter);
        flag = 0;
      }
    } 
  }
}


void yushu_2() {
  int x = analogRead(X);
  int y = analogRead(Y);
  int key = digitalRead(KEY);
  Serial.print("X:");
  Serial.print(x);
  Serial.print("    Y:");
  Serial.print(y);
  Serial.print("    KEY:");
  Serial.println(key);
  delay(100);
}

void yushu_3() {
  int RES = analogRead(resPin);
  int res = map(RES, 0, 4095, 0, 255);
  Serial.println(res);
  analogWrite(LED, res);
  delay(100);
}

void yushu_4() {
  float distance = checkdistance();
  Serial.print("distance:");
  Serial.print(distance);
  Serial.println("cm");
  delay(100);
}

float checkdistance() {
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  float distance = pulseIn(Echo, HIGH) / 58.00;
  delay(10);
  return distance;
}
