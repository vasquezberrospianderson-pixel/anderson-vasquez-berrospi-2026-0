#include <iostream>
using namespace std;

int main() {
    int n;

    // Pedir tamaño
    cout << "Ingrese el tamano del arreglo: ";
    cin >> n;

    // Crear arreglo dinámico
    int* arreglo = new int[n];

    // Llenar el arreglo
    for(int i = 0; i < n; i++) {
        cout << "Ingrese el valor " << i + 1 << ": ";
        cin >> arreglo[i];
    }

    // Mostrar el arreglo
    cout << "Elementos del arreglo: ";
    for(int i = 0; i < n; i++) {
        cout << arreglo[i] << " ";
    }

    // Liberar memoria
    delete[] arreglo;

    return 0;
}
