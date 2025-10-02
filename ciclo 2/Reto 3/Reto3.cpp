// Archivo CPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

//  ------------ Creacion de las entidades: -------------------------
// Autor:
struct Autor {
    int id;
    string nombre;
    string nacionalidad;
};

// Estudiantes:
struct Estudiante {
    int id;
    string nombre;
    string grado;
};

// Libro:
struct Libro {
    int id;
    string titulo;
    string isbn;
    int anio_publicacion;
    int id_autor;
};

// Prestamo
struct Prestamo {
    int id;
    int id_libro;
    int id_estudiante;
    string fecha_prestamo;
    string fecha_devolucion;
};

//  ------------- Clase Base de Datos --------------------------
class Biblioteca {
public:
    vector < Autor > autores;
    vector < Estudiante > estudiantes;
    vector < Libro > libros;
    vector < Prestamo > prestamos;

    //  ----------- Crud de Libros -------------------------
    void agregarLibro(Libro l) {
        for (auto &lib : libros) {
            if (lib.id == l.id) {
                cout << "Error: un libro con el mismo ID ya existe. \n";
                return;
            }
        }
        libros.push_back(l);
        cout << "El libro ha sido agregado correctamente. \n";
    }

    void listarLibros() {
        if (libros.empty()) {
            cout << "No hay libros registrados. \n";
            return;
        }
        for (auto &lib : libros) {
            cout << "ID: " << lib.id << " ----- Titulo: " << lib.titulo
            << " ----- ISBN: " << lib.isbn
            << " ----- Anio: " << lib.anio_publicacion
            << " ----- ID del Autor: " << lib.id_autor << endl;
        }
    }

//  CRUD: operaciones basicas que se aplican sobre bases de datos.
//  REpresenta las fucniones minimas necesarias que un sistema debe de tener
//  ------------- Crud de los Autores -----------------------
    void agregarAutor(Autor a) {
        autores.push_back(a);
        cout << "El autor ha sido agregado. \n";
    } 

    void listarAutores() {
        if (autores.empty()) {
            cout << "No hay autores registrados. \n";
            return;
        }
        for (auto &a : autores) {
            cout << "ID: " << a.id << " ----- Nombre: " << a.nombre
            << " ------ Nacionalidad: " << a.nacionalidad << endl;
        }
    }

    // ------------------------ Crud de los Estudiantes ------------
    void agregarEstudiante(Estudiante e) {
        estudiantes.push_back(e);
        cout << "El estudiante ha sido agregado.\n";
    }

    void listarEstudiantes() {
        if (estudiantes.empty()) {
            cout << "No hay estudiantes registrados.\n";
            return;
        }
        for (auto &e : estudiantes) {
            cout << "ID: " << e.id << " ----- Nombre: " << e.nombre
                 << " ----- Grado: " << e.grado << endl;
        }
    }

    // ------------------ Crud de los Prestamos --------------------
        void agregarPrestamo(Prestamo p) {
        for (auto &pr : prestamos) {
            if (pr.id_libro == p.id_libro && pr.fecha_devolucion == "") {
                cout << "Error: este libro ya se enceuntra prestado.\n";
                return;
            }
        }
        prestamos.push_back(p);
        cout << "El prestamo ha sido registrado.\n";
    }

    void listarPrestamos() {
        if (prestamos.empty()) {
            cout << "No hay prestamos registrados.\n";
            return;
        }
        for (auto &p : prestamos) {
            cout << "ID: " << p.id
                 << " ----- LibroID: " << p.id_libro
                 << " ----- EstudianteID: " << p.id_estudiante
                 << " ----- Fecha Prestamo: " << p.fecha_prestamo
                 << " ----- Fecha Devolucion: " << p.fecha_devolucion << endl;
        }
    }

    // ------------------ Consultas -------------------------
     void librosPrestadosPorEstudiante(int id_estudiante) {
        cout << "Libros prestados por estudiante " << id_estudiante << ":\n";
        for (auto &p : prestamos) {
            if (p.id_estudiante == id_estudiante && p.fecha_devolucion == "") {
                for (auto &lib : libros) {
                    if (lib.id == p.id_libro) {
                        cout << " - " << lib.titulo << endl;
                    }
                }
            }
        }
    }

