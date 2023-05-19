#include<bits/stdc++.h>
using namespace std;

class solution{
public:
 vector<int>topoSort(int N,vector<int>adj[]){
    queue<int>q;
    vector<int>indegree(N,0);
    for(int i=0;i<N;i++){
        // finding the indegree
        for(auto j:adj[i]){
            indegree[j]++;
        }
    }
    //if indegree is 0 push it into queue
    for(int i=0;i<N;i++){
        if(indegree[i]==0) q.push(i);
    }
    //take out front push it into vector and pop it and its all adjacent node ,indegree subtract by 1 and if indegree becomes 0 push it into queue repeat this process
    
    vector<int>topo;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto i:adj[node]){
            indegree[i]--;
            if(indegree[i]==0) q.push(i);
        }
    }
    return topo;
 }
  
};
