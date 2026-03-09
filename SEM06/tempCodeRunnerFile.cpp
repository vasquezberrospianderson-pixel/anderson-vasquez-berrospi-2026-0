#include <iostream>
#include <vector>
using namespace std;
// 1: 
class Reporte; // declaración adelantada

class Vehiculo {
protected:
    int id;
    float velocidad;

public:
    Vehiculo(int id, float velocidad) : id(id), velocidad(velocidad) {}

    virtual void moverse() = 0; // método abstracto

    virtual void mostrarInfo() {
        cout << "ID: " << id << ", Velocidad: " << velocidad << " km/h" << endl;
    }

    virtual ~Vehiculo() {
        // destructor virtual
    }

    friend class Reporte; // clase amiga
};
//2
class Auto : public Vehiculo {
private:
    float consumo;

public:
    Auto(int id, float velocidad, float consumo)
        : Vehiculo(id, velocidad), consumo(consumo) {}

    void moverse() override {
        cout << "El auto se mueve por la carretera." << endl;
    }
};

class Drone : public Vehiculo {
private:
    float altura;

public:
    Drone(int id, float velocidad, float altura)
        : Vehiculo(id, velocidad), altura(altura) {}

    void moverse() override {
        cout << "El drone vuela por el aire." << endl;
    }
};

class Camion : public Vehiculo {
private:
    float carga;

public:
    Camion(int id, float velocidad, float carga)
        : Vehiculo(id, velocidad), carga(carga) {}

    void moverse() override {
        cout << "El camión se mueve transportando carga." << endl;
    }
};

//3

void ejemploPolimorfismoDinamico() {
    vector<Vehiculo*> flota;

    flota.push_back(new Auto(1, 80, 6.5));
    flota.push_back(new Drone(2, 40, 120));
    flota.push_back(new Camion(3, 60, 1000));

    for (Vehiculo* v : flota) {
        v->moverse();
        v->mostrarInfo();
        cout << "------------------" << endl;
    }

    for (Vehiculo* v : flota) {
        delete v;
    }
}

//4
template <typename T>
T calcularEficiencia(T consumo, T distancia) {
    return distancia / consumo;
}

//5
class Reporte {
public:
    void generarReporte(Vehiculo* v) {
        cout << "[REPORTE] ID: " << v->id
             << " | Velocidad: " << v->velocidad << endl;
    }
};