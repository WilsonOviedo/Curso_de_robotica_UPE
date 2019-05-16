

#define pinTrig 4
#define pinEcho 5

#define A1 6
#define B1 7
#define A2 8
#define B2 9



long duracion, distancia;


void setup() {
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);

  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(B1, OUTPUT);
  pinMode(B2, OUTPUT);

  Serial.begin(9600);

}


long medir() {
  digitalWrite(pinTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);

  duracion = pulseIn(pinEcho, HIGH);

  distancia = (duracion / 2) / 29;

  return distancia;
}

void parar(){
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(B1, LOW);
  digitalWrite(B2, LOW);
  }

void frente(){
  //Primer motor
  digitalWrite(A1, HIGH);
  digitalWrite(B1, LOW);
  //Segundo motor
  digitalWrite(A2, HIGH);  
  digitalWrite(B2, LOW);
  }

  void atras(){
  //Primer motor
  digitalWrite(A1, LOW);
  digitalWrite(B1, HIGH);
  //Segundo motor
  digitalWrite(A2, LOW);  
  digitalWrite(B2, HIGH);
  }

  void girarDerecha(){
  //Primer motor
  digitalWrite(A1, LOW);
  digitalWrite(B1, HIGH);
  //Segundo motor
  digitalWrite(A2, HIGH);  
  digitalWrite(B2, LOW);
  }

  void girarIzquierda(){
  //Primer motor
  digitalWrite(A1, HIGH);
  digitalWrite(B1, LOW);
  //Segundo motor
  digitalWrite(A2, LOW);  
  digitalWrite(B2, HIGH);
  }

void loop() {
do{
  frente();
  }while(medir()>25);

  parar();
  girarIzquierda();
  delay(1000);
  parar();

}
