using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement; // Libreria necesaria para gestionar escenas

public class PausarJuego : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {   
        
    }

    // Para pausar el tiempo en el juego
    public void Pausar()
    {
        Time.timeScale = 0; // 0 para detener el tiempo del juego
    }

    // Para iniciar el tiempo en el juego
    public void Despausar()
    {
        Time.timeScale = 1; // 1 para iniciar el tiempo del juego
    }

    // Para salir del juego y regresar a escena Menu
    public void SalirDelJuego()
    {
        Time.timeScale = 1; // Para volver a iniciar el tiempo en el juego
        SceneManager.LoadScene("Menu"); // Usamos objeto SceneManager de la libreria
            // SceneManagement para cargar la escena Menu
    }
}
