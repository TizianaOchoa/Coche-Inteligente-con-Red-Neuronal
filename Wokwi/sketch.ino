#include <Servo.h>

// Simulación de entradas (botones) y salidas (LEDs)
const int sensorIzq = 2;      // Botón 1
const int sensorDer = 3;      // Botón 2
const int sensorFront = 4;    // Botón 3
const int sensorBack = 5;     // Botón 4

const int ledIzq = 6;         // LED azul
const int ledDer = 7;         // LED rojo
const int ledRetroceso = 8;   // LED verde
const int ledAvance = 9;      // LED amarillo
const int ledAlerta = 10;     // LED blanco

Servo servoSensor; // Servo simulado (opcional)

// Configuración de la red neuronal simulada
const int InputNodes = 5;  // 4 entradas + 1 bias
const int HiddenNodes = 4;
const int OutputNodes = 5;
double Hidden[HiddenNodes];
double Output[OutputNodes];

// Pesos simulados (pueden reemplazarse por valores entrenados)
float HiddenWeights[5][4] = {
  {0.8, -0.3, 0.6, -0.2},
  {-0.5, 0.7, -0.1, 0.9},
  {0.3, -0.4, 0.8, -0.6},
  {0.5, 0.2, -0.9, 0.4},
  {1.0, 0.5, 0.3, -0.7}
};

float OutputWeights[4][5] = {
  {0.6, -0.5, 0.8, -0.3, 0.2},
  {0.2, 0.7, -0.6, 0.9, -0.8},
  {-0.5, 0.3, 0.6, -0.4, 0.7},
  {0.4, -0.7, 0.2, 0.5, -0.9}
};

// Inicialización
void setup() {
  Serial.begin(9600);
  pinMode(sensorIzq, INPUT_PULLUP);
  pinMode(sensorDer, INPUT_PULLUP);
  pinMode(sensorFront, INPUT_PULLUP);
  pinMode(sensorBack, INPUT_PULLUP);

  pinMode(ledIzq, OUTPUT);
  pinMode(ledDer, OUTPUT);
  pinMode(ledRetroceso, OUTPUT);
  pinMode(ledAvance, OUTPUT);
  pinMode(ledAlerta, OUTPUT);

  servoSensor.attach(11);
  servoSensor.write(90);

  Serial.println("Red Neuronal - Coche Inteligente Simulado");
}

// Bucle principal
void loop() {
  // Lectura de sensores (1 = no presionado, 0 = presionado)
  double entrada1 = !digitalRead(sensorIzq);
  double entrada2 = !digitalRead(sensorDer);
  double entrada3 = !digitalRead(sensorFront);
  double entrada4 = !digitalRead(sensorBack);

  // Crear vector de entrada
  double inputs[] = {1.0, entrada1, entrada2, entrada3, entrada4}; // incluye bias

  // Procesar red neuronal simulada
  forward(inputs);

  // Acciones simuladas
  digitalWrite(ledIzq, Output[0] > 0.5);
  digitalWrite(ledDer, Output[1] > 0.5);
  digitalWrite(ledRetroceso, Output[2] > 0.5);
  digitalWrite(ledAvance, Output[3] > 0.5);
  digitalWrite(ledAlerta, Output[4] > 0.5);

  // Mostrar estado en consola
  Serial.print("Entradas: ");
  Serial.print(entrada1); Serial.print(" ");
  Serial.print(entrada2); Serial.print(" ");
  Serial.print(entrada3); Serial.print(" ");
  Serial.print(entrada4); Serial.println();
  
  Serial.print("Salidas: ");
  for (int i = 0; i < OutputNodes; i++) {
    Serial.print(Output[i], 2);
    Serial.print(" ");
  }
  Serial.println("\n---");

  delay(1000);
}

// Función feedforward simplificada
void forward(double inputs[]) {
  // Capa oculta
  for (int i = 0; i < HiddenNodes; i++) {
    double sum = 0;
    for (int j = 0; j < InputNodes; j++) {
      sum += inputs[j] * HiddenWeights[j][i];
    }
    Hidden[i] = tanh(sum);
  }

  // Capa de salida
  for (int i = 0; i < OutputNodes; i++) {
    double sum = 0;
    for (int j = 0; j < HiddenNodes; j++) {
      sum += Hidden[j] * OutputWeights[j][i];
    }
    Output[i] = tanh(sum);
  }
}
