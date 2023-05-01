int mcounter=0;

typedef struct
  {
    int distanza;
    String direzione;
  }  dati;

dati movimenti[100];

String opposta(String direzione) {
  if (direzione == "N") {
    return "S";
  } else if (direzione == "E") {
    return "O";
  } else if (direzione == "S") {
    return "N";
  } else if (direzione == "O") {
    return "E";
  } else if (direzione == "NE") {
    return "SO";
  } else if (direzione == "NO") {
    return "SE";
  } else if (direzione == "SE") {
    return "NO";
  } else if (direzione == "SO") {
    return "NE";
  } else {
    // Se la direzione non è valida, ritorna una stringa vuota.
    return "";
  }
}

void salva(String direzione, int tempo) {
  movimenti[mcounter].direzione = direzione;
  movimenti[mcounter].distanza = tempo;
  mcounter++;
}


dati traceback(){
  mcounter--;
  movimenti[mcounter].direzione=opposta(movimenti[mcounter].direzione);
  return movimenti[mcounter];
}

void setup() {
  Serial.begin(9600);
  salva("N",10);
  salva("E",3);
  dati contrario = traceback();
  Serial.println(contrario.distanza);
  Serial.println(contrario.direzione);
  contrario=traceback();
  Serial.println(contrario.distanza);
  Serial.println(contrario.direzione);
}

void loop() {

}
