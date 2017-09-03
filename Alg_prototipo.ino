#include <Servo.h>
Servo servo;
Servo servo1;
int ldrPin = 1; //LDR no pino analígico 8
int ldrValor = 0; //Valor lido do LDR
int pos = 0; 
int pos1 = 0;
void setup() {

 Serial.begin(9600); //Inicia a comunicação serial
 servo.attach(9); 
 servo1.attach(10);
}
 
void loop() {
  // servomotor se move rapidapente para tremer a peneira
  for (pos = 0; pos <= 90; pos += 5 ) {
    servo.write(pos);             
    delay(5);                      
  }
  for (pos = 90; pos >= 0; pos -= 5) { 
    servo.write(pos);              
    delay(5);                       
  }

 ///ler o valor do LDR
 ldrValor = analogRead(ldrPin); //O valor lido será entre 0 e 1023
 
 
 //imprime o valor lido do LDR no monitor serial
 Serial.println("Valor do LDR:");
 Serial.println(ldrValor);
 delay(1000);

 if(ldrValor>400){
  Serial.println("A COR DO OBJETO É MAIS CLARA");
 }
 if(ldrValor<200){
  Serial.println("A COR DO OBJETO É MAIS ESCURA");

  for (pos1 = 0; pos <= 90; pos += 5 ) {
    servo1.write(pos);             
    delay(10);                      
  }
  for (pos1 = 90; pos >= 0; pos -= 5) { 
    servo1.write(pos);              
    delay(10);                       
  }
}

}
 
