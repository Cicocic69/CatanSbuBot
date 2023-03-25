
//motore A
const int enA = 3; //PWM
const int in1 = 2;        
const int in2 = 4;

//motore B
const int enB = 5; // !!! QUESTO PWM FUNZIONA A 500, NON A 255
const int in3 = 7;
const int in4 = 8;

//motore C
const int enC = 6; //PWM
const int in5 = 9;
const int in6 = 10;

//motore D
const int enD = 11; // !!! QUESTO PWM FUNZIONA A 500, NON A 255
const int in7 = 12;
const int in8 = 13;

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

  analogWrite(enA, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enB, 500);    // !!! QUESTO PWM FUNZIONA A 500, NON A 255
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enC, 255);    // !!! QUESTO PWM FUNZIONA A 500, NON A 255
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  analogWrite(enD, 500);    
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
  delay(1000);

}

void vaiAvanti(){
  analogWrite(enA, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enB, 500);    // !!! QUESTO PWM FUNZIONA A 500, NON A 255
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enC, 500);    // !!! QUESTO PWM FUNZIONA A 500, NON A 255
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  analogWrite(enD, 255);
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
  delay(1000);
}

void vaiIndietro(){
  analogWrite(enA, 255);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enB, 500);    // !!! QUESTO PWM FUNZIONA A 500, NON A 255
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enC, 500);    // !!! QUESTO PWM FUNZIONA A 500, NON A 255
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  analogWrite(enD, 255);
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
  delay(1000);
}

void vaiADestra(){
  analogWrite(enA, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enB, 500);    // !!! QUESTO PWM FUNZIONA A 500, NON A 255
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enC, 500);    // !!! QUESTO PWM FUNZIONA A 500, NON A 255
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  analogWrite(enD, 255);
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
  delay(1000);
}
