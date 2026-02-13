int* crearNumero() {
    int* x = new int;
    return x;
}

int main() {
    int* p = crearNumero();
    delete p; // main libera la memoria
}



