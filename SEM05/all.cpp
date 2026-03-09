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

    virtual void mostrarDatos() {
        cout << "Nombre: " << nombre << endl;
        cout << "Sueldo: " << sueldo << endl;
    }
};
//  CLASE DERIVADA 
class EmpleadoTiempoCompleto : public Empleado {
public:
    EmpleadoTiempoCompleto(string n, float s) : Empleado(n, s) {}

    void mostrarDatos() override {
        cout << "Empleado Tiempo Completo" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Sueldo: " << sueldo << endl;
    }
};

int main() {
    EmpleadoTiempoCompleto emp("Ana", 2500);

    emp.mostrarDatos();

    return 0;
}
