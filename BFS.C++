#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
  int V;
  // Array of list;
  list<int> *l;

public:
  Graph(int V)
  {
    this->V = V;
    l = new list<int>[V];
  }

  void addEdge(int x, int y)
  {
    l[x].push_back(y);
    l[y].push_back(x);
  }

  void BFS(int start)
  {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
      int current = q.front();
      cout << current << " ";
      q.pop();

      for (int neighbor : l[current])
      {
        if (!visited[neighbor])
        {
          visited[neighbor] = true;
          q.push(neighbor);
        }
      }
    }
  }

  void printAdjList()
  {
    for (int i = 0; i < V; ++i)
    {
      cout << "Adjacency list of vertex " << i << ": ";
      for (int node : l[i])
      {
        cout << node << " ";
      }
      cout << endl;
    }
  }
};

int main()
{
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(2, 3);
  g.addEdge(1, 2);
  g.BFS(0); // Perform BFS starting from node 0
  return 0;
}