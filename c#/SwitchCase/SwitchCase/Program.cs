using System;

namespace SwitchCase
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hola, ingresa un mes: ");
            string i = Console.ReadLine();
            CalcularMes(i);
            Console.ReadKey();
        }

        public static void CalcularMes(string i)
        {
           switch (i)
            {
                // Concatenamos un rango de casos
                case "enero":
                case "marzo":
                case "mayo":
                case "julio":
                case "agosto":
                case "octubre":
                case "diciembre":
                    Console.WriteLine("El mes tiene 31 días");
                    break;
                case "febrero":
                    Console.WriteLine("El mes tiene 28 días");
                    break;
                case "abril":
                case "junio":
                case "septiembre":
                case "noviembre":
                    Console.WriteLine("El mes tiene 30 días");
                    break;
                default:
                    Console.WriteLine("Error al calcular los días, revisa haber ingresado un mes valido");
                    break;

            }
        }
    }
}
