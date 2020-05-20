import java.io.*;
import java.net.*;
import javax.swing.*;
import java.awt.event.*;

public class ServidorBidireccionalGUI // Clase principal
{ 

    public ServidorBidireccionalGUI() throws IOException 
    {   
        EntornoGraficoServidor gs = new EntornoGraficoServidor();
        gs.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public static void main(String[] args) throws IOException
    {
        try {
            ServidorBidireccionalGUI srv = new ServidorBidireccionalGUI();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

}

// == Interfaz Grafica ==
class EntornoGraficoServidor extends JFrame
{

    public EntornoGraficoServidor()
    {

        setBounds(1200, 300, 280, 350);
        
        PanelChatServidor pc = new PanelChatServidor();

        add(pc);

        setVisible(true);

    }

}

class PanelChatServidor extends JPanel implements Runnable
{
    // Objetos para sockets
    private final int PUERTO = 1234; // Puerto para la conexion
    private final String HOST = "localhost";    
    private ServerSocket serverSocket; // Socket del servidor
    private Socket clientSocket; // Socket del cliente
    private DataInputStream entradaDesdeCliente; // Flujo de entrada de datos del cliente
    private DataOutputStream salidaAlCliente; // Flujo de datos del servidor al cliente

    // String del mensaje que saldra al servidor
    String salida = null;
    // String del mensaje de entrada desde el servidor
    String entrada = null;

    // Objetos Graficos
    JLabel titulo;
    JButton boton;
    JTextField campo;
    JPanel panelArea;
    public JTextArea textArea;

    public PanelChatServidor()
    {
        // Instanciamos objetos graficos
        titulo = new JLabel("Servidor");
        boton =  new JButton("Enviar mensaje");
        campo = new JTextField(20);
        textArea = new JTextArea(12, 20);

        // Los agregamos a nuestro JPanel
        add(titulo);
        add(textArea);
        add(campo);
        add(boton);

        // Implementamos hilo
        Thread hilo = new Thread(this);
        // Iniciamos hilo
        hilo.start();

        // Hacemos instancia del listener EnviarTexto
        EnviarTexto et = new EnviarTexto();
        // Hacemos que nuestro boton escuche el evento
        boton.addActionListener(et);

    }

    @Override
    public void run() { // Metodo run que esta a la escucha en todo momento
        
        try {
            // Ponemos a la escucha a nuestro servidor mediante el socket en el puerto 1234
            serverSocket = new ServerSocket(PUERTO);

            // Iteramos la comunicacion mientras se mantenga el entorno abierto:
            while(true)
            {
                // De encontrar un cliente, aceptar la conexion y crear el socket cliente
                clientSocket = serverSocket.accept();
                // Obtenemos la entrada proveniente desde el socket del cliente
                entradaDesdeCliente = new DataInputStream(clientSocket.getInputStream());
                // Hacemos lectura de ese flujo de datos (UTF) y los guardamos en la string de entrada
                entrada = entradaDesdeCliente.readUTF();
                // Concatenamos esos datos a nuestro TextArea
                textArea.append("Cliente: " + entrada + "\n");
                // Cerramos la conexion
                clientSocket.close();
            }
            
        } catch (Exception e1) {
            System.out.println(e1.getMessage());

        }

    }

    private class EnviarTexto implements ActionListener
    {

        @Override
        public void actionPerformed(ActionEvent e) {

            try {
                // creamos nuestro socket
                clientSocket = new Socket(HOST, 1235);
                // Creamos un flujo de salida para enviar datos al socket
                salidaAlCliente = new DataOutputStream(clientSocket.getOutputStream());
                // Guardamos el mensaje del cliente en la String salida
                salida = campo.getText();
                // Imprimos el mensaje enviado en nuestro chat
                textArea.append("Servidor: " + salida + "\n");
                // Obtenemos flujo de salida del JTextField
                salidaAlCliente.writeUTF(salida);
                // Cerramos nuestro flujo de salida
                salidaAlCliente.close();

            } catch (Exception e1) {
                
                System.out.println(e1.getMessage());

            }

        }
        
    }

}