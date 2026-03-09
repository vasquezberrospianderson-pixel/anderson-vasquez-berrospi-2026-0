#include<iostream>
using namespace std;
#include<vector>

class Persona{
protected:
    string nombre;

public:
    Persona(string n){
        nombre = n;
    }

    virtual void mostrar(){
        cout<<"Nombre: "<<nombre<<endl;
    }

    virtual ~Persona(){}
};


class Paciente : public Persona{
private:
    string dni;
    int edad;
    string telefono;

public:
    Paciente(string n,string d,int e,string t)
        : Persona(n){

        if(d.length()!=8)
            throw invalid_argument("DNI invalido");

        if(e<0 || e>120)
            throw invalid_argument("Edad invalida");

        dni=d;
        edad=e;
        telefono=t;
    }

    string getDni(){
        return dni;
    }
};

class Doctor : public Persona{
private:
    string codigo;
    string especialidad;
    double tarifa;

public:

    Doctor(string n,string c,string e,double t)
        : Persona(n){

        if(t<=0)
            throw invalid_argument("Tarifa invalida");

        codigo=c;
        especialidad=e;
        tarifa=t;
    }

    string getEspecialidad(){
        return especialidad;
    }
};

class Cita{
private:
    int id;
    Paciente* paciente;
    Doctor* doctor;
    string fecha;
    string hora;
    string motivo;

public:

    Cita(int i,Paciente* p,Doctor* d,string f,string h,string m){
        id=i;
        paciente=p;
        doctor=d;
        fecha=f;
        hora=h;
        motivo=m;
    }

    void mostrar(){
        cout<<"Cita "<<id<<" "<<fecha<<" "<<hora<<endl;
    }
};

class Clinica{

private:

    vector<Paciente> pacientes;
    vector<Doctor> doctores;
    vector<Cita> citas;

public:

    void registrarPaciente(Paciente p){
        pacientes.push_back(p);
    }

    void registrarDoctor(Doctor d){
        doctores.push_back(d);
    }

};

int main(){

    Clinica c;
    int op;

    do{

        cout<<"1 Registrar paciente"<<endl;
        cout<<"2 Registrar doctor"<<endl;
        cout<<"3 Agendar cita"<<endl;
        cout<<"4 Cancelar cita"<<endl;
        cout<<"5 Salir"<<endl;

        cin>>op;

        try{

            if(op<1 || op>5)
                throw out_of_range("Opcion invalida");

        }catch(exception &e){

            cout<<"Error: "<<e.what()<<endl;

        }

    }while(op!=5);
}