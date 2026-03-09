// 1 Crea una clase llamada Celular con los atributos: marca (string), modelo (string) y bateria (int).
#include <iostream>
using namespace std;

class Celular {
    string marca;
    string modelo;
    int bateria;
public:
Celular (string mar, string mod, int ba){
marca = mar;
modelo = mod;
bateria = ba;
}
//3 Crea un método mostrarInfo() que imprima la información del celular.
void mostrarinfo() {
    cout<< marca <<" "<< modelo << " " <<bateria<< endl;
}
};

//2 Crea 2 objetos (cel1 y cel2) con valores distintos.

int main() {
    Celular cel1("samsung", "A56", 60);
    Celular cel2("iphone", "x8", 60);
// 4 Llama mostrarInfo() para los 2 objetos.
    cel1.mostrarinfo();
    cel2.mostrarinfo();
    return 0;
}
