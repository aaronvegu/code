// Construccion de funciones asincronas con Promesas
// ES6+

// Estructuracion basica de una promesa
const somethingWillHappen = () => { // Funcion Promesa
    return new Promise((resolve, reject) => { // Retornamos promesa
        if(true)
        {
            resolve('Promesa resuelta');
        }
        else
        {
            reject('Promesa no resuelta');
        }
    });
};

// Ejecucion de una promesa con sus casos de resolucion
somethingWillHappen()
    .then(response => console.log(response))
    .catch(err => console.error(err));



const somethingWillHappen2 = () => {
    return new Promise((resolve, reject) => {
        // Hacemos una ejecucion despues de dos segundos
        if(true)
        { // En caso de exito
            setTimeout(() => {
                resolve('Todo bien!');
            }, 2000);
        }
        else
        { // En caso de rechazo
            const e = new Error("Error!"); // Creamos un obj Error
            reject(error); // Lo devolvemos
        }
    });
};

somethingWillHappen2()
    .then(response => console.log(response)) // Importante poner una funcion
    .then(() => console.log('...despues de dos segundos'))
    .catch(e => console.error(e));

// Podemos usar una Promisa.all() para ejecutar un conjunto de promesas
// y devolver sus respuesta como un arreglo:
// Esta recibe como parametros un arreglo de promesas que queremos ejecutar
Promise.all([somethingWillHappen(), somethingWillHappen2()])
    .then(response => console.log('Array of results: ', response))
    .catch(e => console.error(e));