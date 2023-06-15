#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Libro {
    int codigo;
    string titulo;
    string autor;
    string genero;
    string fechaSalida;
    string fechaDevolucion;
    bool prestado;
    Libro* siguiente;
};
cout<<"xd";
class GestorBiblioteca {
private:
    Libro* cabeza;

public:
    GestorBiblioteca() {
        cabeza = 0;
    }
    
    void agregarLibro() {
        Libro* nuevoLibro = new Libro;
        cout << "Ingrese el código del libro: ";
        cin >> nuevoLibro->codigo;
        cout << "Ingrese el título del libro: ";
        cin.ignore();
        getline(cin, nuevoLibro->titulo);
        cout << "Ingrese el autor del libro: ";
        getline(cin, nuevoLibro->autor);
        cout << "Ingrese el género del libro: ";
        getline(cin, nuevoLibro->genero);
        nuevoLibro->fechaSalida = "";
        nuevoLibro->fechaDevolucion = "";
        nuevoLibro->siguiente = 0;

        if (cabeza == 0) {
            cabeza = nuevoLibro;
        } else {
            Libro* temp = cabeza;
            while (temp->siguiente != 0) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevoLibro;
        }

        cout << "Libro agregado correctamente." << endl;
        system("pause");
        system("cls");
    }

    void mostrarLibros() {
        if (cabeza == 0) {
            cout << "No hay libros en la biblioteca." << endl;
        } else {
            Libro* temp = cabeza;
            cout << "Lista de libros:" << endl;
            while (temp != 0) {
                cout << "Código: " << temp->codigo << endl;
                cout << "Título: " << temp->titulo << endl;
                cout << "Autor: " << temp->autor << endl;
                cout << "Género: " << temp->genero << endl;
                if (temp->fechaSalida != "") {
                    cout << "Estado: Prestado" << endl;
                    cout << "Fecha de salida: " << temp->fechaSalida << endl;
                    cout << "Fecha de devolución: " << temp->fechaDevolucion << endl;
                } else {
                    cout << "Estado: Disponible" << endl;
                }
                cout << "---------------------" << endl;
                temp = temp->siguiente;
            }
        }
        system("pause");
        system("cls");
    }
   
    void prestarLibro() {
        int codigo;
        cout << "Ingrese el código del libro a prestar: ";
        cin >> codigo;

        Libro* temp = cabeza;
        while (temp != 0) {
            if (temp->codigo == codigo) {
                if (temp->fechaSalida != "") {
                    cout << "El libro ya está prestado." << endl;
                } else {
                    cout << "Ingrese la fecha de salida (dd-mm-yyyy): ";
                    cin.ignore();
                    getline(cin, temp->fechaSalida);
                    cout << "Ingrese la fecha de devolución (dd-mm-yyyy): ";
                    getline(cin, temp->fechaDevolucion);
                    cout << "El libro ha sido prestado exitosamente." << endl;
                }
                return;
            }
            temp = temp->siguiente;
        }

        cout << "No se encontró un libro con el código ingresado." << endl;
        system("pause");
        system("cls");
    }

    void buscarLibroPorAutor(const string& autor) {
        bool encontrado = false;
        Libro* temp = cabeza;
        cout << "Resultados de búsqueda por autor (" << autor << "):" << endl;
        while (temp != 0) {
            if (temp->autor == autor) {
                cout << "Código: " << temp->codigo << endl;
                cout << "Título: " << temp->titulo << endl;
                cout << "Autor: " << temp->autor << endl;
                cout << "Género: " << temp->genero << endl;
                if (temp->fechaSalida != "") {
                    cout << "Estado: Prestado" << endl;
                    cout << "Fecha de salida: " << temp->fechaSalida << endl;
                    cout << "Fecha de devolución: " << temp->fechaDevolucion << endl;
                } else {
                    cout << "Estado: Disponible" << endl;
                }
                cout << "---------------------" << endl;
                encontrado = true;
            }
            temp = temp->siguiente;
        }

        if (!encontrado) {
            cout << "No se encontraron libros del autor ingresado." << endl;
        }
        system("pause");
        system("cls");
    }

    void buscarLibroPorGenero(const string& genero) {
        bool encontrado = false;
        Libro* temp = cabeza;
        cout << "Resultados de búsqueda por género (" << genero << "):" << endl;
        while (temp != 0) {
            if (temp->genero == genero) {
                cout << "Código: " << temp->codigo << endl;
                cout << "Título: " << temp->titulo << endl;
                cout << "Autor: " << temp->autor << endl;
                cout << "Género: " << temp->genero << endl;
                if (temp->fechaSalida != "") {
                    cout << "Estado: Prestado" << endl;
                    cout << "Fecha de salida: " << temp->fechaSalida << endl;
                    cout << "Fecha de devolución: " << temp->fechaDevolucion << endl;
                } else {
                    cout << "Estado: Disponible" << endl;
                }
                cout << "---------------------" << endl;
                encontrado = true;
            }
            temp = temp->siguiente;
        }

        if (!encontrado) {
            cout << "No se encontraron libros del género ingresado." << endl;
        }
        system("pause");
        system("cls");
    }

