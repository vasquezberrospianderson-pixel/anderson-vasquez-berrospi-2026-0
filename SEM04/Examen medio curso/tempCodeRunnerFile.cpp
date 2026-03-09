//==================== BITÁCORA IA ====================
//Herramienta IA usada: ChatGPT
//Objetivo del uso: Entender como usar memoria dinamica y sobre todo como darle orden o sentido amis ideas.

//Preguntas que hice a la IA (resumen):
//1) Quiero que me ayudeas a hacer un codigo yo te voy dando las ideas y partes de codigo y tu me indicas si esta bien y si cumplen con lo que deve cumplir el codigo con las especificaciones que te pase.
//2) Crees que lo que estoy haciendo esta bien o dime que falta si puedo aumentar cosas para ver si puedo mejorar el codigo no quiero que tu lo agas sino que me digas que hacer para poder mejorar.
//3) quiero que me ayudes a ver si mi codigo esta bien echo o que me ayudes a ordenarlo para que tenga una estructura buena y que no sea dificil de entender.
//Qué sugerencias acepté y por qué:
//- Acepte la sugerencia de que juntara todo el codigo en 1 como lo hicimos paso a paso que juntara mis ideas con su ayuda que le diera orden para luego yo poder compararlo con mi codigo final y si el mimo tenia fallas me diga en que partes y que me ayudara a corregirlas.
//- tambien acepte en que me ayudara en que cosas devo cambiar ya que mi cogigo no era bueno tenia sentido pero no un orden y una estructura clara entonces lo que iso la IA es ayudrme a ordenarlo por eso se ve bonito el codigo.
//Qué sugerencias rechacé y por qué:
//- Rechaze la sugerencia de que la IA me de cada paso a paso sin nada de aporte de mi parte, la rechaze porque no queria que lo aga todo la IA me ayude si pero no hiso todo el codigo hiso partes que aun no domino.

//Test manual diseñado por mí:
//Entrada (pasos/comandos):
//- agrager 5 libros cada uno con su id, autor, año 
//- agregar 3 usuarios cada uno con su id, nombre y carrera.
//- prestar libro a un usuario que este registrado.
//- busqueda del libro.
//- que el usuario pida ver os libres que estan prestados para que no pueda pedir prestado ese libro.
//Salida esperada:
//- los libros son agragados correctamente.
//- usuarios registrados correctamente.
//- prestarel libro y si algun otro lo quiere ya no estara disponible.
//- hacer la busqueda con su id y nombre de cada libro en caso de no ingresar los datos correctamente no mostrar el libro.
//- mostrar los libros prestados con todos sus datos.
//Nota de autoría:
//Declaro que entiendo el código entregado no en su totalidad y puedo explicarlo no de manera fluida pero si puedo ser capas entender y saber que decir.
//====================================================

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// ================= STRUCTS =================

struct Libro {
    int id;
    string titulo;
    string autor;
    int anio;
    bool disponible;
};

struct Usuario {
    int id;
    string nombre;
    string carrera;
};

struct Prestamo {
    int idUsuario;
    int idLibro;
};

// ================= FUNCIONES DE BUSQUEDA =================

Libro* buscarLibroPorId(Libro* libros, int cant, int id) {
    for (int i = 0; i < cant; i++) {
        if (libros[i].id == id)
            return &libros[i];
    }
    return nullptr;
}

Usuario* buscarUsuarioPorId(Usuario* usuarios, int cant, int id) {
    for (int i = 0; i < cant; i++) {
        if (usuarios[i].id == id)
            return &usuarios[i];
    }
    return nullptr;
}

// ================= LIBROS =================

void agregarLibro(Libro*& libros, int& cant, int& cap) {
    Libro nuevo;

    cout << "ID del libro: ";
    cin >> nuevo.id;

    if (buscarLibroPorId(libros, cant, nuevo.id) != nullptr) {
        cout << "Error: ID repetido.\n";
        return;
    }

    cin.ignore();
    cout << "Titulo: ";
    getline(cin, nuevo.titulo);
    cout << "Autor: ";
    getline(cin, nuevo.autor);
    cout << "Anio: ";
    cin >> nuevo.anio;

    nuevo.disponible = true;

    if (cant == cap) {
        cap *= 2;
        Libro* nuevoArr = new Libro[cap];
        for (int i = 0; i < cant; i++)
            nuevoArr[i] = libros[i];
        delete[] libros;
        libros = nuevoArr;
    }

    libros[cant++] = nuevo;
    cout << "Libro agregado correctamente.\n";
}

void listarLibros(Libro* libros, int cant) {
    if (cant == 0) {
        cout << "No hay libros registrados.\n";
        return;
    }

    for (int i = 0; i < cant; i++) {
        cout << "ID: " << libros[i].id
             << " | " << libros[i].titulo
             << " | " << libros[i].autor
             << " | " << libros[i].anio
             << " | Disponible: "
             << (libros[i].disponible ? "Si" : "No") << endl;
    }
}

// ================= USUARIOS =================

void agregarUsuario(Usuario*& usuarios, int& cant, int& cap) {
    Usuario nuevo;

    cout << "ID del usuario: ";
    cin >> nuevo.id;

    if (buscarUsuarioPorId(usuarios, cant, nuevo.id) != nullptr) {
        cout << "Error: ID repetido.\n";
        return;
    }

    cin.ignore();
    cout << "Nombre: ";
    getline(cin, nuevo.nombre);
    cout << "Carrera: ";
    getline(cin, nuevo.carrera);

    if (cant == cap) {
        cap *= 2;
        Usuario* nuevoArr = new Usuario[cap];
        for (int i = 0; i < cant; i++)
            nuevoArr[i] = usuarios[i];
        delete[] usuarios;
        usuarios = nuevoArr;
    }

    usuarios[cant++] = nuevo;
    cout << "Usuario agregado correctamente.\n";
}

