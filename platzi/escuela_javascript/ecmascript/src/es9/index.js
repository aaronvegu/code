// ES9

/** Operador de Reposo
 * Nos permite extraer propiedades de un objeto
 * que aun no ha sido construido
 */
const obj = {
    name: 'Aaron',
    age: 21,
    country: 'MX'
};
// Aqui estamos encapsulando el nombre del objeto
// y guardando todo lo demas en 'all'
let { name, ...all } = obj;
console.log(name, all);
// Podriamos tambien generar un nuevo objeto que
// tome solo la edad y el nombre, pero guardando
// el pais
let {country, ...other} = obj;
console.log(other);

/** Operador de propagacion
 * Nos permite tomar todos los valores de un
 * objeto y llevarlos a otro
 */
 const obj = {
     name: 'Aaron',
     age: 21
 };

 const fullObj = {
     ...obj, // Traemos los valores de obj a fullObj
     country: 'MX'
 };
 console.log(fullObj);

 /** Promise.finally
  * Para saber cuando la promesa o llamado a terminado,
  * para realizar algo en ese momento especifico
  */
const helloWorld = () => { // Promesa verdadera
    return new Promise((resolve, reject) => {
        (true)
        ? resolve('Holaaa')
        : reject(new Error('Test Error'))
    });
};

helloWorld()
    .then(response => console.log(response))
    .catch(error => console.log(error))
    .finally(() => console.log('Finalizo la promesa'));
    // Nuestro caso final (finally)

/** Grupos de datos Regexp
 * Nos permite clasificar informacion en una funcion
 * RegExp y agruparla como nos sea conveniente
 */
const regexpData = /([0-9]{4})-([0-9]{2})-([0-9]{2})/ // creamos reglas para cada grupo
// /(GRUPO 1 -> [ints del 0 al 9]{4 digitos}) ... hasta GRUPO 3/
const match = regexpData.exec('2020-05-29'); // Ejecutamos nuestra info RegExp
// Creamos grupos de informacion en variables
const year = match[1]; // Grupo 1
const month = match[2]; // Grupo 2
const day = match[3]; // Grupo 3

console.log(year, month, day);