#include <iostream>
#include <queue>
using namespace std;
#define max 100
class Graph
{
    int adjancencyMatrix[max][max];
    int numvertices;

public:
    Graph(int start)
    {
        numvertices = start;
        for (int i = 0; i < numvertices; i++)
        {
            for (int j = 0; j < numvertices; j++)
            {
                adjancencyMatrix[i][j] = 0;
            }
        }
    }
    void addedge(int src, int dest)
    {
        adjancencyMatrix[src][dest] = 1;
        adjancencyMatrix[dest][src] = 1;
    }
    void dfs(int start)
    {
        bool visited[max] = {false};
        cout << "dfs traversal :" << endl;
        dfsutil(start, visited);
    }
    void dfsutil(int start, bool visited[])
    {
        visited[start] = true;
        cout << start << " ";
        for (int i = 0; i < numvertices; i++)
        {
            if (adjancencyMatrix[start][i] == 1 && !visited[i])
            {
                dfsutil(i, visited);
            }
        }
    }
    void bfs(int start)
    {
        bool visited[max] = {false};
        queue<int> q;
        cout << "\nBfs traversal :" << endl;
        visited[start] = true;
        cout << start << " ";
        q.push(start);
        while (!q.empty())
        {
            int vertex = q.front();
            q.pop();
            for (int i = 0; i < numvertices; i++)
            {
                if (adjancencyMatrix[vertex][i] == 1 && !visited[i])
                {
                    visited[i] = true;
                    cout << i << " ";
                    q.push(i);
                }
            }
        }
    }
};
int main()
{
    Graph graph(7);
    graph.addedge(0, 1);
    graph.addedge(0, 2);
    graph.addedge(1, 3);
    graph.addedge(2, 4);
    graph.addedge(2, 5);
    graph.addedge(3, 6);

    graph.dfs(0);
    graph.bfs(0);
    return 0;
}