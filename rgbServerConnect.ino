#define RED_LED D7
#define BLUE_LED D6
#define GREEN_LED D8

int brightness = 255;
int gBright = 0;
int rBright = 0;
int bBright = 0;
int fadeSpeed = 10;
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   pinMode(GREEN_LED, OUTPUT);
   pinMode(RED_LED, OUTPUT);
   pinMode(BLUE_LED, OUTPUT);
}

void StayOnBlue(){
  Serial.println(brightness);
  brightness-=1;
  analogWrite(GREEN_LED, brightness);
  analogWrite(RED_LED, brightness);
  analogWrite(BLUE_LED, brightness);
}

void TurnOn() { 
   for (int i = 0; i < 256; i++) {
       analogWrite(RED_LED, rBright);
       rBright +=1;
       delay(fadeSpeed);
   }
 
   for (int i = 0; i < 256; i++) {
       analogWrite(BLUE_LED, bBright);
       bBright += 1;
       delay(fadeSpeed);
   } 
   for (int i = 0; i < 256; i++) {
       analogWrite(GREEN_LED, gBright);
       gBright +=1;
       delay(fadeSpeed);
   } 
}

void TurnOff() {
   for (int i = 0; i < 256; i++) {
       analogWrite(GREEN_LED, brightness);
       analogWrite(RED_LED, brightness);
       analogWrite(BLUE_LED, brightness);
       brightness -= 1;
       delay(fadeSpeed);
   }
}

void loop() {
  // put your main code here, to run repeatedly
}
