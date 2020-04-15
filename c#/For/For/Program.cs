using System;

namespace For
{
    class Program
    {
        static void Main(string[] args)
        {
            BucleFor();
            UsoForEach();
        }

        private static void BucleFor()
        {
            Console.WriteLine("Uso del Bucle For");
            for (int i = 1; i <= 5; i++)
            {
                Console.WriteLine("Iteracion: " + i);
            }
        }

        private static void UsoForEach()
        {
            string[] maestros =
            {
                "Cesar", "Virgilio", "Patino", "Pablo", "Salvador"
            };
            Console.WriteLine("Lista de Maestros");
            foreach(string maestro in maestros)
            {
                Console.WriteLine("Maestro " + maestro);
            }
        }
    }
}
