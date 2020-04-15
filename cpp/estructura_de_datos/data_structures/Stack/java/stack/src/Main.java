public class Main {

    public static void main(String[] args) {

        Stack fila = new Stack();
        System.out.println("Stack // Fila");
        fila.push(3);
        fila.push(2);
        fila.push(1);
        // System.out.println(fila.pop());
        // System.out.println(fila.pop());
        fila.push(6);
        System.out.println(fila.peek());
        System.out.println(fila.pop());
        System.out.println(fila.toString());

    }
}
