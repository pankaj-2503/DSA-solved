#include<bits/stdc++.h>
using namespace std;

class solution{
 public:
 void BFS(vector<int>adj[],int N,int src){
    int dist[N];
    for(int i=0;i<N;i++) dist[i]=INT_MAX;

    queue<int>q;
    dist[src]=0;
    q.push(src);

    while(!q.empty()){
        int node=q.front();
        q.pop();

        for(auto i:adj[node]){
            if(dist[node]+1<dist[i]){
                dist[i]=dist[node]+1;
                q.push(i);
            }
        }
    }
    for(int i=0;i<N;i++) cout<<dist[i]<<" ";

 }
};