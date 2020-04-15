public class Stack {
    /*
    * Stack o Pila: Estructura que apila elementos conforme van llegando, siguiente el orden FILO
    * (First In First Out).
    * */

    private Node top;   // Necesitamos un apuntador que siempre tenga fijo la cabeza de la Pila

    public Stack() {    // Constructor
        top = null;     // Inicializamos con top apuntando a null, pues no hay datos en la Pila
    }

    public void push(int l) {
        /*
        * Metodo que nos permite ingresar un nuevo elemento a la Pila
        * */
        if (isEmpty()) {    // De estar vacia:
            Node nuevoNodo = new Node(l);   // Creamos el primer nodo con su carga
            top = nuevoNodo;    // Ahora el top apunta al nodo que acabamos de crear, pues es el unico
        } else {    // De NO estar vacia:
            Node nuevoNodo = new Node(l);   // Creamos el nuevo nodo
            Node temporal = top;    // Guardamos el top de la Pila en una variable temporal, para no perder su rastro
            top = nuevoNodo;    // El top es ahora el nuevo nodo que acaba de ingresar
            nuevoNodo.setNext(temporal);    // Y el next del nuevo nodo apunta al top anterior (ahora es var temporal)
        }
    }

    public int pop() {
        /*
         * Metodo que nos permite sacar al elemento superior de la pila y retornarlo
         * */
        if (isEmpty()) return -1;   // De estar vacia, retornar error
        else {  // De NO estar vacia:
            int valor = top.getLoad();  // Obtenemos la carga del nodo superior (top) para retornarla como valor
            top = top.getNext();    // Y el top (nodo superior) ahora es el next del que era el top anterior --
            return valor;           // que hemos sacado de la Pila
        }
    }

    public void clear() {
        /*
         * Metodo para eliminar la Pila
         * */
        while (!isEmpty()) pop(); // Mientras la Pila no este vacia: sacar los elementos (pop())
        top = null;     // Igualamos el top a null para eliminar cualquier referencia de la Pila
    }

    public int peek() {
        /*
         * Metodo para conocer el elemento superior de la Pila, sin sacarlo de ella
         * */
        if (isEmpty()) return -1;   // Si la Pila esta vacia, retornar error
        else return top.getLoad();  // De no ser asi: retornamos la carga del nodo superior (top)
    }

    public boolean isEmpty() {
        /*
         * Metodo para conocer si la Pila se encuentra o no vacia
         * */
        if (top == null) return true;   // Si top es null, significa que la Pila esta vacia (true)
        else return false;  // De no ser null, entonces hay nodos en la Pila (false)
    }

    public String toString() {
        /*
         * Metodo que nos imprime una String con el contenido de la Pila en corchetes
         * */
        String cadena = "[ ";   // Creamos cadena, que alojara nuestra String con el primer valor, el corchete abierto
        while (!isEmpty()) {    // Mientras la Pila no este vacia:
            cadena += pop();    // Hacemos pop() y vamos concatenando la carga en la String cadena
            if (!isEmpty()) cadena += ", ";     // Si aun hay nodos despues del pop, significa que habra por lo menos
        }                                       // otro elemento, asi que agregamos la coma y el espacio
        cadena += " ]";     // De estar vacia la Pila, cerramos el corchete y nuestra String esta lista
        return cadena;
    }
}
