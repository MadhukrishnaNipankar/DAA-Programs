#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100;
class Graph
{
    int adjacencyMatrix[MAX][MAX];
    int V; // number of vertices
    int visited[MAX] = {0};

public:
    Graph(int V)
    {
        this->V = V;

        // Initializing the adjacency matrix to 0
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                adjacencyMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int src, int dest)
    {
        adjacencyMatrix[src][dest] = 1;
        adjacencyMatrix[dest][src] = 1;
    }

    void dfs(int startNode)
    {
        std::cout << startNode << " ";
        visited[startNode] = 1;

        for (int i = 0; i < V; i++)
        {
            if (adjacencyMatrix[startNode][i] == 1 && !visited[i])
            {
                dfs(i);
            }
        }
    }

    void bfs(int startNode)
    {
        queue<int> q;
        visited[startNode] = 1;
        q.push(startNode);

        while (!q.empty())
        {
            int frontNode = q.front();
            std::cout << frontNode << " ";
            q.pop();

            for (int i = 0; i < V; i++)
            {
                if (adjacencyMatrix[frontNode][i] == 1 && !visited[i])
                {
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
    }
};

int main()
{

    Graph g(7);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 6);
    // g.addEdge(3, 4);

    g.bfs(0);
}