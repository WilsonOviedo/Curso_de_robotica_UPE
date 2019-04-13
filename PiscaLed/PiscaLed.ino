//Enciende y apaga un led un tiempo predeterminado
#define Led 2
#define tiempo 1000

void setup() {
  pinMode(Led, OUTPUT);     
}


void loop() {
  digitalWrite(Led, LOW);     
  delay(tiempo);                      
  digitalWrite(Led, HIGH); 
  delay(tiempo);
}                     
