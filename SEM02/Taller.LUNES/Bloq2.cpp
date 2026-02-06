#include <iostream>
using namespace std;
int main() {
    int edad;
    cout << "Ingrese su edad = ";
    cin >> edad;
    if (edad < 0 || edad > 120) {
        cout << "Edad invalida";
    } 
    else if (edad >= 18) {
        cout << "Acceso permitido";
    } 
    else {
        cout << "Acceso denegado";
    }
    return 0;
}
