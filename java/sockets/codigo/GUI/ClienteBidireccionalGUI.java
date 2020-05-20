import java.io.*;
import java.net.*;
import javax.swing.*;
import java.awt.event.*;

public class ClienteBidireccionalGUI // Clase Principal
{

    public ClienteBidireccionalGUI() throws IOException
    {
        EntornoGraficoCliente entorno = new EntornoGraficoCliente();
        entorno.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public static void main(String[] args)
    {
        try {
            ClienteBidireccionalGUI cli = new ClienteBidireccionalGUI();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

}

// == Interfaz Grafica ==
class EntornoGraficoCliente extends JFrame 
{
    public EntornoGraficoCliente()
    {

        setBounds(1200, 300, 280, 350);
        
        PanelChatCliente pc = new PanelChatCliente();

        add(pc);

        setVisible(true);
    }
}

class PanelChatCliente extends JPanel implements Runnable
{
    // Elementos para el socket
    private final int PUERTO = 1234; // Puerto para la conexion
    private final String HOST = "localhost";
    private Socket clientSocket; // Socket del cliente
    private ServerSocket serverSocket;
    private DataOutputStream salidaAlServidor; // Datos de salida al servidor
    private DataInputStream entradaDesdeServidor; // Datos de entrada desde el servidor

    // String del mensaje que saldra al servidor
    String salida = null;
    // String del mensaje de entrada desde el servidor
    String entrada = null;

    // Objetos Graficos
    JLabel titulo;
    JButton boton;
    JTextField campo;
    JTextArea textArea;

    public PanelChatCliente()
    {
        // Instanciamos objetos graficos
        titulo = new JLabel("Cliente");
        boton =  new JButton("Enviar mensaje");
        campo = new JTextField(20);
        textArea = new JTextArea(12, 20);

        // Los agregamos a nuestro JPanel
        add(titulo);
        add(textArea);
        add(campo);
        add(boton);

        /**
         * == Para recibir mensajes ==
         */
        // Implementamos hilo
        Thread hilo = new Thread(this);
        // Iniciamos hilo
        hilo.start();


        /**
         * == Para enviar mensajes ==
         */
        // Hacemos instancia del listener EnviarTexto
        EnviarTexto et = new EnviarTexto();
        // Hacemos que nuestro boton escuche el evento
        boton.addActionListener(et);
    }

    @Override
    public void run() {
        try {
            // Ponemos a la escucha a nuestro servidor mediante el socket en el puerto 1234
            serverSocket = new ServerSocket(1235);

            // Iteramos la comunicacion mientras se mantenga el entorno abierto:
            while(true)
            {
                clientSocket = serverSocket.accept();
                entradaDesdeServidor = new DataInputStream(clientSocket.getInputStream());
                entrada = entradaDesdeServidor.readUTF();
                textArea.append("Servidor: " + entrada + "\n");
                clientSocket.close();
            }

        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    // Listener
    private class EnviarTexto implements ActionListener
    {
		@Override
		public void actionPerformed(ActionEvent e) {            
            try {
                // Creamos nuestro socket
                clientSocket =  new Socket(HOST, PUERTO);
                // Creamos un flujo de salida del socket
                salidaAlServidor = new DataOutputStream(clientSocket.getOutputStream());
                // Guardamos el mensaje del cliente en la String salida
                salida = campo.getText();
                // Imprimos el mensaje enviado en nuestro chat
                textArea.append("Cliente: " + salida + "\n");
                // Enviamos el mensaje Salida como flujo de salida
                salidaAlServidor.writeUTF(salida);
                // Cerramos nuestro flujo de salida
                salidaAlServidor.close();

            } catch (IOException e1) {

                System.out.println(e1.getMessage());

            }
			
		}
    }

}