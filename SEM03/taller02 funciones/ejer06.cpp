#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int minimoArreglo(int arreglo[], int n) {
    int minimo = arreglo[0];
    for (int i = 1; i < n; i++) {
        if (arreglo[i] < minimo) {
            minimo = arreglo[i];
        }
    }
    return minimo;
}
bool esEntero(const string& texto) {
    int inicio = 0;
    if (texto[0] == '-') {
        if (texto.length() == 1)
            return false;
        inicio = 1;
    }
    for (int i = inicio; i < texto.length(); i++) {
        if (!isdigit(texto[i]))
            return false;
    }
    return true;
}
int main() {
    string entrada;
    int n;
    cout << "Ingrese la cantidad de elementos del arreglo: ";
    cin >> entrada;
    while (!esEntero(entrada) || stoi(entrada) <= 0) {
        cout << "Entrada invalida. Ingrese un numero entero positivo: ";
        cin >> entrada;
    }
    n = stoi(entrada);
    int arreglo[n];
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> entrada;
        while (!esEntero(entrada)) {
            cout << "Entrada invalida. Ingrese un numero entero: ";
            cin >> entrada;
        }
        arreglo[i] = stoi(entrada);
    }
    cout << "El valor minimo del arreglo es: "
         << minimoArreglo(arreglo, n) << endl;

    return 0;
}
