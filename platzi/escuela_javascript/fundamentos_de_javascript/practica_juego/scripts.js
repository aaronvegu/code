//Definimos constante para el boton principal
const boton = document.getElementById('btnEmpezar');
// Definimos pads del juego
const padCeleste = document.getElementById('celeste'); // superior izquierdo
const padVioleta = document.getElementById('violeta'); // superior derecho
const padNaranja = document.getElementById('naranja'); // inferior izquierdo
const padVerde = document.getElementById('verde'); // inferior derecho

const ULTIMO_NIVEL = 2; // Ultimo nivel del juego


class Juego
{
    constructor() // Constructor de Juego
    {
        this.inicializar(); // Inicializamos ocultando btn, asignando lvl 1 y creando
            // objeto con cada pad de colores
        this.generarSecuencia(); // Nos genera un arreglo de 10 numeros aleatorios
            // entre 0 y 3, donde cada uno representa un pad de colores
        this.siguienteNivel();
    }

    /**
     * == Metodo para Inicializar el juego == 
     * Oculta nuestro boton de inicio del juego, asi como tambien inicializa los niveles
     * en 1, y nos genera un objeto Colores que contiene cada pad del juego tomandolo
     * del DOM.
     */
    inicializar()
    {
        this.elegirColor = this.elegirColor.bind(this); // Lo ligamos al objeto Juego
        /**
         * ^ Con esto lo que hacemos es enlazar a this.elegirColor con el contexto (this)
         * del objeto Juego en todo momento, aun cuando cambie de contexto a, por ejemplo,
         * Windows.
         */
        this.toggleBoton();
        this.nivel = 1; // Inicializamos los niveles en 1, guardados en var nivel
        this.colores = { // Guardamos los pads en un Objeto llamado colores
            padCeleste, // Si el nombre del atributo es igual al de la variable,
            padVioleta, // podemos omitir su asignacion de valor, pues JS lo agrega
            padNaranja, // automaticamente, teniendo:
            padVerde    // padCeleste: padCeleste == padCeleste
        }
    }

    toggleBoton() // Oculta o muestra el boton segun su estado
    {
        if (boton.classList.contains('hide'))
        {
            boton.classList.remove('hide');
        } 
        else
        {
            boton.classList.add('hide');
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
    {   // Generamos un array con numeros aleatorios entre 0 y 3 dependiendo los niveles del juego
        this.secuencia = new Array(ULTIMO_NIVEL).fill(0).map(n => Math.floor(Math.random() * 4));
    }

    siguienteNivel()
    {
        this.subnivel = 0; // Estamos creando un nuevo atributo para la clase sin necesidad de 
        this.iluminarSecuencia(); // declararlo en el constructor, ahora esta presente globalmente
        this.agregarEventoClick() // Activamos listeners para escuchar evento de eleccion de color
    }

    transformarNumeroAColor(numero)
    {
        switch(numero)
        {
            case 0:
                return 'padCeleste';
            case 1:
                return 'padVioleta';
            case 2:
                return 'padNaranja';
            case 3:
                return 'padVerde';
        }
    }

    transformarColorANumero(color)
    {
        switch(color)
        {
            case 'padCeleste':
                return 0;
            case 'padVioleta':
                return 1;
            case 'padNaranja':
                return 2;
            case 'padVerde':
                return 3;
        }
    }

    iluminarSecuencia()
    {
        for(let i = 0; i < this.nivel; i++) // Para i del for se utiliza let
        {
            const color = this.transformarNumeroAColor(this.secuencia[i]);
            setTimeout(() => {
                this.iluminarColor(color)
            }, 1000 * i); // Ir iluminando
            // conforme va avanzando la secuencia de colores
        }
    }

    iluminarColor(color)
    {
        this.colores[color].classList.add('light');
        setTimeout(() => this.apagarColor(color), 350);
    }

    apagarColor(color)
    {
        this.colores[color].classList.remove('light');
    }
    
    agregarEventoClick() // Activar listeners para evento de eleccion de color
    {
        this.colores.padCeleste.addEventListener('click', this.elegirColor);
        this.colores.padNaranja.addEventListener('click', this.elegirColor);
        this.colores.padVerde.addEventListener('click', this.elegirColor);
        this.colores.padVioleta.addEventListener('click', this.elegirColor);
    }

    eliminarEventoClick() // Desactivar listeners para evento de eleccion de color
    {
        this.colores.padCeleste.removeEventListener('click', this.elegirColor.bind(this));
        this.colores.padNaranja.removeEventListener('click', this.elegirColor.bind(this));
        this.colores.padVerde.removeEventListener('click', this.elegirColor.bind(this));
        this.colores.padVioleta.removeEventListener('click', this.elegirColor.bind(this));
    }

    gameWinner()
    {
        swal('Simon Dice', '¡Felicidades, has ganado el juego!', 'success') // Devuelve una Promise
            .then(() => this.inicializar())
    }

    gameOver()
    {
        swal('Simon Dice', 'Lo lamentamos, perdiste :(', 'error') // Devuelve una Promise
            .then(() => {
                this.eliminarEventoClick();
                this.inicializar();
            })
    }

    elegirColor(ev) // ev es el metodo llamado cuando agregagamos listeners de eventos
    {
        //console.log(ev); // Para observar el objeto del evento
        const nombreColor = ev.target.dataset.color;
        const numeroColor = this.transformarColorANumero(nombreColor);
        this.iluminarColor(nombreColor);
        if(numeroColor === this.secuencia[this.subnivel]) // Si acierta el color:
        {
            this.subnivel++;
            if(this.subnivel === this.nivel)
            {
                this.nivel++;
                this.eliminarEventoClick(); // Desactivamos listeners para eventos de color
                if(this.nivel === (ULTIMO_NIVEL + 1))
                {
                    this.gameWinner();
                }
                else
                {
                    setTimeout(() => this.siguienteNivel(), 1000); // Agregamos un delay para
                    // cambiar de nivel cuando lo pasamos correctamente
                }
            }
        }
        else // De no haber acertado la secuencia de colores:
        {
            this.gameOver();
        }
    }

}

function empezarJuego()
{
    window.juego = new Juego(); // Solo para debuggear metemos la var juego al componente
        // window para poder llamarla desde la consola y ver su comportamiento
}