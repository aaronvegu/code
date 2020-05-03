#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

void imprimirGrafo(set<int> graph[], int numElementos)
{
    for (int i = 0; i < numElementos; i++)
    {
        set<int> :: iterator itr;
        cout << "Set " << i << ": " << "{ ";
        for (itr = graph[i].begin(); itr != graph[i].end(); ++itr)
        {
            cout << *itr << " ";
        }
        cout << "}";
        cout << endl;
    }
    
}

int find(set<int> graph[], int numVertices, int toFind)
{
    for (int i = 0; i < numVertices; i++)
    {
        set<int> :: iterator itr;
        for (itr = graph[i].begin(); itr != graph[i].end(); ++itr)
        {
            if (*itr == toFind) return i;
        }
    }
    return -1;
}

void makeUnion(set<int> graph[], int set1, int set2)
{
    if (set1 == set2) return;
    set<int> :: iterator itr;
    for (itr = graph[set2].begin(); itr != graph[set2].end(); ++itr)
    {
        graph[set1].insert(*itr);
    }
    graph[set2].erase(graph[set2].begin(), graph[set2].end());
}

int findMin(set<int> graph[], int n)
{
    int array[n];
    for (int i = 0; i < n; i++)
    {
        array[i] = graph[i].size();
    }
    int s = sizeof(array)/sizeof(array[0]);
    sort(array, array+n);
    for (int p = 0; p < n; p++)
        if(array[p] != 0) return array[p]; 
    return 0; 
}

int findMax(set<int> graph[], int n)
{
    int array[n];
    for (int i = 0; i < n; i++)
    {
        array[i] = graph[i].size();
    }
    int s = sizeof(array)/sizeof(array[0]);
    sort(array, array+n, greater<int>());
    return array[0];
}

int main()
{

    int n, v, e;

    cin >> n;
    set<int> graph[n];
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        cin.ignore(1, ' ');
        cin >> e;
        graph[i].insert(v);
        graph[i].insert(e);
        if (find(graph, n, v) != -1)
            makeUnion(graph, i, find(graph, n, v));
        if (find(graph, n, e) != -1)
            makeUnion(graph, i, find(graph, n, e));
    }

    cout << findMin(graph, n) << " " << findMax(graph, n);

    return 0;
}