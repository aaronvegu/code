/**
 * En javascript tenemos varios tipos de
 * funciones, entre ellas tenemos:
 * 1. Declarativas
 * 2. Expresivas o Anonimas
 */

 // Declarativas
 function funcionDeclarativa() {
     return 3;
 }
 /**
  * La declarativa se declara para despues
  * mandarla a llamar y utilizarla
  */

 // Expresivas o de Expresión
 var funcionExpresiva = function() {
     return 3;
 }
/**
 * La funcion de expresion lo que hace
 * es declarar una variable sobre la cual
 * se guarda el return de la funcion que se
 * declara despues de la variable, que es la
 * que le asigna su valor. Se le llama anonima
 * pues podemos ver que la funcion declarada
 * despues de la variable no tiene nombre, solo
 * es utilizada para darle valor a la variable
 */

 // Ambas son llamadas de la misma manera:
 funcionDeclarativa();
 funcionExpresiva();

 // Funciones con plantillas de cadena de texto
 function saludo(estudiante) {
    console.log(`Hola ${estudiante}`);
 }