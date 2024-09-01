#include<iostream>
#include<vector>
#include<list>
using std::vector;
using std::list;

void addEdge(vector<list<int>>& adj, int v1, int v2);
void removeEdge(vector<list<int>>& adj, int v1, int v2);
void displayAdjList(vector<list<int>>& adj);

int main() {
  //Order of graph is 4
  int V = 4; //vertices are 0,1,2,3
  
  vector<list<int>> adj(V);
  
  //Add edges one by one
  addEdge(adj, 0, 1);
  addEdge(adj, 0, 2);
  addEdge(adj, 1, 2);
  addEdge(adj, 2, 3);
  
  std::cout << "Adjacency List of Graph is\n";
  displayAdjList(adj);
  
  removeEdge(adj,1,2);
  
  std::cout << "Adjacency List of Graph after removing edge {1,2}\n";
  displayAdjList(adj);
}

void addEdge(vector<list<int>>& adj, int v1, int v2) {
  adj[v1].push_back(v2);
  adj[v2].push_back(v1);  //undirected graph
}

void removeEdge(vector<list<int>>& adj, int v1, int v2) {
  adj[v1].remove(v2);
  adj[v2].remove(v1); //undirected graph
}

void displayAdjList(vector<list<int>>& adj) {
  for(int i=0; i<adj.size(); i++) {
    std::cout << i << ": ";
    for(int j : adj[i]) {
      std::cout << j << " ";
    }
    std::cout << "\n";
  }
} 
