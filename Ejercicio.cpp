#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Interfaz para la gestión de proyectos
class GestionProyectos {    //GestionProyectos seria el padre (Sustitucion de liskov)
public:
    virtual void agregarProyecto(string descripcion, string fechaInicio, string fechaLimite) = 0;
    virtual void mostrarProyectos() const = 0;
};

// Clase para representar un proyecto
class Proyecto {
private:
    string descripcion;
    string fechaInicio;
    string fechaLimite;

public:
    Proyecto(string descripcion, string fechaInicio, string fechaLimite)
        : descripcion(descripcion), fechaInicio(fechaInicio), fechaLimite(fechaLimite) {}

    string getDescripcion() const {
        return descripcion;
    }

    string getFechaInicio() const {
        return fechaInicio;
    }

    string getFechaLimite() const {
        return fechaLimite;
    }
};

// Interfaz para la gestión de comentarios
class GestionComentarios {
public:
    virtual void agregarComentario(string autor, string contenido) = 0;
    virtual void mostrarComentarios() const = 0;
};

// Clase para representar un comentario
class Comentario {
private:
    string autor;
    string contenido;

public:
    Comentario(string autor, string contenido) : autor(autor), contenido(contenido) {}

    string getAutor() const {
        return autor;
    }

    string getContenido() const {
        return contenido;
    }
};

// Interfaz para la gestión de archivos compartidos
class GestionArchivosCompartidos {
public:
    virtual void agregarArchivoCompartido(string nombre, string ubicacion, int tamano) = 0;
    virtual void mostrarArchivosCompartidos() const = 0;
};

// Clase para representar un archivo compartido
class ArchivoCompartido {
private:
    string nombre;
    string ubicacion;
    int tamano;

public:
    ArchivoCompartido(string nombre, string ubicacion, int tamano)
        : nombre(nombre), ubicacion(ubicacion), tamano(tamano) {}

    string getNombre() const {
        return nombre;
    }

    string getUbicacion() const {
        return ubicacion;
    }

    int getTamano() const {
        return tamano;
    }
};

// Implementación concreta de la gestión de proyectos
class GestionProyectosImpl : public GestionProyectos {    //GestionProyectosImpl en este caso seria el hijo el cual hereda del padre (Sustitucion liskov)
private:
    vector<Proyecto> proyectos;

public:
    void agregarProyecto(string descripcion, string fechaInicio, string fechaLimite) override {
        proyectos.push_back(Proyecto(descripcion, fechaInicio, fechaLimite));
    }

    void mostrarProyectos() const override {
        cout << "Lista de proyectos:" << endl;
        for (const auto& proyecto : proyectos) {
            cout << "Descripcion: " << proyecto.getDescripcion()
                 << ", Fecha de inicio: " << proyecto.getFechaInicio()
                 << ", Fecha limite: " << proyecto.getFechaLimite() << endl;
        }
    }
};

// Implementación concreta de la gestión de comentarios
class GestionComentariosImpl : public GestionComentarios {
private:
    vector<Comentario> comentarios;

public:
    void agregarComentario(string autor, string contenido) override {
        comentarios.push_back(Comentario(autor, contenido));
    }

    void mostrarComentarios() const override {
        cout << "Lista de comentarios:" << endl;
        for (const auto& comentario : comentarios) {
            cout << "Autor: " << comentario.getAutor()
                 << ", Contenido: " << comentario.getContenido();
        }
    }
};

// Implementación concreta de la gestión de archivos compartidos
class GestionArchivosCompartidosImpl : public GestionArchivosCompartidos {
private:
    vector<ArchivoCompartido> archivosCompartidos;

public:
    void agregarArchivoCompartido(string nombre, string ubicacion, int tamano) override {
        archivosCompartidos.push_back(ArchivoCompartido(nombre, ubicacion, tamano));
    }

    void mostrarArchivosCompartidos() const override {
        cout << "Lista de archivos compartidos:" << endl;
        for (const auto& archivo : archivosCompartidos) {
            cout << "Nombre: " << archivo.getNombre()
                 << ", Ubicacion: " << archivo.getUbicacion()
                 << ", Tamaño: " << archivo.getTamano() << " bytes" << endl;
        }
    }
};

int main() {
    // Ejemplo de uso de los nuevos módulos
    GestionProyectosImpl gestionProyectos;
    GestionComentariosImpl gestionComentarios;
    GestionArchivosCompartidosImpl gestionArchivosCompartidos;

    gestionProyectos.agregarProyecto("Proyecto de desarrollo de software", "01/04/2024", "30/06/2024");
    gestionProyectos.agregarProyecto("Proyecto de investigacion", "15/04/2024", "30/09/2024");

    gestionComentarios.agregarComentario("Usuario1", "Excelente trabajo");
    gestionComentarios.agregarComentario("Usuario2", "¿Hay alguna actualizacion sobre este proyecto?");

    gestionArchivosCompartidos.agregarArchivoCompartido("Documento1.pdf", "/archivos", 1024);
    gestionArchivosCompartidos.agregarArchivoCompartido("Presentacion.pptx", "/archivos", 2048);

    cout << "Proyectos:" << endl;
    gestionProyectos.mostrarProyectos();
    cout << endl;

    cout << "Comentarios:" << endl;
    gestionComentarios.mostrarComentarios();
    cout << endl;

    cout << "Archivos compartidos:" << endl;
    gestionArchivosCompartidos.mostrarArchivosCompartidos();

    return 0;
}
