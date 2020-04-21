var Quintero = {
    nombre: 'Quintero',
    altura: 1.80,
    edad: 21
};

var Bryan = {
    nombre: 'Bryan',
    altura: 1.76,
    edad: 20
};

var Eduardo = {
    nombre: 'Eduardo',
    altura: 1.74,
    edad: 23
};

var Andres = {
    nombre: 'Andres',
    altura: 1.65,
    edad: 26
};

var Brenda = {
    nombre: 'Brenda',
    altura: 1.76,
    edad: 21
};

/**
 * Para filtrar un array podemos utilizar el metodo filter()
 * el cual nos devuelve un nuevo arreglo que se cumpla con la
 * condicion pasada como parametro. Esta condicion debe estar
 * dada por una funcion */

// Funcion que servira como filtro
var esAltx = persona => persona.altura > 1.75;

 var personas = [Quintero, Bryan, Eduardo, Andres, Brenda];

 var personasAltas = personas.filter(esAltx); // Realizamos un nuevo
 // arreglo a partir del filtro

 /*
 Se puede realizar el filtro del arreglo con una funcion anonima
 dentro de filter(), o tener la funcion con la condicion separada,
 tal como en el primer ejemplo.

 var personasAltas = personas.filter(function (persona) {
     return persona.altura > 1.75;
 });
 */

 console.log(personasAltas);

 // Modificar personas

 // Funcion para pasar altura a cms, devolviendo un nuevo objeto
 var alturaACms = persona => ({  // con el return de la arrow function
    ...persona,
    altura: persona.altura *= 100
 });

 var personasAlturaEnCms = personas.map(alturaACms); // Guardamos el 
 // nuevo objeto en una nueva variable, pues es lo que retorna nuestra
 // funcion

 console.log(personasAlturaEnCms);

 // Uso de Reduce()

 /**
  * El método reduce() nos permite reducir, mediante una función que se 
  * aplica a cada uno de los elemento del array, todos los elementos de 
  * dicho array, a un valor único.
  */

 const sumador = (acum, { edad }) => acum += edad;

  var edadTotal = personas.reduce(sumador, 0);
  // Reduce recibe dos parametros, la funcion que realizara la accion
  // y el valor de la variable que queremos reducir (acumulador)

  console.log(`Edad total: ${edadTotal}`);

