using System;

namespace Arrays
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] pilotos = new string[5] { "Alonso", "Hamilton", "Verstappen", "Sainz", "Perez"};
            Console.WriteLine(pilotos[2] + '\n');
            pilotos[1] = "Vettel";

            // Recorrer un arreglo
            for(int i = pilotos.Length - 1; i >= 0 ; i--)
            {
                Console.WriteLine(pilotos[i]);
            }

            Console.WriteLine("============");

            foreach(string piloto in pilotos)
            {
                Console.WriteLine(piloto);
            }
        }
    }
}
