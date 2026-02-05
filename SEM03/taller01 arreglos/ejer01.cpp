#include <iostream>
using namespace std;
int main() {
    int gastos[7];
    int total = 0;
    float promedio;
    int contador = 0;
    cout << "Ingrese los gastos del Dia 1 al Dia 7:\n";
    for (int i = 0; i < 7; i++) {
        do {
            cout << "Dia " << i + 1 << ": ";
            cin >> gastos[i];
            if (gastos[i] < 0) {
                cout << "Error: no se permiten numeros negativos. Intente nuevamente.\n";
            }
        } while (gastos[i] < 0);
        total += gastos[i];
    }
    promedio = total / 7.0;
    cout << "\nDias con gasto mayor al promedio:\n";
    for (int i = 0; i < 7; i++) {
        if (gastos[i] > promedio) {
            cout << "Dia " << i + 1 << endl;
            contador++;
        }
    }
    cout << "\nTotal: " << total << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Cantidad de dias con gasto mayor al promedio: " << contador << endl;
    return 0;
}


