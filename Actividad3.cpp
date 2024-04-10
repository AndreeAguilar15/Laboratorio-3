#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Interfaz para proporcionar información de progreso de tareas
class Informacionprogreso {
public:
    virtual void progresotarea(const string& descripcion, int progreso) const = 0;
    virtual int obtenerprogreso(const string& descripcion) const = 0;
};

// Interfaz para la gestión de tareas
class Gestiontareas {
public:
    virtual void agregartarea(string descripcion, string fechalimite, int progreso) = 0;
    virtual void mostrartareas() const = 0;
};

// Clase para representar una tarea con descripción, fecha límite y progreso
class Tarea {
private:
    string descripcion;
    string fechalimite;
    int progreso;

public:
    Tarea(string descripcion, string fechalimite, int progreso) : descripcion(descripcion), fechalimite(fechalimite), progreso(progreso) {}

    string getDescripcion() const {
        return descripcion;
    }

    string getFechalimite() const {
        return fechalimite;
    }

    int getProgreso() const {
        return progreso;
    }

    void setProgreso(int value) {
        progreso = value;
    }
};

// Clase para la gestión de tareas que utiliza la interfaz InformacionProgreso
class Gestiondetareas : public Gestiontareas {
private:
    vector<Tarea> tareas;
    const Informacionprogreso& seguimiento;

public:
    Gestiondetareas(const Informacionprogreso& seguimiento) : seguimiento(seguimiento) {}

    void agregartarea(string descripcion, string fechalimite, int progreso) override {
        tareas.push_back(Tarea(descripcion, fechalimite, progreso));
    }

    void mostrartareas() const override {
        cout << "Lista de tareas:" << endl;
        for (const Tarea& tarea : tareas) {
            cout << "Descripcion: " << tarea.getDescripcion() << ", Fecha limite: " << tarea.getFechalimite()
                 << ", Progreso: " << tarea.getProgreso() << "%" << endl;
        }
    }
    void informarprogreso(const string& descripcion, int progreso) {
        for (Tarea& tarea : tareas) {
            if (tarea.getDescripcion() == descripcion) {
                tarea.setProgreso(progreso); // Actualiza el progreso de la tarea en el vector
                seguimiento.progresotarea(descripcion, progreso); // Informa el progreso utilizando la interfaz
                return;
            }
        }
    }

    int obtenerprogreso(const string& descripcion) const {
        for (const Tarea& tarea : tareas) {
            if (tarea.getDescripcion() == descripcion) {
                return tarea.getProgreso();
            }
        }
        return -1; // Retorna un valor inválido si la tarea no se encontró
    }
};

// Implementación concreta de la interfaz Informacionprogreso para seguimiento por consola
class Seguimientoconsola : public Informacionprogreso {
public:
    void progresotarea(const string& descripcion, int progreso) const override {
        cout << "Progreso de la tarea '" << descripcion << "' actualizado: " << progreso << "%" << endl;
    }

    int obtenerprogreso(const string& descripcion) const override {
        return 0;
    }
};

int main() {
    Seguimientoconsola seguimientoconsola;
    Gestiondetareas gestiondetareas(seguimientoconsola);

    gestiondetareas.agregartarea("Resolver ejercicios", "10/04/2024", 0);
    gestiondetareas.agregartarea("Realizar codigo", "15/04/2024", 0);
    gestiondetareas.agregartarea("Presentar informe", "20/04/2024", 0);

    gestiondetareas.mostrartareas();
    cout<<endl;
    gestiondetareas.informarprogreso("Resolver ejercicios", 25);
    cout<<endl;
    gestiondetareas.mostrartareas();;

    return 0;
}
