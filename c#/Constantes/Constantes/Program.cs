using System;

namespace Constantes
{
    class Program
    {
        // Calculo del radio de un circulo
        public const double PI = 3.141592; // Valor de PI
        // Calculo de tiempo en llegar al sol a la
        // velocidad de la luz
        public const int LUZ = 300000; // Velocidad de la luz en Km/s
        public const int SOL = 14900000; // Distancia al sol en KMs

        static void Main(string[] args)
        {
            Console.WriteLine("\t// Menu //\n");
            Console.WriteLine("0. Calcular Radio\n1. Tiempo en llegar al sol");
            Console.WriteLine("¿Que programa desea ejecutar?\n");
            int opc = Convert.ToInt16(Console.ReadLine());

            switch(opc)
            {
                case 0:
                    double rad;
                    Console.WriteLine("Calcular\tRadio \nCon constante PI");
                    Console.WriteLine(PI);
                    Console.WriteLine("Introduzca el valor del radio: ");
                    rad = Convert.ToDouble(Console.ReadLine());
                    double r = PI * (rad * rad);
                    Console.WriteLine("El radio es: {0}, y el area del circulo es: {1}", rad, r);
                    Console.ReadKey();
                    break;
                case 1:
                    double tiempo = CalcularTiempo();
                    Console.WriteLine("A la velocidad de la luz, tardariamos {0} segundos en llegar al sol", tiempo);
                    Console.ReadKey();
                    break;
            }

            

            

        }

        static double CalcularTiempo()
        {
            double tiempo = SOL / LUZ;
            return tiempo;
        }

    }
}
