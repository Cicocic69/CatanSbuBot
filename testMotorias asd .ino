//libreria servo
#include <Servo.h>

//creazione oggetti servo
Servo servoApriBraccio;
Servo servoMuoviBraccio;

//definizione pin servo
#define servoApriBraccioPin 8
#define servoMuoviBraccioPin 9

//motore A
const int enA = 2; // PWM
const int in1 = 22;      
const int in2 = 23;     

//motore B
const int enB = 3; // PWM
const int in3 = 26; 
const int in4 = 27; 

//motore C
const int enC = 4; // PWM
const int in5 = 28; 
const int in6 = 29;  

//motore D
const int enD = 7; // PWM
const int in7 = 30; 
const int in8 = 31; 

//velocità
const int speed255 = 255;

void setup() {
  // put your setup code here, to run once:

  servoApriBraccio.attach(servoApriBraccioPin);
  servoMuoviBraccio.attach(servoMuoviBraccioPin);

  //motore A
  pinMode(enA, OUTPUT); 
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(enA, LOW);

  //motore B
  pinMode(enB, OUTPUT); 
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(enB, LOW);

  //motore C
  pinMode(enC, OUTPUT); 
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);
  digitalWrite(enC, LOW);

  //motore D
  pinMode(enD, OUTPUT); 
  pinMode(in7, OUTPUT);
  pinMode(in8, OUTPUT);
  digitalWrite(in7, LOW);
  digitalWrite(in8, LOW);
  digitalWrite(enD, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

  /*vaiAvanti();
  vaiStop();
  delay(1000);
  vaiIndietro();
  vaiStop();
  delay(1000);
  vaiADestra();
  vaiStop();
  delay(1000);
  vaiASinistra();
  vaiStop();
  delay(1000);
  diagSinAvanti();
  vaiStop();
  delay(1000);
  diagDesAvanti();
  vaiStop();
  delay(1000);
  diagSinIndietro();
  vaiStop();
  delay(1000);
  diagDesIndietro();
  vaiStop();
  delay(1000);
  ruotaSensoOrario();
  vaiStop();
  delay(1000);
  ruotaSensoAntiorario();
  vaiStop();
  delay(1000);
  aperturaBraccio();
  delay(1000);
  chiusuraBraccio();
  delay(1000);
  alzaBraccio();
  delay(1000);
  abbassaBraccio();
  delay(1000);*/

  vaiAvanti();
  aperturaBraccio();
  chiusuraBraccio();
  alzaBraccio();
  abbassaBraccio();
  vaiIndietro();
  
}
void vaiStop(){
  analogWrite(enA, speed255);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enB, speed255);    
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enC, speed255);    
  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);
  analogWrite(enD, speed255);
  digitalWrite(in7, LOW);
  digitalWrite(in8, LOW);
  
  }
void vaiAvanti(){
  analogWrite(enA, speed255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enB, speed255);    
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enC, speed255);    
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  analogWrite(enD, speed255);
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
  delay(1000);
}

void vaiIndietro(){
  analogWrite(enA, speed255);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enB, speed255);    
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enC, speed255);    
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  analogWrite(enD, speed255);
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
  delay(1000);
}

void vaiADestra(){
  analogWrite(enA, speed255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enB, speed255);    
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enC, speed255);    
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  analogWrite(enD, speed255);
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
  delay(1000);
}

void vaiASinistra(){
  analogWrite(enA, speed255);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enB, speed255);    
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enC, speed255);    
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  analogWrite(enD, speed255);
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
  delay(1000);
}

void diagDesAvanti(){
  analogWrite(enA, speed255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enD, speed255);
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
  delay(1000);
}

void diagSinAvanti(){
  analogWrite(enB, speed255);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enC, speed255);
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  delay(1000);
}

void diagDesIndietro(){
  analogWrite(enA, speed255);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enD, speed255);
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
  delay(1000);
}

void diagSinIndietro(){
  analogWrite(enB, speed255);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enC, speed255);
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  delay(1000);
}

void ruotaSensoOrario(){
  analogWrite(enA, speed255);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enB, speed255);    
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enC, speed255);    
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  analogWrite(enD, speed255);
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
  delay(1000);
}

void ruotaSensoAntiorario(){
  analogWrite(enA, speed255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enB, speed255);    
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enC, speed255);    
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  analogWrite(enD, speed255);
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
  delay(1000);
}

void aperturaBraccio(){
  servoApriBraccio.write(180);     //APERTO
  delay(1000);
}

void chiusuraBraccio(){
  servoApriBraccio.write(70);      //CHIUSO
  delay(1000);
}

void alzaBraccio(){
  servoMuoviBraccio.write(50);    //ALZATO
  delay(1000);
}

void abbassaBraccio(){
  servoMuoviBraccio.write(105);      //ABBASSATO
  delay(1000);
}
