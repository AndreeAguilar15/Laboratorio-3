#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Clase para representar una tarea con su descipcion y su fecha limite
class Tarea {
private:
    string descripcion;
    string fechalimite;

public:
    Tarea(string descripcion, string fechalimite) : descripcion(descripcion), fechalimite(fechalimite) {}

    string getDescripcion() const {
        return descripcion;
    }

    string getFechalimite() const {
        return fechalimite;
    }
};

// Clase para la gestión de tareas
class Gestiondetareas {
private:
    vector<Tarea> tareas;

public:
    Gestiondetareas() {} // Constructor por defecto

    void agregartarea(string descripcion, string fechalimite) {
        tareas.push_back(Tarea(descripcion, fechalimite));
    }

    void mostrartareas() {
        cout << "Lista de tareas:" << endl;
        for (const Tarea& tarea : tareas) {
            cout << "Descripcion: " << tarea.getDescripcion() << ", Fecha limite: " << tarea.getFechalimite() << endl;
        }
    }
};

int main() {
    Gestiondetareas gestionDeTareas;

    gestionDeTareas.agregartarea("Resolver ejercicios", "10/04/2024");
    gestionDeTareas.agregartarea("Realizar codigo", "15/04/2024");
    gestionDeTareas.agregartarea("Presentar informe", "20/04/2024");

    gestionDeTareas.mostrartareas();

    return 0;
}