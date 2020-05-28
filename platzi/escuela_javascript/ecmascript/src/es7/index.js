/** == Include()
 * El método includes() determina si una matriz incluye un determinado elemento, 
 * devuelve true o false según corresponda.
 */
let numbers = [1, 2, 3, 4, 5, 6, 7];
let n = 5;

// Uso de include como una condicional
if (numbers.includes(n))
{
    console.log(`Sí contiene un ${n}`);
}
else
{
    console.log(`No contiene un ${n}`);
}

// Antes lograr esto significaba mayor codigo y el uso de indexOf()


/** == Operaciones en forma exponencial
 * Nos permite hacer uso de operaciones exponenciales mediante el
 * uso de los dobles asteriscos
 */

let base = 4;
let exponent = 3;
let result = base ** exponent;

console.log(result);