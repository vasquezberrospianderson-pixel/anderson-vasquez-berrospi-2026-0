#include <iostream>
#include <string>
#include <cctype>
using namespace std;
bool esPar(int n) {
    return n % 2 == 0;
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
    int numero;
    cout << "Ingrese un numero entero: ";
    cin >> entrada;
    while (!esEntero(entrada)) {
        cout << "Entrada invalida. Ingrese SOLO un numero entero: ";
        cin >> entrada;
    }
    numero = stoi(entrada);
    if (esPar(numero)) {
        cout << "El numero es par." << endl;
    } else {
        cout << "El numero es impar." << endl;
    }
    return 0;
}

