#define Led D3

void setup() {
  pinMode(Led, OUTPUT);     
}


void loop() {
  digitalWrite(Led, LOW);     
  delay(1000);                      
  digitalWrite(Led, HIGH); 
  delay(2000);
}                     
