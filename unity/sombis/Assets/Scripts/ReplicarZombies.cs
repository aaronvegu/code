using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ReplicarZombies : MonoBehaviour
{
    // Replicadores
    public Transform spawn1;
    public Transform spawn2;
    public Transform spawn3;
    // Contadores de tiempo
    float creationInterval1 = 10.0f;
    float creationInterval2 = 15.0f;
    float creationInterval3 = 20.0f;
    // Prefab Zombie
    public GameObject PrefabZombie;

    // Metodos
    private void calcularTiempo() // Disminuye el contador de respawn
    {
        creationInterval1 -= Time.deltaTime;
        creationInterval2 -= Time.deltaTime;
        creationInterval3 -= Time.deltaTime;
        // Debug.Log(creationInterval1);
    }
    private void crearZombie(Transform spawn)
    {
        GameObject zombie = (GameObject)Instantiate(PrefabZombie, spawn.position, spawn.rotation);
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        calcularTiempo();
        if(creationInterval1 <= 0)
        {
            crearZombie(spawn1);
            creationInterval1 = 10;
        }
        if(creationInterval2 <= 0)
        {
            crearZombie(spawn2);
            creationInterval2 = 15;
        }
        if(creationInterval3 <= 0)
        {
            crearZombie(spawn3);
            creationInterval3 = 20;
        }
    }
}
