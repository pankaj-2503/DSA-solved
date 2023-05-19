#include<bits/stdc++.h>
using namespace std;

class solution{

    void findtopoSort(int node,vector<int>&vis,stack<int>&st,vector<int>adj[]){
        //mark visited 
        vis[node]=1;
        //traversing all its adjacent nodes
        for(auto i:adj[node]){
            if(!vis[i]){
                findtopoSort(i,vis,st,adj); // dfs call 
            }
        }
        //if over then push it into stack
        st.push(node);

    }

 public:
  vector<int>topoSort(int N,vector<int>adj[]){
     vector<int>vis(N,0);
     stack<int>st;
     for(int i=0;i<N;i++){
        if(!vis[i]){
            findtopoSort(i,vis,st,adj);
        }
     }
     vector<int>topo;
     // pop out one by one and push into vector
     while(!st.empty()){
       topo.push_back(st.top());
       st.pop();
     }
     return topo;


  }
};