#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>
#include <limits>
#include <cctype>

using namespace std;

//FUNCIONES DE VALIDACION PARA QUE NO HAYA FALLAS AUNQUE AUN HAY PERO SON MENOS GRACIAS ALA IA

bool soloNumeros(string s){

    for(char c : s)
        if(!isdigit(c))
            return false;

    return true;
}

bool validarFecha(string f){

    if(f.size()!=10) return false;

    if(f[4]!='-' || f[7]!='-') return false;

    for(int i=0;i<10;i++){

        if(i==4 || i==7) continue;

        if(!isdigit(f[i])) return false;
    }

    int mes = stoi(f.substr(5,2));
    int dia = stoi(f.substr(8,2));

    if(mes < 1 || mes > 12) return false;
    if(dia < 1 || dia > 31) return false;

    return true;
}

bool validarHora(string h){

    if(h.size()!=5) return false;

    if(h[2]!=':') return false;

    for(int i=0;i<5;i++){

        if(i==2) continue;

        if(!isdigit(h[i])) return false;
    }

    int hora = stoi(h.substr(0,2));
    int min = stoi(h.substr(3,2));

    if(hora < 0 || hora > 23) return false;
    if(min < 0 || min > 59) return false;

    return true;
}

//EXCEPCION PERSONALIZADA

class EntidadNoEncontrada : public runtime_error{

public:

    EntidadNoEncontrada(string msg)
        : runtime_error(msg){}
};

//PERSONA

class Persona{

protected:

    string nombre;

public:

    Persona(string n){
        nombre=n;
    }

    virtual void mostrar() const{

        cout<<"Nombre: "<<nombre<<endl;
    }

    virtual ~Persona(){}
};

//ENTRADA HISTORIA

class EntradaHistoria{

public:

    string fecha;
    string nota;

    EntradaHistoria(string f,string n){

        fecha=f;
        nota=n;
    }
};

//HISTORIA CLINICA

class HistoriaClinica{

private:

    vector<EntradaHistoria> entradas;

public:

    void agregarEntrada(string f,string n){

        entradas.push_back(EntradaHistoria(f,n));
    }
};

//PACIENTE

class Paciente : public Persona{

private:

    string dni;
    int edad;
    string telefono;
    HistoriaClinica historia;

public:

    Paciente(string n,string d,int e,string t)
        : Persona(n){

        if(d.length()!=8 || !soloNumeros(d))
            throw invalid_argument("DNI invalido");

        if(e<0 || e>120)
            throw invalid_argument("Edad invalida");

        if(t.length()!=9 || !soloNumeros(t))
            throw invalid_argument("Telefono invalido");

        dni=d;
        edad=e;
        telefono=t;
    }

    string getDni() const{
        return dni;
    }

    void mostrar() const override{

        cout<<"Paciente: "<<nombre
            <<" DNI: "<<dni
            <<" Edad: "<<edad
            <<" Telefono: "<<telefono<<endl;
    }
};

//DOCTOR

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

    string getCodigo() const{
        return codigo;
    }

    string getEspecialidad() const{
        return especialidad;
    }

    void mostrar() const override{

        cout<<"Doctor: "<<nombre
            <<" Codigo: "<<codigo
            <<" Especialidad: "<<especialidad
            <<" Tarifa: "<<tarifa<<endl;
    }
};

//CITA

class Cita{

private:

    int id;
    Paciente* paciente;
    Doctor* doctor;
    string fecha;
    string hora;
    string motivo;
    string estado;

public:

    Cita(int i,Paciente* p,Doctor* d,string f,string h,string m){

        id=i;
        paciente=p;
        doctor=d;
        fecha=f;
        hora=h;
        motivo=m;
        estado="Activa";
    }

    int getId(){ return id; }

    Paciente* getPaciente(){ return paciente; }

    Doctor* getDoctor(){ return doctor; }

    string getFecha(){ return fecha; }

    string getHora(){ return hora; }

    void cancelar(){
        estado="Cancelada";
    }

    void mostrar(){

        cout<<"Cita "<<id
            <<" Paciente "<<paciente->getDni()
            <<" Doctor "<<doctor->getCodigo()
            <<" "<<fecha<<" "<<hora
            <<" Estado "<<estado<<endl;
    }
};

//CLINICA

class Clinica{

private:

    vector<unique_ptr<Paciente>> pacientes;
    vector<unique_ptr<Doctor>> doctores;
    vector<Cita> citas;

    int contadorCitas=1;

public:

    Paciente* buscarPaciente(string dni){

        for(auto& p : pacientes)
            if(p->getDni()==dni)
                return p.get();

        throw EntidadNoEncontrada("Paciente no encontrado");
    }

    Doctor* buscarDoctor(string codigo){

        for(auto& d : doctores)
            if(d->getCodigo()==codigo)
                return d.get();

        throw EntidadNoEncontrada("Doctor no encontrado");
    }

    void registrarPaciente(){

        string nombre,dni,telefono;
        int edad;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout<<"Nombre: ";
        getline(cin,nombre);

        cout<<"DNI: ";
        cin>>dni;

        cout<<"Edad: ";
        cin>>edad;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            throw invalid_argument("Edad debe ser numerica");
        }

