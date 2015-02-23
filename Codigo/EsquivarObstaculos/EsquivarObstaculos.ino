/* CODIGO EMPUJAR OBSTACULOS FUERA DEL CIRCULO*/
//------------------------------------------------------
//------------------------------------------------------

#include <Servo.h> // Librera del servo
#include <Ultrasonic.h> // Librera del Ultrasonido

// Declaramos Variables
int ir_derecha; 
int ir_izquierda;

int Negro;
int Blanco;

Servo servo_6; // Servo izquierdo
Servo servo_9; // Servo derecho

long distancia;
long tiempo;

Ultrasonic ultrasonic(11,10); // (Trig PIN, Echo PIN) ejemplo (4,A0);

void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT); // SeguiLineas izquierdo
  pinMode(3,INPUT); // SeguiLneas derecho
  
  Negro = HIGH;
  Blanco = LOW;
  
  servo_6.attach(6); // Conexion servo izquierdo
  servo_9.attach(9); // Conexion servo derecho
  
  Serial.begin(9600); // Incializada la comunicacion serial

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(11,LOW);
  delayMicroseconds(5);
  digitalWrite(11,HIGH);
  delayMicroseconds(10);
  
  tiempo = pulseIn(10,HIGH);
  distancia = int(0.017*tiempo);
  
  Serial.println("Distancia ");
  Serial.println(distancia);
  Serial.println(" cm");
  
  /* El servo al modificarlo indicamos que esta en posición 90º, si le diecimos
  que se coloque en una posición mayor, por ejemplo 180º, girará de forma
  continua en una dirección, si le indicamos al servo que se coloque en una 
  posición inferior, por ejemplo 0º, girará de forma continua en el otro sentido.
  Si le indicamos 90º el servo se parará */
  
  if (ultrasonic.Ranging(CM)<50){
    servo_6.write(0);
    servo_9.write(180);
  }else{
    servo_6.write(0);
    servo_9.write(90);
  }
  
  /*
  ir_derecha = digitalRead(3);
  ir_izquierda = digitalRead(2);
  
  if (ir_derecha == Negro || ir_izquierda == Negro){
    servo_6.write(180);
    servo_9.write(0);
    delay(1000);
  }*/

}
