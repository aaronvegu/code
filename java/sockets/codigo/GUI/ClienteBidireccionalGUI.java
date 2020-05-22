import java.io.*;
import javax.swing.*;

// == Clase Principal ==
public class ClienteBidireccionalGUI 
{

    public ClienteBidireccionalGUI() throws IOException
    {
        EntornoGraficoCliente entorno = new EntornoGraficoCliente("Cliente", 1234, 1235);
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
    public EntornoGraficoCliente(String tipo, int puerto_salida, int puerto_entrada)
    {

        setBounds(1200, 300, 280, 350);
        
        // Implementamos servicio
        Servicio s = new Servicio(tipo, puerto_salida, puerto_entrada);

        add(s);

        setVisible(true);
    }
}