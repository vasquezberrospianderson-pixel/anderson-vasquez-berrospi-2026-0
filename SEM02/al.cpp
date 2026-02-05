#include <iostream>
using namespace std;
int main() {
    int numeros[] = {-3, 2, 5, 8, -1, 10, 7, 4};
    int n=8;
    for (int i=0; i<n; i++){
        if (numeros[i] < 0){
            continue;
        }
        if (numeros[i] % 2 !=0){
            continue;
        }
        cout<< numeros[i]<<""<<endl;
    }
    return 0;
}