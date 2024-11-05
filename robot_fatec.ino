#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
#include <Servo.h>
   
int portA = 2;
int portB = 3;
int portC = 4;
int portD = 5;

Servo meuServo; //Cria um objeto

   
void setup()
{
  Serial.begin(255000);
  Dabble.begin(9600,7,6);  
  pinMode(portA,OUTPUT);
  pinMode(portB,OUTPUT);
  pinMode(portC,OUTPUT);                                                                    
  pinMode(portD,OUTPUT);
  meuServo.attach(9);
  Stop();
}

void loop() {
   
   
Dabble.processInput();          

//Serial.println("ok");
   
if(GamePad.isUpPressed())
{
  //Serial.println("UP");
 forward(); 
}
else if(GamePad.isDownPressed())
{
  //Serial.println("DOWN");
 backward(); 
}
else if(GamePad.isLeftPressed())
{
  //Serial.println("LEFT");
 left(); 
}
else if(GamePad.isRightPressed())
{
  //Serial.println("RIGHT");
 right(); 
}
else if(GamePad.isTrianglePressed()){
  kick();
}
else
{
 Stop(); 
}
   
}
void forward() {
  digitalWrite(portA,LOW);
  digitalWrite(portB,HIGH);
  digitalWrite(portC,HIGH);
  digitalWrite(portD,LOW);
}
      
void backward() {
  digitalWrite(portA,HIGH);
  digitalWrite(portB,LOW);
  digitalWrite(portC,LOW);
  digitalWrite(portD,HIGH);
}
      
void left() {
  digitalWrite(portA,HIGH);
  digitalWrite(portB,LOW);
  digitalWrite(portC,HIGH);
  digitalWrite(portD,LOW);    
}
      
void right() {
  digitalWrite(portA,LOW);
  digitalWrite(portB,HIGH);
  digitalWrite(portC,LOW);
  digitalWrite(portD,HIGH);  
}
      
void Stop() {
  digitalWrite(portA,LOW);
  digitalWrite(portB,LOW);
  digitalWrite(portC,LOW);
  digitalWrite(portD,LOW);  
}

void kick(){
  // Girar para frente (por exemplo, 180 graus)
  meuServo.write(180);
  delay(100);  // Espera 2 segundos

  // Voltar para a posição inicial (0 graus)
  meuServo.write(0);
  delay(100);  // Espera 2 segundos
}