    // ------------------ Presistencia -----------------------------
    void guardarDatos() {
        ofstream archAutores("autores.txt");
        for (auto &a : autores) {
            archAutores << a.id << "," << a.nombre << "," << a.nacionalidad << "\n";
        }
        archAutores.close();

        ofstream archEstudiantes("estudiantes.txt");
        for (auto &e : estudiantes) {
            archEstudiantes << e.id << "," << e.nombre << "," << e.grado << "\n";
        }
        archEstudiantes.close();

        ofstream archLibros("libros.txt");
        for (auto &l : libros) {
            archLibros << l.id << "," << l.titulo << "," << l.isbn << ","
                       << l.anio_publicacion << "," << l.id_autor << "\n";
        }
        archLibros.close();

        ofstream archPrestamos("prestamos.txt");
        for (auto &p : prestamos) {
            archPrestamos << p.id << "," << p.id_libro << "," << p.id_estudiante << ","
                          << p.fecha_prestamo << "," << p.fecha_devolucion << "\n";
        }
        archPrestamos.close();

        cout << "Datos guardados en archivos.\n";
    }

};

// Menu interactivo (int main)
int main() {
    Biblioteca db;
    int opcion;

    do {
        cout << "\n----- Menu inicial -----\n";
        cout << "1. Agregar Libro\n";
        cout << "2. Listar Libros\n";
        cout << "3. Agregar Autor\n";
        cout << "4. Listar Autores\n";
        cout << "5. Agregar Estudiante\n";
        cout << "6. Listar Estudiantes\n";
        cout << "7. Registrar Prestamo\n";
        cout << "8. Listar Prestamos\n";
        cout << "9. Consultar libros prestados por estudiante\n";
        cout << "10. Guardar datos en archivos\n";
        cout << "0. Salir\n";
        cout << "Seleccione opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                Libro l;
                cout << "ID: "; cin >> l.id;
                cin.ignore();
                cout << "Titulo: "; getline(cin, l.titulo);
                cout << "ISBN: "; getline(cin, l.isbn);
                cout << "Año: "; cin >> l.anio_publicacion;
                cout << "ID Autor: "; cin >> l.id_autor;
                db.agregarLibro(l);
                break;
            }
            case 2: db.listarLibros(); break;
            case 3: {
                Autor a;
                cout << "ID: "; cin >> a.id;
                cin.ignore();
                cout << "Nombre: "; getline(cin, a.nombre);
                cout << "Nacionalidad: "; getline(cin, a.nacionalidad);
                db.agregarAutor(a);
                break;
            }
            case 4: db.listarAutores(); break;
            case 5: {
                Estudiante e;
                cout << "ID: "; cin >> e.id;
                cin.ignore();
                cout << "Nombre: "; getline(cin, e.nombre);
                cout << "Grado: "; getline(cin, e.grado);
                db.agregarEstudiante(e);
                break;
            }
            case 6: db.listarEstudiantes(); break;
            case 7: {
                Prestamo p;
                cout << "ID: "; cin >> p.id;
                cout << "ID Libro: "; cin >> p.id_libro;
                cout << "ID Estudiante: "; cin >> p.id_estudiante;
                cin.ignore();
                cout << "Fecha Prestamo: "; getline(cin, p.fecha_prestamo);
                cout << "Fecha Devolucion (vacio si no se ha devuelto): ";
                getline(cin, p.fecha_devolucion);
                db.agregarPrestamo(p);
                break;
            }
            case 8: db.listarPrestamos(); break;
            case 9: {
                int idE;
                cout << "Ingrese ID estudiante: ";
                cin >> idE;
                db.librosPrestadosPorEstudiante(idE);
                break;
            }
            case 10: db.guardarDatos(); break;
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida.\n"; break;
        }
    } while (opcion != 0);

    return 0;
}

    

