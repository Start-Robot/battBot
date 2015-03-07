
/* PROBANDO LOS SERVOMOTORES FUTABA S3003 */
/* -------------------------------------- */
/* Vamos a escribir un pequeño programa para comprobar
que los servomotores Futaba S3003 funcionan correctametne*/

// Incluimos las librerias de Arduino
#include <Servo.h>

// Constantes
//-------------
/* Cuando hablamos de izquierdo o derecho nos referimos a la 
posicion del servmotor */
// Definimos los valores en microsegundos para los servos
#define derechoParada 1450 //El servo se para, equivale a 90º
#define izquierdoParada 1390 
#define derechoAdelante 2000 //El servo gira totalmente a la derecha, equvale a 180º
#define izquierdoAdelante 1000 //El servo gira totalmente a la izquierda, equivale a 0º
#define derechoAtras 1000 //Los servos estan conectados de forma opuesta. Hay que tenerlo en cuenta.
#define izquierdoAtras 2000
/* Para el control de los servomotres Futaba S3003, al haber sido
modificados, utilizamos la función writeMicroseconds() de la 
librería de Servo de Arduino, de ahí las constantes con esos valores
que hemos definido */

// Declaracion Variables
//-----------------------
Servo servo_6; //Servo izquierdo
Servo servo_9; //Servo derecho

void setup() {
  // put your setup code here, to run once:
  servo_6.attach(6); //Conexión del servo izquierdo al Pin 6
  servo_9.attach(9); //Conexión del servo derecho al Pin 9
}

void loop() {
  // put your main code here, to run repeatedly:
  //Ir hacia adelante
  servo_6.writeMicroseconds(izquierdoAdelante);
  servo_9.writeMicroseconds(derechoAdelante);
  delay(1000); //Esperar 1 segundo
  //Ir hacia atras
  servo_6.writeMicroseconds(izquierdoAtras);
  servo_9.writeMicroseconds(derechoAtras);
  delay(1000);//Esperar 1 segundo
  //Parar
  servo_6.writeMicroseconds(izquierdoParada);
  servo_9.writeMicroseconds(derechoParada);
}
/* Los valores no tienen porque se ser exactamente estos para todos
los servomotores modificados, hay que ir probando. El rango de 
valores es entre 733 a 2300 */
