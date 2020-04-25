const API_URL = 'https://swapi.dev/api/';
const PEOPLE_URL = 'people/:id/';
const options = { crossDomain: true };

// Creacion de una funcion con promesa
function obtenerPersonaje(id)
{   // Promesa
    return new Promise((resolve, reject) => { // Arrow Function
        var url = `${API_URL}${PEOPLE_URL.replace(':id', id)}`;
        $.get(url, options, function (personaje) { // Llamado Asincrono
            resolve(personaje) // Si obtenemos la data, se ejecuta resolve. SOLO hasta que recibimos la info exitosamente
        })
        .fail(() => reject(id)); // Si falla el request (.get), o sea que sea activa el .fail, llamamos a reject()
    });
}

/**
 * Con esto, y debido a que obtenerPersonaje() nos retorna una promesa,
 * ya tenemos una promesa al utilizar la funcion, y es solo cuestion de 
 * acceder a sus metodos then() y catch() para dentro de cada uno definir
 * lo que sucedera dependiendo si se activa then o catch, que dependen las
 * llamadas a resolver y reject que definimos dentro de nuestra promesa.
 */

// Funcion de error
function onError (id)
{
    console.log(`Sucedió un error al obtener el personaje ${id}`);
}

 // Usando la Promesa
 obtenerPersonaje(1)
    .then(function(personaje) { // Si se resuelve exitosamente, hacer:
        console.log(`Hola, mi nombre es ${personaje.name}`);
    })
    .catch(onerror) // Si hay un error, ejecutar onError
    // Estamos haciendo una referencia a nuestra funcion de error, y 
    // como recibe el parametro, no es necesario definirlo como tal
/*
 Bien nuestra definicion de error podria ser por medio de una funcion local:
    .catch(function (id) {
        console.log(`Sucedió un error al obtener el personaje ${id}`)
    })
*/

/* // Promesas encadenadas
obtenerPersonaje(1)
    .then( personaje => { // Lo cambiamos por una Arrow Function
        console.log(`Hola, mi nombre es ${personaje.name}`);
        return obtenerPersonaje(2);
    })
    .then( personaje => { // Obtenemos el personaje del Return y usamos then
        console.log(`Hola, mi nombre es ${personaje.name}`);
        return obtenerPersonaje(3);
    })
    .then( personaje => { 
        console.log(`Hola, mi nombre es ${personaje.name}`);
        return obtenerPersonaje(4);
    })
    .then( personaje => { 
        console.log(`Hola, mi nombre es ${personaje.name}`);
        return obtenerPersonaje(5);
    })
    .then( personaje => { 
        console.log(`Hola, mi nombre es ${personaje.name}`);
        return obtenerPersonaje(6);
    })
    .then( personaje => { 
        console.log(`Hola, mi nombre es ${personaje.name}`);
    }) // Ya no necesitamos realizar otro callback
    .catch(onerror) */

/* // Promesas Paralelas

// Creamos nuestro array de ID's
var ids = [1, 2, 3, 4, 5, 6, 7];

// Generamos un array de Promesas sobre cada ID con Map
var promesas = ids.map(id => obtenerPersonaje(id)); // usando una arrow function

// Usamos all() para ejecutar un arreglo de promesas
Promise.all(promesas)
    .then(personajes => console.log(personajes))
    .catch(onerror) */

// Async-Await
async function obtenerPersonajes() // Funcion asincrona
{
    var ids = [1, 2, 3, 4, 5, 6, 7];
    var promesas = ids.map(id => obtenerPersonaje(id));
    try
    {
        var personajes = await Promise.all(promesas); // Esperamos la resolucion de
        console.log(personajes);    // la promesa antes de continuar con el codigo
    } catch(id)
    {
        onError(id);
    }
}

obtenerPersonajes();