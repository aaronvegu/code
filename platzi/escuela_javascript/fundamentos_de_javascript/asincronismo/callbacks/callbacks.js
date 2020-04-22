// Constante del URL de SWAPI
const API_URL = 'https://swapi.dev/api/';

// Constante para pedir info de Personas
const PEOPLE_URL = 'people/:id';

// URL completa para pedir a la API la info de Skywalker
// reemplazando :id por 1, que es el id de Luke skywalker
const LUKE_URL = `${API_URL}${PEOPLE_URL.replace(':id', 1)}`;

// Para indicar que la informacion seria enviada a otro documento
var options = { crossDomain: true};

// Nuestro Callback
/**
 * Un Callback es una funcion que es pasada a otra funcion como
 * argumento o parametro. Esta funcion (callback) es invocada
 * y ejecutada dentro de la funcion externa para completar alguna
 * accion o especifica o ante cualquier evento, bien podria nunca
 * ejecutarse, por eso mismo es un Callback
 */
/* var onResponse = function(data) {
    console.log(`Hola, mi nombre es ${data.name}`);
}
// Nuestro Callback onResponse se ejecutara por JQuery.get() solo
// cuando ha sido traida la informacion de la API con exito


function obtenerPersonaje(id)
{
    // Url del request con el id recibido como parametro
    var url = `${API_URL}${PEOPLE_URL.replace(':id', id)}`;
    // Metodo para solicitar informacion a traves de un request HTTP GET
    $.get(url, options, onResponse);
}

// Funcion que nos trae un personaje segun el ID que le pasemos
obtenerPersonaje(1);
obtenerPersonaje(2);
obtenerPersonaje(3); */
/**
 * Al ejecutar multiples peticiones asincronicas, nos podemos dar
 * cuenta que el orden de llegada de las respuestas no esta garan-
 * tizado por el orden en que fueron pedidas, pues el asincronismo
 * de JS dependera del tiempo en que responsa cada request y el 
 * orden en que JS los tome y nos lo regrese al documento.
 */

/*
 // == Controlando el flujo de llegada de los Requests (Callback Hell) ==
function obtenerPersonaje(id, callback)
{
    var url = `${API_URL}${PEOPLE_URL.replace(':id', id)}`;

    $.get(url, options, function(personaje) { // Pasamos la onRespone a una
        console.log(`Hola, yo soy ${personaje.name}`); // funcion local
        if(callback) callback(); // Si tenemos callback, lo mandamos a llamar
        // despues de terminar la ejecucion de la funcion
    });
}

// Callback Hell
obtenerPersonaje(1, function() {
    obtenerPersonaje(2, function() {
        obtenerPersonaje(3, function() {
            obtenerPersonaje(4, function() {
                obtenerPersonaje(5, function() {

                })
            })
        })
    })
})
*/

// == Manejando errores de Callbacks ==
/**
 * Lo que haremos es tomar la implementacion pasada, y cambiar el .get de 
 * obtenerPersonaje(), donde lo que haremos es que en vez de ejecutar la funcion
 * del callback con una funcion anonima seria que lo pase tal como parametro
 * y al llamar a la funcion, en vez de enviar la funcion obtenerPersonaje, escribiremos
 * el callback como funcion anonima.
 */

function obtenerPersonaje(id, callback)
{
    var url = `${API_URL}${PEOPLE_URL.replace(':id', id)}`;

    $.get(url, options, callback).fail(function() { // Manejo de error
        console.log(`Sucedió un error. No se pudo obtener el personaje ${id}`);
    });
}

// Y al metodo .get le agregaremos el metodo fail() para detener la ejecucion
// y mostrar un mensaje de error en caso de presentarse un error.


// En la invocacion pasamos callback como una funcion anonima
obtenerPersonaje(1, function(personaje) {
    console.log(`Hola, yo soy ${personaje.name}`);
    
    obtenerPersonaje(2, function(personaje) {
        console.log(`Hola, yo soy ${personaje.name}`);

        obtenerPersonaje(3, function(personaje) {
            console.log(`Hola, yo soy ${personaje.name}`);

            obtenerPersonaje(4, function(personaje) {
                console.log(`Hola, yo soy ${personaje.name}`);

                obtenerPersonaje(5, function(personaje) {
                    console.log(`Hola, yo soy ${personaje.name}`);
                });
            });
        });
    });
});