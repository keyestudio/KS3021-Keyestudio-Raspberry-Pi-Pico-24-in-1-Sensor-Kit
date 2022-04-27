/* 
 * Keyestudio 24 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 8
 * Active buzzer
 * http://www.keyestudio.com
*/
int buzzer = 20; //set the pin of the active sensor to GP20
void setup() {
  pinMode(buzzer, OUTPUT);//set OUTPUT
}

void loop() {
  digitalWrite(buzzer, HIGH); //stop beeping
  delay(1000);
  digitalWrite(buzzer, LOW); //stop beeping
  delay(1000);
}
