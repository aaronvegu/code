public class Queue {
	
	private Node head;
	private Node tail;

	public void enqueue(int n) {
		Node temp = new Node(n); // Se crea el nodo
		if (isEmpty()) {
			head = temp;
			tail = temp;
		} else {
			Node current = head;
			while(current.getNext() != null) {
				current = current.getNext();
			}
			current.setNext(temp);
			tail = temp;
			tail.setNext(null);
		}
	}

	public int dequeue() {
		if (!isEmpty()) {
			int n = head.getLoad();
			Node temp = head.getNext();
			head = temp;
			return n;
		} else return -1;
	}

	public void clear() {
		Node current = head;
		while(!isEmpty()) dequeue();
		head = null;
		tail = null;
	}

	public int peek() {
		return head.getLoad();
	}

	public boolean isEmpty() {
		if (head == null) return true;
		else return (head.getNext() == null);
	}

	public String toString() {
		String s = "[ ";
		while (isEmpty()) {
			s += dequeue();
			s += ", ";
		}
		s += " ]";
		return s;
	}

}