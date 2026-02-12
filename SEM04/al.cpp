#include <iostream>
using namespace std;

int main() {
    int numero;
    int total = 0;

    do {
        cout << "Ingrese un numero positivo y par: ";
        cin >> numero;

        if (numero <= 0 || numero % 2 != 0) {
            cout << "Error: el numero debe ser positivo y par:"<<endl;
        }

    } while (numero <= 0 || numero % 2 != 0);

    while (numero > 0) {
        total = total + numero;
        numero = numero - 2;
    }

    cout << "El resultado es: " << total << endl;

    return 0;
}



