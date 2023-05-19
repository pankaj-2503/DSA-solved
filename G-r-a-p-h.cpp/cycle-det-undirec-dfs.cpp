#include<bits/stdc++.h>
using namespace std;

class solution{

    bool checkCycle(int node,int parent,vector<int>&vis,vector<int>adj[]){
        vis[node]=1;
        for(auto i:adj[node]){
          if(!vis[i]){
            if(checkCycle(i,node,vis,adj)) return true;
          }
          else if(i!=parent) return true;
        }
        return false;
    }
    public:
  
  bool isCycle(int V,vector<int>adj[]){
     vector<int>vis(V+1,0);
     for(int i=0;i<V;i++){
        if(!vis[i]){
            if(checkCycle(i,-1,vis,adj)) return true; 
        }
     }
     return false;
  }
};