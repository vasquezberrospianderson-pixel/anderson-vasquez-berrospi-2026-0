#include <iostream>
using namespace std;

struct Persona {
    int edad;
    float altura;
};

int main() {
    Persona* p = new Persona;  
    cout << "Ingrese la edad: ";
    cin >> p->edad;

    cout << "Ingrese la altura: ";
    cin >> p->altura;

    cout << "Edad: " << p->edad << endl;
    cout << "Altura: " << p->altura << endl;

    delete p;       
    p = nullptr;

    return 0;
}
