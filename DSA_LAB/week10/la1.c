#include <stdio.h>

// Maximum number of nodes in the graph
#define MAX_NODES 100

// Function to initialize the graph with all edges set to 0
void initializeGraph(int graph[MAX_NODES][MAX_NODES], int numNodes)
{
    for (int i = 0; i < numNodes; i++)
    {
        for (int j = 0; j < numNodes; j++)
        {
            graph[i][j] = 0;
        }
    }
}

// Function to add an edge to the graph
void addEdge(int graph[MAX_NODES][MAX_NODES], int start, int end)
{
    graph[start][end] = 1;
    graph[end][start] = 1; // Assuming an undirected graph
}

// Function to delete an edge from the graph
void deleteEdge(int graph[MAX_NODES][MAX_NODES], int start, int end)
{
    graph[start][end] = 0;
    graph[end][start] = 0;
}

// Function to add a new node to the graph
void addNode(int graph[MAX_NODES][MAX_NODES], int *numNodes)
{
    if (*numNodes < MAX_NODES)
    {
        (*numNodes)++;
    }
    else
    {
        printf("Cannot add more nodes. Maximum limit reached.\n");
        return;
    }
}

// Function to delete a node from the graph
void deleteNode(int graph[MAX_NODES][MAX_NODES], int *numNodes, int nodeToDelete)
{
    if (nodeToDelete >= *numNodes)
    {
        printf("Invalid node index.\n");
        return;
    }

    for (int i = nodeToDelete; i < *numNodes - 1; i++)
    {
        for (int j = 0; j < *numNodes; j++)
        {
            graph[i][j] = graph[i + 1][j];
            graph[j][i] = graph[j][i + 1];
        }
    }

    for (int i = 0; i < *numNodes; i++)
    {
        graph[*numNodes - 1][i] = 0;
        graph[i][*numNodes - 1] = 0;
    }

    (*numNodes)--;
}

// Function to count the number of nodes and edges in the graph
void countNodesAndEdges(int numNodes, int graph[MAX_NODES][MAX_NODES])
{
    int numEdges = 0;

    for (int i = 0; i < numNodes; i++)
    {
        for (int j = 0; j < numNodes; j++)
        {
            if (graph[i][j] == 1)
            {
                numEdges++;
            }
        }
    }

    printf("Number of nodes: %d\n", numNodes);
    printf("Number of edges: %d\n", numEdges);
}

// Function for Depth First Search (DFS)
void DFS(int node, int numNodes, int graph[MAX_NODES][MAX_NODES], int visited[MAX_NODES])
{
    printf("%d ", node);
    visited[node] = 1;

    for (int i = 0; i < numNodes; i++)
    {
        if (graph[node][i] == 1 && !visited[i])
        {
            DFS(i, numNodes, graph, visited);
        }
    }
}

// Function for Breadth First Search (BFS)
void BFS(int start, int numNodes, int graph[MAX_NODES][MAX_NODES], int visited[MAX_NODES])
{
    int queue[MAX_NODES];
    int front = 0, rear = 0;

    printf("%d ", start);
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear)
    {
        int currentNode = queue[front++];

        for (int i = 0; i < numNodes; i++)
        {
            if (graph[currentNode][i] == 1 && !visited[i])
            {
                printf("%d ", i);
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main()
{
    int graph[MAX_NODES][MAX_NODES];
    int numNodes = 0;
    int visited[MAX_NODES];

    initializeGraph(graph, MAX_NODES);

    int choice, start, end, nodeToDelete;
    printf("Roll NO. 2230028 NAME : MANODEEP RAY");

    do
    {
        printf("\n1. Add Edge\n");
        printf("2. Delete Edge\n");
        printf("3. Add Node\n");
        printf("4. Delete Node\n");
        printf("5. Count Nodes and Edges\n");
        printf("6. Depth First Search (DFS)\n");
        printf("7. Breadth First Search (BFS)\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter start and end nodes for the new edge: ");
            scanf("%d %d", &start, &end);
            addEdge(graph, start, end);
            break;

        case 2:
            printf("Enter start and end nodes for the edge to delete: ");
            scanf("%d %d", &start, &end);
            deleteEdge(graph, start, end);
            break;

        case 3:
            addNode(graph, &numNodes);
            break;

        case 4:
            printf("Enter the index of the node to delete: ");
            scanf("%d", &nodeToDelete);
            deleteNode(graph, &numNodes, nodeToDelete);
            break;

        case 5:
            countNodesAndEdges(numNodes, graph);
            break;

        case 6:
            printf("Enter the starting node for DFS: ");
            scanf("%d", &start);
            initializeGraph(visited, MAX_NODES);
            printf("DFS traversal starting from node %d: ", start);
            DFS(start, numNodes, graph, visited);
            printf("\n");
            break;

        case 7:
            printf("Enter the starting node for BFS: ");
            scanf("%d", &start);
            initializeGraph(visited, MAX_NODES);
            printf("BFS traversal starting from node %d: ", start);
            BFS(start, numNodes, graph, visited);
            printf("\n");
            break;

        case 8:
            printf("Exiting the program.\n");
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 8);

    return 0;
}
