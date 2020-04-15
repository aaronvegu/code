using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MovimientoAnimado : MonoBehaviour
{
    // Declaracion de variables
    static Animator anim;   // Encargada de todas las animaciones, nos toma el componente Animator de nuestro personaje
    private bool isMoving = false;  // Para saber si esta moviendose o no el personaje

    // Start is called before the first frame update
    void Start()
    {
        anim = GetComponent<Animator>(); // Le damos el componente Animator a nuestra variable anim
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey(KeyCode.LeftArrow))
        {
            isMoving = true;    // Si el personaje se mueve, isMoving es verdadero
            Vector3 newPosition = this.transform.position; // Se toman las posiciones actuales del objeto
            newPosition.y = Time.deltaTime * 150.0f; // Cambiamos la posicion del objeto en su eje de las y
            this.transform.Rotate(0, -newPosition.y, 0); // Rotamos la posicion del objeto sobre el eje de las y
                                                         // En base al movimiento ya creado en position.y
        }
        if (Input.GetKey(KeyCode.UpArrow))
        {
            isMoving = true;    // Si el personaje se mueve, isMoving es verdadero
            Vector3 newPosition = this.transform.position;
            newPosition.z = Time.deltaTime * 3.0f;
            this.transform.Translate(0, 0, newPosition.z);
        }
        if (Input.GetKey(KeyCode.RightArrow))
        {
            isMoving = true;    // Si el personaje se mueve, isMoving es verdadero
            Vector3 newPosition = this.transform.position;
            newPosition.y = Time.deltaTime * 150.0f;
            this.transform.Rotate(0, newPosition.y, 0);
        }
        if (Input.GetKey(KeyCode.DownArrow))
        {
            isMoving = true;    // Si el personaje se mueve, isMoving es verdadero
            Vector3 newPosition = this.transform.position;
            newPosition.z = Time.deltaTime * 3.0f;
            this.transform.Translate(0, 0, -newPosition.z);
        }
        if (isMoving == true)   // Si hay movimiento
        {
            anim.SetBool("IsIdle", false);
            anim.SetBool("IsRunning", true);
        }
        else
        {
            anim.SetBool("IsRunning", false);
            anim.SetBool("IsIdle", true);
        }
        if (Input.GetKeyDown(KeyCode.Space))
        {
            anim.SetTrigger("IsJumping");
        }
        isMoving = false;
    }
}
