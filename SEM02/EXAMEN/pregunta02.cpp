#include <iostream>
using namespace std;
int main(){
    int M, x;
    cout << "Ingrese cantidad de consultas: ";
    cin >> M;
    for(int i = 1; i <= M; i++){
        cout << "Ingrese x: ";
        cin >> x;
        int y = x;
        if(y < 0) y = -y;   
        int suma = 0, temp = y;
        if(temp == 0) suma = 0;
        while(temp > 0){
            suma += temp % 10;
            temp /= 10;
        }
        int dig = 0;
        temp = y;
        if(temp == 0) dig = 1;
        while(temp > 0){
            dig++;
            temp /= 10;
        }
        if(suma % 2 == 0 && x % 4 == 0)
            cout << "A";
        else if(suma % 2 == 1 && x % 6 == 0)
            cout << "B";
        else if(dig == 3)
            cout << "C";
        else
            cout << "D";

        cout << endl;
    }
    return 0;
}