        cout<<"Telefono: ";
        cin>>telefono;

        for(auto& p : pacientes)
            if(p->getDni()==dni)
                throw runtime_error("DNI ya registrado");

        pacientes.push_back(
            make_unique<Paciente>(nombre,dni,edad,telefono)
        );

        cout<<"Paciente registrado\n";
    }

    void registrarDoctor(){

        string nombre,codigo,esp;
        double tarifa;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout<<"Nombre: ";
        getline(cin,nombre);

        cout<<"Codigo: ";
        cin>>codigo;

        cout<<"Especialidad: ";
        cin>>esp;

        cout<<"Tarifa: ";
        cin>>tarifa;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            throw invalid_argument("Tarifa debe ser numerica");
        }

        for(auto& d : doctores)
            if(d->getCodigo()==codigo)
                throw runtime_error("Codigo de doctor ya existe");

        doctores.push_back(
            make_unique<Doctor>(nombre,codigo,esp,tarifa)
        );

        cout<<"Doctor registrado\n";
    }

    // para la fecha deve ser maso menos en este formato: 2026-03-05, de otras maneras no acepta al igual que la hora un 
    // ejemplo: 12:30

    void agendarCita(){

        string dni,codigo,fecha,hora,motivo;

        cout<<"DNI paciente: ";
        cin>>dni;

        cout<<"Codigo doctor: ";
        cin>>codigo;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout<<"Fecha (YYYY-MM-DD): ";
        getline(cin,fecha);

        if(!validarFecha(fecha))
            throw invalid_argument("Formato fecha invalido");

        cout<<"Hora (HH:MM): ";
        getline(cin,hora);

        if(!validarHora(hora))
            throw invalid_argument("Formato hora invalido");

        cout<<"Motivo: ";
        getline(cin,motivo);

        Paciente* p = buscarPaciente(dni);
        Doctor* d = buscarDoctor(codigo);

        for(auto& c : citas){

            if(c.getDoctor()==d &&
               c.getFecha()==fecha &&
               c.getHora()==hora)

                throw runtime_error("Cita duplicada");
        }

        citas.push_back(
            Cita(contadorCitas++,p,d,fecha,hora,motivo)
        );

        cout<<"Cita registrada\n";
    }

    void cancelarCita(){

        int id;

        cout<<"ID cita: ";
        cin>>id;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            throw invalid_argument("ID invalido");
        }

        for(auto& c : citas){

            if(c.getId()==id){

                c.cancelar();
                cout<<"Cita cancelada\n";
                return;
            }
        }

        throw runtime_error("Cita no encontrada");
    }

    void listarCitasPaciente(){

        string dni;

        cout<<"DNI paciente: ";
        cin>>dni;

        if(dni.length()!=8 || !soloNumeros(dni))
            throw invalid_argument("DNI invalido");

        for(auto& c : citas)

            if(c.getPaciente()->getDni()==dni)
                c.mostrar();
    }

    void listarCitasDoctor(){

        string codigo;

        cout<<"Codigo doctor: ";
        cin>>codigo;

        for(auto& c : citas)

            if(c.getDoctor()->getCodigo()==codigo)
                c.mostrar();
    }

    vector<Cita>& getCitas(){
        return citas;
    }
};

//REPORTE ES CASI LO MISMO QUE LISTAR CITA DEL DOCTOR Y CITA DEL PACIENTE NO IGUALES PERO TIENEN COMO FIBNALIDAD CASI MOSTRAR LA MISMA INFORMACION

class Reporte{

public:

    static void generarPorEspecialidad(Clinica& c){

        cout<<"\n--- REPORTE DE CITAS ---\n";

        for(auto& cita : c.getCitas())
            cita.mostrar();
    }
};

//MAIN

int main(){

    Clinica clinica;
    int op;

    do{

        cout<<"\n--- CLINICA SALUD+ ---\n";
        cout<<"1 Registrar paciente\n";
        cout<<"2 Registrar doctor\n";
        cout<<"3 Agendar cita\n";
        cout<<"4 Cancelar cita\n";
        cout<<"5 Listar citas paciente\n";
        cout<<"6 Listar citas doctor\n";
        cout<<"7 Reporte\n";
        cout<<"8 Salir\n";

        cin>>op;

        if(cin.fail()){

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            cout<<"Ingrese un numero valido\n";
            continue;
        }

        try{

            if(op<1 || op>8)
                throw out_of_range("Opcion fuera de rango");

            switch(op){

                case 1: clinica.registrarPaciente(); break;
                case 2: clinica.registrarDoctor(); break;
                case 3: clinica.agendarCita(); break;
                case 4: clinica.cancelarCita(); break;
                case 5: clinica.listarCitasPaciente(); break;
                case 6: clinica.listarCitasDoctor(); break;
                case 7: Reporte::generarPorEspecialidad(clinica); break;
            }

        }
        catch(exception& e){

            cout<<"Error: "<<e.what()<<endl;
        }

    }while(op!=8);

}