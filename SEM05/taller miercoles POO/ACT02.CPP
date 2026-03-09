#include <iostream>
using namespace std;
// 1 modificar la clase para que sea privada
class Celular {
private:
    string marca;
    string modelo;
    int bateria;
public:
Celular (string mar, string mod, int ba){
marca = mar;
modelo = mod;
bateria = ba;
}
// getters para marca, modelo y bateria
string getmarca(){
    return marca;
}

string getmodelo(){
    return modelo;
}

int getbateria(){
    return bateria;
}
// 3 seters con validacion
void setmarca(string mar){
    marca = mar;
}

void setmodelo(string mod){
    modelo = mod;
}
// 4 bateria solo entre 0 y 100
void setbateria(int ba){
    if (bateria>=0 && bateria <=100){
        bateria = ba;
    }else {
        cout<<"ERROR";
    }
}

void mostrarinfo() {
    cout<< marca <<" "<< modelo << " " <<bateria << endl;
}

};

int main(){
    Celular cel1("samsung", "A56", 150);
    Celular cel2("iphone", "x8", -20);

    cel1.mostrarinfo();
    cel2.mostrarinfo();
    return 0;
}
// En este codigo al ejecutar sale la bateria como 150 a uno y como -20 a otro estuve intentando hacerlo pero no logro que saliera error
// Es lo maximo que pude llegar en la actividad 2 sin ayuda de la IA en cuanto errores solo hubo de que ponia mal las condiciones el codigo es caso lo mismo que el anterior.