void listarUsuarios(Usuario* usuarios, int cant) {
    if (cant == 0) {
        cout << "No hay usuarios registrados.\n";
        return;
    }

    for (int i = 0; i < cant; i++) {
        cout << "ID: " << usuarios[i].id
             << " | " << usuarios[i].nombre
             << " | " << usuarios[i].carrera << endl;
    }
}

// ================= PRESTAMOS =================

void prestarLibro(Libro* libros, int cantLibros,
                  Usuario* usuarios, int cantUsuarios,
                  Prestamo*& prestamos, int& cantPrestamos, int& capPrestamos) {

    int idUsuario, idLibro;
    cout << "ID Usuario: ";
    cin >> idUsuario;
    cout << "ID Libro: ";
    cin >> idLibro;

    Usuario* u = buscarUsuarioPorId(usuarios, cantUsuarios, idUsuario);
    Libro* l = buscarLibroPorId(libros, cantLibros, idLibro);

    if (!u || !l) {
        cout << "Usuario o libro inexistente.\n";
        return;
    }

    if (!l->disponible) {
        cout << "Libro no disponible.\n";
        return;
    }

    if (cantPrestamos == capPrestamos) {
        capPrestamos *= 2;
        Prestamo* nuevoArr = new Prestamo[capPrestamos];
        for (int i = 0; i < cantPrestamos; i++)
            nuevoArr[i] = prestamos[i];
        delete[] prestamos;
        prestamos = nuevoArr;
    }

    prestamos[cantPrestamos++] = {idUsuario, idLibro};
    l->disponible = false;

    cout << "Prestamo registrado.\n";
}

void devolverLibro(Libro* libros, int cantLibros,
                   Prestamo* prestamos, int& cantPrestamos) {

    int idLibro;
    cout << "ID del libro a devolver: ";
    cin >> idLibro;

    for (int i = 0; i < cantPrestamos; i++) {
        if (prestamos[i].idLibro == idLibro) {
            Libro* l = buscarLibroPorId(libros, cantLibros, idLibro);
            if (l) l->disponible = true;

            for (int j = i; j < cantPrestamos - 1; j++)
                prestamos[j] = prestamos[j + 1];

            cantPrestamos--;
            cout << "Libro devuelto.\n";
            return;
        }
    }

    cout << "No existe prestamo activo.\n";
}

// ================= CONSULTAS =================

string aMinusculas(string s) {
    for (char& c : s)
        c = tolower(c);
    return s;
}

void buscarLibrosTexto(Libro* libros, int cant) {
    cin.ignore();
    string texto;
    cout << "Texto a buscar: ";
    getline(cin, texto);
    texto = aMinusculas(texto);

    bool encontrado = false;
    for (int i = 0; i < cant; i++) {
        if (aMinusculas(libros[i].titulo).find(texto) != string::npos ||
            aMinusculas(libros[i].autor).find(texto) != string::npos) {

            cout << libros[i].id << " - "
                 << libros[i].titulo << " - "
                 << libros[i].autor << endl;
            encontrado = true;
        }
    }

    if (!encontrado)
        cout << "No se encontraron resultados.\n";
}

void mostrarPrestamos(Prestamo* prestamos, int cantPrestamos,
                      Libro* libros, int cantLibros,
                      Usuario* usuarios, int cantUsuarios) {

    if (cantPrestamos == 0) {
        cout << "No hay prestamos activos.\n";
        return;
    }

    for (int i = 0; i < cantPrestamos; i++) {
        Libro* l = buscarLibroPorId(libros, cantLibros, prestamos[i].idLibro);
        Usuario* u = buscarUsuarioPorId(usuarios, cantUsuarios, prestamos[i].idUsuario);

        if (l && u) {
            cout << "Usuario: " << u->nombre
                 << " | Libro: " << l->titulo << endl;
        }
    }
}

// ================= MAIN =================

int main() {
    int capLibros = 5, cantLibros = 0;
    Libro* libros = new Libro[capLibros];

    int capUsuarios = 3, cantUsuarios = 0;
    Usuario* usuarios = new Usuario[capUsuarios];

    int capPrestamos = 5, cantPrestamos = 0;
    Prestamo* prestamos = new Prestamo[capPrestamos];

    int op;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Agregar libro\n";
        cout << "2. Listar libros\n";
        cout << "3. Agregar usuario\n";
        cout << "4. Listar usuarios\n";
        cout << "5. Prestar libro\n";
        cout << "6. Devolver libro\n";
        cout << "7. Buscar libro por texto\n";
        cout << "8. Mostrar prestamos\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> op;

        switch (op) {
            case 1: agregarLibro(libros, cantLibros, capLibros); break;
            case 2: listarLibros(libros, cantLibros); break;
            case 3: agregarUsuario(usuarios, cantUsuarios, capUsuarios); break;
            case 4: listarUsuarios(usuarios, cantUsuarios); break;
            case 5: prestarLibro(libros, cantLibros, usuarios, cantUsuarios,
                                 prestamos, cantPrestamos, capPrestamos); break;
            case 6: devolverLibro(libros, cantLibros, prestamos, cantPrestamos); break;
            case 7: buscarLibrosTexto(libros, cantLibros); break;
            case 8: mostrarPrestamos(prestamos, cantPrestamos,
                                     libros, cantLibros,
                                     usuarios, cantUsuarios); break;
        }
    } while (op != 0);

    delete[] libros;
    delete[] usuarios;
    delete[] prestamos;

    return 0;
}
