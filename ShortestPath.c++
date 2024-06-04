#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <queue>
#include <climits> // for INT_MAX
#include <unordered_map>
using namespace std;

class Graph
{
  int V;
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

  void SPBFS(int start)
  {
    vector<bool> visited(V, false);
    unordered_map<int, int> distance; // Initialize the hash map
    queue<int> q;

    visited[start] = true;
    distance[start] = 0; // Set the distance of the start node to  0
   
    q.push(start);

    while (!q.empty())
    {
      int current = q.front();
      q.pop();

      for (int neighbor : l[current])
      {
        if (!visited[neighbor])
        {
          visited[neighbor] = true;
          // Set the distance of the neighbor
          distance[neighbor] = distance[current] + 1;
          q.push(neighbor);
        }
      }
    }

    // Print the distance from the start node for each node
    for (const auto &node : distance)
    {
      cout << "Node: " << node.first << " Distance from start: " << node.second << endl;
    }
  }
};

int main()
{
  Graph g(6);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 3);
  g.addEdge(2, 3);
  g.addEdge(3, 4);
  g.addEdge(2, 5);
  g.SPBFS(0);

  return 0;
}