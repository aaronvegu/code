/**
 * A partir del lanzamiento del ECMAScript del 2015 se integro el uso de "clases"
 * para la creacion de objetos, tal como se suele utilizar en otros lenguajes.
 * Solo que no debemos olvidar que aunque parecen Clases e incluso se usa la palabra
 * class y constructores, estos no dejan de ser prototipos.
 */

// Declaracion de una "Clase"
class Persona  // Clase
{
    constructor(nombre, apellido, altura) // Constructor de la clase (parametros)
    {
        this.nombre = nombre;       // Cuerpo del constructor
        this.apellido = apellido;
        this.altura = altura;
    }

    // Metodos
    Saludar(fn) // No es necesario utilizar la palabra function
    {
        console.log(`Hola, mi nombre es ${this.nombre} ${this.apellido}`);
        if(fn) fn(this.nombre, this.apellido, false); // Funcion como parametro
    }
    soyAlto() 
    {
        return this.altura > 1.8;
    }
}

/**
 * En js la Herencia de Clases se logra con la palabra extends, con la sig sintaxis:
 *      class ClaseHija extends ClasePadre {}
 * Y dentro del cuerpo creamos su contructor tal como cualquier otra clase,
 * pero antes de todo, dentro del constructor, debemos llamar a la clase Padre para
 * de ahi construir el constructor propio de la clase Hija. Siempre despues de haber
 * llamado a la clase padre, asi:
 *      super(//parametros//)
 * Y posteriormente, fuera del constructor, podemos definir Metodos nuevos para la 
 * clase hija o incluso sobreescribir los metodos heredados, pues al realizar el
 * extends la clase hija obtiene los metodos del padre.
 */

 // Herencia
 class Desarrollador extends Persona // Marcamos la herencia
 {
    constructor(nombre, apellidos, altura) // Constructor de Desarrollador
    {
        super(nombre, apellidos, altura) // Clase Padre con sus parametros necesarios
        /**
         * Aqui iria el cuerpo de construccion de la nueva clase
         */
    }

    Saludar(fn) // Sobreescritura de Metodos
    {
        console.log(`Hola, mi nombre es ${this.nombre} ${this.apellido} y soy desarrollador`);
        if(fn) fn(this.nombre, this.apellido, true); // Funcion como parametro
    }
    Programar() // Metodo propio de la Clase Hija Desarrollador
    {
        console.log(`${this.nombre} esta programando...`);
    }
 }

 // Funciones como parametro
 function responderSaludo(nombre, apellido, esDev)
 {
    if(esDev) console.log(`Buen dia, desarrollador(a) ${nombre} ${apellido}`);
    else console.log(`Buen dia, ${nombre} ${apellido}`);
 }