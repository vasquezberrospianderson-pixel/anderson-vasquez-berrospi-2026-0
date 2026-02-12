#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Ingrese la cantidad de numeros: ";
    cin >> n;

    int* numeros = new int[n];  

    for (int i = 0; i < n; i++) {
        cout << "Numero " << i + 1 << ": ";
        cin >> numeros[i];
    }

    cout << "Numeros ingresados: ";
    for (int i = 0; i < n; i++) {
        cout << numeros[i] << " ";
    }

    delete[] numeros;      
    numeros = nullptr;

    return 0;
}
