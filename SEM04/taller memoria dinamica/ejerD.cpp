#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;

    // Pedir tamaño
    cout << "Ingrese el tamano del arreglo: ";
    cin >> n;

    // Crear vector de tamaño n
    vector<int> arreglo(n);

    // Llenar el vector
    for(int i = 0; i < n; i++) {
        cout << "Ingrese el valor " << i + 1 << ": ";
        cin >> arreglo[i];
    }

    // Mostrar el vector
    cout << "Elementos del vector: ";
    for(int i = 0; i < n; i++) {
        cout << arreglo[i] << " ";
    }

    return 0;
}
