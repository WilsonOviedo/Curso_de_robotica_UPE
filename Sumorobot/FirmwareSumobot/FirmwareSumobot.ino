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
#define pinTrigAtras    7
#define pinEchoAtras    8

#define pinTrigFrente   2
#define pinEchoFrente   3

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

delay(3900);    //retardo de 5 segundos para inciar la pelea
}

void loop() {  
//Serial.println(leerDistancia(pinTrigAtras,pinEchoAtras));

  
  if(leerLinea(pinLineaFrente)==Negro&&leerLinea(pinLineaAtras)==Negro){
      //Busqueda del contrincante
    do{
      girarDerecha();
      }while(leerDistancia(pinTrigFrente,pinEchoFrente)>distanciaMinima&&leerDistancia(pinTrigFrente,pinEchoFrente)<=distanciaMinima); 
      
    //Ataques
    while(leerDistancia(pinTrigFrente,pinEchoFrente)<=distanciaMinima&&leerLinea(pinLineaFrente)==Negro&&leerLinea(pinLineaAtras)==Negro){
      Serial.println("Ataque frontal");
      moverFrente();
      delay(50);
      }

      do{
        
      girarIzquierda();
      
      }while(leerDistancia(pinTrigAtras,pinEchoAtras)>distanciaMinima&&leerDistancia(pinTrigFrente,pinEchoFrente)>distanciaMinima); 

      while(leerDistancia(pinTrigAtras,pinEchoAtras)<=distanciaMinima&&leerLinea(pinLineaFrente)==Negro&&leerLinea(pinLineaAtras)==Negro){
      moverAtras();
      Serial.println("Ataque trasero");
       delay(50);
      }

    
    if(leerLinea(pinLineaFrente)==Blanco&&leerLinea(pinLineaAtras)==Negro){
      
      moverFrente();
      delay(250);
      girarDerecha();
      delay(250);
      }

      if(leerLinea(pinLineaAtras)==Blanco&&leerLinea(pinLineaFrente)==Negro){
      moverAtras();
      delay(250);
      girarIzquierda();
      delay(250);
      }
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
  Serial.print("Distacia de ");
  Serial.print(String(pinTrig));
  Serial.print(": ");
  Serial.println(dist);
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
    Serial.println("Linea ON");
    return true;
    }else{
      Serial.println("Linea OFF");
      return false;
      }
  }
