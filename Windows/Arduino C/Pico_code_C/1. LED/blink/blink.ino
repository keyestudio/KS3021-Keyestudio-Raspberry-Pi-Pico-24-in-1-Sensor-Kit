/* 
 * Keyestudio 24 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 1.2
 * Blink
 * http://www.keyestudio.com
*/
int ledPin = 0; //connect led to GP0
void setup() {
  pinMode(ledPin, OUTPUT);//set GP0 to OUTPUT
}

void loop() {
  digitalWrite(ledPin, HIGH); //output high levels，light up
  delay(1000);//delay in 1000ms
  digitalWrite(ledPin, LOW); //output low levels, go off
  delay(1000);//delay in 1000ms

}
