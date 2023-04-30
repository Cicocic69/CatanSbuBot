//libreria servo
#include <Servo.h>

//creazione oggetti servo
Servo servoApriBraccio;
Servo servoMuoviBraccio;

//definizione pin servo
#define servoApriBraccioPin 8
#define servoMuoviBraccioPin 9

//inizializzazione variabili relative al timer
unsigned long startTime; 
unsigned long stopTime;
unsigned long myDesiredTime;
bool controllo = false;



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
const int speed255 = 150;

//comando RPi
String comando;
int durata;
int pointer;

void setup() {
  // put your setup code here, to run once:
  
  //avvio seriale
  Serial.begin(9600);

  startTime = 0;
  stopTime = 0;
  myDesiredTime = 205000;
  
  //collegamento servo
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

  if(true){
    Serial.flush();
    if(Serial.available()){
    
      if(controllo == false){
        //prende input da seriale RPi
        
      
        comando = Serial.readString();
        comando.trim();
        Serial.flush();
        /*
        for(int i=0;i<comando.length();i=i+1){
          Serial.println(comando[i]);
          if(comando[i]==" "){
            pointer=i;
            break;
          }
        }
        */
        Serial.println("pointer found at ");
        pointer=comando.indexOf(' ');
        Serial.println(pointer);
        durata=comando.substring(pointer,comando.length()).toInt();
        comando=comando.substring(0,pointer);
        
        //Serial.available()
        //* debug
        //*stopTime - startTime <= myDesiredTime
        Serial.print("Comando ricevuto: ");
        Serial.println(comando);
        Serial.print("durata ricevuta");
        Serial.println(durata);
        

        if(comando == "InizioTimer"){
          iniziaTimer();
        }

        if(comando == "Stop"){
          vaiStop();
          
        }

        if(comando == "N"){
          Serial.println("vaiAvanti();");
          vaiAvanti();
          delay(durata);
          vaiStop();
        }

        if(comando == "S"){
          vaiIndietro();
          delay(durata);
          vaiStop();
        }

        if(comando == "E"){
          vaiADestra();
          delay(durata);
          vaiStop();
        }

        if(comando == "O"){
          vaiASinistra();
          delay(durata);
          vaiStop();
        }

        if(comando == "NE"){
          diagDesAvanti();
          delay(durata);
          vaiStop();
        }

        if(comando == "NO"){
          diagSinAvanti();
          delay(durata);
          vaiStop();
        }

        if(comando == "SE"){
          diagDesIndietro();
          delay(durata);
          vaiStop();
        }
        
        if(comando == "SO"){
          diagSinIndietro();
          delay(durata);
          vaiStop();
        }

        if(comando == "RO"){
          ruotaSensoOrario();
          delay(durata);
          vaiStop();
        }

        if(comando == "RA"){
          ruotaSensoAntiorario();
          delay(durata);
          vaiStop();
        }

        if(comando == "Apri"){
          apriBraccio();
        }

        if(comando == "Chiudi"){
          chiudiBraccio();
        }

        if(comando == "Alza"){
          alzaBraccio();
        }

        if(comando == "Abbassa"){
          abbassaBraccio();
        } 
      }
    }
  } else {
    vaiStop();
    controllo = true;
  }
}

void iniziaTimer(){
  stopTime = millis();
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

void apriBraccio(){
  servoApriBraccio.write(180);     //APERTO
  delay(1000);
}

void chiudiBraccio(){
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
