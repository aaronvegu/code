using System;
namespace Repeticiones
{
    public class Lista
    {
        // Atributos
        private Nodo first;

        // Constructor
        public Lista()
        {
            first = null;
        }

        // Metodos
        public Nodo GetFirst()
        {
            return first;
        }

        public bool IsEmpty()
        {
            if (first == null) return true;
            else return false;
        }

        public void Add(int l)
        {
            if(IsEmpty())
            {
                Nodo nodo = new Nodo(l);
                first = nodo;
                return;
            }
            Nodo current = first;
            do
            {
                if(current.GetLoad() == l)
                {
                    current.AddCounter();
                    return;
                }
                if (current.GetNext() == null) break;
                else
                {
                    current = current.GetNext();
                }
            } while (current != null);
            Nodo nuevoNodo = new Nodo(l);
            nuevoNodo.SetNext(first);
            first = nuevoNodo;
            return;
        }

        public int Peek()
        {
            if (IsEmpty()) return -1;
            else return first.GetLoad();
        }

        public string ContentToString()
        {
            if (IsEmpty()) return "Error: Lista Vacia";
            string content = "";
            if(first.GetNext() == null)
            {
                content += "Entero " + first.GetLoad() + " se repite " + first.GetCounter() + " veces, ";
                return content;
            }
            else
            {
                Nodo temporal = first;
                while (temporal.GetNext() != null)
                {
                    content += "Valor: " + temporal.GetLoad() + " -> N. de Repeticiones: " + temporal.GetCounter() + "\n";
                    temporal = temporal.GetNext();
                    if (temporal.IsNull() == true) content += "Valor: " + temporal.GetLoad() + " -> N. de Repeticiones: " + temporal.GetCounter() + "\n";
                }
            }
            return content;
        }

    }
}
