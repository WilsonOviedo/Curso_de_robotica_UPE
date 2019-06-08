/*
  Pines de conexion del pueste H
*/
#define pinA1 5
#define pinA2 6
#define pinB1 10
#define pinB2 11

#define velocidad 255  //Velocidad 0=0; maxima=255

/*
  Pines de conexion del sensor ultrasonico
*/
#define pinTrigAtras    2
#define pinEchoAtras    3

#define pinTrigFrente   7
#define pinEchoFrente   8

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  leerDistancia();

}
/*===Funciones de funcionamiento===*/

//Funcion de lectura de sensores
int leerDistancia(int pinTrig, int pinEcho) {
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(20);
  digitalWrite(pinTrig , LOW);
  int dure = pulseIn(pinEcho, HIGH);
  int dist = (dure / 2) / 29.1;
  Serial.println(dist);
  return dist;
}

//Funciones de motores
//Mover hacia el frente
void moverFrente() {
  analogWrite (pinA1, velocidad);
  analogWrite (pinA2, 0);
  analogWrite (pinB1, velocidad);
  analogWrite (pinB2, 0);
}

//Mover hacia el atras
void moverAtras() {
  analogWrite (pinA1, 0);
  analogWrite (pinA2, velocidad);
  analogWrite (pinB1, 0);
  analogWrite (pinB2, velocidad);
}

//Girar hacia la derecha
void girarDerecha() {
  analogWrite (pinA1, 0);
  analogWrite (pinA2, velocidad);
  analogWrite (pinB1, velocidad);
  analogWrite (pinB2, 0);
}

//Girar hacia la izquierda
void girarIzquierda() {
  analogWrite (pinA1, velocidad);
  analogWrite (pinA2, 0);
  analogWrite (pinB1, 0);
  analogWrite (pinB2, velocidad);
}
