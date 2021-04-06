/* Bluetooth Hex Locker Code
   Author: Apurva Umredkar*/

//Defining all the pins and importing all the required  libraries

#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver rgb = Adafruit_PWMServoDriver();
#define pwmR1 0
#define pwmG1 1
#define pwmB1 2
#define pwmR2 3
#define pwmG2 4
#define pwmB2 5
#define pwmR3 6
#define pwmG3 7
#define pwmB3 8
int r1 = 0, r2 = 0, r3 = 0, g1 = 0, g2 = 0, g3 = 0, b1 = 0, b2 = 0, b3 = 0;



//LCD Pins

#define L0 12
#define L1 13
#define L2 14
#define L3 22
#define L4 21
#define L5 20
#define L6 19
#define L7 18
#define RS 10
#define LCDEN 11

#include <LiquidCrystal.h>
LiquidCrystal lcd(RS, LCDEN, L0, L1, L2, L3, L4, L5, L6, L7);

//Keypad Pins

#define KR1 27
#define KR2 26
#define KR3 25
#define KR4 24
#define KR5 23
#define KC1 28
#define KC2 29
#define KC3 30
#define KC4 31

int i, j, key;
int krow[] = {KR1, KR2, KR3, KR4, KR5};
int kcol[] = {KC1, KC2, KC3, KC4};

//Buzzer pins
#define BUZ 2

//PASSWORD
String p1 = "222222";
String p2 = "222222";
String p3 = "222222";

//Current Code
String c1, c2, c3;
int digitcount = -1, attempts = 5, stat = 0;


void setup() {
  // put your setup code here, to run once:
  lcd.begin(20, 4);
  lcd.clear();
  for (i = 0; i < 5; i++)
    pinMode(krow[i], OUTPUT);
  for (i = 0; i < 4; i++)
  {
    pinMode(kcol[i], INPUT);
    digitalWrite(kcol[i], HIGH);
  }

  //initial random password
  randomSeed(analogRead(30));
  randomizePass();
  rgb.begin();
  rgb.setPWMFreq(1600);
  dispRGB();
}

void loop() {
  // put your main code here, to run repeatedly:

  for (i = 0; i < 5; i++)
  {
    digitalWrite(krow[0], HIGH);
    digitalWrite(krow[1], HIGH);
    digitalWrite(krow[2], HIGH);
    digitalWrite(krow[3], HIGH);
    digitalWrite(krow[4], HIGH);
    digitalWrite(krow[i], LOW);
    for (j = 0; j < 4; j++)
    {
      key = digitalRead(kcol[j]);
      if (key == LOW)
      {
        if (digitcount == 0)
          c1 = "000000";
        else if (digitcount == 6)
          c2 = "000000";
        else if (digitcount == 12)
          c3 = "000000";
        keypress(i, j);
        digitcount == 18 ? digitcount = -1 : digitcount++;
        lcdText();
        delay(50);
      }
    }
  }
}

