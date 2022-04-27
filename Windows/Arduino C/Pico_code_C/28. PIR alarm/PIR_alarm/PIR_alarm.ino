/* 
 * Keyestudio 24 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 28
 * PIR alarm
 * http://www.keyestudio.com
*/
int item = 0;
void setup() {
  pinMode(15, INPUT);  //the PIR motion sensor is connected to GP15 and set it to INPUT
  pinMode(16, OUTPUT);//the active buzzer is connected to GP16 and set it to output
}

void loop() {
  item = digitalRead(15);//Read the digital level signal output by the PIR motion sensor
  if (item == 1) {  //detect someone moving
    digitalWrite(16, HIGH); //turn on the buzzer
  } else {  //not detected
    digitalWrite(16, LOW); //turn off the buzzer
  }
}
