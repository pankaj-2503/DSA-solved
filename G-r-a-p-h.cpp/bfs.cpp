#include<bits/stdc++.h>
using namespace std;

class solution{
/*
 we need vectors bfs,visited vector and queue 
 push the element into the queue and mark as visited and pop and push in vector 

 */
public:
  
vector<int>bfsofGraph(int V,vector<int>adj[]){
  vector<int>bfs;
  vector<int>vis(V+1,0);

  for(int i=0;i<V;i++){
    if(!vis[i]){
      queue<int>q;
      q.push(i);
      vis[i]=1;
      while(!q.empty()){
        int node=q.front();
        q.pop();
        bfs.push_back(node);

        for(auto j:adj[node]){
           if(!vis[j]){
             q.push(j);
             vis[j]=1;
           }
        }
      }
    }
  }
  return bfs;
}
  
};