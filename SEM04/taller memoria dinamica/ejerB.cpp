#include <iostream>
using namespace std;

// Función que crea y devuelve un arreglo dinámico
int* crearArreglo(int n) {
    int* arreglo = new int[n];   // reservar memoria

    for (int i = 0; i < n; i++) {
        arreglo[i] = 2 * (i + 1); // números pares
    }

    return arreglo; // retornar puntero
}

int main() {
    int n;

    cout << "Ingrese el tamano del arreglo: ";
    cin >> n;

    // Llamar a la función
    int* arreglo = crearArreglo(n);

    // Imprimir los elementos
    cout << "Arreglo de numeros pares: ";
    for (int i = 0; i < n; i++) {
        cout << arreglo[i] << " ";
    }

    // Liberar memoria
    delete[] arreglo;

    return 0;
}
