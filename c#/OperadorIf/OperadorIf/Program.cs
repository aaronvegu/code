using System;

namespace OperadorIf
{
    class Program
    {
        static void Main(string[] args)
        {
            int op = 1;
            while (op == 1)
            {
                Console.WriteLine("Hola, ingrese el promedio del alumno: ");
                double i = Convert.ToDouble(Console.ReadLine());
                Console.WriteLine(Resolucion(i));
                Console.WriteLine("Desea repetir el programa?");
                Console.WriteLine("1. Continuar 0. Salir");
                op = Convert.ToInt16(Console.ReadLine());
            }
            Console.ReadKey();
        }

        // Metodo con estructura if tradicional
        public static string Resolucion(double c)
        {
            string r;
            if (c >= 11)
            {
                r = "Valor fuera de rango";
            }
            else
            {
                if (c >= 6)
                {
                    r = "Aprobatorio";
                }
                else if (c < 6 && c >= 5)
                {
                    r = "Extra";
                }
                else
                {
                    r = "Reprobado";
                }
            }
            return r;
        }

        // Metodo con operador ternario
        public static string ResolucionTern(double c)
        {
            string r = "El alumno ha ";
            return r += c >= 6 ? "aprobado." : "reprobado.";
        }
    }
}
