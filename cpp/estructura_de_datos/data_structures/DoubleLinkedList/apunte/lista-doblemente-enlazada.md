---
title: "Lista Doblemente-enlazada"
tags: ""
---
###### Clase

## Lista Doblemente-enlazada

### Definicion

Con respecto a una lista enlazada, una lista doblemente enlazada contiene un puntero adicional, típicamente llamado puntero anterior, junto con el siguiente puntero y los datos que están allí en una lista individualmente vinculada.

## 

Ventajas 

    1) Se puede atravesar una DLL tanto en dirección hacia adelante como hacia atrás.
    2) La operación de eliminación en DLL es más eficiente si se proporciona un puntero al nodo que se va a eliminar.
    3) Podemos insertar rápidamente un nuevo nodo antes de un nodo dado.
    En la lista vinculada individualmente, para eliminar un nodo, se necesita un puntero al nodo anterior. Para obtener este nodo anterior, a veces se recorre la lista. En una lista doblemente-enlazada podemos obtener el nodo anterior usando el puntero anterior.

Desventajas 

    1) Cada nodo de uno doblemenete enlazado requiere espacio adicional para un puntero anterior. Sin embargo, es posible implementar con un solo puntero
    2) Todas las operaciones requieren un puntero adicional antes de mantenerse. Por ejemplo, en la inserción, necesitamos modificar los punteros anteriores junto con los siguientes. Por ejemplo, en las siguientes funciones para inserciones en diferentes posiciones, necesitamos 1 o 2 pasos adicionales para establecer el puntero anterior.
