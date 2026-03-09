import turtle
import time

pantalla = turtle.Screen()
pantalla.bgcolor("black")

flor = turtle.Turtle()
flor.speed(0)
flor.color("pink")
flor.width(2)

# Función para dibujar un pétalo
def petalo():
    for i in range(2):
        flor.circle(100, 60)
        flor.left(120)

# Animación de la flor girando
while True:
    flor.clear()
    for i in range(6):
        petalo()
        flor.left(60)
    flor.right(5)   # movimiento (rotación)
    time.sleep(0.05)
