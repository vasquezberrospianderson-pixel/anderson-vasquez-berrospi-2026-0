#include <iostream>
#include <string>
#include <cctype>
using namespace std;
long long factorial(int n) {
    long long resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
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
    cout << "Ingrese un numero entero mayor o igual a 0: ";
    cin >> entrada;
    while (!esEntero(entrada) || stoi(entrada) < 0) {
        cout << "Entrada invalida. Ingrese un numero entero mayor o igual a 0: ";
        cin >> entrada;
    }
    numero = stoi(entrada);
    cout << "El factorial de " << numero << " es: "
         << factorial(numero) << endl;

    return 0;
}
