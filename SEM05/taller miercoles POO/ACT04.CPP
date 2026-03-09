#include <iostream>
using namespace std;

class Celular {
private:
    string marca;
    string modelo;
    int bateria;
public:
// 1: por defecto
Celular (){
    marca ="Desconocido";
    modelo = "Generico";
    bateria = 100;
}
// 2: con 2 parametros
Celular (string mar, string mod){
    marca = mar;
    modelo = mod;
    bateria = 100;
}
// 3: con tres parametros
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
// 4: cada constructor con su informacion
int main(){
    Celular cel1;
    Celular cel2("samsung", "A56");
    Celular cel3("iphone", "x8", 100);

    cel1.mostrarinfo();
    cel2.mostrarinfo();
    cel3.mostrarinfo();

    return 0;
}
// no hubo error solo el de sintaxis que pude solucionar no con ayuda de IA sino leyendo un poco de teoria
// no hay errores porque lo que estoy haciendo es usar el mismo codigo solo en cada actividad aumento lo que piden