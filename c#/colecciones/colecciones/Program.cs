using System;
using System.Collections;
using System.Collections.Generic;
//using System.Linq; // Para base de datos y colecciones

namespace colecciones
{
    class Program
    {
        // Metodos

        // Implementacion de un Stack
        private static void Pila()
        {
            Stack Pila = new Stack();

            Pila.Push(50);
            Pila.Push(100);
            Pila.Push(150);

            Console.WriteLine("Peek: " + Pila.Peek());

            Console.WriteLine("Los elementos de la Pila son: ");
         
            while(Pila.Count > 0)
            {
                Console.WriteLine("Elemento: " + Pila.Pop());
            }
        }

        // Implementación de una Queue
        private static void Cola()
        {
            Queue Cola = new Queue();

            Cola.Enqueue("50");
            Cola.Enqueue("100");
            Cola.Enqueue("150");

            Console.WriteLine("Peek: " + Cola.Peek());

            Console.WriteLine("Los elementos de la Cola son: ");

            while (Cola.Count > 0)
            {
                Console.WriteLine("Elemento: " + Cola.Dequeue());
            }
        }

        // Implementacion de una Lista Ordenada
        private static void ListaOrdenada()
        {
            SortedList ListaO = new SortedList();

            ListaO.Add(218253432, "Fuentes Tinajero Eduardo");
            ListaO.Add(218253430, "Quintero Corrales Gustavo Alonso");
            ListaO.Add(218253429, "Velazquez Gurrola Jesus J. Aaron");
            ListaO.Add(218253431, "Ramos Avalos Bryan Emannuel");
            

            Console.WriteLine("// Lista de Alumnos //");

            foreach (object clave in ListaO.Keys) // Iteramos sobre cada key en la lista
            {
                Console.WriteLine("Matricula: " + clave +
                    " | Nombre: " + ListaO[clave]);
            }
        }

        static void Main(string[] args)
        {
            Pila();
            Console.WriteLine("== ==");
            Cola();
            Console.WriteLine("== ==");
            ListaOrdenada();
        }
    }
}
