# ======================================================
# Red Neuronal para Coche Inteligente - Versión Extendida
# 4 Entradas y 5 Salidas
# ======================================================

import numpy as np

# ------------------------------------------------------
# Clase NeuralNetwork
# ------------------------------------------------------
class NeuralNetwork:
    def __init__(self, layers, activation='tanh'):
        self.activation = np.tanh
        self.activation_deriv = lambda x: 1.0 - np.tanh(x)**2
        self.weights = []
        for i in range(1, len(layers)):
            r = 2 * np.random.random((layers[i-1] + 1, layers[i] + (i < len(layers)-1))) - 1
            self.weights.append(r * 0.25)

    def fit(self, X, y, learning_rate=0.03, epochs=40000):
        X = np.hstack([np.ones((X.shape[0], 1)), X])
        for k in range(epochs):
            i = np.random.randint(X.shape[0])
            a = [X[i]]
            for l in range(len(self.weights)):
                a.append(self.activation(np.dot(a[l], self.weights[l])))
            error = y[i] - a[-1]
            deltas = [error * self.activation_deriv(a[-1])]
            for l in range(len(a) - 2, 0, -1):
                deltas.append(deltas[-1].dot(self.weights[l].T) * self.activation_deriv(a[l]))
            deltas.reverse()
            for i in range(len(self.weights)):
                layer = np.atleast_2d(a[i])
                delta = np.atleast_2d(deltas[i])
                self.weights[i] += learning_rate * layer.T.dot(delta)

    def predict(self, x):
        x = np.hstack([np.ones(1), x])
        for l in range(len(self.weights)):
            x = self.activation(np.dot(x, self.weights[l]))
        return x

# ------------------------------------------------------
# Nuevos datos de entrenamiento (4 entradas, 5 salidas)
# ------------------------------------------------------

nn = NeuralNetwork([4, 5, 5], activation='tanh')

# X: [Sensor Izq, Sensor Der, Sensor Frontal, Sensor Trasero]
X = np.array([
    [-1, -1, -1, -1],  # sin obstáculos
    [0, -1, -1, -1],   # obstáculo derecha
    [-1, 0, -1, -1],   # obstáculo izquierda
    [-1, -1, 0, -1],   # obstáculo frente
    [-1, -1, -1, 0],   # obstáculo atrás
    [1, 0, -1, -1],    # demasiado cerca izquierda
    [0, 1, -1, -1],    # demasiado cerca derecha
    [1, 1, 1, -1],     # rodeado adelante
    [0, 0, 0, 0],      # rodeado en todos lados
])

# y: [Motor Izq, Motor Der, Retroceso, Avance, Luz de Alerta]
y = np.array([
    [1, 1, 0, 1, 0],  # avanzar
    [0, 1, 0, 1, 0],  # giro derecha
    [1, 0, 0, 1, 0],  # giro izquierda
    [0, 0, 0, 1, 1],  # freno + alerta
    [0, 0, 1, 0, 1],  # retroceder + alerta
    [0, 1, 1, 0, 1],  # retroceso derecha + alerta
    [1, 0, 1, 0, 1],  # retroceso izquierda + alerta
    [0, 0, 1, 0, 1],  # retroceder
    [0, 0, 0, 0, 1],  # detenido + alerta
])

# ------------------------------------------------------
# Entrenamiento
# ------------------------------------------------------
print("Entrenando la red neuronal con 4 entradas y 5 salidas...")
nn.fit(X, y, learning_rate=0.03, epochs=45000)
print("Entrenamiento completado.\n")

# ------------------------------------------------------
# Redondeo de resultados
# ------------------------------------------------------
def valNN(x):
    return int(abs(round(x)))

# ------------------------------------------------------
# Pruebas
# ------------------------------------------------------
index = 0
for e in X:
    prediccion = nn.predict(e)
    print(f"Entrada: {e} → Esperado: {y[index]} → Obtenido:",
          [valNN(x) for x in prediccion])
    index += 1

print("\nPesos finales de la red:")
for i, w in enumerate(nn.weights):
    print(f"Capa {i+1}:\n{w}\n")
