import java.util.ArrayList; //Impotacion de librerias
import java.util.List;

// Clase para representar una tarea con su descripción y su fecha límite
class Tarea {
    private String descripcion;     //atributos
    private String fechaLimite;
    
    //Metodo constructor
    public Tarea(String descripcion, String fechaLimite) {
        this.descripcion = descripcion;
        this.fechaLimite = fechaLimite;
    }
    //Getters para descripcion y fechaLimite
    public String getDescripcion() {
        return descripcion;
    }
    public String getFechaLimite() {
        return fechaLimite;
    }
}
// Clase para la gestión de tareas
class GestionDeTareas {
    //creacion de lista de instancias de Tarea
    private List<Tarea> tareas;
    
    //metodo constructor
    public GestionDeTareas() {
        this.tareas = new ArrayList<>();
    }
    //agrega tareas
    public void agregarTarea(String descripcion, String fechaLimite) {
        tareas.add(new Tarea(descripcion, fechaLimite));
    }
    //getter de tareas
    public List<Tarea> obtenerTareas() {
        return tareas;
    }
}

// Clase para la presentación de tareas
class PresentadorTareas {
    public static void mostrarTareas(List<Tarea> tareas) {
        System.out.println("Lista de tareas:");
        for (Tarea tarea : tareas) {
            System.out.println("Descripcion: " + tarea.getDescripcion() + ", Fecha limite: " + tarea.getFechaLimite());
        }
    }
}

public class Actividad1 {
    public static void main(String[] args) {
        //Instanciamiento de la clase
        GestionDeTareas gestionDeTareas = new GestionDeTareas();
        //agregamos datos de tareas
        gestionDeTareas.agregarTarea("Resolver ejercicios", "10/04/2024");
        gestionDeTareas.agregarTarea("Realizar código", "15/04/2024");
        gestionDeTareas.agregarTarea("Presentar informe", "20/04/2024");
        //Presentamos tareas
        PresentadorTareas.mostrarTareas(gestionDeTareas.obtenerTareas());
    }
}
