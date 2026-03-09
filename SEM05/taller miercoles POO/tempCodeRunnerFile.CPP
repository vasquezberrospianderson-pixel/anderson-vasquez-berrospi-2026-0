#include <iostream>
using namespace std;
//clase base
class Vehiculo{
    string marca;
    float velocidadMAX;
public:
    Vehiculo(string marca, float vel){
        marca = marca;
        velocidadMAX = vel;
    }

void setMarca(string marca) {
        marca = marca;
    }

void setVelocidadMax(int velocidadMax) {
        velocidadMax = velocidadMax;
    }

string getMarca() {
        return marca;
    }

float getVelocidadMax() {
        return velocidadMAX;
    }
void mostrarinfo(){
    cout<<"marca: "<<marca<<" "<<"modelo:"<<endl;
}
};
// clase derivada carro
class Carro : public Vehiculo{
    int puertas;
public:
    Carro(string marca, float vel, int puertas)
    : Vehiculo(marca, vel){
        puertas = puertas;
    }
    void mostrarinfo(){
        Vehiculo::mostrarinfo();
        cout<<"prueba: "<<endl;
    }
};
// clase derivada moto
class Moto : public Vehiculo{
    int cilindraje;

public:
    Moto(string marca, int vel, int cilindraje)
    : Vehiculo(marca, vel){
        cilindraje = cilindraje;
    }

    void mostrarInfo() {
        Vehiculo::mostrarinfo();
        cout << "Cilindraje: " << cilindraje << " cc" << endl;
    }
};

int main(){

    Carro carro("Toyota", 180, 4);
    Moto moto("Yamaha", 220, 300);

    cout << "Datos del carro:" << endl;
    carro.mostrarinfo();

    cout << "Datos de la moto:" << endl;
    moto.mostrarInfo();

    return 0;
}
