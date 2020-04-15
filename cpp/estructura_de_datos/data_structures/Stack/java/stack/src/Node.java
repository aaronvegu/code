public class Node {
    /*
    * Nodo: Objeto que contendra las cargas y apuntara al siguiente nodo, funcionando
    * como una lista enlazada dentro de la Fila
    * */

    private int load;       // La carga del nodo
    private  Node next;     // Apuntador al nodo debajo en la Fila

    public Node(int n){     // Constructor que recibe como argumento la carga del nodo
        this.load = n;      // La carga es guardada en load
        this.next = null;   // Al inicializarse el next no existe
    }

    // Getters y Setters
    public int getLoad() {
        return load;
    }

    public Node getNext() {
        return next;
    }

    public void setLoad(int load) {
        this.load = load;
    }

    public void setNext(Node next) {
        this.next = next;
    }
}
