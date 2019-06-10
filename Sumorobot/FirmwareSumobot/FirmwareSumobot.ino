/*
  Pines de conexion del pueste H
*/

#define pinIN1 5
#define pinIN2 6

#define pinIN3 10
#define pinIN4 11

#define Blanco true
#define Negro false

#define velocidad 255  //Velocidad 0=0; maxima=255

#define distanciaMinima 30 //distancia minima entre el oponente

/*
  Pines de conexion del sensor ultrasonico
*/
#define pinTrigAtras    2
#define pinEchoAtras    3

#define pinTrigFrente   7
#define pinEchoFrente   8

//Pines de sensores de linea
#define pinLineaFrente  9
#define pinLineaAtras   4

void setup() {
//Entradas
Serial.begin(9600);
pinMode(pinTrigAtras,OUTPUT);
pinMode(pinTrigFrente,OUTPUT);
pinMode(pinIN1,OUTPUT);
pinMode(pinIN2,OUTPUT);
pinMode(pinIN3,OUTPUT);
pinMode(pinIN4,OUTPUT);

//Salidas
pinMode(pinEchoFrente,INPUT);
pinMode(pinEchoAtras,INPUT);
pinMode(pinLineaFrente,INPUT);
pinMode(pinLineaAtras,INPUT);

}

void loop() {
  
  if(leerLinea(pinLineaFrente)==Negro&&leerLinea(pinLineaAtras)==Negro){
      //Busqueda del contrincante
    do{
      girarDerecha();
      }while(leerDistancia(pinTrigFrente,pinEchoFrente)>distanciaMinima); 
      
    //Ataques
    if(leerDistancia(pinTrigFrente,pinEchoFrente)<=distanciaMinima){
      moverFrente();
      }

      do{
        
      girarIzquierda();
      
      }while(leerDistancia(pinTrigAtras,pinEchoAtras)>distanciaMinima); 

      if(leerDistancia(pinTrigAtras,pinEchoAtras)<=distanciaMinima){
      moverAtras();
      }
    }
    
    if(leerLinea(pinLineaFrente)==Blanco){
      moverAtras();
      delay(1000);
      girarDerecha();
      delay(1000);
      }

      if(leerLinea(pinLineaAtras)==Blanco){
      moverFrente();
      delay(1000);
      girarIzquierda();
      delay(1000);
      }

}
/*===Funciones de funcionamiento===*/

//Funcion de lectura de sensores
int leerDistancia(int pinTrig, int pinEcho) {
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(20);
  digitalWrite(pinTrig , LOW);
  int dure = pulseIn(pinEcho, HIGH);
  int dist = (dure / 2) / 29.1;
  return dist;
}

//Funciones de motores
//Mover hacia el frente
void moverFrente() {
  Serial.println("Frente");
  analogWrite (pinIN1, velocidad);
  analogWrite (pinIN2, 0);
  analogWrite (pinIN3, velocidad);
  analogWrite (pinIN4, 0);
}

//Mover hacia el atras
void moverAtras() {
  Serial.println("Atras");
  analogWrite (pinIN1, 0);
  analogWrite (pinIN2, velocidad);
  analogWrite (pinIN3, 0);
  analogWrite (pinIN4, velocidad);
}

//Girar hacia la derecha
void girarDerecha() {
  Serial.println("Girar derecha");
  analogWrite (pinIN1, 0);
  analogWrite (pinIN2, velocidad);
  analogWrite (pinIN3, velocidad);
  analogWrite (pinIN4, 0);
}

//Girar hacia la izquierda
void girarIzquierda() {
  Serial.println("Girar izquierda");
  analogWrite (pinIN1, velocidad);
  analogWrite (pinIN2, 0);
  analogWrite (pinIN3, 0);
  analogWrite (pinIN4, velocidad);
}
//Leer Sensores
bool leerLinea(int pinSensor){
  if(digitalRead(pinSensor)==HIGH){
    return true;
    }else{
      return false;
      }
  }
