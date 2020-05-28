---
title: "Vector"
tags: ""
---
###### Clase

## Vector

### Definicion de Vector

Los vectores son iguales a las matrices dinámicas con la capacidad de cambiar su tamaño automáticamente cuando se inserta o elimina un elemento, y su almacenamiento es manejado automáticamente por el contenedor. Los elementos vectoriales se colocan en un almacenamiento contiguo para que se pueda acceder y atravesarlos mediante iteradores. En vectores, los datos se insertan al final. Insertar al final requiere un tiempo diferencial, ya que a veces puede ser necesario extender la matriz. 

Eliminar el último elemento lleva solo un tiempo constante porque no se produce el cambio de tamaño. Insertar y borrar al principio o en el medio es lineal en el tiempo.

## 

#### Algunos metodos

    begin()
    end()
    size()
    capacity()
    resize()
    empty()
    shrink_to_fit()
