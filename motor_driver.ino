#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#include <TimerOne.h>
int ledState = LOW;

#define OLED_ADDR   0x3C
// reset pin not used on 4-pin OLED module
Adafruit_SSD1306 display(-1);  // -1 = no reset pin


const int stepPin = 7;
const int dirPin = 6; 

void setup() {
  Serial.begin(9600);

  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.setTextSize(4);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("Hello");
  display.display();
  
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  digitalWrite(dirPin, HIGH);

  Timer1.initialize(150); //The led will blink in a half second time interval
  Timer1.attachInterrupt(blinkLed);
  
}
void loop() {
  /*
  display.clearDisplay();
  display.setTextSize(4);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print(map(analogRead(A0), 0, 1023, 1, 1000));
  
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(map(analogRead(A0), 0, 1023, 1, 1000));
  digitalWrite(stepPin, LOW);
  delayMicroseconds(map(analogRead(A0), 0, 1023, 1, 1000));
  
  //display.display();
  */
}


void blinkLed(){
  ledState = !ledState;
  digitalWrite(stepPin, ledState);
}
