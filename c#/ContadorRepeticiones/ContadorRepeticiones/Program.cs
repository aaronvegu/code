using System;

namespace ContadorRepeticiones
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("¿Cuantos valores enteros desea ingresar en el arreglo?");
            int n = Convert.ToInt32(Console.ReadLine());
            int[] a = new int[n];
            a = CrearArreglo(n);
            Console.WriteLine("Se repiten los valores " + ContarDuplicados(a) + " veces");
        }

        static public int[] CrearArreglo(int n)
        {
            int[] arr = new int[n];
            for(int i = 0; i < n; i++)
            {
                Console.WriteLine("Ingrese valor " + (i + 1) + ": ");
                int value = Convert.ToInt32(Console.ReadLine());
                arr[i] = value;
            }
            Console.WriteLine("Arreglo terminado.");
            return arr;
        }

        static public int ContarDuplicados(int[] a)
        {
            int t = 0, c = 0;
            int[] duplicados = new int[a.Length];
            for (int i = 0; i < a.Length; i++)
            {
                int temp = 0;
                for(int o = 0; o < a.Length; o++)
                {
                    if (a[i] == a[o]) temp++;
                }
                duplicados[i] = temp;
            }
            return t;
        }
    }
}
