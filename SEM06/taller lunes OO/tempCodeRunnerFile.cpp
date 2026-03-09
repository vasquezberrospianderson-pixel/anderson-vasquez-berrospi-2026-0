#include <iostream>
#include <vector>
using namespace std;

// Declaración adelantada
class Reporte;


//PASO 1: Clase abstracta Vehiculo

class Vehiculo {
protected:
    int id;
    float velocidad;

public:
    Vehiculo(int id, float velocidad) : id(id), velocidad(velocidad) {}

    // Método virtual puro
    virtual void moverse() = 0;

    // Método virtual
    virtual void mostrarInfo() {
        cout << "ID: " << id
             << " | Velocidad: " << velocidad << " km/h" << endl;
    }

    // Destructor virtual
    virtual ~Vehiculo() {}

    // Clase amiga
    friend class Reporte;
};


//PASO 2: Clases derivadas


// AUTO
class Auto : public Vehiculo {
private:
    float consumo;

public:
    Auto(int id, float velocidad, float consumo)
        : Vehiculo(id, velocidad), consumo(consumo) {}

    void moverse() override {
        cout << "El auto se desplaza por carretera." << endl;
    }
};

// DRONE
class Drone : public Vehiculo {
private:
    float altura;

public:
    Drone(int id, float velocidad, float altura)
        : Vehiculo(id, velocidad), altura(altura) {}

    void moverse() override {
        cout << "El drone vuela en el aire." << endl;
    }
};

// CAMION
class Camion : public Vehiculo {
private:
    float carga;

public:
    Camion(int id, float velocidad, float carga)
        : Vehiculo(id, velocidad), carga(carga) {}

    void moverse() override {
        cout << "El camion transporta carga pesada." << endl;
    }
};


//PASO 4: Polimorfismo estático (Template)

template <typename T>
T calcularEficiencia(T consumo, T distancia) {
    return distancia / consumo;
}


//PASO 5: Clase amiga Reporte

class Reporte {
public:
    void generarReporte(Vehiculo* v) {
        cout << "[REPORTE] Vehículo ID: " << v->id
             << " | Velocidad: " << v->velocidad << " km/h" << endl;
    }
};


//PASO 3: Polimorfismo dinámico + MAIN

int main() {

    vector<Vehiculo*> flota;

    flota.push_back(new Auto(1, 90, 6.5));
    flota.push_back(new Drone(2, 50, 120));
    flota.push_back(new Camion(3, 70, 1500));

    cout << "=== MOVIMIENTO DE VEHICULOS ===" << endl;
    for (Vehiculo* v : flota) {
        v->moverse();
        v->mostrarInfo();
        cout << "-----------------------------" << endl;
    }

    cout << "\n=== EFICIENCIA (Polimorfismo estatico) ===" << endl;
    float eficiencia = calcularEficiencia(5.0f, 100.0f);
    cout << "Eficiencia calculada: " << eficiencia << endl;

    cout << "\n=== REPORTES ===" << endl;
    Reporte reporte;
    for (Vehiculo* v : flota) {
        reporte.generarReporte(v);
    }

    // Liberar memoria
    for (Vehiculo* v : flota) {
        delete v;
    }

    return 0;
}