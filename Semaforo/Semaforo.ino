#define LuzRoja 2
#define LuzAmarillo 3
#define LuzVerde 4


void setup() {
  
  pinMode(LuzRoja,OUTPUT);
  pinMode(LuzAmarillo,OUTPUT);
  pinMode(LuzVerde,OUTPUT);

}

void loop() {

  digitalWrite(LuzRoja,HIGH);   //Encendemos luz roja
  delay(2000);                  //Esperamos 2 seg
  digitalWrite(LuzRoja,LOW);    //Apagamos luz roja
  digitalWrite(LuzAmarillo,HIGH);//Encedemos luz amarilla
  delay(500);                   //Esperamos medio segundo
  digitalWrite(LuzAmarillo,LOW);//apagamos luz amarilla
  digitalWrite(LuzVerde,HIGH);//Encedemos luz verde
  delay(2000);                //Esperamos 2 segundos
  digitalWrite(LuzVerde,LOW); ////Encedemos luz verde
  delay(500);                 //Esperamos medio segundo     
}
