// Before ES6
function newFunction(name, age, country)
{
    var name = name || 'Aaron';
    var age = age || 21;
    var country = country || 'MX';
    console.log(name, age, country);
}

// ES6
// Nos permite declarar valores por defecto en los parametros
function newFunctionES6(name = 'Aaron', age = 21, country = 'MX')
{
    console.log(name, age, country);
}

newFunctionES6();
newFunctionES6('Ricardo', 23, 'CO');


// === Template Literal ===

// Before ES6
let hello = 'Hello';
let world = 'World';
console.log(hello + " " + world);

// ES6
console.log(`${hello} ${world}`);


// === Multilinea ===

// Before ES6
let lorem = "Lorem ipsum dolor sit amet, consectetur adipiscing elit,\n"
+ "sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";

// ES6
let loremES6 = `Lorem ipsum dolor sit amet, consectetur adipiscing elit,
sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.
`;

console.log(lorem);
console.log(loremES6);


// === Desestructuracion  de Elementos ===

let person = {
    name: 'Aaron',
    age: 21,
    country: 'MX'
}

// Before ES6
console.log(person.name, person.age);

// ES6
// Desestructuracion del objeto person en variables:
let = {name, age} = person;
console.log(name, age);


// === Operador de Propagacion (Spread Operator) ===

let team1 = ['Oscar', 'Julian', 'Ricardo'];
let team2 = ['Valeria', 'Jessica', 'Camila'];

// Usamos el operador de propagacion para unir elementos
let education = ['David', 'Diana', ...team1, ...team2];

console.log(education);


// === Variables Let y Const ===

// Con Let nuestra variable declarada solo existe en el 
// scope local en el que sera utilizada

// Definidos dos scopes para cada variable:
{
    var variableGlobal = 'Valor global';
}

{
    let variableLet = 'Scope local';
    console.log(variableLet);
}

console.log(variableGlobal);
// console.log(variableLet); Aqui la variable no esta
// definida

// Las variables const son constantes que no pueden tener
// reasignacion de valores en el codigo


// === Propiedad de objetos mejorada ===

let name = 'Aaron';
let age = 32;

// Declaracion de Atributos
// Before ES6
obj = { name: name, age: age };

// ES6
obj2 = { name, age };
// De esta manera realiza la asignacion del valor con el
// mismo nombre con que es llamado el elemento

console.log(obj2);


// === Arrow Functions ===

const names = [
    { name: 'Aaron', age: 21 },
    { name: 'Quintero', age: 21 }
];

// Iteramos el arreglo names
let listOfNames = names.map(function (item) {
    console.log(item.name);
});
// Utilizando una funcion anonima para nuestra funcion
// map()

// Ahora solo utilizamos una arrow function con parametro y su return
let listOfNames2 = names.map(item => console.log(item.name));

// Otro ejemplo de arrow function:
const square = num => num * num;


// === Promises ===

// Creacion de la Promise
const helloPromise = () => {
    return new Promise((resolve, reject) => {
        if(true) resolve('Hey!'); // false para provocar error
        else reject('Ups!, ha habido un error');
    });
}

// Ejecucion de la Promise segun resultado
helloPromise()
    .then(response => console.log(response))
    .then(() => console.log('Se resolvio exitosamente la promesa'))
    .catch(error => console.log(error))


// === Clases y Objetos ===

// Creamos una clase:
class calculator {
    // Clase Constructora
    constructor()
    {
        this.valueA = 0;
        this.valueB = 0;
    }

    // Metodo de suma
    sum(valueA, valueB)
    {
        this.valueA = valueA;
        this.valueB = valueB;
        return this.valueA + valueB;
    }
}

// Instanciamos un objeto de tipo calculator
const calc = new calculator();
console.log(calc.sum(3, 2));


// === Modulos ===
// Nos permite tener distintos modulos con logica separada
// para nuestros programas y reutilizar este codigo mediante modulos

import { hello } from './module';

hello();


// === Generadores (Generators) ===
// Es un tipo especial de funcion que nos retorna una serie de valores
// segun el algoritmo definido dentro del generator, o segun los steps
// creados en el.
// Retorna un Yield, pues recuerda en que paso se quedo y va continuando
// la secuencia conforme se le van pidiendo sus siguientes valores

function* helloWorld() // con * indicamos que es un generador
{
    if (true)
    {
        yield 'Hello, ';
    }
    if (true)
    {
        yield 'world!';
    }
};

const generatorHello = helloWorld();

console.log(generatorHello.next().value); // Step 1
console.log(generatorHello.next().value); // Step 2
console.log(generatorHello.next().value); // Step 3 -> undefined

/**
 * Hasta aqui son las implementacion o cambios mas relevantes agregados
 * en la version ES6 del anio 2015.
 */