    void buscarLibroPorTitulo(const string& titulo) {
        bool encontrado = false;
        Libro* temp = cabeza;
        cout << "Resultados de búsqueda por título (" << titulo << "):" << endl;
        while (temp != 0) {
            if (temp->titulo == titulo) {
                cout << "Código: " << temp->codigo << endl;
                cout << "Título: " << temp->titulo << endl;
                cout << "Autor: " << temp->autor << endl;
                cout << "Género: " << temp->genero << endl;
                if (temp->fechaSalida != "") {
                    cout << "Estado: Prestado" << endl;
                    cout << "Fecha de salida: " << temp->fechaSalida << endl;
                    cout << "Fecha de devolución: " << temp->fechaDevolucion << endl;
                } else {
                    cout << "Estado: Disponible" << endl;
                }
                cout << "---------------------" << endl;
                encontrado = true;
            }
            temp = temp->siguiente;
        }

        if (!encontrado) {
            cout << "No se encontraron libros con el título ingresado." << endl;
        }
        system("pause");
        system("cls");
    }

    void buscarLibroPorCodigo(int codigo) {
        bool encontrado = false;
        Libro* temp = cabeza;
        cout << "Resultados de búsqueda por código (" << codigo << "):" << endl;
        while (temp != 0) {
            if (temp->codigo == codigo) {
                cout << "Código: " << temp->codigo << endl;
                cout << "Título: " << temp->titulo << endl;
                cout << "Autor: " << temp->autor << endl;
                cout << "Género: " << temp->genero << endl;
                if (temp->fechaSalida != "") {
                    cout << "Estado: Prestado" << endl;
                    cout << "Fecha de salida: " << temp->fechaSalida << endl;
                    cout << "Fecha de devolución: " << temp->fechaDevolucion << endl;
                } else {
                    cout << "Estado: Disponible" << endl;
                }
                cout << "---------------------" << endl;
                encontrado = true;
                break;
            }
            temp = temp->siguiente;
        }

        if (!encontrado) {
            cout << "No se encontró un libro con el código ingresado." << endl;
        }
        system("pause");
        system("cls");
    }

    void liberarMemoria() {
        Libro* temp = cabeza;
        while (temp != 0) {
            Libro* siguiente = temp->siguiente;
            delete temp;
            temp = siguiente;
        }
        cabeza = 0;
    }
    void guardarLibrosEnArchivo(const char* nombreArchivo) {
        ofstream archivo(nombreArchivo);
        if (archivo.is_open()) {
            Libro* temp = cabeza;
            while (temp != 0) {
                archivo << temp->codigo << endl;
                archivo << temp->titulo << endl;
                archivo << temp->autor << endl;
                archivo << temp->genero << endl;
                archivo << temp->fechaSalida << endl;
                archivo << temp->fechaDevolucion << endl;
                temp = temp->siguiente;
            }
            archivo.close();
            cout << "Datos de libros guardados correctamente en el archivo " << nombreArchivo << "." << endl;
        } else {
            cout << "Error al abrir el archivo." << endl;
        }
    }
    void devolverLibro() {
        int codigo;
        cout << "Ingrese el código del libro a devolver: ";
        cin >> codigo;

        Libro* temp = cabeza;
        while (temp != 0) {
            if (temp->codigo == codigo) {
                if (temp->prestado) {
                    temp->prestado = false;
                    cout << "El libro con código " << codigo << " ha sido devuelto." << endl;
                } else {
                    cout << "El libro con código " << codigo << " no está prestado actualmente." << endl;
                }
                return;
            }
            temp = temp->siguiente;
        }

        cout << "No se encontró ningún libro con el código " << codigo << "." << endl;
        system("pause");
        system("cls");
    }
};

void mostrarMenu() {
    cout << "===== GESTOR DE BIBLIOTECA =====" << endl;
    cout << "1. Agregar libro" << endl;
    cout << "2. Mostrar libros" << endl;
    cout << "3. Prestar libro" << endl;
    cout << "4. Búsqueda de libro" << endl;
    cout << "5. Devolución de libro" << endl;
    cout << "6. Salir" << endl;
    cout << "==============================" << endl;
    cout << "Ingrese una opción: ";
}

void buscarLibro(GestorBiblioteca& gestor) {
    int opcion;
    cout << "===== BÚSQUEDA DE LIBRO =====" << endl;
    cout << "Seleccione el criterio de búsqueda:" << endl;
    cout << "1. Autor" << endl;
    cout << "2. Género" << endl;
    cout << "3. Título" << endl;
    cout << "4. Código" << endl;
    cout << "Ingrese una opción: ";
    cin >> opcion;

    string consulta;
    switch (opcion) {
        case 1:
            cout << "Ingrese el autor del libro: ";
            cin.ignore();
            getline(cin, consulta);
            gestor.buscarLibroPorAutor(consulta);
            break;
        case 2:
            cout << "Ingrese el género del libro: ";
            cin.ignore();
            getline(cin, consulta);
            gestor.buscarLibroPorGenero(consulta);
            break;
        case 3:
            cout << "Ingrese el título del libro: ";
            cin.ignore();
            getline(cin, consulta);
            gestor.buscarLibroPorTitulo(consulta);
            break;
        case 4:
            int codigo;
            cout << "Ingrese el código del libro: ";
            cin >> codigo;
            gestor.buscarLibroPorCodigo(codigo);
            break;
        default:
            cout << "Opción inválida. Intente nuevamente." << endl;
            break;
    }
}

int main() {
    GestorBiblioteca gestor;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
            	system("cls");
                gestor.agregarLibro();
                break;
            case 2:
            	system("cls");
                gestor.mostrarLibros();
                break;
            case 3:
            	system("cls");
                gestor.prestarLibro();
                break;
            case 4:
            	system("cls");
                buscarLibro(gestor);
                break;
            case 5:
            	system("cls");
            	gestor.devolverLibro();
            	break;
            case 6:
                cout << "Saliendo del programa..." << endl;
                gestor.guardarLibrosEnArchivo("libros.txt");
                gestor.liberarMemoria();
                break;
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
                break;
        }
        cout << endl;
    } while (opcion != 5);
    return 0;
}


