// Vamos a resolver el reto de realizar multiples peticiones a una
// API, pero ahora mediante el uso de Promesas, una caracteristica
// de ES6+

// Instanciamos nuestra funcion creada fetchData
const fetchData = require('../utils/fetchData');
// Guardamos la URL de nuestra API
const API = 'https://rickandmortyapi.com/api/character/';

fetchData(API)
    .then(data => { // Obtenemos el num de personajes
        console.log(`Numero de personajes: ${data.info.count}`); 
        return fetchData(`${API}${data.results[0].id}`);
    })
    .then(data => { // Traemos el nombre del primer personaje
        console.log(data.name)
        return fetchData(data.origin.url)
    })
    .then(data => { // Traemos la dimension del personaje
        console.log(data.dimension)
    })
    .catch(e => console.error(e));