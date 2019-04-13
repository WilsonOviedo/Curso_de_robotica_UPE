//Shopping Lai Lai 5to Piso **RaioLaser**

//Enciende y apaga un led un tiempo predeterminado
void setup(){
  
  pinMode(13,OUTPUT);
  
  }

  void loop(){

      digitalWrite(13,HIGH);  //Encender el led 
      delay(1000);            //Esperar 1 segundo
      digitalWrite(13,LOW);   //Apagar el led
      delay(1000);            //Esperar 1 segundo
    
    }
