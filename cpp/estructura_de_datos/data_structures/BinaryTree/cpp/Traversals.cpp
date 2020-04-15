#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNewNode(int data) {
    TreeNode* newNode = new TreeNode(); // Instanciamos un apuntador a Nodo llamado newNode
    newNode->data = data; // Almacenamos la carga en el nuevo nodo mediante al apuntador creado
    newNode->left = newNode->right = NULL; // Apuntamos apuntadores de hijos izq y der del nodo a NULL
    return newNode; // Retornamos el apuntador al nuevo nodo newNode
}

TreeNode* insert(TreeNode* r, int data) { // args = (apuntador a root, carga a insertar)
    if (r == NULL)
    {
        r = createNewNode(data);
        return r;
    } 
    else if (data <= r->data)
    {
        r->left = insert(r->left, data);
    }
    else
    {
        r->right = insert(r->right, data);
    }
    return r;
}

/* Recorridos Avanzados BF / DF */

/**
 * == Breadth-First Traversal o Level-Order Traversal == 
 * En este recorrido, lo que se hace es iniciar el recorri-
 * do en la raiz, e ir visitando cada nodo de izq a der por
 * nivel de profundidad.
 * 
 * La implementacion de la funcion consiste en recibir como
 * parametro el apuntador a la raiz, crear una Queue donde se
 * almacenen las direcciones de los hijos de cada nodo, pero
 * primero se inicia con la raiz, para de ahi iniciar con la
 * impresion de la carga de la raiz (que seria el primer y 
 * unico elemento de la Queue) y despues almacenar en la Queue
 * la direccion de ambos hijos, de exisitr, de la raiz, antes
 * de continuar con el nodo al frente de la Queue (que seria el
 * hijo izq de la raiz) y volver a repetir el proceso:
 * 1. Imprimir la carga (Front Queue)
 * 2. Almacenar en Queue sus hijos
 * 3. Hacer pop del frente de la Queue
 * Asi hasta que se recorra todo el arbol
 */
 void breadthFirstTraversal(TreeNode* r) {
     if(r == NULL) return; // Si el nodo esta vacio, salimos
     queue<TreeNode*> Q; // Creamos la cola
     Q.push(r); // Iniciamos la cola con la direccion de root
     while (!Q.empty()) // Mientras haya direcciones en la cola
     {
        TreeNode* current = Q.front(); // Guardamos el frente de la cola en current
        cout << current->data << " "; // Imprimimos la carga de current
        if(current->left != NULL) Q.push(current->left); // Si no es NULL, almacenamos la dir del hijo izq
        if(current->right != NULL) Q.push(current->right); // Si no es NULL, almacenamos la dir del hijo der
        Q.pop(); // Pop del nodo del frente de la cola, que ya se imprimió
     }
 }

/**
 * == Depth-First Traversal ==
 * Este recorrido inicia desde la raiz, y a apartir de ahi,
 * sigue recorriendo por medio de los nodos hijos izquierdos
 * conforme va bajando en niveles de profundidad, para luego
 * pasar al siguien hermano del nodo. El punto es no cambiar
 * de nodo hermano hasta bajar toda la profundidad del arbol.
 * 
 * La funcion del recorrido consistira en iniciar por la impre-
 * sion del root, para de manera recursiva, pasar al nodo iz-
 * quierdo hasta que termine los nodos izquierdos (gracias a la
 * recursividad) y despues recorrer los nodos derechos.
 * Es necesario crear una primera verificacion de que el nodo
 * no sea NULL, y si lo es, salir de la funcion, justamente para
 * que la recursividad funcione y vaya saltando de nodo en nodo
 * conforme llega a visitarlos todos en su profundidad, lo que es
 * lo mismo a encontrarse con un nodo NULL
 */
void depthFirstTraversal(TreeNode* r) {
    if(r == NULL) return;
    cout << r->data << " ";
    depthFirstTraversal(r->left);
    depthFirstTraversal(r->right);
}

/**
 * Arbol formado con [22, 8, 44, 3, 56, 10]:
 * 0         22
 *         /    \
 * 1      8     44    
 *      /   \     \
 * 2    3   10     56
 */ 

int main() {

    // Creacion del Arbol
    TreeNode* root = NULL; // Creamos un puntero que apunta a un arbol vacio
    root = insert(root, 22);
    root = insert(root, 8);
    root = insert(root, 44);
    root = insert(root, 3);
    root = insert(root, 56);
    root = insert(root, 10);

    /* Recorridos */
    cout << "== Recorrido Breadth-First ==" << endl;
    cout << "Breadth-First: [ "; 
    breadthFirstTraversal(root);
    cout << "]" << endl;
    cout << "== = ==" << endl;
    cout << "== Recorrido Depth-First ==" << endl;
    cout << "Depth-First: [ "; 
    depthFirstTraversal(root);
    cout << "]" << endl;
    cout << "== = ==" << endl;

    return 0;
}