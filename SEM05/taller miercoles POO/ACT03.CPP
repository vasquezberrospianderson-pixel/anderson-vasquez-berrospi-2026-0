#include <iostream>
using namespace std;

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

string getmarca(){
    return marca;
}

string getmodelo(){
    return modelo;
}

int getbateria(){
    return bateria;
}
// 1 y 2
void setmarca(string mar){
    this -> marca = mar;
}

void setmodelo(string mod){
    this -> modelo = mod;
}

void setbateria(int ba){
    if (bateria>=0 && bateria <=100){
        this -> bateria = ba;
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
// El codigo sigue funcionando pero con el mismo error que la 2