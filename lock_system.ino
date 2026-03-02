#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servo;
#define buzzer 11

String pass = "200A", input = "";

const byte ROWS=4, COLS=4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rPins[ROWS] = {9,8,7,6}, cPins[COLS] = {5,4,3,2};
Keypad pad(makeKeymap(keys), rPins, cPins, ROWS, COLS);

void setup(){
  lcd.init(); lcd.backlight();
  servo.attach(10);
  pinMode(buzzer, OUTPUT);
  lcd.print("Enter Password:");
}

void loop(){
  char key = pad.getKey();
  if (!key) return;

  if (key == '*') { input = ""; lcd.clear(); lcd.print("Enter Password:"); }
  else if (key == '#') {
    if (input == pass) { tone(buzzer,2000,200); servo.write(90); delay(2000); servo.write(0); }
    else { for(int i=0;i<3;i++){ tone(buzzer,1000,200); delay(400);} }
    input = ""; lcd.clear(); lcd.print("Enter Password:");
  }
  else { input += key; lcd.setCursor(0,1); lcd.print(input); }
}
