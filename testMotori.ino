
//motore A
const int enA = 3; // PWM
const int in1 = 2;        
const int in2 = 4;
const int speedA = 255;

//motore B
const int enB = 5; // !!! QUESTO PWM FUNZIONA A 500, NON A 255
const int in3 = 7;
const int in4 = 8;
const int speedB = 500;

//motore C
const int enC = 6; // !!! QUESTO PWM FUNZIONA A 500, NON A 255
const int in5 = 9;
const int in6 = 10;
const int speedC = 500;

//motore D
const int enD = 11; // PWM
const int in7 = 12;
const int in8 = 13;
const int speedD = 255;

void setup() {
  // put your setup code here, to run once:

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

  vaiADestra();
  delay(1000);

}

void vaiAvanti(){
  analogWrite(enA, speedA);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enB, speedB);    // !!! QUESTO PWM FUNZIONA A 500, NON A 255
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enC, speedC);    // !!! QUESTO PWM FUNZIONA A 500, NON A 255
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  analogWrite(enD, speedD);
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
  delay(1000);
}

void vaiIndietro(){
  analogWrite(enA, speedA);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enB, speedB);    // !!! QUESTO PWM FUNZIONA A 500, NON A 255
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enC, speedC);    // !!! QUESTO PWM FUNZIONA A 500, NON A 255
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  analogWrite(enD, speedD);
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
  delay(1000);
}

void vaiADestra(){
  analogWrite(enA, speedA);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enB, speedB);    // !!! QUESTO PWM FUNZIONA A 500, NON A 255
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enC, speedC);    // !!! QUESTO PWM FUNZIONA A 500, NON A 255
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  analogWrite(enD, speedD);
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
  delay(1000);
}

void vaiASinistra(){
  analogWrite(enA, speedA);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enB, speedB);    // !!! QUESTO PWM FUNZIONA A 500, NON A 255
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enC, speedC);    // !!! QUESTO PWM FUNZIONA A 500, NON A 255
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  analogWrite(enD, speedD);
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
  delay(1000);
}

void diagDes(){
  analogWrite(enA, speedA);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enD, speedD);
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
  delay(1000);
}

void diagSin(){
  analogWrite(enB, speedA);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enC, speedD);
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
  delay(1000);
}
