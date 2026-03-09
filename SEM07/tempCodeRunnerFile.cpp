#include <iostream>
using namespace std;

class Persona {
private:
    string nombre;
    int edad;

public:
    Persona(string n, int e) {
        nombre = n;
        edad = e;
    }

    // Sobrecarga del operador ==
    bool operator==(const Persona& p) {
        return edad == p.edad;
    }

    // Sobrecarga del operador <
    bool operator<(const Persona& p) {
        return edad < p.edad;
    }

    // Sobrecarga del operador <<
    friend ostream& operator<<(ostream& os, const Persona& p);
};

ostream& operator<<(ostream& os, const Persona& p) {
    os << "Nombre: " << p.nombre << ", Edad: " << p.edad;
    return os;
}

int main() {
    Persona p1("Ana", 20);
    Persona p2("Luis", 25);

    if (p1 == p2)
        cout << "Tienen la misma edad\n";
    else
        cout << "No tienen la misma edad\n";

    if (p1 < p2)
        cout << "Ana es menor que Luis\n";

    cout << p1 << endl;
    cout << p2 << endl;

    return 0;
}