/*
   Keyestudio 24 in 1 Starter Kit for Raspberry Pi Pico
   lesson 31
   adjust the light
   http://www.keyestudio.com
*/
int val1 = 0;//used to save analog values
int val2 = 0;//used to save the PWM value to be output
void setup() {
  Serial.begin(9600);//Set baud rate to 9600
}

void loop() {
  val1 = analogRead(26);//read the analog value of the potentiometer
  Serial.print(val1);//print analog value
  Serial.print("  ");
  val2 = map(val1, 0, 4095, 0, 255);//map analog values to the range of PWM value
  Serial.println(val2);//
  analogWrite(15, val2);//the pin 15 outputs PWM value
  delay(100);//delay in 1000ms
}
