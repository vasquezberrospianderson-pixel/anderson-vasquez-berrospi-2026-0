#include <iostream>
#include <vector>
using namespace std;

int main() {
    int f, c;

    // Pedir filas y columnas
    cout << "Ingrese numero de filas: ";
    cin >> f;
    cout << "Ingrese numero de columnas: ";
    cin >> c;

    // Crear matriz dinámica f x c
    vector<vector<int>> matriz(f, vector<int>(c));

    // 3) Llenar la matriz
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < c; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    // Imprimir la matriz como tabla
    cout << "\nMatriz ingresada:\n";
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < c; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
