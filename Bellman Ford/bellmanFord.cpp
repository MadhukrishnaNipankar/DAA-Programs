#include <iostream>
#include <climits>
using namespace std;

const int MAX_SIZE = 100;

bool bellmanFord(int graph[8][3], int numVertices, int numEdges, int source)
{
    int distance[numVertices];

    // Initialize all the distances to infinity
    int inf = INT_MAX;
    for (int i = 0; i < numVertices; i++)
    {
        distance[i] = inf;
    }

    distance[source] = 0;

    for (int i = 0; i < numVertices - 1; i++)
    {
        for (int j = 0; j < numEdges; j++)
        {
            int src = graph[j][0];
            int destination = graph[j][1];
            int weight = graph[j][2];

            if (distance[src] != INT_MAX && distance[src] + weight < distance[destination])
            {
                distance[destination] = distance[src] + weight;
            }
        }
    }

    // Check for negative weight cycles
    for (int j = 0; j < numEdges; j++)
    {
        int src = graph[j][0];
        int destination = graph[j][1];
        int weight = graph[j][2];

        if (distance[src] != INT_MAX && distance[src] + weight < distance[destination])
        {
            return true; // Negative weight cycle detected
        }
    }

    return false; // No negative weight cycle
}

int main()
{

    int numVertices = 5;
    int numEdges = 8;
    int graph[8][3] = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}};

    int source = 0;

    bool hasNegativeCycle = bellmanFord(graph, numVertices, numEdges, source);

    if (hasNegativeCycle)
    {
        cout << "Negative weight cycle detected!" << endl;
    }
    else
    {
        cout << "No negative weight cycle found." << endl;
    }

    return 0;
}