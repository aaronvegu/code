using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Directions : MonoBehaviour
{
    public GameObject PrefabBullet;
    public Transform BulletPosition; // No conviene que nuestro objeto vacio sea
                  // un game object, pues consume mas recursos y no los necesita

        // Start is called before the first frame update
    void Start()
    {
        
    }

    void Fire()
    {
        var bullet = (GameObject)Instantiate(PrefabBullet, BulletPosition.position, BulletPosition.rotation);
        bullet.GetComponent<Rigidbody>().velocity = bullet.transform.forward * 20;
        // GetComponen<NombreComponente> nos permite tomar algun componente que queremos para nuestra variable
        Destroy(bullet, 2.0f);
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey(KeyCode.Space))
        {
            Fire();
        }
        if (Input.GetKey(KeyCode.LeftArrow))
        {
            Vector3 newPosition = this.transform.position; // Se toman las posiciones actuales del objeto
            newPosition.y = Time.deltaTime * 150.0f; // Cambiamos la posicion del objeto en su eje de las y
            this.transform.Rotate(0, -newPosition.y, 0); // Rotamos la posicion del objeto sobre el eje de las y
                // En base al movimiento ya creado en position.y
        }
        if(Input.GetKey(KeyCode.UpArrow))
        {
            Vector3 newPosition = this.transform.position;
            newPosition.z = Time.deltaTime * 3.0f;
            this.transform.Translate(0, 0, newPosition.z);
        }
        if(Input.GetKey(KeyCode.RightArrow))
        {
            Vector3 newPosition = this.transform.position;
            newPosition.y = Time.deltaTime * 150.0f;
            this.transform.Rotate(0, newPosition.y, 0);
        }
        if(Input.GetKey(KeyCode.DownArrow))
        {
            Vector3 newPosition = this.transform.position;
            newPosition.z = Time.deltaTime * 3.0f;
            this.transform.Translate(0, 0, -newPosition.z);
        }
    }
}
