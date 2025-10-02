// Archivo .h -> Descripcion y esqueleto

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//  ------------ Creacion de las entidades -------------------------
struct Autor {
    int id;
    string nombre;
    string nacionalidad;
};

struct Estudiante {
    int id;
    string nombre;
    string grado;
};

struct Libro {
    int id;
    string titulo;
    string isbn;
    int anio_publicacion;
    int id_autor;
};

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
    vector <Autor> autores;
    vector <Estudiante> estudiantes;
    vector <Libro> libros;
    vector <Prestamo> prestamos;

    // Métodos Libros
    void agregarLibro(Libro l);
    void listarLibros();

    // Métodos Autores
    void agregarAutor(Autor a);
    void listarAutores();

    // Métodos Estudiantes
    void agregarEstudiante(Estudiante e);
    void listarEstudiantes();

    // Métodos Prestamos
    void agregarPrestamo(Prestamo p);
    void listarPrestamos();

    // Consultas
    void librosPrestadosPorEstudiante(int id_estudiante);

    // Persistencia
    void guardarDatos();
};

#endif
