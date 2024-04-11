import java.util.ArrayList;
import java.util.List;

// Interfaz para la gestión de proyectos (INTERFACE SEGREGATION)/OPEN-CLOSE
interface GestionProyectos {
    void agregarProyecto(String descripcion, String fechaInicio, String fechaLimite);
    void mostrarProyectos();
}

// Clase para representar un proyecto
class Proyecto {    //SingleResponsability
    private String descripcion;
    private String fechaInicio;
    private String fechaLimite;
    //Metodo constructor
    public Proyecto(String descripcion, String fechaInicio, String fechaLimite) {
        this.descripcion = descripcion;
        this.fechaInicio = fechaInicio;
        this.fechaLimite = fechaLimite;
    }
    //Getters
    public String getDescripcion() {
        return descripcion;
    }

    public String getFechaInicio() {
        return fechaInicio;
    }

    public String getFechaLimite() {
        return fechaLimite;
    }
}

// Interfaz para la gestión de comentarios (INTERFACE SEGREGATION)/(OPEN-CLOSE)
interface GestionComentarios {
    void agregarComentario(String autor, String contenido);
    void mostrarComentarios();
}

// Clase para representar un comentario
class Comentario {  //SingleResponsability
    private String autor;
    private String contenido;

    public Comentario(String autor, String contenido) {
        this.autor = autor;
        this.contenido = contenido;
    }

    public String getAutor() {
        return autor;
    }

    public String getContenido() {
        return contenido;
    }
}

// Interfaz para la gestión de archivos compartidos (INTERFACE SEGREGATION)/(OPEN-CLOSED)
interface GestionArchivosCompartidos {
    void agregarArchivoCompartido(String nombre, String ubicacion, int tamano);
    void mostrarArchivosCompartidos();
}

// Clase para representar un archivo compartido
class ArchivoCompartido {      //SingleResponsability   
    private String nombre;
    private String ubicacion;
    private int tamano;

    public ArchivoCompartido(String nombre, String ubicacion, int tamano) {
        this.nombre = nombre;
        this.ubicacion = ubicacion;
        this.tamano = tamano;
    }

    public String getNombre() {
        return nombre;
    }

    public String getUbicacion() {
        return ubicacion;
    }

    public int getTamano() {
        return tamano;
    }
}

// Implementación concreta de la gestión de proyectos           //LISKOV
class GestionProyectosImpl implements GestionProyectos {        //CLOSED
    private List<Proyecto> proyectos = new ArrayList<>();

    @Override       
    public void agregarProyecto(String descripcion, String fechaInicio, String fechaLimite) {
        proyectos.add(new Proyecto(descripcion, fechaInicio, fechaLimite));
    }

    @Override
    public void mostrarProyectos() {
        System.out.println("Lista de proyectos:");
        for (Proyecto proyecto : proyectos) {
            System.out.println("Descripcion: " + proyecto.getDescripcion() +
                    ", Fecha de inicio: " + proyecto.getFechaInicio() +
                    ", Fecha limite: " + proyecto.getFechaLimite());
        }
    }
}

// Implementación concreta de la gestión de comentarios             //LISKOV
class GestionComentariosImpl implements GestionComentarios {        //CLOSED
    private List<Comentario> comentarios = new ArrayList<>();

    @Override
    public void agregarComentario(String autor, String contenido) {
        comentarios.add(new Comentario(autor, contenido));
    }

    @Override
    public void mostrarComentarios() {
        System.out.println("Lista de comentarios:");
        for (Comentario comentario : comentarios) {
            System.out.println("Autor: " + comentario.getAutor() +
                    ", Contenido: " + comentario.getContenido());
        }
    }
}

// Implementación concreta de la gestión de archivos compartidos                //LISKOV
class GestionArchivosCompartidosImpl implements GestionArchivosCompartidos {    //CLOSED
    private List<ArchivoCompartido> archivosCompartidos = new ArrayList<>();

    @Override
    public void agregarArchivoCompartido(String nombre, String ubicacion, int tamano) {
        archivosCompartidos.add(new ArchivoCompartido(nombre, ubicacion, tamano));
    }

    @Override
    public void mostrarArchivosCompartidos() {
        System.out.println("Lista de archivos compartidos:");
        for (ArchivoCompartido archivo : archivosCompartidos) {
            System.out.println("Nombre: " + archivo.getNombre() +
                    ", Ubicacion: " + archivo.getUbicacion() +
                    ", Tamaño: " + archivo.getTamano() + " bytes");
        }
    }
}

public class Ejercicio {
    public static void main(String[] args) {
        GestionProyectosImpl gestionProyectos = new GestionProyectosImpl();
        GestionComentariosImpl gestionComentarios = new GestionComentariosImpl();
        GestionArchivosCompartidosImpl gestionArchivosCompartidos = new GestionArchivosCompartidosImpl();

        gestionProyectos.agregarProyecto("Proyecto de desarrollo de software", "01/04/2024", "30/06/2024");
        gestionProyectos.agregarProyecto("Proyecto de investigación", "15/04/2024", "30/09/2024");

        gestionComentarios.agregarComentario("Usuario1", "Excelente trabajo");
        gestionComentarios.agregarComentario("Usuario2", "¿Hay alguna actualización sobre este proyecto?");

        gestionArchivosCompartidos.agregarArchivoCompartido("Documento1.pdf", "/archivos", 1024);
        gestionArchivosCompartidos.agregarArchivoCompartido("Presentacion.pptx", "/archivos", 2048);

        System.out.println("Proyectos:");
        gestionProyectos.mostrarProyectos();
        System.out.println();

        System.out.println("Comentarios:");
        gestionComentarios.mostrarComentarios();
        System.out.println();

        System.out.println("Archivos compartidos:");
        gestionArchivosCompartidos.mostrarArchivosCompartidos();
    }
}
