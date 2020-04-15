#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <math.h>
#include <ctime>

using namespace std;

// Vector que contendra la cantidad solicitada de numeros aleatorios
vector<float> numerosAleatorios;
int cantidad;

void generarNumerosAleat(int cantidad) {

	for (int i = 0; i < cantidad; i++)
	{
		float numeroTemporal = (rand() % 100);
		numeroTemporal /= 10;
		numerosAleatorios.push_back(numeroTemporal);
	}
	
}

void BucketSort(float arr[], int x)
{
	// Paso 1.
	// Creamos el vector de tamanio X, donde x es el numero de numeros ingresados por el usuario
	vector<float> b[x]; // Este vector llamado b, es el encargado de almacenar los buckets, por lo tanto:
	// cada espacio o indice del vector seria un bucket, se veria asi:
	/*
		vector b = {
			[0] = bucket 0
				numeros que estan dentro del bucket 0
			[1] = bucket 1
				numeros que estan dentro del bucket 1
		}

		Aqui solo se creo el vector (vacio) de buckets, pero aun no hay buckets dentro
	*/

	// Paso 2
	// En este paso se llenara el vector vacio creado en el Paso 1 con buckets, segun los numeros ingresados
	for (int a=0; a<x; a++)
    {
		// Crear los buckets necesarios dependiendo los numeros ingresados
		float bucket = arr[a] / 1000;	// Crear la restriccion o parametro para el bucket
    	int y = x * bucket; // 12 * 214 = 2568	|  Y es igual al bucket -> 0.804 = 0 ->  Se hace el bucket 0
       	b[y].push_back(arr[a]); // vector tiene 10 -> 0 al 9 -> push_back en el 40 | Agregar el numero a su bucket correspondiente
    }

	// Paso 3
	// Ordenamiento de cada buckets dentro del vector b
	// Tomar cada bucket del vector b (b[a] = b[bucket n])
    for (int a=0; a<x; a++)
    {	
	    sort(b[a].begin(), b[a].end()); // Ordena de menor a mayor
    }

	// Paso 4 (Metodo Burbuja)
	// Juntar el contenido de todos los buckets en un solo vector
	// Lo que hacemos es ingresar a cada bucket del vector b, agarrar cada numero dentro de ese bucket
	// y guardarlo en el arreglo arr[], haciendo esta accion por cada bucket, y dentro de cada bucket, 
	// por cada numero
    int index = 0;
    for (int i=0; i<x; i++) // Recorrer cada Bucket del vector b
    {	// Dentro del vector
        for (int j = 0; j < b[i].size(); j++)  // Recorrer cada elemento dentro del Bucket
		{	// Dentro del Bucket
			arr[index++] = b[i][j];
		}
	}
}

// Mostrar lo que tenemos en nuestro arreglo a consola de inicio a fin
void display(float arr[], int x)
{
	for (int a=0; a<x; a++)
    {
       cout<<arr[a]<<" ";
    }
}

// Mostrar el contenido del arreglo de fin a inicio, para satisfacer la condicion de que sean de 
// mayor a menor, debido a que se encuentran ordenados de menor a mayor
void displayDesc(float arr[], int x)
{
	for (int a=x-1; a>=0; a--)
    {
       cout<<arr[a]<<" ";
    }
}

int main ()
{
	int opc;
	cout << "==MENU==" << endl;
	cout << "1. Generar Numeros Aleatorios\n2. Yo quiero ingresar los numeros" << endl;
	cout << "Elige la opcion deseada: ";
	cin >> opc;
	if (opc == 1)
	{
		cout << "Cuantos numeros desea generar?" << endl;
		cin >> cantidad;

		// Generamos los numeros aleatorios
		generarNumerosAleat(cantidad); 

		// Arreglo que contendra nuestros numeros aleatorios
		float arregloNumAleat[numerosAleatorios.size()];

		// Guardamos nuestro vector de num aleatorios en un arreglo
		for (int i=0; i<numerosAleatorios.size(); i++)
		{
		arregloNumAleat[i] = numerosAleatorios[i];
		}

		cout << "Numero aleatorios generados: " << endl;
		display(arregloNumAleat, cantidad);
		cout << endl;
		BucketSort(arregloNumAleat, cantidad);
		cout << "Numero aleatorios ordenados: " << endl;
		displayDesc(arregloNumAleat, cantidad);
	}
	else if(opc == 2)
	{
		cout<<"Introduce cuantos numeros quieres ordenar: ";
		cin>>cantidad;
		float arr[cantidad];
		cout<<"Dime los numeros:\n";
		for(int a=0; a<cantidad;a++)
		{
			cout<<"Numero "<<a+1<<" de "<<cantidad<<": ";
			cin>>arr[a];
		}
		cout<<"Arreglo original: ";
		display(arr,cantidad);
		BucketSort(arr,cantidad);
		cout << endl;
		cout<<"Arreglo de mayor a menor: ";
		displayDesc(arr,cantidad);
	}
	else {
		cout << "No se reconoce la opcion ingresada" << endl;
	}
	
	return 0;
}
