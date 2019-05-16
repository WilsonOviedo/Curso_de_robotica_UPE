#define trigSensor 4 
#define echoSensor 5 

long duracion,distancia;  // Variables de Sensor ultrasonico del frente

void setup() {
  pinMode(trigSensor, OUTPUT);
  pinMode(echoSensor, INPUT);
  Serial.begin(9600);

}
void loop() {
  digitalWrite(trigSensor, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigSensor, HIGH);  
  delayMicroseconds(10);       
  digitalWrite(trigSensor, LOW);  
  duracion = pulseIn(echoSensor, HIGH);
  distancia= (duracion/2) / 29;
  Serial.print("Distancia: ");
  Serial.println(distancia);
  delay(1000);
}
