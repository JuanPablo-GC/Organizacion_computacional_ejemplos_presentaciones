#include <Servo.h>

Servo myServo;  // Crear un objeto Servo

void setup() {
  myServo.attach(9);  // Conectar el servo al pin 9
  myServo.write(0);   // Inicializar el servo en 0 grados
  Serial.begin(9600); // Iniciar comunicación serial
  Serial.println("Inicializando Servo en 0 grados");
}

void loop() {
    Serial.println("Moviendo el servo a 90 grados");
    myServo.write(90);  // Mover el servo a 90 grados
    delay(10000);       // Esperar 10 segundos

    Serial.println("Regresando el servo a 0 grados");
    myServo.write(0);   // Regresar el servo a 0 grados
    delay(10000);       // Esperar 10 segundos
}
