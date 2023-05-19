#include<bits/stdc++.h>
using namespace std;
class solution{
/*
for this we need vector to store dfs and visited vector, call the dfs function recursively and push into the vector and marked 
visited as 1 and put all adj node of current node

*/
void dfs(int node,vector<int>&vis,vector<int>adj[],vector<int>&dfs_store){
  dfs_store.push_back(node);
  vis[node]=1;
  for(auto i:adj[node]){
     if(!vis[i]){
      dfs(i,vis,adj,dfs_store);
     }
  }
}
 public:
vector<int>dfsofGraph(int V,vector<int>adj[]){
  vector<int>dfs_store;
  vector<int>vis(V+1,0);
  for(int i=0;i<V;i++){
    if(!vis[i]) dfs(i,vis,adj,dfs_store);
  }
  return dfs_store;
}

};