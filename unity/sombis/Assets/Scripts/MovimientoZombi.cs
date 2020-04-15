using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MovimientoZombi : MonoBehaviour
{
    // Declaracion de Variables
    private GameObject Player;
    private bool IsFollowing = false;

    // Start is called before the first frame update
    void Start()
    {
        Player = GameObject.Find("Player"); // Guardamos nuestro jugador a seguir como un GameObject en la variable Player
    }

    // Update is called once per frame
    void Update()
    {
        if (IsFollowing == true)
        {
            Vector3 destino = new Vector3(Player.transform.position.x, this.transform.position.y, Player.transform.position.z);

            this.transform.parent.position =
                Vector3.MoveTowards(this.transform.parent.position, destino, 0.05f);
        }
    }

    private void OnTriggerEnter(Collider other)
    {
        if(other.gameObject.name == "Player")
        {
            IsFollowing = true;
        }
    }

    private void OnTriggerExit(Collider other)
    {
        if(other.gameObject.name == "Player")
        {
            IsFollowing = false;
        }
    }
}
