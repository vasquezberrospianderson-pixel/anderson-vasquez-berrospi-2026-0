#include <iostream>
#include <string>
#include <cctype>
using namespace std;
float calcularPromedio(float notas[], int n) {
    float suma = 0;
    for (int i = 0; i < n; i++) {
        suma += notas[i];
    }
    return suma / n;
}
bool esEntero(const string& texto) {
    for (int i = 0; i < texto.length(); i++) {
        if (!isdigit(texto[i]))
            return false;
    }
    return true;
}
bool esDecimal(const string& texto) {
    bool punto = false;
    for (int i = 0; i < texto.length(); i++) {
        if (texto[i] == '.') {
            if (punto) return false;
            punto = true;
        } else if (!isdigit(texto[i])) {
            return false;
        }
    }
    return true;
}
int main() {
    string entrada;
    int n;
    cout << "Ingrese la cantidad de notas: ";
    cin >> entrada;
    while (!esEntero(entrada) || stoi(entrada) <= 0) {
        cout << "Entrada invalida. Ingrese un numero entero positivo: ";
        cin >> entrada;
    }
    n = stoi(entrada);
    float notas[n];
    for (int i = 0; i < n; i++) {
        cout << "Ingrese la nota " << i + 1 << " (0 a 20): ";
        cin >> entrada;
        while (!esDecimal(entrada) || stof(entrada) < 0 || stof(entrada) > 20) {
            cout << "Nota invalida. Ingrese un valor entre 0 y 20: ";
            cin >> entrada;
        }
        notas[i] = stof(entrada);
    }
    cout << "El promedio de las notas es: "
         << calcularPromedio(notas, n) << endl;

    return 0;
}
