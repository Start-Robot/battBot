//Leguage: Spanish
//Nombre: Codigo para el módulo Line Finder
//Funcion: Detectar linea blanco o negra
//Parametros:  Cuando la señal digital es ALTA (HIGH), es linea negra
//             Cuando la señal digital es BAJA (LOW), es linea blanca
//--------------------------------------------------------

#include <Servo.h> // libreria para los servos

int ir_derecha;
int ir_izquierda;

int signalPinLeft = 2; // Conexion modulo segui lineas izquiedo
int signalPinRight = 3; // Conexion modulo segui lineas derecho

Servo servo_6; // Servo derecho
Servo servo_9; // Servo izquierdo

void setup() {
  // put your setup code here, to run once:
  pinMode(signalPinLeft, INPUT); // inicializa la el pin digital como una salida
  pinMode(signalPinRight, INPUT); //Iniciaiza el derecho
  
  servo_6.attach(6); // Conexion Servo derecho
  servo_9.attach(9); // Conexion Servo izquierdo
  
  Serial.begin(9600); // inicializa la comunicacion serial a 9600 bps:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  ir_derecha = digitalRead(signalPinLeft);
  ir_izquierda = digitalRead(signalPinRight);
  
  if (ir_derecha == HIGH){
    servo_6.write(0);
    delay(20);
  }else{
    servo_6.write(90);
    delay(20);
  }
  
  if (ir_izquierda == HIGH){
    servo_9.write(180);
    delay(20);
  }else{
    servo_9.write(90);
    delay(20);
  }
  
  /*if (HIGH == digitalRead(signalPinLeft) || HIGH == digitalRead(signalPinRight)){
    Serial.println("black");
  }else{
    Serial.println("white"); // saca por pantalla el color
    delay(1000);            // esperar por un segundo
   } */
}
