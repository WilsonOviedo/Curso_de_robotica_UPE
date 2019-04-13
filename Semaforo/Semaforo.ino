//Pines donde estan conectados los Leds

#define LuzRoja       2
#define LuzAmarilla   3
#define LuzVerde      4

//Tiempos de encendidos
#define TiempoRojo      3000
#define TiempoAmarillo  1000
#define TiempoVerde     3000

void setup() {
  pinMode(LuzRoja,OUTPUT);
  pinMode(LuzAmarilla,OUTPUT);
  pinMode(LuzVerde,OUTPUT);

}

void loop() {
  
  digitalWrite(LuzRoja,HIGH);
  delay(TiempoRojo);
  digitalWrite(LuzRoja,LOW);
  digitalWrite(LuzAmarilla,HIGH);
  delay(TiempoAmarillo);
  digitalWrite(LuzAmarilla,LOW);
  digitalWrite(LuzVerde,HIGH);
  delay(TiempoVerde);
  digitalWrite(LuzVerde,HIGH);
  
}
