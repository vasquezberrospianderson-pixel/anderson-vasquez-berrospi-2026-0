#include <iostream>
using namespace std;
int main() {
    int asistencia[3][5];
    int totalAula = 0;
    cout << "Ingrese la asistencia (1 = asistio, 0 = no asistio):\n";
    for (int i = 0; i < 3; i++) {
        cout << "\nEstudiante " << i + 1 << endl;
        for (int j = 0; j < 5; j++) {
            do {
                cout << "Dia " << j + 1 << ": ";
                cin >> asistencia[i][j];
                if (asistencia[i][j] != 0 && asistencia[i][j] != 1) {
                    cout << "ERROR. En el Dia " << j + 1
                         << " ingrese solo 0 o 1.\n";
                }
            } while (asistencia[i][j] != 0 && asistencia[i][j] != 1);
        }
    }
    for (int i = 0; i < 3; i++) {
        int totalEstudiante = 0;
        bool perfecta = true;
        for (int j = 0; j < 5; j++) {
            totalEstudiante += asistencia[i][j];
            totalAula += asistencia[i][j];
            if (asistencia[i][j] == 0) {
                perfecta = false;
            }
        }
        cout << "\nEstudiante " << i + 1
             << " - Total asistencias: " << totalEstudiante << endl;
        if (perfecta) {
            cout << "Asistencia perfecta" << endl;
        }
    }
    cout << "\nTotal de asistencias del aula: " << totalAula << endl;
    return 0;
}


