#include <iostream>
#include <cmath>
#include <stack>
#include <set>
#include <cstring>

using namespace std; 

#define FLT_MAX    1E+37
#define FILAS 9
#define COLUMNAS 10

typedef pair<int, int> Par;
typedef pair<double, pair<int, int> > pPar;

// node almacenara la informacion de los vertices
// padres que se iran sustiyendo segun las distancias
struct node
{
    int parent_i, parent_j;
    double f, g, h;
};

// Funcion para verificar si las coordenadas ingresadas
// existen en el plano o grid creado
bool isValid(int r, int c)
{
    return (r >= 0) && (r < FILAS) &&
            (c >= 0) && (c < COLUMNAS);
}

// Funcion para saber si la celda a trabajar es un obstaculo
bool isObstacle(int grid[][COLUMNAS], int r, int c)
{
    // Retorna verdadero si la celda es 1, lo que significa
    // que no es un obstaculo
    if(grid[r][c] == 1) return (true);
    else return (false);
}

// Funcion para saber si se ha llegado al vertice destino
bool isDestination(int r, int c, Par d)
{ // r = row, c = column, d = destination
    if(r == d.first && c == d.second) return (true);
    else return (false);
}

// Function para calcular el valor heuristico de la distancia
double calculateHeuristic(int r, int c, Par d)
{
    return ((double)sqrt ((r - d.first) * (r - d.first)
                    + (c - d.second) * ( - d.second)));
}

// Funcion para trazar la ruta desde el punto inicial al destino
void tracePath(node nodeDetails[][COLUMNAS], Par d)
{
    printf("\nLa ruta es ");
    int row = d.first;
    int col = d.second;

    stack<Par> Path;

    while (!(nodeDetails[row][col].parent_i == row 
			&& nodeDetails[row][col].parent_j == col )) 
	{ 
		Path.push (make_pair (row, col)); 
		int temp_row = nodeDetails[row][col].parent_i; 
		int temp_col = nodeDetails[row][col].parent_j; 
		row = temp_row; 
		col = temp_col; 
	} 

	Path.push (make_pair (row, col)); 
	while (!Path.empty()) 
	{ 
		pair<int,int> p = Path.top(); 
		Path.pop(); 
		printf("-> (%d,%d) ",p.first,p.second); 
	} 

	return;
}

