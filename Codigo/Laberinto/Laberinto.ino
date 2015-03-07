/*********************/
/***** LABERINTO *****/
/*********************/
/* Este programa lo que hará es que battBot
sea capaz de salir de un laberinto*/

//Librerias
//---------------
#include <Servo.h>
#include <Ultrasonic.h>

//Constantes
//----------------
#define derechoParada 1450
#define izquierdoParada 1390
#define derechoAdelante 2000
#define izquierdoAdelante 1000
#define derechoAtras 1000
#define izquierdoAtras 2000

//Variables
//-----------------
int ir_derecha;
int ir_izquierda;

Servo servoIzquierdo; //Servo izquierdo (Pin 6)
Servo servoDerecho; //Servo derecho (Pin 9)
Servo servoMicro; //Micro servo (Pin 1)


Ultrasonic ultrasonic(11,10); //(Trig Pin, Echo Pin) 

int sensorPinIR = 0; //Pin Sensor IR
int valIR; //Valor que toma el sensor IR

void setup() {
  // put your setup code here, to run once:
  servoIzquierdo.attach(6); //Conexión servo izquierdo
  servoDerecho.attach(9); //Conexión servo derecho

}

void loop() {
  // put your main code here, to run repeatedly:
  if (ultrasonic.Ranging(CM)<5){
    servoIzquierdo.writeMicroseconds(izquierdoParada);
    servoDerecho.writeMicroseconds(derechoParada);
    
    valIR = analogRead(sensorPinIR); //Leer el valor que llega de la señal
    
  }else if (valIR<5){
      servoMicro.write(180);
      delay(1000);
      servoMicro.write(0);
      delay(1000);
  }else{
    servoIzquierdo.writeMicroseconds(izquierdoAdelante);
    servoDerecho.writeMicroseconds(derechoAdelante);
  }      
}
