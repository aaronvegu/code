package doubleList;

public class DoubleLinkedList extends Node{
	public DoubleLinkedList() {
		super();
	}
	public DoubleLinkedList(int key,int value) {
		super(key,value);
	}
	
	private Node head = null;
	
	public Node contains(int key) { 
		Node temp = null; 
    	Node ptr = head;
    	while(ptr!=null) {
      		if(ptr.getKey()==key) {
        		temp = ptr;
      		}
      		ptr = ptr.getNext();
    	}
    	return temp;
  	}
	public boolean isEmpty() {
		if(head==null) {
			return true;
		}else {
			return false;
		}
	}
  	public void insertLast(Node node) {
  		if(contains(node.getKey())!=null) {
    		System.out.print("\nValue exists with key value: " + node.getKey() + ". Insert at last another value with different Key value.\n");
    	}else {
      		if((isEmpty())) {
        		head = node;
        		System.out.print("\nValue has been added at last succesfully.\n");
      		}else {
        		Node ptr = head;
        		while(ptr.getNext()!=null) {
          			ptr = ptr.getNext();
        		}
        		ptr.setNext(node);
       		 	node.setPrevious(ptr);
       		 	System.out.print("\nValue has been added at last succesfully.\n");
      		}
    	}
  	}
  	public void insertFirst(Node node) {
  		if(contains(node.getKey())!=null) {
    		System.out.print("\nValue exists with key value: " + node.getKey() + ". Insert at first another value with different Key value.\n");
   	 	}else {
      		if((isEmpty())) {
        		head = node;
        		System.out.print("\nValue has been added at fist succesfully.\n");
      		}else {
       	 		head.setPrevious(node);
        		node.setNext(head);
        		head = node;
        		System.out.print("\nValue has been added at first succesfully.\n");
      		}
    	}
  	}
  	public void insertBefore(int key,Node node) {
  		if((isEmpty())) {
    		insertFirst(node);
    	}else {
    		Node ptr = contains(key);
    		if(ptr==null) {
    			System.out.print("\nValue doesn't exist with key value: " + key + "\n");
    		}else {
      			if(contains(node.getKey())!=null) {
      				System.out.print("\nValue exists with key value: " + node.getKey() + ". Insert at first another value with different Key value.\n");
      			}else {
        			if(ptr.getPrevious()==null) {
        				insertFirst(node);	
        			}else {
        				Node previousNode = ptr.getPrevious();
        				if(previousNode==null) {
          					ptr.setPrevious(node);
          					node.setNext(ptr);
          					System.out.print("\nValue has been added before succesfully.\n");
        				}else {
          					node.setPrevious(previousNode); 
          					previousNode.setNext(node); 
          					node.setNext(ptr);
          					ptr.setPrevious(node); 
          					System.out.print("\nValue has been added before succesfully.\n");
        				}
        			}
      			}
    		}
    	}
  	}
  	public void insertAfter(int key,Node node) {
  		if((isEmpty())) {
    		insertFirst(node);
    	}else{
    		Node ptr = contains(key);
    		if(ptr==null) {
    			System.out.print("\nValue doesn't exist with key value: " + key + "\n");
    		}else {
      			if(contains(node.getKey())!=null) {
      				System.out.print("\nValue exists with key value: " + node.getKey() + ". Insert at last another value with different Key value.\n");
      			}else {
       	 			Node nextNode = ptr.getNext();
       		 		if(nextNode==null) {
          				ptr.setNext(node); 
          				node.setPrevious(ptr); 
          				System.out.print("\nValue has been added after succesfully.\n");
        			}else {
          				node.setNext(nextNode);
          				nextNode.setPrevious(node);
         	 			node.setPrevious(ptr); 
         	 			ptr.setNext(node); 
         	 			System.out.print("\nValue has been added after succesfully.\n");
        			}
      			}
    		}
    	}
  	}
  	public void insertAt(int i,Node node){
    	if((isEmpty())) {
      		if(i>0){
      			System.out.print("\nValue can't be added, because index " + i + " doesn't exist.\n");
      		}else{
      			insertFirst(node);
      		}
    	}else {
      		if(contains(node.getKey())!=null) {
      			System.out.print("\nValue exists with key value: " + node.getKey() + ". Insert another value with different Key value.\n");
      		}else {
      			if(i>0) {
      				int var = 0,key = 0;
    				Node ptr = head;
    				while(ptr!=null) {
      					if(var==i) {
      						key = ptr.getKey();
      						break;
      					}
      					var++;
      					ptr = ptr.getNext();
    				}
    				insertBefore(key,node);
      			}else {
      				insertFirst(node);
      			}
      		}
    	}	
  	}
  	public void deleteValueByKey(int key) {
    	if(isEmpty()) {
    		System.out.print("\nDoble Linked List is empty.\n");
    	}else {
    		Node ptr = contains(key);
        	if(ptr==null) {
        		System.out.print("\nValue doesn't exist with key value: " + key + "\n");
        	}else {
          		if(head.getKey()==key) {
            		head = head.getNext();
            		System.out.print("\nValue has been deleted succesfully.\n");
          		}else {
            		Node nextNode = ptr.getNext();
            		Node prevNode = ptr.getPrevious();
            		if(nextNode==null) { 
              			prevNode.setNext(null);
              			System.out.print("\nValue has been deleted succesfully.\n");
            		}else {
              			prevNode.setNext(nextNode);
              			nextNode.setPrevious(prevNode);
              			System.out.print("\nValue has been deleted succesfully.\n");
            		}
          		}
        	}
    	}
  	}
  	public void updateValueByKey(int key,int data) {
    	if(isEmpty()) {
    		System.out.print("\nDoble Linked List is empty.\n");
    	}else {
    		Node ptr = contains(key);
        	if(ptr!=null) {
        		ptr.setKey(data);
          		ptr.setValue(data);
          		System.out.print("\nValue has been updated successfully\n");
        	}else {
        		System.out.print("\nValue doesn't exist with that key: " + key + "\n");
        	}
    	}
  	}
  	public boolean search(int key){
  		if(isEmpty()) {
  			System.out.print("\nDoble Linked List is empty.\n");
  			return false;
  		}else {
  			if(contains(key)!=null) {
  	  			System.out.print("\nValue has been found it.\n");
  	  			return true;
  	  		}else {
  	  			System.out.print("\nValue has not been found it.\n");
  	  			return false;
  	  		}
  		}
  	}
  	public int extract() {
  		if(isEmpty()) {
  			return -1;
  		}else {
  			int value = head.getValue();
  			head = head.getNext();	
        	return value;
  		}
  	}
  	public void ToString() {
    	if(isEmpty()) {
    		System.out.print("\nDouble Linked List is empty.\n");
    	}else {
    		Node temp = head;
      		if(temp.getNext()==null) {
      			System.out.print("\nDouble Linked List Value: \n\n{");
      		}else{
      			System.out.print("\nDouble Linked List Values: \n\n{");
      		}
      		while(temp!=null) {
      			if(temp.getNext()==null) {
      				System.out.print(temp.getValue());
      			}else {
      				System.out.print(temp.getValue() + ",");
      			}
        		temp = temp.getNext();
      		}
      		System.out.print("}\n\n");
    	}
  	}
  	public void clear(){
  		if(isEmpty()) {
  			System.out.print("\nDouble Linked List is empty.\n");
  		}else {
  			Node temp = head;
  			while(temp!=null) {
  				if(isEmpty()) {
  					System.out.print("\nDouble Linked List has been clear succesfully.\n");
  					return;
  				}else {
  					head = head.getNext();
  				}
  			}
  		}
  	}
}
