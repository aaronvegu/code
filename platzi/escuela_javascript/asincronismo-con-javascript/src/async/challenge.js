// Instanciamos nuestra funcion fetchData y establecemos nuestra
// URL de la API
const fetchData = require('../utils/fetchData');
const API = 'https://rickandmortyapi.com/api/character/';

const anotherFunction = async (url_api) => {
    try {
        // Realizamos las peticiones pertinentes a la API
        const data = await fetchData(url_api);
        const character = await fetchData(`${url_api}${data.results[0].id}`);
        const origin = await fetchData(character.origin.url);

        // Imprimimos los valores traidos
        console.log(data.info.count); // Nunero de personajes
        console.log(character.name); // Nombre del personaje
        console.log(origin.dimension); // Dimension del personaje
    } catch (error) {
        console.error(error);
    }
}

// Ejecucion
console.log('Before...');
anotherFunction(API);
console.log('After');