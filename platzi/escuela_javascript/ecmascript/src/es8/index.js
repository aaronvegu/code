/** ES8
 * En esta version de JS se implemento Async await asi como
 * otras caracteristicas importantes
 */

/** == Object.entries
 * Nos permite convertir el contenido de un objeto en valores
 * de una matriz o arreglo
 */
const data = { // Objeto
    frontend: 'Eduardo',
    backend: 'Quintero',
    data: 'Aaron'
}
// Convertimos el objeto en una matriz
const entries = Object.entries(data);
console.log(entries);

// Asi como tambien nos permite convertir los valores
// del objeto en valores dentro de un arreglo:

const data = { // Objeto
    frontend: 'Eduardo',
    backend: 'Quintero',
    data: 'Aaron'
}
// Convertimos sus valores en un arreglo
const values = Object.values(data);
console.log(values);

/** Padding
 * Este método rellena la cadena actual con una cadena dada
 * (repetida eventualmente) de modo que la cadena resultante alcance 
 * una longitud dada. El relleno es aplicado desde el inicio (izquierda) 
 * de la cadena actual.
 */
// padStart() para rellenar el string desde el inicio
const hello = 'Hello';
console.log(hello.padStart(11, '----> '));

// padEnd() para rellenar el string al final
const list = 'Apple';
console.log(list.padEnd(11, ' -----'));