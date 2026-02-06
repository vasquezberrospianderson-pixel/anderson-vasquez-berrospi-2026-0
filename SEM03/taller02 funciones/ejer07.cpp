#include <iostream>
#include <string>
#include <cctype>
using namespace std;
bool validarOpcion(int opcion, int min, int max) {
    if (opcion >= min && opcion <= max) {
        return true;
    } else {
        return false;
    }
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
    int opcion;
    const int MIN = 1;
    const int MAX = 5;
    cout << "MENU DE OPCIONES" << endl;
    cout << "1. Opcion 1" << endl;
    cout << "2. Opcion 2" << endl;
    cout << "3. Opcion 3" << endl;
    cout << "4. Opcion 4" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opcion (1-5): ";
    cin >> entrada;
    while (!esEntero(entrada)) {
        cout << "Entrada invalida. Ingrese un numero entero: ";
        cin >> entrada;
    }
    opcion = stoi(entrada);
    if (validarOpcion(opcion, MIN, MAX)) {
        cout << "Opcion valida." << endl;
    } else {
        cout << "Opcion fuera del rango permitido." << endl;
    }
    return 0;
}
