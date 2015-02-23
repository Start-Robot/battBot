// Ejemplo de uso del Sensor Ultrasonido HC-SR04
//--------------------------------------------------

#include <Ultrasonic.h>; // Librearia Sensor Ultrasonido

long distancia;
long tiempo;

Ultrasonic ultrasonic(11,10);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //pinMode(11,OUTPUT); // Activación del pin 11 como salida
  //pinMode(10,INPUT); // Activación del pin 10 como entrada

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(11,LOW); // Por cuestión de establidad del sensor
  delayMicroseconds(5); 
  digitalWrite(11,HIGH); // Envio del pulso ultrasonico
  delayMicroseconds(10);
  
  tiempo = pulseIn(10,HIGH); /* Funcion para medir la longitud del pulso
  entrante. Mide el tiempo que transcurrido entre el envío del pulso
  ultrasónico y cuando el sensor recibe el rebote, es decir: desde que el pin 12
  empieza a recibir el rebote, HIGH, hasta que deja de hacerlo, LOW,
  la longitud del pulso entratne*/
  
  distancia = int(0.017*tiempo); /* Fórmula para calcular la distancia
  obteniendo un valor entero */
  
  /* Monitorización en centímetros por el monitor serial */
  Serial.println("Distancia ");
  Serial.println(distancia);
  Serial.println(" cm");
  delay(1000);

}
