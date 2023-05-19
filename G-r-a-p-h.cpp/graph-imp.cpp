#include<bits/stdc++.h>
using namespace std;

class Graph{
   int V; // no of vertices
   vector<list<int>>adj;
  public:
  Graph(int V){
    this->V=V;
    adj.resize(V);
  }
   void addEdge(int u,int v);
   void BFS(int x);
};

void Graph::addEdge(int u,int v){
    adj[u].push_back(v);
}

void Graph:: BFS(int x){
   vector<bool>visited;
   visited.resize(V,false); //initialised as false

   
   list<int>queue;
   visited[x]=true;
   queue.push_back(x);

   while(!queue.empty()){
     int y=queue.front();
     cout<<y<<" ";
     queue.pop_front();


     for(auto i:adj[x]){
        if(!visited[i]){
            visited[i]=true;
            queue.push_back(i);
        }
     }
   }

}

int main(){

Graph g(4);
 g.addEdge(0, 1);
 g.addEdge(0, 2);
 g.addEdge(1, 2);
 g.addEdge(2, 0);
 g.addEdge(2, 3);
 g.addEdge(3, 3);
 g.BFS(2);

return 0;
}