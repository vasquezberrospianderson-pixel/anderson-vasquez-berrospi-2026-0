#include <iostream>
#include <string>
using namespace std;
int mayor(int a, int b) {
    return (a > b) ? a : b;
}
bool esEntero(string texto) {
    int inicio = 0;
    if (texto[0] == '-') {
        if (texto.length() == 1) return false;
        inicio = 1;
    }
    for (int i = inicio; i < texto.length(); i++) {
        if (!isdigit(texto[i])) {
            return false;
        }
    }
    return true;
}
int main() {
    string entrada;
    int num1, num2;
    cout << "Ingrese el primer numero entero: ";
    cin >> entrada;
    while (!esEntero(entrada)) {
        cout << "Entrada invalida. Ingrese SOLO un numero entero: ";
        cin >> entrada;
    }
    num1 = stoi(entrada);
    cout << "Ingrese el segundo numero entero: ";
    cin >> entrada;
    while (!esEntero(entrada)) {
        cout << "Entrada invalida. Ingrese SOLO un numero entero: ";
        cin >> entrada;
    }
    num2 = stoi(entrada);
    cout << "El numero mayor es: " << mayor(num1, num2) << endl;
    return 0;
}



