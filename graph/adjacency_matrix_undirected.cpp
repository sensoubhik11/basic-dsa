#include<iostream>
#include<vector>
using std::vector;

void addEdge(vector<vector<int>>& mat, int v1, int v2);
void removeEdge(vector<vector<int>>& mat, int v1, int v2);
void displayMatrix(vector<vector<int>>& mat);

int main() {
  //Order of graph is 4
  int V = 4; //vertices are 0,1,2,3
  
  //create adjacency matrix of a null graph with 4 vertices
  vector<vector<int>> mat(V, vector<int>(V,0));
  
  //Add edges one by one
  addEdge(mat, 0, 1);
  addEdge(mat, 0, 2);
  addEdge(mat, 1, 2);
  addEdge(mat, 2, 3);
  
  std::cout << "Adjacency Matrix of Graph is\n";
  displayMatrix(mat);
  
  removeEdge(mat, 1, 0);
  
  std::cout << "Adjacency Matrix of Graph after removing edge {1,0}\n";
  displayMatrix(mat);  
}
//Tc = O(1)
void addEdge(vector<vector<int>>& mat, int v1, int v2) {
  mat[v1][v2] = 1;
  mat[v2][v1] = 1;  //undirected graph
}
//TC = O(1)
void removeEdge(vector<vector<int>>& mat, int v1, int v2) {
  mat[v1][v2] = mat[v2][v1] = 0;
}

void displayMatrix(vector<vector<int>>& mat) {
  for(int i=0; i<mat.size(); i++) {
    for(int j=0; j<mat[i].size(); j++) {
      std::cout << mat[i][j] << " ";
    }
    std::cout << "\n";
  }
} 
