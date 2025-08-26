#include <iostream>
#include <string>
#include <vector>

//--------Definicion de la clase Libro
class Libro {
    public:
    std::string titulo;
    std::string autor;
    int anioPublicacion;
    bool estaDisponible; //nuevo atributo

    Libro(): anioPublicacion(0), estaDisponible(true) {}

    void mostrarDetallesCompletos() const {
        std::cout << "Titulo: " << titulo
                  << " --- Autor: " << autor
                  << " --- Anio: " << anioPublicacion
                  << " --- Estado: " << (estaDisponible ? "Disponible" : "Prestado")
                  << std::endl;
    }

};

//--------Definicion de la clase Biblioteca
class Biblioteca {
    private:
    std::vector<Libro> coleccion; //se encarga de guardar todos los libros

    public:
    void agregarLibro(const Libro& nuevoLibro) {//anade un nuevo libro, const = no se puede modificar, & = pasa por referencia
        for (const auto& libro : coleccion) {
        if (libro.titulo == nuevoLibro.titulo) {
            std::cout << "El libro \"" << nuevoLibro.titulo << "\" ya existe en la biblioteca.\n";
            return; 
        }
    }
        coleccion.push_back(nuevoLibro);
        std::cout << "Libro agregado: " << nuevoLibro.titulo << std::endl;
    }

    void mostrarInventario() {//mostrara en pantalla los libros de la bilbioteca
        if (coleccion.empty()) {
            std::cout << "No hay libros en la biblioteca \n";
            return;
        }

        std::cout << "\n---Inventario de la Biblioteca----\n";
        for (const auto& libro : coleccion) {
            libro.mostrarDetallesCompletos(); //llama de un solo a la funcion que muestra

        }
    }

    Libro* buscarLibro(const std::string& tituloBuscado) {//busca libro por titulo, (cosnt ...) = nombre del libro, Libro* = puntero al libro
        for(auto& libro : coleccion) {
            if (libro.titulo == tituloBuscado) {
                return &libro; //retorna el puntero al libro que se encontro
            }
        }
        return nullptr; //no se encontro el libro
    }

    void prestarLibro(const std::string& tituloPrestamo) {//presta un libro, usa buscarLibro() para encontrarlo, 
        Libro* libro = buscarLibro(tituloPrestamo);
        if (libro != nullptr) {
            if (libro->estaDisponible) {
                libro->estaDisponible = false;
                std::cout << "Tu prestamo del libro: " << libro->titulo << " se ha realizado" << std::endl;
            } else {
                std::cout << "El libro ya esta prestado. \n";
            }
        } else {
            std::cout << "No se ha encontrado el libro \n";
        }
    }

    void devolverLibro(const std::string& tituloDevolucion) {//devuelve un libro prestado
        Libro* libro = buscarLibro(tituloDevolucion);
        if (libro != nullptr) {
            if (!libro->estaDisponible) {
                libro->estaDisponible = true;
                std::cout << "El libro: " << libro->titulo << " ha sido devuelto" << std::endl;
            } else {
                std::cout << "EL libro ya se encontraba en disponibilidad \n";
            }
        } else {
            std::cout << "El libro no se encontro \n";
        }
    }

};

//---------Funcion Principal con el Menu---------- 
int main () {
    Biblioteca miBiblioteca;
    int opcion = 0;

    //Libros de ejemplo
    Libro libroInicial;
    libroInicial.titulo = "Las aventuras de Tom Sawyer";
    libroInicial.autor = "Mark Twain";
    libroInicial.anioPublicacion = 1878;
    miBiblioteca.agregarLibro(libroInicial);

    //Otros libros:
    Libro libro1;
    libro1.titulo = "La Isla del Tesoro";
    libro1.autor = "Robert Louis Stevenson";
    libro1.anioPublicacion = 1882;
    miBiblioteca.agregarLibro(libro1);

    Libro libro2;
    libro2.titulo = "La Ciudad de las Bestias";
    libro2.autor = "Isabel Allende";
    libro2.anioPublicacion = 2002;
    miBiblioteca.agregarLibro(libro2);

    Libro libro3;
    libro3.titulo = "La metamorfosis";
    libro3.autor = "Franz Kafka";
    libro3.anioPublicacion = 1915;
    miBiblioteca.agregarLibro(libro3);

    Libro libro4;
    libro4.titulo = "Vuelta al mundo en 80 dias";
    libro4.autor = "Julio Verne";
    libro4.anioPublicacion = 1872;
    miBiblioteca.agregarLibro(libro4);

    Libro libro5;
    libro5.titulo = "Estudio en Escarlata";
    libro5.autor = "Arthur Conan Doyle";
    libro5.anioPublicacion = 1887;
    miBiblioteca.agregarLibro(libro5);


    while (opcion != 5) {
        std::cout << "\n ----BIBLIOTECA DIGITAL----" <<std::endl;
        std::cout << "1. Anadir libro" <<std::endl;
        std::cout << "2. Mostrar inventario" <<std::endl;
        std::cout << "3. Prestar libro" << std::endl;
        std::cout << "4. Devolver libro" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        //Limpiar el bufer de entrada
        std::cin.ignore();

        //Usar un switch o if-else para manejar opcion del usuario
        switch (opcion) {
            case 1: { //en caso de que seleccione opcion 1
                Libro nuevoLibro; //crea un nuevo libro
                std::cout << "Ingrese titulo: ";
                std::getline(std::cin, nuevoLibro.titulo); //lee el titulo
                std::cout << "Ingrese autor: ";
                std::getline(std::cin, nuevoLibro.autor); //lee autor
                std::cout << "Ingrese el anio de publicacion: ";
                std::cin >> nuevoLibro.anioPublicacion; //lee el anio
                std::cin.ignore(); //limpia el buffer
                nuevoLibro.estaDisponible = true;
                miBiblioteca.agregarLibro(nuevoLibro); //el libro es agregado
                break;
            }

            case 2: //en caso de que seleccione opcion 2
                miBiblioteca.mostrarInventario(); //lama funcion para mostrar inventario
            break;

            case 3: { //en caso de que seleccione opcion 3
               std::string titulo;
               std::cout << "Ingrese el titulo del libro que quiere prestar: ";
               std::getline(std::cin, titulo);
               miBiblioteca.prestarLibro(titulo);
               break; 
            }

            case 4: {
                std::string titulo;
                std::cout << "Ingrese el titulo del libro que desea devolver: ";
                std::getline(std::cin, titulo);
                miBiblioteca.devolverLibro(titulo);
                break;
            }

            case 5:
                std::cout << "Saliendo...\n";
                break;
            default:
            std::cout << "Opcion no valida \n";
            break;

        }
    }

    return 0;

}