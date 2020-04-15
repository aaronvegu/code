using System;
namespace Repeticiones
{
    public class Nodo
    {
        // Atributos
        private int load;
        private int counter;
        private Nodo next;

        // Constructor
        public Nodo(int n)
        {
            load = n;
            counter = 1;
            next = null;
        }

        // Metodos (Setters and Getters)
        public void SetNext(Nodo nodo)
        {
            next = nodo;
        }

        public Nodo GetNext()
        {
            return next;
        }

        public void AddCounter()
        {
            counter++;
        }

        public int GetCounter()
        {
            return counter;
        }

        public void SetLoad(int l)
        {
            load = l;
        }

        public int GetLoad()
        {
            return load;
        }

        public bool IsNull()
        {
            if (next == null) return true;
            else return false;
        }

    }
}
