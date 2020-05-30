// ES10

/** Array Flat
 * Para aplanar los valores de un arreglo multi-
 * dimensional
 */
let array = [1, 2, 3, [1, 2, 3, [1, 2, 3]]];
console.log(array.flat());

/** Array Map
 * Nos permite mapear nuestro arreglo, ejecutando una
 * funcion sobre cada uno de sus elementos
 */
let array = [1, 2, 3, 4, 5];
// Mapeamos nuestro arreglo, ejecutando nuestra funcion
// por cada cada elemento en el arreglo
console.log(array.flatMap(value => [value, value*2]));

/** Trim
 * Nos permite eliminar los espacios en blanco de un 
 * string
 */
// trimStart()
let hello = '       Hello world';
console.log(hello);
// Eliminamos los espacios en blanco al inicio de una
// string
console.log(hello.trimStart());

// trimEnd()
let hello = 'hello world        ';
console.log(hello);
console.log(hello.trimEnd());

/** Parametro de error opcional en Catch 
 * No es necesario pasar nuestro error como parametro
 * para usarlo en nuestro bloque Catch
*/
try {
    // ... code ...
} catch {
    error // podemos usar nuestro error sin pasarlo como
    // parametro
}

/** Object.fromEntries
 * Podemos pasar el contenido de un arreglo a elementos
 * de un objeto y crearlo, tomando nuestra clave valor del
 * arreglo como propiedad del objeto
 */
let entries = [['name', 'Aaron'], ['age', 21]]; // Arreglo
// Arreglo -> lo pasamos a objeto
console.log(Object.fromEntries(entries));

/** Object Symbol
 * Objeto de tipo simbolo que nos permite acceder a una
 * descripcion
 */
let mySymbol = 'Mi Simbolo';
let symbol = Symbol(mySymbol);
console.log(symbol.description);