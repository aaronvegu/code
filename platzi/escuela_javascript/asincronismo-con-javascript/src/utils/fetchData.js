// Aqui tendremos nuestra funcion para traer datos desde una API
// usandola como una herramienta

let XMLHttpRequest = require('xmlhttprequest').XMLHttpRequest;

const fetchData = (url_api) => {
    // Promesa
    return new Promise((resolve, reject) => {
        const xhttp = new XMLHttpRequest();
        xhttp.open('GET', url_api, true);
        xhttp.onreadystatechange = (() => {
            if (xhttp.readyState === 4) {
                (xhttp.status === 200) // If ternario
                    ? resolve(JSON.parse(xhttp.responseText))
                    : reject(new Error('Error ', url_api));
            }
        });
        xhttp.send();
    });   
}

module.exports = fetchData;