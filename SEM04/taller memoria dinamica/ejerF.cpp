#include <iostream>
using namespace std;

int main() {
    int capacidad = 2;
    int tamano = 0;

    int* arreglo = new int[capacidad];

    int valor;

    cout << "Ingrese numeros (-1 para terminar)\n";

    while (true) {
        cin >> valor;

        if (valor == -1) {
            break;
        }

        if (tamano == capacidad) {
            int nuevaCapacidad = capacidad * 2;
            int* nuevo = new int[nuevaCapacidad];

            for (int i = 0; i < tamano; i++) {
                nuevo[i] = arreglo[i];
            }

            delete[] arreglo;
            arreglo = nuevo;
            capacidad = nuevaCapacidad;
        }

        arreglo[tamano] = valor;
        tamano++;
    }

    cout << "\nNumeros guardados:\n";
    for (int i = 0; i < tamano; i++) {
        cout << arreglo[i] << " ";
    }

    delete[] arreglo;
    return 0;
}
