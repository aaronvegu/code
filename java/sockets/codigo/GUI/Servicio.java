import java.net.*;
import java.io.*;
import javax.swing.*;
import java.awt.event.*;


class Servicio extends JPanel implements Runnable
{
    // Elementos para el socket
    private final int PUERTO_O; // Puerto para la entrada
    private final int PUERTO_I; // Puerto para la salida
    private final String HOST = "localhost"; // Host
    private Socket clientSocket = null; // Socket del cliente
    private ServerSocket serverSocket;
    private DataOutputStream flujoDeSalida; // Datos de salida al servidor
    private DataInputStream flujoDeEntrada; // Datos de entrada desde el servidor

    // String del mensaje que saldra al servidor
    String salida = null;
    // String del mensaje de entrada desde el servidor
    String entrada = null;

    // Objetos Graficos
    JLabel titulo, estado;
    JButton boton;
    JTextField campo;
    JTextArea textArea;

    public Servicio(String tipo, int puerto_salida, int puerto_entrada)
    {
        // Puertos
        PUERTO_I = puerto_salida;
        PUERTO_O = puerto_entrada;

        // Instanciamos objetos graficos
        titulo = new JLabel(tipo);
        estado = new JLabel();
        boton =  new JButton("Enviar mensaje");
        campo = new JTextField(20);
        textArea = new JTextArea(12, 20);

        // Los agregamos a nuestro JPanel
        add(titulo);
        add(estado);
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

    /**
     * Implementacion del codigo del hilo mediante nuestro metodo Run()
     * Que estuviera escuchando todo el tiempo
     * Obtiene la entrada desde el socket del cliente aceptado
     * Guarda esa entrada en la String entrada
     * Un append al JTextArea del mensaje recibido
     */
    @Override
    public void run() { // EL hilo es el que escucha el flujo del otro socket
        try {
            // Ponemos a la escucha a nuestro servidor mediante el socket en el puerto de entrada
            serverSocket = new ServerSocket(PUERTO_I);

            // Iteramos la comunicacion mientras se mantenga el entorno abierto:
            while(true)
            {
                // De encontrar un cliente, aceptar la conexion y crear el socket cliente
                clientSocket = serverSocket.accept();
                // Marcamos estado
                estado.setText("Conectado");
                // Obtenemos la entrada proveniente desde el socket del cliente
                flujoDeEntrada = new DataInputStream(clientSocket.getInputStream());
                // Hacemos lectura de ese flujo de datos (UTF) y los guardamos en la string de entrada
                entrada = flujoDeEntrada.readUTF();
                // Concatenamos esos datos a nuestro TextArea
                textArea.append(entrada + "\n");
                // Cerramos la conexion 
                clientSocket.close();
            }

        } catch (Exception e) {
            System.out.println(e.getMessage());
            estado.setText("Sin Conexion");
        }
    }

    // Listener
    private class EnviarTexto implements ActionListener
    {
		@Override
		public void actionPerformed(ActionEvent e) {            
            try {
                // Creamos nuestro socket
                clientSocket =  new Socket(HOST, PUERTO_O);
                // Creamos un flujo de salida del socket
                flujoDeSalida = new DataOutputStream(clientSocket.getOutputStream());
                // Marcamos estado
                estado.setText("Conectado");
                // Guardamos el mensaje del cliente en la String salida
                salida = campo.getText();
                // Imprimos el mensaje enviado en nuestro chat
                textArea.append("Tú: " + salida + "\n");
                // Enviamos el mensaje Salida como flujo de salida
                flujoDeSalida.writeUTF(salida);
                // Cerramos nuestro flujo de salida
                flujoDeSalida.close();

            } catch (IOException e1) {
                System.out.println(e1.getMessage());
                estado.setText("Sin Conexion");
            }
			
		}
    }

}