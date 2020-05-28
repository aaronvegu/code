
import java.util.Scanner;

public class Main {
	private static Vector v  = new Vector(0);
	private static Scanner key = new Scanner(System.in);
	private static void validKey() {
		while(!key.hasNextInt()){
	    	key.next();
	    }
	}
	public static void main(String args[]) {
		v.buildVector();
		int option,value;
		boolean out = false;
		do{
			System.out.println("|		  Menu			|");
			System.out.println("\n0.- Out. \n1.- Add. \n2.- Get. \n3.- Remove. \n4.- Remove At. \n5.- Print Vector. \n6.- Capacity. \n7.- Size. \n8.- Free Space At. \n9.- Contains. \n10.- Is Full. \n11.- Clear.");
			System.out.println("\nType the require option: ");
			validKey();
			option = key.nextInt();
					
			switch(option){
				case 0:
					out = true;
					System.out.println("\nIt has exited, press twice any key to close the program.");
				break;
				case 1:
					boolean s1 = false;
					do {
						System.out.println("\nType the value to add(integer): ");
						validKey();
						value = key.nextInt();
						if(value > -1) {
							v.add(value);
							s1 = true;
						}
					}while(!s1);
				break;
				case 2:
					boolean s2 = false;
					do {
						System.out.println("\nType the index to get(integer): ");
						validKey();
						value = key.nextInt();
						if(value > -1) {
							System.out.println("\nThe value is: " + v.get(value) + ".");
							s2 = true;
						}
					}while(!s2);
				break;
				case 3:
					boolean s3 = false;
					do {
						System.out.println("\nType the value to remove(integer): ");
						validKey();
						value = key.nextInt();
						if(value > -1) {
							v.remove(value);
							s3 = true;
						}
					}while(!s3);
				break;
				case 4:
					boolean s4 = false;
					do {
						System.out.println("\nType the index to remove(integer): ");
						validKey();
						value = key.nextInt();
						if(value > -1) {
							v.removeAt(value);
							s4 = true;
						}
					}while(!s4);
				break;
				case 5:
					v.vectorToString();	
				break;
				case 6:
					System.out.println("\nCapacity of vector is: " + v.capacity());
				break;
				case 7:
					System.out.println("\nSpaces on use: " + v.size());
				break;
				case 8:
					System.out.println("\nFree space index at: " + v.freeAt());
				break;
				case 9:
					boolean s5 = false;
					do {
						System.out.println("\nType the value to search(integer): ");
						validKey();
						value = key.nextInt();
						if(value > -1) {
							if(v.contains(value)){
								System.out.println("\nThe value is on the vector.");
							}else{
								System.out.println("\nThe value is not on the vector.");
							}
							s5 = true;
						}
					}while(!s5);
				break;
				case 10:
					if(v.isFull()){
						System.out.println("\nVector is full.");
					}else{
						System.out.println("\nVector has empty spaces.");
					}
				break;
				case 11:
					v.clear();
				break;
					
				default: System.out.println("\nError incorrect option, please type again a valid option.");
			}
			System.out.println("\n");
		}while(!out);
	}
}
