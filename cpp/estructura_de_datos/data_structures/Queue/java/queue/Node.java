public class Node {

	private int load; // Carga del nodo
	private Node next; // Apuntador al siguiente Nodo

	public Node(int load) {
		this.load = load;
		this.next = null;
	}

	public int getLoad() {
		return load;
	}

	public void setLoad(int load) {
		this.load = load;
	}

	public Node getNext() {
		return next;
	}

	public void setNext(Node next) {
		this.next = next;
	}

}