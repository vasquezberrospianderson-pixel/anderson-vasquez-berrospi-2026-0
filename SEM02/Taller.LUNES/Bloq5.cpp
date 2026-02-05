#include <iostream>
using namespace std;
int main() {
    int hora;
    cout << "Ingrese la hora (0 a 23): ";
    cin >> hora;
    if (hora < 0 || hora > 23) {
        cout << "Hora no valida";
    } else if (hora >= 6 && hora <= 11) {
        cout << "Buenos dias";
    } else if (hora >= 12 && hora <= 18) {
        cout << "Buenas tardes";
    } else {
        cout << "Buenas noches";
    }
    return 0;
}
