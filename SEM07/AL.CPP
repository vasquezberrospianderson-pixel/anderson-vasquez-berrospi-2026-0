#include <iostream>
using namespace std;

class Vehiculo {
protected:
    string marca;
    int velocidad;
public:
    virtual void mover() = 0; // clase abstracta
    virtual ~Vehiculo() {}
};

class Auto : public Vehiculo {
public:
    void mover() override {
        cout << "El auto se está moviendo" << endl;
    }
};

int main() {
    Vehiculo* v = new Auto();
    v->mover(); // polimorfismo
    delete v;
}