// Inclui a biblioteca Servo Motor
#include <Servo.h>. 

// Define os pinos Trig e Echo do sensor ultrassônico
const int trigPin = 10;
const int echoPin = 11;
// Variáveis para a duração e a distância
long duration;
int distance;

Servo myServo; // Cria um objeto servo para controlar o servo motor

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  myServo.attach(12); // Define em qual pino o Servo Motor está conectado
}
void loop() {
  // gira o Servo Motor de 15 a 165 graus
  for(int i=15;i<=165;i++){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();// Chama uma função para calcular a distância medida pelo sensor ultrassônico para cada grau
  
  Serial.print(i); // Envia o grau atual para a porta serial
  Serial.print(","); // Envia o caractere de adição ao lado do valor anterior necessário posteriormente no IDE de processamento para indexação
  Serial.print(distance); // Envia o valor da distância para a porta serial
  Serial.print("."); // Envia o caractere de adição ao lado do valor anterior necessário posteriormente no IDE de processamento para indexação
  }
  // Repete as linhas anteriores de 165 a 15 graus
  for(int i=165;i>15;i--){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
}
// Função para calcular a distância medida pelo sensor ultrassônico
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Define o trigPin no estado HIGH por 10 micro segundos
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Lê o echoPin, retorna o tempo de viagem da onda sonora em microssegundos
  distance= duration*0.034/2;
  return distance;
}
