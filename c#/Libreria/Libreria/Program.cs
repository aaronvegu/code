using System;
using System.Collections;

namespace Libreria
{
    class Program
    {
        //Propiedades
        static Hashtable Libros = new Hashtable();

        // Metodos
        static int MostrarMenu()
        {
            Console.WriteLine("== Menu ==");
            Console.WriteLine("1. Añadir libro\n2. Mostrar todos los libros\n" +
                "3. Buscar libro\n4. Borrar libro\n5. Salir");
            Console.WriteLine("Seleccione la opción deseada: ");
            int opc = Convert.ToInt32(Console.ReadLine());
            return opc;
        }

        static void AgregarLibro()
        {
            Console.WriteLine("== Agregar Libro ==");
            Console.WriteLine("Se creara un nuevo registro\n" +
                "Ingrese el codigo del libro: ");
            int clave = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Ingrese el titulo del Libro: ");
            String titulo = Convert.ToString(Console.ReadLine());
            try
            {
                Libros.Add(clave, titulo);
            }
            catch
            {
                Console.WriteLine("Codigo existente, intente con otro codigo.");
                AgregarLibro();
            }
            Console.WriteLine("Registro agregado exitosamente");
        }

        static void MostrarLibros()
        {
            if (Libros.Count == 0)
            {
                Console.WriteLine("Registros Vacios");
                return;
            }
            int n = 1;
            Console.WriteLine("== Libros Registrados ==");
            foreach (DictionaryEntry elemento in Libros)
            {
                Console.WriteLine(n + ". Clave: " + elemento.Key + " | Titulo: " +
                    elemento.Value);
                n++;
            }
            Console.WriteLine("== Fin ==");
        }

        static void BuscarLibro(int clave)
        {
            if (Libros.ContainsKey(clave))
            {
                Console.WriteLine("Clave: " + clave + " | Titulo: " + Libros[clave]);
            }
            else Console.WriteLine("El libro con el codigo ingresado no existe");
        }

        static bool BorrarLibro(int clave)
        {
            if (Libros.ContainsKey(clave))
            {
                Libros.Remove(clave);
                return true;
            }
            else return false;
        }

        static void Main(string[] args)
        {
            int opc = 0;
            while(opc != 5)
            {
                opc = MostrarMenu();
                switch (opc)
                {
                    case 1:
                        AgregarLibro();
                        break;

                    case 2:
                        MostrarLibros();
                        break;

                    case 3:
                        {
                            Console.WriteLine("== Mostrar Libros ==");
                            Console.WriteLine("Inserte el codigo del libro a buscar: ");
                            int clave = Convert.ToInt32(Console.ReadLine());
                            BuscarLibro(clave);
                            break;
                        }

                    case 4:
                        {
                            Console.WriteLine("== Eliminar Libro ==");
                            Console.WriteLine("Inserte el codigo del libro a borrar: ");
                            int clave = Convert.ToInt32(Console.ReadLine());
                            if (BorrarLibro(clave)) Console.WriteLine("Libro Eliminado");
                            else Console.WriteLine("Libro no encontrado, no pudo ser eliminado");
                            break;
                        }

                    case 5:
                        Console.WriteLine("== Programa Terminado ==");
                        break;

                    default:
                        Console.WriteLine("Opcion no valida");
                        break;
                }
                Console.WriteLine("Ingrese la opcion deseada:\n1. Continuar 5. Salir");
                opc = Convert.ToInt32(Console.ReadLine());
            }
        }
    }
}
