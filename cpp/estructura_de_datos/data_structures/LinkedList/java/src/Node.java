public class Node {

    private int load;
    private Node next;

    public Node(int l) {
        load = l;
        next = null;
    }

    public int getLoad(){
        return  load;
    }

    public  void setLoad(int l) {
        load = l;
    }

    public  Node getNext() {
        return next;
    }

    public void setNext(Node n) {
        next = n;
    }
}
