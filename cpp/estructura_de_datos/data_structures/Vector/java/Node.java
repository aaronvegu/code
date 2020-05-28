
public class Vector extends Node{
	public Vector(int data) {
		super(data);
	}
	
	private Node vector = null;
	private Node back = null;
	
	void newNode(int value) {
		Node current = new Node(value);
		current.setData(value);
		if(vector==null){
			vector = current;
			back = current;
		}else{
			back.setNext(current);
			back = current;
		}
	}
	void buildVector() {
		for(int i=0;i<10;i++){
			newNode(-1);
		}
	}
	int capacity() {
		int i = 0;
		Node current = vector;
		while(current!=null){
			i++;
			current = current.getNext();
		}
		return i;
	}
	int size(){
		int i = 0;
		Node current = vector;
		while(current!=null){
			if(current.getData()!=-1){
				i++;	
			}
			current = current.getNext();
		}
		return i;
	}
	int freeAt(){
		int i = 0;
		Node current = vector;
		while(current!=null){
			if(current.getData()==-1){
				return i;
			}
			i++;
			current = current.getNext();
		}
		return i;
	}
	boolean isFull(){
		Node current = vector;
		while(current!=null){
			if(current.getData()==-1){
				return false;	
			}
			current = current.getNext();
		}
		Node node = vector;
		while(node!=null){
			if(node.getNext()==null){
				for(int i=0;i<5;i++){
					newNode(-1);
				}
				break;
			}
			node = node.getNext();
		}
		return true;
	}
	boolean contains(int value){
		Node current = vector;
		while(current!=null){
			if(current.getData()==value){
				return true;
			}
			current = current.getNext();
		}
		return false;
	}
	boolean add(int value){
		if(isFull()){
			if(contains(value)){
				System.out.println("\nYour value has not been add, because there exists.");
				return false;
			}else{
				Node current = vector;
				while(current!=null){
					if(current.getData()==-1){
						current.setData(value);
						break;
					}
					current = current.getNext();
				}
				System.out.println("\nYour value has been successfully added.");
				return true;
			}
		}else{
			if(contains(value)){
				System.out.println("\nYour value has not been add, because there exists.");
				return false;
			}else{
				Node current = vector;
				while(current!=null){
					if(current.getData()==-1){
						current.setData(value);
						break;
					}
					current = current.getNext();
				}
				System.out.println("\nYour value has been successfully added.");
				return true;
			}
		}
	}
	int get(int i){
		int var = 0;
		Node current = vector;
		while(current!=null){
			if(var==i){
				return current.getData();
			}
			var++;
			current = current.getNext();
		}
		return 0;
	}
	boolean remove(int value){
		if(contains(value)){
			Node current = vector;
			while(current!=null){
				if(current.getData()==value){
					current.setData(-1);;
					break;
				}
				current = current.getNext();
			}
			System.out.println("\nYour value has been successfully removed.");
			return true;
		}else{
			System.out.println("\nYour value has not been removed, because there is not exists.");
			return false;
		}
	}
	boolean removeAt(int i){
		int var = 0;
		Node current = vector;
		while(current!=null){
			if(var==i){
				if(current.getData()!=-1){
					current.setData(-1);
					System.out.println("\nYour value has been successfully removed.");
					return true;
				}else{
					System.out.println("\nYour value has not been removed, because there is not exists.");
					return false;
				}
			}
			var++;
			current = current.getNext();
		}
		System.out.println("\nYour value has not been removed, because there is not exists.");
		return false;
	}
	void vectorToString(){
		Node current = vector;
		if(current.getNext()==null){
			System.out.println("\nThe value of the Vector is: \n\n");
		}else{
			System.out.println("\nThe values of the Vector are: \n\n");
		}
		System.out.print("{");
		while(current!=null){
			if(current.getNext()==null){
				System.out.print(current.getData() + "}");
			}else{
				System.out.print(current.getData() + ",");
			}
			current = current.getNext();
		}
		System.out.println("\n");
	}
	void clear(){
		Node current = vector;
		while(current!=null){
			if(vector==null) {
				current = null;
			}else {
				vector = vector.getNext();
			}
		}
		buildVector();
		System.out.println("\nThe Vector is clear successfully.");
	}
}