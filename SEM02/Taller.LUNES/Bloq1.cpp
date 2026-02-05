#include <iostream>
using namespace std;
int main() {
    int temperatura;
    cout << "Ingrese la temperatura: ";
    cin >> temperatura;
    if (temperatura > 30) {
        cout << "Encender el ventilador";
    } else {
        cout << "Apagar el ventilador";
    }
    return 0;
}
