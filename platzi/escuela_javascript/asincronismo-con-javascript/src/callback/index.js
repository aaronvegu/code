// Callbacks
// Estas son funciones que reciben como parametro otra funcion, por 
// lo tanto estas ejecutan tal funcion una vez que son llamadas mediante
// un llamado asincrono

// Funcion que suma dos valores
function suma(num1, num2)
{
    return num1 + num2;
}

// Nuestro callback que recibe la funcion suma como parametro y la
// ejecuta con los otros dos parametros cuando es llamada
function calc(num1, num2, callback)
{
    return callback(num1, num2);
}

console.log(calc(4, 5, suma));

// === Otro ejemplo de callback

// Nuestra funcion callback que se ejecutara despues de 3 segundos
function date(callback)
{
    console.log(new Date); // Imprime la fecha actual
    setTimeout(function () { // Espera 3 segundos y ejecuta el callback
        let date = new Date; // con la fecha actual como parametro
        callback(date);
    }, 3000);
}

// Nuestro funcion que pasaremos como parametro del callback
function printDate(dateNow)
{
    console.log(`La fecha es: ${dateNow}`);
}

// Ejecutamos date como callback
date(printDate);