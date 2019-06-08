/*
  Pines de conexion del pueste H
*/

#define pinIN1 5
#define pinIN2 6

#define pinIN3 10
#define pinIN4 11

#define Blanco HIGH
#define Negro LOW

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
  analogWrite (pinIN1, velocidad);
  analogWrite (pinIN2, 0);
  analogWrite (pinIN3, velocidad);
  analogWrite (pinIN4, 0);
}

//Mover hacia el atras
void moverAtras() {
  analogWrite (pinIN1, 0);
  analogWrite (pinIN2, velocidad);
  analogWrite (pinIN3, 0);
  analogWrite (pinIN4, velocidad);
}

//Girar hacia la derecha
void girarDerecha() {
  analogWrite (pinIN1, 0);
  analogWrite (pinIN2, velocidad);
  analogWrite (pinIN3, velocidad);
  analogWrite (pinIN4, 0);
}

//Girar hacia la izquierda
void girarIzquierda() {
  analogWrite (pinIN1, velocidad);
  analogWrite (pinIN2, 0);
  analogWrite (pinIN3, 0);
  analogWrite (pinIN4, velocidad);
}
//Leer Sensores
bool leerLinea(int pinSensor){
  if(digitalRead(pinSensor)==Blanco){
    return true;
    }else{
      return false;
      }
  }
