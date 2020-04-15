using System;

namespace Strings
{
    class Program
    {
        static void Main(string[] args)
        {
            Substring();
            IndexOf();
            Console.WriteLine(SustituirA());
            Console.WriteLine("");
            StartsEndsWith();
            MetodoTrim();
        }

        private static void Substring()
        {
            Console.WriteLine("Metodo Substring");
            string nombre = "Aaron Velazquez";
            string apellido = nombre.Substring(6, 9);
            Console.WriteLine(apellido);
            Console.WriteLine("");
        }

        private static void IndexOf()
        {
            Console.WriteLine("Metodo IndexOf");
            string datos = "Aaron Velazquez Gurrola - Alumno ICCO";
            int position = datos.IndexOf("Gurrola");
            Console.WriteLine("Posicion de inicio de Gurrola: " + position);
            Console.WriteLine("");
        }

        private static string SustituirA()
        {
            string resultado = "";
            Console.WriteLine("Todas las Aa de la cadena en #");
            string datos = "Aaron Velazquez Gurrola - Alumno ICCO";
            for(int i = 0; i < datos.Length; i++)
            {
                if (datos[i] == 'a' || datos[i] == 'A') resultado += "#";
                else resultado += datos[i];
            }
            return resultado;
        }

        private static void StartsEndsWith()
        {
            Console.WriteLine("Metodo starts ends with");
            Console.WriteLine("Ingrese un nombre de archivo");
            string archivo = Console.ReadLine();
            if (archivo.StartsWith("com")) Console.WriteLine("El nombre del archivo inicia con: com");
            else Console.WriteLine("El nombre del archivo NO inicia con: com");
            if(archivo.EndsWith(".dll")) Console.WriteLine("El archivo es un .dll");
            else Console.WriteLine("El archivo no es un .dll");
            Console.WriteLine("");
        }

        private static void MetodoTrim()
        {
            Console.WriteLine("Metodo Trim");
            Console.WriteLine("Ingrese una linea de texto: ");
            string texto = Console.ReadLine();
            texto = texto.Trim();
            Console.WriteLine("Texto con Metodo Trim aplicado: " + texto);
            Console.WriteLine("");
        }
    }
}
