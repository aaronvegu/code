//Definimos constante para el boton principal
const boton = document.getElementById('btnEmpezar');
// Definimos pads del juego
const padCeleste = document.getElementById('celeste'); // superior izquierdo
const padVioleta = document.getElementById('violeta'); // superior derecho
const padNaranja = document.getElementById('naranja'); // inferior izquierdo
const padVerde = document.getElementById('verde'); // inferior derecho

class Juego
{
    constructor() // Constructor de Juego
    {
        this.inicializar(); // Inicializamos ocultando btn, asignando lvl 1 y creando
            // objeto con cada pad de colores
        this.generarSecuencia(); // Nos genera un arreglo de 10 numeros aleatorios
            // entre 0 y 3, donde cada uno representa un pad de colores
    }

    /**
     * == Metodo para Inicializar el juego == 
     * Oculta nuestro boton de inicio del juego, asi como tambien inicializa los niveles
     * en 1, y nos genera un objeto Colores que contiene cada pad del juego tomandolo
     * del DOM.
     */
    inicializar()
    {
        boton.classList.add('hide'); // Le agregamos la clase css hide al boton
        this.nivel = 1; // Inicializamos los niveles en 1, guardados en var nivel
        this.colores = { // Guardamos los pads en un Objeto llamado colores
            padCeleste, // Si el nombre del atributo es igual al de la variable,
            padVioleta, // podemos omitir su asignacion de valor, pues JS lo agrega
            padNaranja, // automaticamente, teniendo:
            padVerde    // padCeleste: padCeleste == padCeleste
        }
    }

    /**
     * == Metodo para generar una secuencia de numeros ==
     * Este metodo es encargado de generar un array aleatorio de 10 numeros entre 0 y 3
     * que representan cada pad del juego. Este array se encargara de la secuencia que
     * tomara el juego.
     * 
     * 1. Lo primero es generar un array de 10 espacios mediante su constructor (new Array(espacios))
     * Lo que queremos es aplicar la funcion map() sobre cada elemento del array, para que se
     * encargue de generar un numero aleatorio con cada elemento, pues recordemos que map() lo
     * que hace es tomar cada elemento de una arreglo y aplicar la funcion que le definamos.
     * 2. Para aplicar map() primero deben existir elementos, por eso llenamos nuestro array con
     * 10 enteros 0, mediante el metodo fill()
     * 3. Una vez que tenemos 10 elementos, podemos aplicar map() sobre cada uno
     * 4. Usamos el metodo random() del modulo Math para generar un numero aleatorio entre 0.0 y 0.9,
     * lo cual al multiplicarlo por 4 nos dara numeros entre 0.0 y 3.99, que como son decimales,
     * los pasamos a enteros con floor(), que tomara el valor y lo redondeara hacia el entero menor,
     * teniendo lo que queremos, numeros de entre 0 y 3, correspondientes a cada uno de los pads. 
     */
    generarSecuencia()
    {   // Generamos un array con 10 numeros aleatorios entre 0 y 3
        this.secuencia = new Array(10).fill(0).map(n => Math.floor(Math.random() * 4));
    }
}

function empezarJuego()
{
    window.juego = new Juego(); // Solo para debuggear metemos la var juego al componente
        // windows para poder llamarla desde la consola y ver su comportamiento
}