# 🤖 Coche Inteligente con Red Neuronal – Arduino Uno + Wokwi

## 🏫 Proyecto Universitario

Este trabajo fue desarrollado como parte de la materia **Arquitectura de Computadoras**, bajo la dirección del **Profesor Narciso Pérez**.  
El proyecto demuestra la integración entre **Inteligencia Artificial (IA)** y **sistemas embebidos**, aplicando conceptos de arquitectura, programación y control electrónico mediante **Arduino** y **Python**.

---

## 📋 Descripción del Proyecto

Este proyecto implementa un **coche inteligente controlado por una red neuronal artificial (RNA)**, capaz de tomar decisiones de movimiento en función de la información recibida por sensores.  

La simulación se realiza en **Wokwi (Arduino Uno)** y el entrenamiento de la red neuronal se lleva a cabo en **Python (Google Colab)**.  

El sistema replica el comportamiento de un vehículo autónomo básico, que **detecta obstáculos, ajusta su dirección, retrocede, avanza o se detiene con alerta** según el entorno simulado.

---

## 🧠 1. Entrenamiento de la Red Neuronal

### 🔹 Versión inicial
La red comenzó con:
- **2 entradas** → sensores laterales (izquierdo y derecho)
- **4 salidas** → control de motores (izquierdo, derecho, avance, retroceso)

### 🔹 Versión extendida
Posteriormente, la red fue **modificada y ajustada** para simular:
- **4 entradas**:
  1. Sensor Izquierdo  
  2. Sensor Derecho  
  3. Sensor Frontal  
  4. Sensor Trasero  
- **5 salidas**:
  1. Motor Izquierdo  
  2. Motor Derecho  
  3. Retroceso  
  4. Avance  
  5. Luz de Alerta  

Esta ampliación permitió un comportamiento más realista: el coche puede detectar obstáculos en todas las direcciones y activar una **alerta visual (LED)** cuando se encuentra en peligro o rodeado.

---

## 🧩 2. Entrenamiento en Python (Google Colab)

Se implementó una red neuronal con arquitectura **[4, 5, 5]** usando `tanh` como función de activación.

```python
nn = NeuralNetwork([4, 5, 5], activation='tanh')
```

### 📘 Datos de entrenamiento

**Entradas (X):** sensores simulados  
**Salidas (y):** acciones del coche  

```python
# X: [Sensor Izq, Sensor Der, Sensor Frontal, Sensor Trasero]
X = np.array([
    [-1, -1, -1, -1],
    [0, -1, -1, -1],
    [-1, 0, -1, -1],
    [-1, -1, 0, -1],
    [-1, -1, -1, 0],
    [1, 0, -1, -1],
    [0, 1, -1, -1],
    [1, 1, 1, -1],
    [0, 0, 0, 0],
])

# y: [Motor Izq, Motor Der, Retroceso, Avance, Luz de Alerta]
y = np.array([
    [1, 1, 0, 1, 0],
    [0, 1, 0, 1, 0],
    [1, 0, 0, 1, 0],
    [0, 0, 0, 1, 1],
    [0, 0, 1, 0, 1],
    [0, 1, 1, 0, 1],
    [1, 0, 1, 0, 1],
    [0, 0, 1, 0, 1],
    [0, 0, 0, 0, 1],
])
```

La red se entrenó durante **45,000 épocas**, ajustando sus pesos internos para minimizar el error de predicción.

---

## ⚙️ 3. Implementación en Arduino (Wokwi)

### 🔧 Componentes usados:
- 🧠 **Arduino Uno**
- ⚙️ **Motores DC** (simulados)
- 🌀 **Servo motor** (para mover el sensor ultrasónico)
- 📏 **Sensor ultrasónico HC-SR04**
- 💡 **LED indicador de alerta**
- 🔘 **Pulsador de control (opcional)**
- ⚡ **Resistencias de 1kΩ**

### 🔹 Funcionalidades:
- Mide distancia con sensor ultrasónico  
- Controla dirección del servo para escanear el entorno  
- Utiliza la red neuronal entrenada (pesos fijos) para decidir:
  - Avanzar  
  - Retroceder  
  - Girar izquierda/derecha  
  - Activar alerta visual  

### 📁 Archivo principal: `sketch.ino`

Incluye:
- Configuración de pines  
- Lectura del sensor ultrasónico  
- Movimiento del servo  
- Aplicación de la red neuronal entrenada (`InputToOutput`)  
- Activación de motores según salidas de la red  

---

## 🔌 4. Esquema de Conexión (Wokwi)

El proyecto se simuló con el siguiente diagrama (`diagram.json`):

- LED azul → Pin 8  
- LED rojo → Pin 9  
- Resistencia 1kΩ para cada LED  
- Servo en pin 3  
- Sensor ultrasónico en A4 (Echo) y A5 (Trig)  
- Motores controlados por pines 5–11  
- GND comunes entre Arduino y componentes  

📎 *El archivo `diagram.json` incluido permite importar directamente el circuito en Wokwi.*

---

## 🚗 5. Resultados de Simulación

Durante las pruebas:
- Cuando el sensor detecta objetos cercanos, la red neuronal ordena **retroceder o girar**.  
- Si hay obstáculos en todas las direcciones, el sistema **activa la luz de alerta (LED)**.  
- Si no hay obstáculos, **avanza** con ambos motores activos.  

El comportamiento demuestra una **adaptación autónoma** similar a un vehículo con detección de entorno básica.

---

## 📂 6. Estructura del Repositorio

```
├── /Coche-Inteligente-con-Red-Neuronal #Carpeta vacia innecesaria 
├── /Wokwi
│   ├── sketch.ino           # Código Arduino principal
│   ├── diagram.json         # Diagrama de conexiones para Wokwi
│
├── /python
│   ├── entrenamiento.ipynb  # Entrenamiento de la red neuronal
│
└── README.md                # Descripción del proyecto
```

---

## 🧾 7. Conclusiones

- Se implementó una **red neuronal artificial funcional** en Python y se transfirieron los pesos al código Arduino.  
- Se logró una **simulación completa** en Wokwi, demostrando cómo el vehículo puede tomar decisiones simples de navegación.  
- El sistema fue **ampliado** para manejar **4 entradas y 5 salidas**, incluyendo una alerta visual.  
- Este proyecto demuestra el **vínculo entre IA y sistemas embebidos**, integrando **aprendizaje automático con hardware real o simulado**.

---

## 👩‍💻 Autoría

**Estudiante:** Tiziana Yazmin Ochoa  
**Materia:** Arquitectura de Computadoras  
**Profesor:** Narciso Pérez  
**Año:** 2025  
🏫 **Proyecto Universitario – Universidad Provincial de Cordoba**
