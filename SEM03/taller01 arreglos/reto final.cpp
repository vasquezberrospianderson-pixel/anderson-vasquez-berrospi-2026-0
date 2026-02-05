#include <iostream>
using namespace std;
int main() {
    int datos[8];
    int rachaActual = 0;
    int rachaMayor = 0;
    cout << "Ingrese las ganancias y perdidas:\n";
    for (int i = 0; i < 8; i++) {
        cin >> datos[i];
    }
    for (int i = 0; i < 8; i++) {
        if (datos[i] > 0) {
            rachaActual++;
            if (rachaActual > rachaMayor) {
                rachaMayor = rachaActual;
            }
        } else {
            rachaActual = 0;
        }
    }
    cout << "Mayor racha positiva: " << rachaMayor << " dias" << endl;
    return 0;
}

