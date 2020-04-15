using System;

namespace ParImpar
{
    class Program
    {
        static void Main(string[] args)
        {
            int op = 1;
            while(op == 1) {
                Console.WriteLine("Ingresa un numero: ");
                double i = Convert.ToDouble(Console.ReadLine());
                if (i % 2 == 0)
                {
                    Console.WriteLine("el numero ingresado es par");
                }
                else
                {
                    Console.WriteLine("El numero ingresar es impar");
                }
                Console.WriteLine("¿Desea Continuar?\n1. Continuar 0. Salir");
                op = Convert.ToInt16(Console.ReadLine());
            }
            Console.ReadKey();
        }
    }
}
