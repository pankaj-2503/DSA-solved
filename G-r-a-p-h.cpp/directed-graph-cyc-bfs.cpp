#include<bits/stdc++.h>
using namespace std;

class solution{
public:
 bool isCyclic(int N,vector<int>adj[]){
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
    int cnt=0;
    
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cnt++;
        for(auto i:adj[node]){
            indegree[i]--;
            if(indegree[i]==0) q.push(i);
        }
    }
    //if generated topological sort then it doesn't have cycle i.e cnt==N return false
    if(cnt==N)  return false;
    else return true;
 }
  
};
