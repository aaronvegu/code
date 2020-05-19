import java.io.*;
import java.net.*;

public class ClienteBidir // Clase Principal
{

    private final int PUERTO = 1234; // Puerto para la conexion
    private final String HOST = "localhost";
    private Socket clientSocket; // Socket del cliente
    private DataOutputStream salidaAlServidor; // Datos de salida al servidor
    private BufferedReader entradaDesdeServidor; // Datos de entrada desde el servidor

    public ClienteBidir() throws IOException
    {
        clientSocket = new Socket(HOST, PUERTO); // Instanciamos socket para el cliente
        System.out.println("Cliente Inicializado");
    }

    public void startClient() // Metodo para iniciar el cliente
    {
        // Para leer la entrada del teclado:
        BufferedReader keyboard = new BufferedReader(new InputStreamReader(System.in));
        
        // String del mensaje que saldra al servidor
        String salida = null;
        // String del mensaje de entrada desde el servidor
        String entrada = null;

        try {
            System.out.println("Para terminar comunicacion escriba: salir\n");

            // Datos de salida al servidor
            salidaAlServidor = new DataOutputStream(clientSocket.getOutputStream());

            // Datos de entrada desde el servidor
            entradaDesdeServidor = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));

            // Mantenemos comunicacion mientras el cliente no escriba "salir"
            while(!(salida = keyboard.readLine()).equals("salir"))
            {
                // Para enviar mensaje al servidor
                salidaAlServidor.writeBytes("Cliente: " + salida + "\n");

                // Para recibir mensaje del servidor
                entrada = entradaDesdeServidor.readLine();

                // Imprimimos entrada desde el servidor
                System.out.println(entrada);
            }

            // Cerramos conexiones
            salidaAlServidor.close();
            entradaDesdeServidor.close();
            keyboard.close();
            clientSocket.close();
            
        } catch (Exception e) {

            System.out.println(e.getMessage());

        }
    }

    public static void main(String[] args)
    {
        ClienteBidir cb = null; // Declaramos nuestro cliente en null

        try {
            
            cb = new ClienteBidir(); // Instanciamos nuestro cliente, que 
            // intentara realizar la conexion

        } catch (IOException e) {
            
            System.out.println("\nError en la conexion, no se pudo conectar con el servidor");

        }
        if(cb != null) // Si nuestro cliente es distinto a null
            cb.startClient(); // Iniciamos comunicaciones
    }

}