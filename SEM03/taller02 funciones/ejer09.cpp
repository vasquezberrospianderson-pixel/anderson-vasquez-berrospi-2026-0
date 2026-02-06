#include <iostream>
#include <string>
#include <cctype>
using namespace std;
bool buscarElemento(int arreglo[], int tam, int valor) {
    for (int i = 0; i < tam; i++) {
        if (arreglo[i] == valor) {
            return true;
        }
    }
    return false;
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
    int tam;
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> entrada;
    while (!esEntero(entrada) || stoi(entrada) <= 0) {
        cout << "Entrada invalida. Ingrese un numero entero mayor que 0: ";
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
    int valor;
    cout << "Ingrese el valor a buscar: ";
    cin >> entrada;
    while (!esEntero(entrada)) {
        cout << "Entrada invalida. Ingrese un numero entero: ";
        cin >> entrada;
    }
    valor = stoi(entrada);
    if (buscarElemento(arreglo, tam, valor)) {
        cout << "El valor existe dentro del arreglo." << endl;
    } else {
        cout << "El valor no existe dentro del arreglo." << endl;
    }
    return 0;
}

