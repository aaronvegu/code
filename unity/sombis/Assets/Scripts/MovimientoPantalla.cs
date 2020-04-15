using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MovimientoPantalla : MonoBehaviour
{
    // Declaracion de variables de clase
    private bool movLeft;
    private bool movRight;
    private bool movUp;
    private bool movDown;
    public GameObject Player; // Es el objeto a mover en el juego

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    { 
        if (movLeft) // Cada variable booleana se activara segun cada boton que sea presionado en el juego
        {
            Vector3 newPosition = Player.transform.position; // Se toman las posiciones actuales del objeto
            newPosition.y = Time.deltaTime * 150.0f; // Cambiamos la posicion del objeto en su eje de las y
            Player.transform.Rotate(0, -newPosition.y, 0); // Rotamos la posicion del objeto sobre el eje de las y
                                                         // En base al movimiento ya creado en position.y
        }
        if (movUp)
        {
            Vector3 newPosition = Player.transform.position;
            newPosition.z = Time.deltaTime * 3.0f;
            Player.transform.Translate(0, 0, newPosition.z);
        }
        if (movRight)
        {
            Vector3 newPosition = Player.transform.position;
            newPosition.y = Time.deltaTime * 150.0f;
            Player.transform.Rotate(0, newPosition.y, 0);
        }
        if (movDown)
        {
            Vector3 newPosition = Player.transform.position;
            newPosition.z = Time.deltaTime * 3.0f;
            Player.transform.Translate(0, 0, -newPosition.z);
        }
    }

    // Metodos de movimiento por teclado (Eventos)

    public void ActivateMoveLeft() // Para activar movimiento a la izquierda
    {
        movLeft = true;
    }

    public void DesactivateMoveLeft() // Para desactivar movimiento a la izquierda
    {
        movLeft = false;
    }

    public void ActivateMoveUp() // Para activar movimiento hacia arriba
    {
        movUp = true;
    }

    public void DesactivateMoveUp() // Para desactivar movimiento hacia arriba
    {
        movUp = false;
    }

    public void ActivateMoveRight() // Para activar movimiento a la derecha
    {
        movRight = true;
    }

    public void DesactivateMoveRight() // Para desactivar movimiento a la derecha
    {
        movRight = false;
    }

    public void ActivateMoveDown() // Para activar movimiento hacia abajo
    {
        movDown = true;
    }

    public void DesactivateMoveDown() // Para desactivar movimiento hacia abajo
    {
        movDown = false;
    }
}
