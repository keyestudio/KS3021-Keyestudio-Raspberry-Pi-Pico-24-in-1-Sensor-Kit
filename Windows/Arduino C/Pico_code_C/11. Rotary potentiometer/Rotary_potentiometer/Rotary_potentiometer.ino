/* 
 * Keyestudio 24 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 11
 * Rotary potentiometer
 * http://www.keyestudio.com
*/
int analogVal = 0;
int resPin = 26; //the potentiometer is connected to ADC0
void setup() {
  Serial.begin(9600);//Set baud rate to 9600
}

void loop() {
  analogVal = analogRead(resPin);//read the value of the potentiometer
  Serial.println(analogVal);//print analog value
  delay(100);//delay in 100ms

}
