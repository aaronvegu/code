// Definicion del constructor de Persona
function Persona(nombre, apellido, peso) 
{
    // Atributos
    this.nombre = nombre,
    this.apellido = apellido,
    this.peso = peso
};

// Declaraciones
const CONSTANTE_DE_PESO = 0.2
const PERIODO = 365; // Periodo de tiempo
var aaron = new Persona("Aaron", "Vegu", 80); // Creacion de la persona a usar

// Funciones
var bajarPeso = persona => persona.peso -= CONSTANTE_DE_PESO; // Funcion para decrementar el peso en base a la constante de peso definida
var subirPeso = persona => persona.peso += CONSTANTE_DE_PESO; // Funcion para incrementar el peso en base a la constante de peso definida
var mostrarInfo = (persona, esInicial) => { // Funcion para imprimir la informacion de la persona, segun si se muestra la info
    if(esInicial)                           // antes de iniciar el periodo de peso o despues, el cual se define como un booleano
    {                                       // en el segundo parametro, siendo TRUE cuando se muestra la info antes de iniciar el periodo
        console.log(`== Antes del Periodo ==
        Nombre: ${persona.nombre} ${persona.apellido}
        Peso: ${persona.peso}kg`);
    } else
    {
        console.log(`== Depues del Periodo ==
        Nombre: ${persona.nombre} ${persona.apellido}
        Peso: ${persona.peso.toFixed(2)}kg
        Dias del Periodo: ${PERIODO}`);
    } // En peso se usa el metodo toFixed() para delimitar los puntos decimales a solo dos
};

// Cuerpo
mostrarInfo(aaron, true);

for(var i = 1; i <= 365; i++) {
    var ran = Math.random();
    if(ran <= 0.25)
    {
        bajarPeso(aaron);
    } else if(ran <= 0.5)
    {
        subirPeso(aaron);
    }
}

mostrarInfo(aaron, false);