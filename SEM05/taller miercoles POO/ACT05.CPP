#include <iostream>
using namespace std;
// CLASE A
// 1: crear la clase persona
class persona{
private:
    string nombre;
    int edad;
public:
    persona(string nom, int edad){
        nombre = nom;
        edad = edad;
    }
// 2: get/set
string getnombre(){
    return nombre;
}

int getedad(){
    return edad;
}

void setnombre(string nom){
    nombre = nom;
}

void setedad(int edad){
    if(edad>0){
    edad = edad;
    }else {
        cout<<"ERRROR";
    }
}

void mostrardatos() const {
    cout<<nombre<<" "<<edad<<endl;
}
};

// CLASE DERIVADA
class Estudiante : public persona {
private: 
    string carrera;
public:
    Estudiante(string nombre, int edad, string carrera)
        : persona(nombre, edad){
            carrera = carrera;
    }
    void Estudiar() const{
        cout<<"El estudiante estudia: "<<carrera<<endl;
    }
};

// clase derivada profesor
class Profesor : public persona{
private:
    string materia;
public:
    Profesor(string nombre, int edad, string materia)
        : persona(nombre, edad){
            materia = materia;
        }
    void ensenar() const{
        cout<<"El profesor ensena: "<<materia<<endl;
    }
};


int main (){
    Estudiante est("ANDERSON", 19, "SISTEMAS");
    Profesor prof("angel", 35, "PROGRAMACIÓN");

    cout<<"datos del estudiante"<<endl,
    est.mostrardatos();
    est.Estudiar();

    cout<<"Datos del profesor"<<endl;
    prof.mostrardatos();
    prof.ensenar();
    return 0;
}
// Despues de las pruebas hay error de que no salen los datos correctamente por pantalla por lo que se hasta ahora no sabria solucionar ese error.