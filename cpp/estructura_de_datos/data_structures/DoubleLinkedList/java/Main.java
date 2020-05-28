package doubleList;

import java.util.Scanner;

public class Main {
	private static DoubleLinkedList obj = new DoubleLinkedList(0,0);
	private static Scanner key = new Scanner(System.in);
	private static void validKey() {
		while(!key.hasNextInt()){
	    	key.next();
	    }
	}
	public static void main(String args[]) {
		boolean out = false;
	  	int option;
	  	int key1, k1, data1;
	  	
	  	do{
	  		System.out.println(" == Menu == ");
	  		System.out.print("\n0.- Salir. \n1.- Agregar. \n2.- Obtener. \n3.- Eliminar. \n4.- Eliminar al. \n5.- Vector a String. \n6.- Capacidad. \n7.- Tamanio. \n8.- Liberar espacio. \n9.- Contiene. \n10.- Esta lleno. \n11.- Limpiar.");
	  		System.out.println("\nIngresa la opcion deseada: ");
	  		validKey();
	    	option = key.nextInt();
	    	Node n1 = new Node();
	    	
	    	switch(option) {
	    		case 0:
	    			out = true;
	    			System.out.print("\nPrograma Terminado");
	      		break;
	    		case 1:
	    			System.out.print("\nIngresa el valor a agregar al final: ");
	    			validKey();
	      			data1 = key.nextInt();
	      			n1.setKey(data1); 
	      			n1.setValue(data1); 
	      			obj.insertLast(n1);
	      		break;
	    		case 2:
	    			System.out.print("\nIngresa el valor a agregar al inicio: ");
	    			validKey();
	      			data1 = key.nextInt();
	      			n1.setKey(data1); 
	      			n1.setValue(data1); 
	      			obj.insertFirst(n1);
	      		break;
	      		case 3:
	      			System.out.print("\nIngresa el valor a buscar: ");
	      			validKey();
	      			k1 = key.nextInt();
	      			System.out.print("Ingresa el valor a agregar antes: ");
	      			validKey();
	      			data1 = key.nextInt();
	      			n1.setKey(data1); 
	      			n1.setValue(data1); 
	      			obj.insertBefore(k1,n1);
	      		break;
	    		case 4:
	    			System.out.print("\nIngresa el valor a buscar: ");
	    			validKey();
	      			k1 = key.nextInt();
	      			System.out.print("Ingresa el valor a agregar despues: ");
	      			validKey();
	      			data1 = key.nextInt();
	      			n1.setKey(data1); 
	      			n1.setValue(data1); 
	      			obj.insertAfter(k1,n1);
	      		break;
	      		case 5:
	      			System.out.print("\nIngresa el indice: ");
	      			validKey();
	      			k1 = key.nextInt();
	      			System.out.print("Ingresa el valor a ingresar: ");
	      			validKey();
	      			data1 = key.nextInt();
	      			n1.setKey(data1); 
	      			n1.setValue(data1); 
	      			obj.insertAt(k1,n1);
	      		break;
	      		case 6:
	      			System.out.print("\nValor extraido: " + obj.extract() + ".\n");
	      		break;
	      		case 7:
	      			obj.ToString();
	      		break;
	      		case 8:
	      			System.out.print("\nIngresa el valor a buscar: ");
	      			k1 = key.nextInt();
	      			obj.search(k1);
	      		break;
	      		case 9:
	      			System.out.print("\nValor a actualizar: ");
	      			validKey();
	      			key1 = key.nextInt();
	      			System.out.print("A valor: ");
	      			validKey();
	      			data1 = key.nextInt();
	      			obj.updateValueByKey(key1,data1);
	      		break;
	      		case 10:
	      			System.out.print("\nIngresa el valor a eliminar: ");
	      			validKey();
	      			k1 = key.nextInt();
	      			obj.deleteValueByKey(k1);
	      		break;
	      		case 11:
	      			obj.clear();
	      		break;
	    		default: System.out.println("\nOpcion ingresada no valida\n");
	    	}
	    	System.out.print("\n");
	  	}while(!out);
	}
}
