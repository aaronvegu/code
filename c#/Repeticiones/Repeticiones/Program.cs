using System;

namespace Repeticiones
{
    class Program
    {
        static void Main(string[] args)
        {
            int bandera = 1;
            Lista listaPrincipal = new Lista();
            Console.WriteLine("//   Contador de Repeticiones  //");
            do
            {
                Console.WriteLine("Ingrese un entero: ");
                int valor = Convert.ToInt32(Console.ReadLine());
                listaPrincipal.Add(valor);
                Console.WriteLine("¿Desea agregar otro valor?\n0.No    1.Si");
                bandera = Convert.ToInt32(Console.ReadLine());
            } while (bandera == 1);
            Console.WriteLine("\nResultados: \n");
            Console.WriteLine(listaPrincipal.ContentToString());
            Console.WriteLine("/// Programa Terminado ///");
        }
    }
}
