#include <iostream>
#include <string>

using namespace std;

//  CLASE BASE 
class Empleado {
protected:
    string nombre;
    float sueldo;

public:
    Empleado(string n, float s) {
        nombre = n;
        sueldo = s;
    }

    void mostrarDatos() {
        cout << "Nombre: " << nombre << endl;
        cout << "Sueldo: " << sueldo << endl;
    }
};


int main() {
    Empleado emp("Carlos", 1500);

    emp.mostrarDatos();

    return 0;
}

