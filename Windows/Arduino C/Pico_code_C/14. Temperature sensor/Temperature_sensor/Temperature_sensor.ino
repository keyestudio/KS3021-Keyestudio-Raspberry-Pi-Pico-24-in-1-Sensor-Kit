 /* 
 * Keyestudio 24 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 14
 * Temperature sensor
 * http://www.keyestudio.com
*/
int val;
int ntcPin = 26;  //NTC-MF52AT analog thermistor is connected to ADC0
void setup() {
  Serial.begin(9600);//Set baud rate to 9600
}

void loop() {
  val = analogRead(ntcPin); //read the analog temperature value
  Serial.println(val); //read and print the analog vale of photoresistor
  delay(100);//delay in 100ms

}
