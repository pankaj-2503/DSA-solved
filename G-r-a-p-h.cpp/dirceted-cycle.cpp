#include<bits/stdc++.h>
using namespace std;

class solution{

 bool checkCycle(int node,vector<int>adj[],int vis[],int dfsvis[]){
     vis[node]=1;
     dfsvis[node]=1;
     for(auto i:adj[node]){
        if(!vis[i]){
            if(checkCycle(i,adj,vis,dfsvis))  return true;
        }
        else if(dfsvis[i])  return true;
     }
     dfsvis[node]=0;
     return false;
 }

 public:
 bool isCyclic(int N,vector<int>adj[]){
    int vis[N],dfsvis[N];
    memset(vis,0,sizeof vis);
    memset(dfsvis,0,sizeof dfsvis);
    
    for(int i=0;i<N;i++){
        if(!vis[i]){
            if(checkCycle(i,adj,vis,dfsvis)){
                return true;
            }
        }
    }
    return false;
 }
  
};