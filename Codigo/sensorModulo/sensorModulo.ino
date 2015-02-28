//Lenguaje: Español
//Nombre: Código para probar el módulo LineFinder
//Función: Detectar linea blanco o negra
//Parámetros: Cuando la señal digital es ALTA (HIGH), es linea negra
// Cuando la señal digital es BAJA (LOW), es linea blanca
//--------------------------------------------------------
 
// Declaramos las variables:
int signalPinLeft = 2; // Conexión modulo seguilineas izquierdo
int signalPinRight = 3; // Conexión módulo seguilíneas derecho
 
void setup() {
 // put your setup code here, to run once:
 
 pinMode(signalPinLeft, INPUT); // Inicializa el pin digital como una salida
 pinMode(signalPinRight, INPUT); //Inicializa el módulo derecho
 
 Serial.begin(9600); // inicializa la comunicación serial a 9600 bps:
}
 
void loop() {
 // put your main code here, to run repeatedly:
 
 if (HIGH == digitalRead(signalPinLeft) || HIGH == digitalRead(signalPinRight)){
    Serial.println("negro"); // Saca por pantalla el nombre negro
 }else{
    Serial.println("blanco"); // Saca por pantalla el nombre blanco
    delay(1000); // Esperar por un segundo
 }
}