void keypress(int x, int y)
{
  if (i == 0 && j == 0)
  {
    if (digitcount < 6)
    {
      c1[digitcount] = '0';
    }
    else if (digitcount < 12 && digitcount > 5)
    {
      c2[digitcount - 6] = '0';
    }
    if (digitcount < 18 && digitcount > 11)
    {
      c3[digitcount - 12] = '0';
    }
    lcdText();
    dispRGB();
  }
  if (i == 0 && j == 1)
  {
    if (digitcount < 6)
    {
      c1[digitcount] = '1';
    }
    else if (digitcount < 12 && digitcount > 5)
    {
      c2[digitcount - 6] = '1';
    }
    if (digitcount < 18 && digitcount > 11)
    {
      c3[digitcount - 12] = '1';
    }
    lcdText();
    dispRGB();
  }
  if (i == 0 && j == 2)
  {
    if (digitcount < 6)
    {
      c1[digitcount] = '2';
    }
    else if (digitcount < 12 && digitcount > 5)
    {
      c2[digitcount - 6] = '2';
    }
    if (digitcount < 18 && digitcount > 11)
    {
      c3[digitcount - 12] = '2';
    }
    lcdText();
    dispRGB();
  }
  if (i == 0 && j == 3)
  {
    if (digitcount < 6)
    {
      c1[digitcount] = '3';
    }
    else if (digitcount < 12 && digitcount > 5)
    {
      c2[digitcount - 6] = '3';
    }
    if (digitcount < 18 && digitcount > 11)
    {
      c3[digitcount - 12] = '3';
    }
    lcdText();
  }
  if (i == 1 && j == 0)
  {
    if (digitcount < 6)
    {
      c1[digitcount] = '4';
    }
    else if (digitcount < 12 && digitcount > 5)
    {
      c2[digitcount - 6] = '4';
    }
    if (digitcount < 18 && digitcount > 11)
    {
      c3[digitcount - 12] = '4';
    }
    lcdText();
    dispRGB();
  }
  if (i == 1 && j == 1)
  {
    if (digitcount < 6)
    {
      c1[digitcount] = '5';
    }
    else if (digitcount < 12 && digitcount > 5)
    {
      c2[digitcount - 6] = '5';
    }
    if (digitcount < 18 && digitcount > 11)
    {
      c3[digitcount - 12] = '5';
    }
    lcdText();
    dispRGB();
  }
  if (i == 1 && j == 2)
  {
    if (digitcount < 6)
    {
      c1[digitcount] = '6';
    }
    else if (digitcount < 12 && digitcount > 5)
    {
      c2[digitcount - 6] = '6';
    }
    if (digitcount < 18 && digitcount > 11)
    {
      c3[digitcount - 12] = '6';
    }
    lcdText();
    dispRGB();
  }
  if (i == 1 && j == 3)
  {
    if (digitcount < 6)
    {
      c1[digitcount] = '7';
    }
    else if (digitcount < 12 && digitcount > 5)
    {
      c2[digitcount - 6] = '7';
    }
    if (digitcount < 18 && digitcount > 11)
    {
      c3[digitcount - 12] = '7';
    }
    lcdText();
    dispRGB();
  }
  if (i == 2 && j == 0)
  {
    if (digitcount < 6)
    {
      c1[digitcount] = '8';
    }
    else if (digitcount < 12 && digitcount > 5)
    {
      c2[digitcount - 6] = '8';
    }
    if (digitcount < 18 && digitcount > 11)
    {
      c3[digitcount - 12] = '8';
    }
    lcdText();
    dispRGB();
  }
  if (i == 2 && j == 1)
  {
    if (digitcount < 6)
    {
      c1[digitcount] = '9';
    }
    else if (digitcount < 12 && digitcount > 5)
    {
      c2[digitcount - 6] = '9';
    }
    if (digitcount < 18 && digitcount > 11)
    {
      c3[digitcount - 12] = '9';
    }
    lcdText();
    dispRGB();
  }
  if (i == 2 && j == 2)
  {
    if (digitcount < 6)
    {
      c1[digitcount] = 'A';
    }
    else if (digitcount < 12 && digitcount > 5)
    {
      c2[digitcount - 6] = 'A';
    }
    if (digitcount < 18 && digitcount > 11)
    {
      c3[digitcount - 12] = 'A';
    }
    lcdText();
    dispRGB();
  }
  if (i == 2 && j == 3)
  {
    if (digitcount < 6)
    {
      c1[digitcount] = 'B';
    }
    else if (digitcount < 12 && digitcount > 5)
    {
      c2[digitcount - 6] = 'B';
    }
    if (digitcount < 18 && digitcount > 11)
    {
      c3[digitcount - 12] = 'B';
    }
    lcdText();
    dispRGB();
  }
  if (i == 3 && j == 0)
  {
    if (digitcount < 6)
    {
      c1[digitcount] = 'C';
    }
    else if (digitcount < 12 && digitcount > 5)
    {
      c2[digitcount - 6] = 'C';
    }
    if (digitcount < 18 && digitcount > 11)
    {
      c3[digitcount - 12] = 'C';
    }

    lcdText();
    dispRGB();
  } if (i == 3 && j == 1)
  {
    if (digitcount < 6)
    {
      c1[digitcount] = 'D';
    }
    else if (digitcount < 12 && digitcount > 5)
    {
      c2[digitcount - 6] = 'D';
    }
    if (digitcount < 18 && digitcount > 11)
    {
      c3[digitcount - 12] = 'D';
    }
    lcdText();
    dispRGB();
  }
  if (i == 3 && j == 2)
  {
    if (digitcount < 6)
    {
      c1[digitcount] = 'E';
    }
    else if (digitcount < 12 && digitcount > 5)
    {
      c2[digitcount - 6] = 'E';
    }
    if (digitcount < 18 && digitcount > 11)
    {
      c3[digitcount - 12] = 'E';
    }
    lcdText();
    dispRGB();
  }
  if (i == 3 && j == 3)
  {
    if (digitcount < 6)
    {
      c1[digitcount] = 'F';
    }
    else if (digitcount < 12 && digitcount > 5)
    {
      c2[digitcount - 6] = 'F';
    }
    if (digitcount < 18 && digitcount > 11)
    {
      c3[digitcount - 12] = 'F';
    }
    lcdText();
    dispRGB();
  }
  if (i == 4 && j == 0)
  {
    if (digitcount < 6)
    {
      digitcount = -1;
      c1 = "000000";
      lcdText();
      dispRGB();
    }
    else if (digitcount > 5 && digitcount < 12)
    {
      digitcount = -1;
      c1 = "000000";
      lcdText();
      dispRGB();
    }
    else if (digitcount > 11 && digitcount < 18)
    {
      digitcount = 5;
      c2 = "000000";
      lcdText();
      dispRGB();
    }
  }
  if (i == 4 && j == 1)
  {
    if (digitcount < 6)
    {
      digitcount = 5;
      c2 = "000000";
      lcdText();
      dispRGB();
    }
    else if (digitcount > 5 && digitcount < 12)
    {
      digitcount = 11;
      c3 = "000000";
      lcdText();
      dispRGB();
    }
    else if (digitcount > 11 && digitcount < 18)
    {
      digitcount = 11;
      c3 = "000000";
      lcdText();
      dispRGB();
    }
  }
  if (i == 4 && j == 2)
  {
    lcd.clear();
    lcd.print("Status: LOCKED");
    rgb.setPWM(pwmR1, 4096, 0);
    rgb.setPWM(pwmG1, 0, 0);
    rgb.setPWM(pwmB1, 0, 0);
    rgb.setPWM(pwmR2, 4096, 0);
    rgb.setPWM(pwmG2, 0, 0);
    rgb.setPWM(pwmB2, 0, 0);
    rgb.setPWM(pwmR3, 4096, 0);
    rgb.setPWM(pwmG3, 0, 0);
    rgb.setPWM(pwmB3, 0, 0);
    delay(250);
    if(stat!=0)
      attempts = 5;
    randomizePass();
  }

  if (i == 4 && j == 3)
  {
    if (p1 == c1 && p2 == c2 && p3 == c3)
    {
      lcd.clear();
      lcd.print("Status: UNLOCKED");
      rgb.setPWM(pwmR1, 0, 0);
      rgb.setPWM(pwmG1, 4096, 0);
      rgb.setPWM(pwmB1, 0, 0);
      rgb.setPWM(pwmR2, 0, 0);
      rgb.setPWM(pwmG2, 4096, 0);
      rgb.setPWM(pwmB2, 0, 0);
      rgb.setPWM(pwmR3, 0, 0);
      rgb.setPWM(pwmG3, 4096, 0);
      rgb.setPWM(pwmB3, 0, 0);
    }
    else
    {
      rgb.setPWM(pwmR1, 4096, 0);
      rgb.setPWM(pwmG1, 0, 0);
      rgb.setPWM(pwmB1, 0, 0);
      rgb.setPWM(pwmR2, 4096, 0);
      rgb.setPWM(pwmG2, 0, 0);
      rgb.setPWM(pwmB2, 0, 0);
      rgb.setPWM(pwmR3, 4096, 0);
      rgb.setPWM(pwmG3, 0, 0);
      rgb.setPWM(pwmB3, 0, 0);

      lcd.clear();
      lcd.print("INCORRECT CODE!");
      attempts--;
      if (attempts > 0)
      {
        lcd.setCursor(0,1);
        lcd.print(String(attempts) + " ATTEMPTS REMAINING");
        digitalWrite(BUZ, HIGH);
      }
      else
      {
        lcd.clear();
        lcd.print("INTRUSION DETECTED");
        lcd.setCursor(0, 1);
        lcd.print("DISABLING LOCKER FOR 2 MINUTES");
        for (int i = 0; i <= 240; i++)
        {
          digitalWrite(BUZ, HIGH);
          delay(250);
          digitalWrite(BUZ, LOW);
          delay(250);
        }
      }
    }
    delay(250);
    randomizePass();
    lcdText();
    dispRGB();
    digitalWrite(BUZ, LOW);
  }
}

