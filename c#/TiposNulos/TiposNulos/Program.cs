using System;

namespace TiposNulos
{
    class Program
    {
        static void Main(string[] args)
        {
            int? i = null;
            FuncionHasValue(i);
        }

        static void FuncionHasValue(int? i)
        {
            if (i.HasValue) Console.WriteLine("Tiene valor. Su valor es: " + i.Value);
            else Console.WriteLine("No tiene valor. Es null");
        }
    }
}
