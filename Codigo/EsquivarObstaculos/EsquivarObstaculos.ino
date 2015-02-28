/* CODIGO EMPUJAR OBSTACULOS FUERA DEL CIRCULO*/
//------------------------------------------------------
/* Bibliografa:*/
/* blog TR3SDLAND http://www.tr3sdland.com/2013/04/robot-miniskybot-2-como-siguelineas-y-detector-de-obstaculos/ 
Autor: Pablo 18/05/2013*/
// LineFinder http://www.seeedstudio.com/wiki/Grove_-_Line_Finder
// Adaptacin: Germn Souto Fernndez http://www.start-robot.com/index.html
//------------------------------------------------------

#include <Servo.h> // Librera del servo
#include <Ultrasonic.h> // Librera del Ultrasonido

#define derechoParada 1450
#define izquierdoParada 1390
#define derechoAdelante 2000
#define izquierdoAdelante 1000
#define derechoAtras 1000
#define izquierdoAtras 2000

// Declaramos Variables
int ir_derecha; 
int ir_izquierda;

int Negro;
int Blanco;

Servo servo_6; // Servo izquierdo
Servo servo_9; // Servo derecho

//long distancia;
//long tiempo;

Ultrasonic ultrasonic(11,10); // (Trig PIN, Echo PIN) ejemplo (4,A0);

void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT); // SeguiLineas izquierdo
  pinMode(3,INPUT); // SeguiLneas derecho
  
  Negro = HIGH;
  Blanco = LOW;
  
  servo_6.attach(6); // Conexion servo izquierdo
  servo_9.attach(9); // Conexion servo derecho
  
  //Serial.begin(9600); // Incializada la comunicacion serial

}

void loop() {
  // put your main code here, to run repeatedly:
  /*digitalWrite(11,LOW);
  delayMicroseconds(5);
  digitalWrite(11,HIGH);
  delayMicroseconds(10);
  
  tiempo = pulseIn(10,HIGH);
  distancia = int(0.017*tiempo);
  
  Serial.println("Distancia ");
  Serial.println(distancia);
  Serial.println(" cm");*/
  
  /* El servo al modificarlo indicamos que esta en posición 90º, si le diecimos
  que se coloque en una posición mayor, por ejemplo 180º, girará de forma
  continua en una dirección, si le indicamos al servo que se coloque en una 
  posición inferior, por ejemplo 0º, girará de forma continua en el otro sentido.
  Si le indicamos 90º el servo se parará */
  
  if (ultrasonic.Ranging(CM) <20){
    servo_6.writeMicroseconds(izquierdoAdelante);
    servo_9.writeMicroseconds(derechoAdelante);
  }else{
    servo_6.writeMicroseconds(izquierdoParada);
    servo_9.writeMicroseconds(derechoAdelante);
  }
  
  ir_derecha = digitalRead(3);
  ir_izquierda = digitalRead(2);
  
  if (ir_derecha == Negro || ir_izquierda == Negro){
    servo_6.writeMicroseconds(izquierdoAtras);
    servo_9.writeMicroseconds(derechoAtras);
    delay(1000);
  }

}
