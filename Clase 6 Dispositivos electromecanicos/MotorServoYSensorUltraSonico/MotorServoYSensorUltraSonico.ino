#include <Servo.h>

int trigPin = 12;
int echoPin = 11;
int pingTravelTime;
long distance;

Servo myServo;  // Crear un objeto Servo

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(9);  // Conectar el servo al pin 9
  myServo.write(0);   // Inicializar el servo en 0 grados
  Serial.begin(9600);
}

void loop() {
  // Enviar pulso del sensor ultrasónico
  digitalWrite(trigPin, LOW);   // Asegurarse de que el pin esté bajo
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);  // Enviar pulso
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Leer el pulso de respuesta
  pingTravelTime = pulseIn(echoPin, HIGH);

  // Calcular la distancia (en centímetros si queremos)
  //distance = (pingTravelTime * 0.034) / 2;

  distance = pingTravelTime;

  Serial.print("Distance: ");
  Serial.println(distance);

  // Condición: si la distancia es menor a 500 (puedes ajustarlo según sea necesario)
  if (distance < 500) {
    myServo.write(90);  // Mover el servo a 90 grados
    delay(10000);       // Esperar 20 segundos
    myServo.write(0);   // Regresar el servo a 0 grados
  }

  delay(1000);  // Pequeña pausa para evitar lecturas muy rápidas
}
