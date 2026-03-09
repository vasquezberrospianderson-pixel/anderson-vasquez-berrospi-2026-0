#include <iostream>
using namespace std;
//1
class persona{
public:
    virtual void rol(){
        cout<<"SOY UNA PERSONA"<<endl;
    }
};
// 2
class Estudiante : public persona{
public:
    void rol(){
        cout<<"SOY ESTUDIANTE"<<endl;
    }
};
// 3

class Profesor : public persona{
public:
    void rol(){
        cout<<"SOY PROFESOR"<<endl;
    }
};
//4
int main(){
    persona* p1 = new Estudiante();
    persona* p2 = new Profesor();
// 5
    p1->rol();
    p2->rol();

    return 0;
}