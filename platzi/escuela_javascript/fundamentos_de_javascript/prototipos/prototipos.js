// Prototipo de Persona
function Persona (nombre, apellido, altura)
{
    this.nombre = nombre;
    this.apellido = apellido;
    this.altura = altura;
}

// Creacion de Funciones para nuestra clase Persona
// Indicando que tal funcion pertenece al prototipo Persona
Persona.prototype.saludar = function()
{
    console.log(`Hola, me llamo ${this.nombre} ${this.apellido}`); // Debemos utilizar this
}

Persona.prototype.soyAlto = function()
{
    if(this.altura >= 180) console.log(`Soy alto`);
    else console.log(`No soy alto`);
}

// Creacion del objeto a traves del prototipo creado
var aaron = new Persona('Aaron', 'Vegu', 179);