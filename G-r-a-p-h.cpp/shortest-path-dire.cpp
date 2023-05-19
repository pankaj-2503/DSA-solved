#include<bits/stdc++.h>
#define INF  INT_MAX
using namespace std;

void findtopoSort(int node,int vis[],stack<int>&st,vector<pair<int,int>>adj[]){
    vis[node]=1;
    for(auto i:adj[node]){
        if(!vis[i.first]){
            findtopoSort(it.first,vis,st,adj);
        }
    }
    st.push(node);
}

void shortestPath(int src,int N,vector<pair<int,int>>adj[]){
    int vis[N]={0};
    stack<int>st;
    for(int i=0;i<N;i++){
        if(!vis[i]){
            findtopoSort(i,vis,st,adj);
        }
    }
    int dist[N];
    for(int i=0;i<N;i++) dist[i]=1e9;
     
    dist[src]=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(dist[node]!=INF){
            for(auto i:adj[node]){
               if(dist[node]+i.second<dist[i.first]){
                dist[i.first]=dist[node]+i.second;
               }
            }
        }
    }
    for(int i=0;i<N;i++){
        if(dist[i]==1e9) cout<<INF<<' ';
        else cout<<dist[i]<<' ';
    }
}
int main(){
 int n,m;
 cin>>n>>m;
 vector<pair<int,int>>adj[n];
 for(int i=0;i<m;i++){
    int u,v,wt;
    cin>>u>>v>>wt;
    adj[u].push_back({v,wt});
 }
 shortestPath(0,n,adj);


return 0;
}