// Funcion para encontrar el camino mas corto entre los
// puntos dados de inicio y destin conforme al algoritmo 
// A-Star
void aStar(int grid[][COLUMNAS], Par src, Par d)
{
    // Si el vertice inicial no es valido
    if(isValid(src.first, src.second) == false)
    {
        cout << "Punto inicial no valido" << endl;
        return;
    }

    // Si el vertice destino no es valido o fuera de rango
    if(isValid(d.first, d.second) == false)
    {
        cout << "Destino no valido" << endl;
        return;
    }

    // Si el destino o punto inicial son obstaculos
    if ( isObstacle(grid, src.first, src.second) == false ||
        isObstacle(grid, d.first, d.second) == false )
    {
         cout << "El destino o punto de partida es un obstaculo" << endl;
        return;
    }

    // Si el destino y punto inicial son la misma direccion
    if (isDestination(src.first, src.second, d))
    {
        cout << "Ya nos encontramos en el punto destino" << endl;
        return;
    }
    
    bool closedList[FILAS][COLUMNAS]; 
	memset(closedList, false, sizeof (closedList)); 

	// Declaramos un array 2D para almancenar los datos
    // de los vertices
	node nodeDetails[FILAS][COLUMNAS]; 

	int i, j; 

	for (i=0; i<FILAS; i++) 
	{ 
		for (j=0; j<COLUMNAS; j++) 
		{ 
			nodeDetails[i][j].f = FLT_MAX; 
			nodeDetails[i][j].g = FLT_MAX; 
			nodeDetails[i][j].h = FLT_MAX; 
			nodeDetails[i][j].parent_i = -1; 
			nodeDetails[i][j].parent_j = -1; 
		} 
	} 

	// Inicializamos los parametros del primer nodo
	i = src.first, j = src.second; 
	nodeDetails[i][j].f = 0.0; 
	nodeDetails[i][j].g = 0.0; 
	nodeDetails[i][j].h = 0.0; 
	nodeDetails[i][j].parent_i = i; 
	nodeDetails[i][j].parent_j = j; 

	set<pPar> openList; 

	openList.insert(make_pair (0.0, make_pair (i, j))); 

	// Inicializamos en false que hemos llegado al punto destino
	bool foundDest = false; 

	while (!openList.empty()) 
	{ 
		pPar p = *openList.begin(); 

		// Eliminamos el vertice de la lista
		openList.erase(openList.begin()); 

		// agregamos el vertice a la lista
		i = p.second.first; 
		j = p.second.second; 
		closedList[i][j] = true; 

		// Para almacenar los datos de g, h y f del 
        // vertice siguiente
		double gNew, hNew, fNew; 

		//----------- Primer eje ------------ 

		// Solo iniciamos el proceso si el vertice es valido 
		if (isValid(i-1, j) == true) 
		{ 
			// Revisamos que el punto destino no sea igual al
            // sucesor
			if (isDestination(i-1, j, d) == true) 
			{ 
				// Declaramos el parent de nuestro vertice destino
				nodeDetails[i-1][j].parent_i = i; 
				nodeDetails[i-1][j].parent_j = j; 
				cout << "Se ha encontrado la mejor ruta!" << endl; 
				tracePath (nodeDetails, d); 
				foundDest = true; 
				return; 
			} 
			else if (closedList[i-1][j] == false && 
					isObstacle(grid, i-1, j) == true) 
			{ 
				gNew = nodeDetails[i][j].g + 1.0; 
				hNew = calculateHeuristic (i-1, j, d); 
				fNew = gNew + hNew; 
                
				if (nodeDetails[i-1][j].f == FLT_MAX || 
						nodeDetails[i-1][j].f > fNew) 
				{ 
					openList.insert( make_pair(fNew, 
											make_pair(i-1, j))); 

					// Actualizamos los datos de nuestro nodo
					nodeDetails[i-1][j].f = fNew; 
					nodeDetails[i-1][j].g = gNew; 
					nodeDetails[i-1][j].h = hNew; 
					nodeDetails[i-1][j].parent_i = i; 
					nodeDetails[i-1][j].parent_j = j; 
				} 
			} 
		} 

		//----------- Siguiente eje ------------ 

		if (isValid(i+1, j) == true) 
		{ 
			if (isDestination(i+1, j, d) == true) 
			{ 
				nodeDetails[i+1][j].parent_i = i; 
				nodeDetails[i+1][j].parent_j = j; 
				cout << "Se ha encontrado la mejor ruta!" << endl;
				tracePath(nodeDetails, d); 
				foundDest = true; 
				return; 
			} 
			else if (closedList[i+1][j] == false && 
					isObstacle(grid, i+1, j) == true) 
			{ 
				gNew = nodeDetails[i][j].g + 1.0; 
				hNew = calculateHeuristic(i+1, j, d); 
				fNew = gNew + hNew; 

				if (nodeDetails[i+1][j].f == FLT_MAX || 
						nodeDetails[i+1][j].f > fNew) 
				{ 
					openList.insert( make_pair (fNew, make_pair (i+1, j))); 
					nodeDetails[i+1][j].f = fNew; 
					nodeDetails[i+1][j].g = gNew; 
					nodeDetails[i+1][j].h = hNew; 
					nodeDetails[i+1][j].parent_i = i; 
					nodeDetails[i+1][j].parent_j = j; 
				} 
			} 
		} 

		//----------- Siguiente eje ------------ 

		if (isValid (i, j+1) == true) 
		{ 
			if (isDestination(i, j+1, d) == true) 
			{ 
				nodeDetails[i][j+1].parent_i = i; 
				nodeDetails[i][j+1].parent_j = j; 
				cout << "Se ha encontrado la mejor ruta!" << endl;
				tracePath(nodeDetails, d); 
				foundDest = true; 
				return; 
			} 

			else if (closedList[i][j+1] == false && 
					isObstacle (grid, i, j+1) == true) 
			{ 
				gNew = nodeDetails[i][j].g + 1.0; 
				hNew = calculateHeuristic (i, j+1, d); 
				fNew = gNew + hNew; 

				if (nodeDetails[i][j+1].f == FLT_MAX || 
						nodeDetails[i][j+1].f > fNew) 
				{ 
					openList.insert( make_pair(fNew, 
										make_pair (i, j+1))); 

					nodeDetails[i][j+1].f = fNew; 
					nodeDetails[i][j+1].g = gNew; 
					nodeDetails[i][j+1].h = hNew; 
					nodeDetails[i][j+1].parent_i = i; 
					nodeDetails[i][j+1].parent_j = j; 
				} 
			} 
		} 

		//----------- Siguiente eje ------------ 

		if (isValid(i, j-1) == true) 
		{ 
			if (isDestination(i, j-1, d) == true) 
			{ 
				nodeDetails[i][j-1].parent_i = i; 
				nodeDetails[i][j-1].parent_j = j; 
				cout << "Se ha encontrado la mejor ruta!" << endl;
				tracePath(nodeDetails, d); 
				foundDest = true; 
				return; 
			} 

			else if (closedList[i][j-1] == false && 
					isObstacle(grid, i, j-1) == true) 
			{ 
				gNew = nodeDetails[i][j].g + 1.0; 
				hNew = calculateHeuristic(i, j-1, d); 
				fNew = gNew + hNew; 

				if (nodeDetails[i][j-1].f == FLT_MAX || 
						nodeDetails[i][j-1].f > fNew) 
				{ 
					openList.insert( make_pair (fNew, 
										make_pair (i, j-1))); 

					nodeDetails[i][j-1].f = fNew; 
					nodeDetails[i][j-1].g = gNew; 
					nodeDetails[i][j-1].h = hNew; 
					nodeDetails[i][j-1].parent_i = i; 
					nodeDetails[i][j-1].parent_j = j; 
				} 
			} 
		} 

		//----------- Siguiente eje ------------ 

		if (isValid(i-1, j+1) == true) 
		{ 
			if (isDestination(i-1, j+1, d) == true) 
			{ 
				nodeDetails[i-1][j+1].parent_i = i; 
				nodeDetails[i-1][j+1].parent_j = j; 
				cout << "Se ha encontrado la mejor ruta!" << endl; 
				tracePath (nodeDetails, d); 
				foundDest = true; 
				return; 
			} 

			else if (closedList[i-1][j+1] == false && 
					isObstacle(grid, i-1, j+1) == true) 
			{ 
				gNew = nodeDetails[i][j].g + 1.414; 
				hNew = calculateHeuristic(i-1, j+1, d); 
				fNew = gNew + hNew; 

				if (nodeDetails[i-1][j+1].f == FLT_MAX || 
						nodeDetails[i-1][j+1].f > fNew) 
				{ 
					openList.insert( make_pair (fNew, 
									make_pair(i-1, j+1))); 

					nodeDetails[i-1][j+1].f = fNew; 
					nodeDetails[i-1][j+1].g = gNew; 
					nodeDetails[i-1][j+1].h = hNew; 
					nodeDetails[i-1][j+1].parent_i = i; 
					nodeDetails[i-1][j+1].parent_j = j; 
				} 
			} 
		} 

		//----------- Siguiente eje ------------ 

		if (isValid (i-1, j-1) == true) 
		{ 
			if (isDestination (i-1, j-1, d) == true) 
			{ 
				nodeDetails[i-1][j-1].parent_i = i; 
				nodeDetails[i-1][j-1].parent_j = j; 
				cout << "Se ha encontrado la mejor ruta!" << endl; 
				tracePath (nodeDetails, d); 
				foundDest = true; 
				return; 
			} 

			else if (closedList[i-1][j-1] == false && 
					isObstacle(grid, i-1, j-1) == true) 
			{ 
				gNew = nodeDetails[i][j].g + 1.414; 
				hNew = calculateHeuristic(i-1, j-1, d); 
				fNew = gNew + hNew; 

				if (nodeDetails[i-1][j-1].f == FLT_MAX || 
						nodeDetails[i-1][j-1].f > fNew) 
				{ 
					openList.insert( make_pair (fNew, make_pair (i-1, j-1))); 
					nodeDetails[i-1][j-1].f = fNew; 
					nodeDetails[i-1][j-1].g = gNew; 
					nodeDetails[i-1][j-1].h = hNew; 
					nodeDetails[i-1][j-1].parent_i = i; 
					nodeDetails[i-1][j-1].parent_j = j; 
				} 
			} 
		} 

		//----------- Siguiente eje ------------ 

		if (isValid(i+1, j+1) == true) 
		{ 
			if (isDestination(i+1, j+1, d) == true) 
			{ 
				// Set the Parent of the destination node 
				nodeDetails[i+1][j+1].parent_i = i; 
				nodeDetails[i+1][j+1].parent_j = j; 
				cout << "Se ha encontrado la mejor ruta!" << endl; 
				tracePath (nodeDetails, d); 
				foundDest = true; 
				return; 
			} 

			else if (closedList[i+1][j+1] == false && 
					isObstacle(grid, i+1, j+1) == true) 
			{ 
				gNew = nodeDetails[i][j].g + 1.414; 
				hNew = calculateHeuristic(i+1, j+1, d); 
				fNew = gNew + hNew; 

				if (nodeDetails[i+1][j+1].f == FLT_MAX || 
						nodeDetails[i+1][j+1].f > fNew) 
				{ 
					openList.insert(make_pair(fNew, 
										make_pair (i+1, j+1))); 

					nodeDetails[i+1][j+1].f = fNew; 
					nodeDetails[i+1][j+1].g = gNew; 
					nodeDetails[i+1][j+1].h = hNew; 
					nodeDetails[i+1][j+1].parent_i = i; 
					nodeDetails[i+1][j+1].parent_j = j; 
				} 
			} 
		} 

		//----------- Siguiente eje ------------ 

		// Solo entramos en el proceso si el nodo es valido
		if (isValid (i+1, j-1) == true) 
		{ 
			// Cuando nuestro vertice destino es el mismo que
			// el vertice siguiente
			if (isDestination(i+1, j-1, d) == true) 
			{ 
				// Declaramos el parent de nuestro vertice destino
				nodeDetails[i+1][j-1].parent_i = i; 
				nodeDetails[i+1][j-1].parent_j = j; 
				cout << "Se ha encontrado la mejor ruta!" << endl;
				tracePath(nodeDetails, d); 
				foundDest = true; 
				return; 
			} 

			else if (closedList[i+1][j-1] == false && 
					isObstacle(grid, i+1, j-1) == true) 
			{ 
				gNew = nodeDetails[i][j].g + 1.414; 
				hNew = calculateHeuristic(i+1, j-1, d); 
				fNew = gNew + hNew; 

				if (nodeDetails[i+1][j-1].f == FLT_MAX || 
						nodeDetails[i+1][j-1].f > fNew) 
				{ 
					openList.insert(make_pair(fNew, 
										make_pair(i+1, j-1))); 

					// Actualizamos los datos de nuestro nodo
					nodeDetails[i+1][j-1].f = fNew; 
					nodeDetails[i+1][j-1].g = gNew; 
					nodeDetails[i+1][j-1].h = hNew; 
					nodeDetails[i+1][j-1].parent_i = i; 
					nodeDetails[i+1][j-1].parent_j = j; 
				} 
			} 
		} 
	} 

	// Esta condicion se cumple solo cuando no hemos encontrado 
    // el destino y nuestra cola de vertices esta vacia
	if (foundDest == false) 
        cout << "No se ha podido encontrar el punto de destino" << endl;

	return; 
}

int main()
{
    // Creamos nuestro grid de vertices
    // 1 = Es un vertice libre
    // 0 = Es un obstaculo
    int grid[FILAS][COLUMNAS] = 
	{ 
		{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 }, 
		{ 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 }, 
		{ 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 }, 
		{ 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 }, 
		{ 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 }, 
		{ 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 }, 
		{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 }, 
		{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 }, 
		{ 1, 1, 1, 0, 0, 0, 1, 0, 0, 1 } 
	}; 

    // Definimos el punto de partida
    Par s = make_pair(8, 6);

    // Definimos el punto de destino
    Par d = make_pair(1, 1);

    // Algoritmo de busqueda de caminos cortos
    // A* Algorithm
    aStar(grid, s, d);

    return 0;
}