using System;

namespace CalculoEntero
{
    class Program
    {

        static void Main(string[] args)
        {
            Console.WriteLine("Ingresa un numero entero, el cual será tratado como numero de días, y se te devolverá el numero de años, meses, semanas y dias");
            int d = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine(Calculo(d));

        }

        private static int Calculo(int a)
        {

            return 0;
        }
    }
}
