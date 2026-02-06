#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Función que verifica si un arreglo está ordenado de forma ascendente
bool estaOrdenadoAsc(int arreglo[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        if (arreglo[i] > arreglo[i + 1]) {
            return false;
        }
    }
    return true;
}

// Función que valida si una cadena es un número entero
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
    int tam;

    cout << "Ingrese el tamaño del arreglo: ";
    cin >> entrada;

    while (!esEntero(entrada) || stoi(entrada) <= 0) {
        cout << "Entrada invalida. Ingrese un numero entero mayor que cero: ";
        cin >> entrada;
    }

    tam = stoi(entrada);
    int arreglo[tam];

    cout << "Ingrese los elementos del arreglo:" << endl;
    for (int i = 0; i < tam; i++) {
        cin >> entrada;
        while (!esEntero(entrada)) {
            cout << "Entrada invalida. Ingrese un numero entero: ";
            cin >> entrada;
        }
        arreglo[i] = stoi(entrada);
    }

    if (estaOrdenadoAsc(arreglo, tam)) {
        cout << "El arreglo esta ordenado de forma ascendente." << endl;
    } else {
        cout << "El arreglo no esta ordenado de forma ascendente." << endl;
    }

    return 0;
}