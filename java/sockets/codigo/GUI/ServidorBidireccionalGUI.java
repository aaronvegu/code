import java.io.*;
import javax.swing.*;

public class ServidorBidireccionalGUI // Clase principal
{ 

    public ServidorBidireccionalGUI() throws IOException 
    {   
        EntornoGraficoServidor gs = new EntornoGraficoServidor("Servidor", 1235, 1234);
        gs.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // Para que se cierre nuestra interfaz cuando presionamos la x
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
    

    public EntornoGraficoServidor(String tipo, int puerto_salida, int puerto_entrada)
    {

        setBounds(1200, 300, 280, 350); // Le ponemos tamanio al JFrame
        
        // Implementamos servicio
        Servicio s = new Servicio(tipo, puerto_salida, puerto_entrada);

        add(s);

        setVisible(true); // Lo hacemos visible

    }

}