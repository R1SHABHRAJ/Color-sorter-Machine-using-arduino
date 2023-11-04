/*     Arduino Project - Color Sorting Machine(CSM)
 *
 *     Author@ Dr. Rishabh Raj
 *
 */
#include <Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6
int red, blue, green =0;
LiquidCrystal_I2C lcd(0x27,16,2);
Servo topServo;
Servo bottomServo;
int frequency = 0;
int color=0;
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("WELCOME TO COLOR");
  lcd.setCursor(0,1);
  lcd.print("SORTING MACHINE");
  delay(5000);  
  lcd.clear();
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  // Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  topServo.attach(7);
  bottomServo.attach(8);
  Serial.begin(9600);
}
void loop() {
  topServo.write(115);
  delay(500);
     
  for(int i = 115; i > 65; i--) {
    topServo.write(i);
    delay(2);
  }
  delay(500);
  
  color = readColor();
  delay(100);  
  switch (color) {
    
    case 1://for red color
    bottomServo.write(25);
    red++;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Red Detected");
    lcd.setCursor(0,1);
    lcd.print("Total Red =");
    lcd.setCursor(11,1);
    lcd.print(red);
    delay(1500);
    lcd.clear();
    break;
    
    case 2://for blue color
    bottomServo.write(100);
    blue++;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Blue Detected");
    lcd.setCursor(0,1);
    lcd.print("Total blue =");
    lcd.setCursor(12,1);
    lcd.print(blue);
    delay(1500);
    lcd.clear();
    break;
    
    case 3:
    bottomServo.write(165);
    green++;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Green Detected");
    lcd.setCursor(0,1);
    lcd.print("Total green =");
    lcd.setCursor(13,1);
    lcd.print(red);
    delay(1500);
    lcd.clear();
    break;
       
    case 0:
    lcd.setCursor(0,0);
    lcd.print("Detecting color");
    lcd.setCursor(0,1);
    lcd.print("Please Wait...");
    break;
    //You can add more case-statement based on color you have defined 
  }
  delay(300);
  
  for(int i = 65; i > 29; i--) {
    topServo.write(i);
    delay(2);
  } 
  delay(200);
  
  for(int i = 29; i < 115; i++) {
    topServo.write(i);
    delay(2);
  }
  color=0;
}
// Custom Function - readColor()
int readColor() {
  // Setting red filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int R = frequency;
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  delay(50);
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int G = frequency;
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  delay(50);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int B = frequency;
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.println("  ");
  delay(50);
  //This is color section, you first have to calibrate for each color you have in your collection to be sorted out
  //You Have to take range for each color by first looking at its frequency you get from Color detector(serial moitior)
  if(R>55 & R<90 & G>150 & G<210){
    color = 1; // Red
  }
  if (G<180 & G>140 & B<100 &B>70){
    color = 2; // Blue
  }
  if(R>55 & R<75 & G<60 & G>40){
    color = 3; // Green
  }
  
  return color;  
}