void hex2rgb(String s, int *r, int *g, int *b) {
  int n[6];
  for (int i = 0; i < 6; i++) {
    switch (s[i]) {
      case '0': n[i] = 0;
        break;
      case '1': n[i] = 1;
        break;
      case '2': n[i] = 2;
        break;
      case '3': n[i] = 3;
        break;
      case '4': n[i] = 4;
        break;
      case '5': n[i] = 5;
        break;
      case '6': n[i] = 6;
        break;
      case '7': n[i] = 7;
        break;
      case '8': n[i] = 8;
        break;
      case '9': n[i] = 9;
        break;
      case 'A': n[i] = 10;
        break;
      case 'B': n[i] = 11;
        break;
      case 'C': n[i] = 12;
        break;
      case 'D': n[i] = 13;
        break;
      case 'E': n[i] = 14;
        break;
      case 'F': n[i] = 15;
        break;
    }
  }
  *r = 16 * n[0] + n[1];

  *g = 16 * n[2] + n[3];

  *b = 16 * n[4] + n[5];
}

String dec2hex(long int n) {
  if (n == 0)
    return "0";
  String h = "";
  while (n > 0) {
    int x = n % 16;
    switch (x) {
      case 10: h.concat("A");
        break;
      case 11: h.concat("B");
        break;
      case 12: h.concat("C");
        break;
      case 13: h.concat("D");
        break;
      case 14: h.concat("E");
        break;
      case 15: h.concat("F");
        break;
      default: h.concat(x);
    }
    n /= 16;
  }

  if (h.length() < 6)
    while (h.length() < 6)
      h.concat("0");
  String x = "";
  int f = h.length() - 1;
  while (f >= 0) {
    x.concat(h[f]);
    f--;
  }

  return x;
}

