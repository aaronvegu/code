using System;

namespace ContarDias
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hola, ingresa un numero entero positivo de dias");
            int t = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine(Contador(t));
        }

        static public string Contador(int n)
        {
            string s = n + " dias son:";
            int a = n / 365;
            s += (" " + a + " año(s),");
            int m = (n - (365*a)) / 30;
            s += (" " + m + " mes(es),");
            int sem = (n - ((365*a)+(30*m)))/7;
            s += (" " + sem + " semana(s),");
            int d = (n - ((365 * a) + (30 * m) + (7 * sem)));
            s += (" " + d + " dia(s).");
            return s;
        }
    }
}
