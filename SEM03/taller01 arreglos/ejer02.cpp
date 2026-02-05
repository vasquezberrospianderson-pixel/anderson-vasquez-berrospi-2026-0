#include <iostream>
using namespace std;
int main() {
    int temp[7];
    int max, min;
    int diaMax = 1, diaMin = 1;
    int contador = 0;
    cout << "Ingrese las temperaturas del Dia 1 al Dia 7:\n";
    for (int i = 0; i < 7; i++) {
        cout << "Dia " << i + 1 << ": ";
        cin >> temp[i];
    }
    max = temp[0];
    min = temp[0];
    for (int i = 0; i < 7; i++) {
        if (temp[i] > max) {
            max = temp[i];
            diaMax = i + 1;
        }
        if (temp[i] < min) {
            min = temp[i];
            diaMin = i + 1;
        }
        if (temp[i] > 30) {
            contador++;
        }
    }
    cout << "\nMaxima: " << max << " (dia " << diaMax << ")" << endl;
    cout << "Minima: " << min << " (dia " << diaMin << ")" << endl;
    cout << "Dias mayores a 30: " << contador << endl;
    return 0;
}
