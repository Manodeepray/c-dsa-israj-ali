
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>


#define V 9

int minKey(int key[], bool mstSet[])
{
   
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}


int printMST(int parent[], int graph[V][V])
{
    printf("graph : \n");
    for(int i = 0 ; i < V ; i++)
    {
    	for(int j = 0 ; j < V ; j++)
    		{
    		printf(" %d ",graph[i][j]);
    		}
    	printf("\n");
    }	
    int totWT = 0;

    for (int i = 1; i < V; i++){
    	totWT += graph[i][parent[i]];
        
              	}
    printf("total weight = %d " , totWT);
}


void primMST(int graph[V][V])
{

    int parent[V];

    int key[V];

    bool mstSet[V];


    for (int i = 0; i < V; i++){
        key[i] = INT_MAX;
        mstSet[i] = false;}



 
    key[0] = 0;
  

    parent[0] = -1;


    for (int count = 0; count < V - 1; count++) {
        
        int u = minKey(key, mstSet);


        mstSet[u] = true;

        for (int v = 0; v < V; v++)

            if (graph[u][v] && mstSet[v] == false
                && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }


    printMST(parent, graph);
}


int main()
{
    int graph[V][V] = { { 0, 4, 0, 0, 0 ,0 ,0 ,8 ,0},
                        { 4, 0, 0, 0, 0 ,0 ,0 ,0 ,0},
                        { 0, 0, 0, 7, 0 ,4 ,0 ,0 ,2},
                        { 0, 0, 7, 0, 9 ,0 ,0 ,0 ,0},
                        { 0, 0, 0, 9, 0 ,0 ,0 ,0 ,0},
                        { 0, 0, 4, 0, 0 ,0 ,2 ,0 ,0},
                        { 0, 0, 0, 0, 0 ,2 ,0 ,1 ,0},
                        { 8, 0, 0, 0, 0 ,0 ,1 ,0 ,0},
                        { 0, 0, 2, 0, 0 ,0 ,0 ,0 ,0} };


    primMST(graph);

    return 0;
}

