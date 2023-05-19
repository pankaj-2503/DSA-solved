#include<bits/stdc++.h>
using namespace std;

class solution{
    //basically we do bfs with parent node of current node check if found return true else return false

  bool checkCycle(int s,int V,vector<int>adj[],vector<int>&vis){
     vector<int>parent(V,-1);
     queue<pair<int,int>>q;
     vis[s]=true;
     q.push({s,-1});

     while(!q.empty()){
        int node=q.front().first;
        int par=q.front().second;
        q.pop();

        for(auto i:adj[node]){
            if(!vis[i]){
                q.push({i,node});
                vis[i]=true;
            }
            else if(par!=i) return true;
        }
     }
     return false;
  }


 public:
   
   bool isCycle(int V,vector<int>adj[]){
     vector<int>vis(V+1,0);
     for(int i=1;i<=V;i++){
       if(!vis[i]){
          if(checkCycle(i,V,adj,vis)) return true;
       }
     }

     return false;
   }
   
};