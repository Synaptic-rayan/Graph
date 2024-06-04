#include <iostream>
#include <list>
#include <cstring>
#include <unordered_map>
using namespace std;

class Graph
{
  unordered_map<string, list<pair<string, int>>> l;

public:
  void addEdge(string x, string y, int wt, bool bidir)
  {
    l[x].push_back(make_pair(y, wt));
    if (bidir)
    {
      l[y].push_back(make_pair(x, wt));
    }
  }

  void printAdjList()
  {
    for (auto p : l)
    {
      string city = p.first;
      list<pair<string, int>> nbrs = p.second;
      cout << city << "->";
      for (auto nbr : nbrs)
      {
        string dest = nbr.first;
        int dis = nbr.second;
        cout << dest << " " << dis << ","; 
      }
      cout << endl;
    }
  }
};

int main()
{
  Graph g;
  g.addEdge("A", "B", 20, true); 
  g.addEdge("B", "D", 40, true);
  g.addEdge("A", "C", 10, true);
  g.addEdge("C", "D", 40, true);
  g.addEdge("A", "D", 50, false);
  g.printAdjList();
  return 0;
}
