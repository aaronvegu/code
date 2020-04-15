using System;

namespace While
{
    class Program
    {
        static void Main(string[] args)
        {
            UsoDeBrake();
            UsoDeContinue();
            DoWhile();
        }

        private static void UsoDeBrake()
        {
            int i = 1;
            Console.WriteLine("Uso de Brake");
            while (i <= 10)
            {
                if (i == 5)
                {
                    break;
                }
                Console.WriteLine(i);
                i++;
            }

        }

        private static void UsoDeContinue()
        {
            int i = 0;
            Console.WriteLine("Uso de Continue");
            while (i < 10)
            {
                i++;
                if (i%2 == 0)
                {
                    continue;
                }
                Console.WriteLine(i);
            }
        }

        private static void DoWhile()
        {
            Console.WriteLine("Uso de Do While");
            int n = 10;
            do
            {
                Console.WriteLine(n);
            } while (n < 5);
        }
    }
}