void lcdText()
{
  lcd.setCursor(8, 0);
  lcd.print("CODE");
  lcd.setCursor(0, 1);
  lcd.print("LED 1: #" + c1);
  lcd.setCursor(0, 2);
  lcd.print("LED 2: #" + c2);
  lcd.setCursor(0, 3);
  lcd.print("LED 3: #" + c3);
}

void dispRGB()
{
  hex2rgb(c1, &r1, &g1, &b1);
  hex2rgb(c2, &r2, &g2, &b2);
  hex2rgb(c3, &r3, &g3, &b3);
  rgb.setPWM(pwmR1, r1, 0);
  rgb.setPWM(pwmG1, g1, 0);
  rgb.setPWM(pwmB1, b1, 0);
  rgb.setPWM(pwmR2, r2, 0);
  rgb.setPWM(pwmG2, g2, 0);
  rgb.setPWM(pwmB2, b2, 0);
  rgb.setPWM(pwmR3, r3, 0);
  rgb.setPWM(pwmG3, g3, 0);
  rgb.setPWM(pwmB3, b3, 0);
}

void randomizePass()
{
  digitcount = -1;
  lcd.clear();
  c1 = dec2hex(random(0, 16777215));
  c2 = dec2hex(random(0, 16777215));
  c3 = dec2hex(random(0, 16777215));
  lcdText();
  dispRGB();
}
