#include <stdio.h> // Para NULL, printf
#include <stdlib.h> // Para malloc y free
#include <iostream> // Para cout

struct node
{
    int data;   // Carga del nodo
    struct node *left;  // Apuntador al hijo izquierdo
    struct node *right; // Apuntador al hijo derecho
};

/* Creamos la funcion newNode(), que crea un nuevo nodo con 
la carga pasada como parametro y define los apuntadores derechos
e izquierdos apuntando a NULL.  */
struct node* newNode(int data)
{
    // Creamos memoria para el nuevo nodo
    struct node* node = (struct node*)malloc(sizeof(struct node));

    // Asignamos la carga al nodo
    node->data = data;

    // Inicializamos los apuntadores de los hijos izq y der a NULL
    node->left = NULL;
    node->right = NULL;

    // Retornamos el apuntador al nodo creado
    return(node);
}

int main()
{
    // Creamos la raiz del arbol (root)
    struct node *root = newNode(1);
    /* Quedando algo asi:
        1  
      /   \
    NULL  NULL
    */

   // Ahora le asignamos los dos siguientes valores en sus hijos
   root->left = newNode(2);
   root->right = newNode(3);
   /* Ahora los enteros 2 y 3 se vuelven los hijos izq y der del root 1
      Lo cual deja a los hijos de 2 y 3 apuntando a NULL, debido a newNode()
           1 
         /   \ 
        2      3 
     /    \    /  \ 
    NULL NULL NULL NULL 
  */
}