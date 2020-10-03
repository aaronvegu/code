// Vamos a consumir una API de Rick y Morty para obtener informacion
// sobre la serie

// Trabajaremos sobre Nodejs, por lo mismo utilizaremos la dependencia
// XMLHTTPRequest para realizar las peticiones a la api

// Instalacion del modulo en terminal:
// npm install xmlhttprequest --save

// Instanciamos el modulo
let XMLHttpRequest = require('xmlhttprequest').XMLHttpRequest;

// API a la que haremos la peticion
let API = 'https://rickandmortyapi.com/api/character/';

// Utilizaremos callbacks para las llamadas

// Creamos la funcion fetchData para traer informacion desde la API
function fetchData(url_api, callback) // recibe url del api y un callbaxk
{
    // Generamos un objeto de la instancia que trajimos
    let xhttp = new XMLHttpRequest();

    // Hacemos un llamado a una url mediante nuestra instancia (abrimos conex)
    xhttp.open('GET', url_api, true); // Le decimos, en orden:
        // Que el metodo sera GET, luego la url de donde traera la info
        // y por ultimo indicamos que queremos trabajar de manera asincrona

    // Escuchamos la conexion abierta
    // Y de haber un cambio en el estado, ejecutar una funcion que puede
    // recibir un evento como parametro
    // onreadystatechange define una funcion que sera llamada cuando el 
    // estado de readyState cambia
    // https://www.w3schools.com/xml/ajax_xmlhttprequest_response.asp
    xhttp.onreadystatechange = function (event) { // Funcion a llamar
        /** Hay cinco estados:
         * 0: Peticion NO inicializada
         * 1: Conexion con el servidor establecida
         * 2: Peticion recibida
         * 3: Peticion siendo procesada
         * 4: Peticion finalizada y respuesta lista
         */
        if(xhttp.readyState === 4) // Si la peticion finalizo:
        {
            // Ejecutamos otra llamada para conocer el estatus de la 
            // respuesta, donde tenemos 3 estatus principales:
            // 200: OK
            // 403: Forbideen
            // 404: Pagina no encontrada
            if(xhttp.status === 200) // Si todo salio bien:
            {
                // Ahora si le pasamos el callback a nuestra funcion
                callback(null, JSON.parse(xhttp.responseText)); // Primer parametro es el error
                // y el segundo es la respuesta a la peticion en texto
                // que la parseamos a JSON
            }
            else // De haber fallado
            {   // Creamos un nuevo error
                const error = new Error('Error: ' + url_api);
                // Y pasamos a nuestro callback el error (primer parametro)
                // y ninguna respuesta desencadenada
                return callback(error, null);
            }
        }
    }
    // Al final enviamos la solicitud al servidor
    xhttp.send();
}

// Queremos realizar multiples llamados a nuestro API conforme recibimos
// respuestas, esto lo lograremos mediante callbacks

// Ejecutamos nuestra funcion con la direccion de la api y un callback
// que hara multiples llamadas a la API
fetchData(API, function(error1, data1) { // <- callback
    // Si hay errores
    if(error1) return console.error(error1); // mandamos error a consola
    // De no haber error, usamos nuestra funcion de llamada de nuevo,
    // pero ahora le pasamos como url nuestra API mas el objeto
    // results en su primer indice, pues sabemos que results almacena
    // todos los datos de los personajes y obtenemos el id del primer 
    // personaje
    fetchData(API + data1.results[0].id, function(error2, data2) {
        // De igual manera revisamos que no haya error pero ahora en 
        // nuestro segundo llamado, con la peticion a characters/result/id/origin/url
        if(error2) return console.error(error2);
        fetchData(data2.origin.url, function(error3, data3) {
            if(error3) return console.error(error3);
            // Imprimimos los valores obtenidos
            console.log('Personajes disponibles: ' + data1.info.count); // Mostramos el total de personajes
            // solicitando tal informacion a la API
            console.log('Nombre del personaje: ' + data2.name); // Obtenemos el nombre del personaje con id 0
            console.log('Dimension del personaje: ' + data3.dimension); // Traemos la dimension del personaje
            // una vez que hicimos peticion a la url dentro del origen
        });
    });
});
// Con esto realizamos un callback que realiza 3 llamadas dentro de la API
// conforme va recibiendo informacion de la llamada anterior, y asi sucesivamente

// Como no estamos utilizando promises, y estamos utilizando
// multiples llamadas mediante callbacks, tenemos un callback hell

/**
 * Por ultimo creamos una instruccion en nuestra configuracion
 * de nuestra app Node, yendo a package.json y creando un nuevo
 * script llamado challenge que ejecuta challenge.js, asi:
 * "challenge": "node src/callback/challenge.js"
 * 
 * Ejecutando en consola:
 * npm run challenge
 */