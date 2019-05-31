//Pines de sensores
#define D1 A0
#define D2 A3
#define D3 A4
#define D4 A5

//Definir puenteH
#define A1 5
#define A2 11
#define B1 6
#define B2 10

#define velocidad 130

#define lineaMax 1023
#define lineaMin 800

void setup() {
  Serial.begin(9600);
  //Definimos entradas analogicas
  pinMode(D1,INPUT);
  pinMode(D2,INPUT);
  pinMode(D3,INPUT);
  pinMode(D4,INPUT);
  //Defininmos salidas
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(B1,OUTPUT);
  pinMode(B2,OUTPUT);
}
//Funciones de funcinamiento del robot
void frente(){
    Serial.println("Frente");
  analogWrite(A1,velocidad);
  analogWrite(B1,0);
  analogWrite(A2,velocidad);
  analogWrite(B2,0);  
  }  
  
  void izquierdaF(){
    Serial.println("Derecha Fuerte");
  analogWrite(A1,velocidad);
  analogWrite(B1,0);
  analogWrite(A2,velocidad/3);
  analogWrite(B2,0);  
  }
  
    void derechaF(){
    Serial.println("Izquierda Fuerte");
  analogWrite(A1,0);
  analogWrite(B1,velocidad/3);
  analogWrite(A2,velocidad);
  analogWrite(B2,0);  
  }

   void izquierdaS(){
    Serial.println("Derecha Suave");
  analogWrite(A1,velocidad);
  analogWrite(B1,velocidad/2);
  analogWrite(A2,0);
  analogWrite(B2,0);
  
  }

    void derechaS(){
    Serial.println("Izquierda Suave");
  analogWrite(A2,velocidad/2);
  analogWrite(B2,0);
  analogWrite(A1,velocidad);
  analogWrite(B1,0);
  
  }

  int sensor(){
    int d1=analogRead(D1);  //Sensor derecha
    int d2=analogRead(D2);  //Sensor medio derecha
    int d3=analogRead(D3);  //Sensor medio izquierda
    int d4=analogRead(D4);  //Sensor izquierda
  Serial.print("\t");
  Serial.print(d1);
  Serial.print("\t");
  Serial.print(d2);
  Serial.print("\t");
  Serial.print(d3);
  Serial.print("\t");
  Serial.println(d4);
  
    if(d1>lineaMin && d2<lineaMin&& d3<lineaMin&& d4<lineaMin){
      return 1;
      }

if(d1<lineaMin && d2>lineaMin&& d3>lineaMin&& d4<lineaMin){
      return 2;
      }
      
      if(d4>lineaMin && d2<lineaMin&& d3<lineaMin&& d1<lineaMin){
      return 3;
      }

      

      if(d1<lineaMin && d2<lineaMin&& d3>lineaMin&& d4<lineaMin){
      return 4;
      }
      if(d1<lineaMin && d2>lineaMin&& d3<lineaMin&& d4<lineaMin){
      return 5;
      }
    }

void loop() {
//sensor();
switch(sensor())
{
    case 1:
    izquierdaF();
    break;

    case 2:
    frente();
    break;
    
    case 3:
    derechaF();
    break;  

    case 4:
    derechaS();
    break;  

    case 5:
    izquierdaS();
    break;  
  }
  
delay(100);
}
