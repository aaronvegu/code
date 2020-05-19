import java.io.*;
import java.net.*;

public class ServidorBidir // Clase principal
{ 
    
    private final int PUERTO = 1234; // Puerto para la conexion
    private final String HOST = "localhost";
    private String mensajeDelServidor; // Entrada de mensajes
    private String salidaDelServidor; // Mensaje de salida del servidor al cliente
    private ServerSocket serverSocket; // Socket del servidor
    private Socket clientSocket; // Socket del cliente

    public ServidorBidir() throws IOException 
    {   // Constructor de clase
        serverSocket = new ServerSocket(PUERTO); // Creamos socket para el servidor
        clientSocket = new Socket(); // Creamos socket oara el cliente
        System.out.println("Servidor Inicializado\n");
    }

    public void startServer() // Metodo para inicializar el server
    {
        try {
            System.out.println("Esperando conexion..."); // Esperando conexion del cliente

            clientSocket = serverSocket.accept(); // Conexion con el socket del cliente
            System.out.println("Conexión establecida");

            // Para enviar datos al cliente:
            PrintStream sendStream = new PrintStream(clientSocket.getOutputStream());

            // Para obtner datos desde el cliente
            BufferedReader inputStream = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));

            // Para leer la entrada del teclado
            BufferedReader keyboard = new BufferedReader(new InputStreamReader(System.in));

            // Mantenemos la ejecucion continua del servidor
            while(true)
            {
                // Mantenemos iteracion mientras el cliente no envie una null string
                while((mensajeDelServidor = inputStream.readLine()) != null)
                {
                    // Mostramos mensaje recibido del cliente
                    System.out.println(mensajeDelServidor);
                    
                    
                    // Obtenemos lectura del teclado
                    salidaDelServidor = keyboard.readLine();
                    // Enviamos mensaje al cliente
                    sendStream.println("Servidor: " + salidaDelServidor);
                }

                System.out.println("Conexión terminada");

                // Cerramos conexiones
                sendStream.close();
                inputStream.close();
                keyboard.close();
                clientSocket.close();
                serverSocket.close();
            }

        } catch (Exception e) { // Cachamos el error
            System.out.println(e.getMessage()); // Mostramos mensaje de error
        }
    }

    public static void main(String[] args) throws IOException
    {
        ServidorBidir sb = null; // Declaramos nuestro servidor en null

        try {
            
            sb = new ServidorBidir(); // Instanciamos nuestro servidor

        } catch (IOException e) {

            System.out.println("Error al iniciar el servidor");

        }
        if(sb != null) // De no ser null
            sb.startServer(); // Iniciamos servidor
    }
}