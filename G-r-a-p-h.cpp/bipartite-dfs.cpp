#include<bits/stdc++.h>
using namespace std;

bool bipartitedfs(int node,vector<int>adj[],int color[]){
    if(color[node]==-1) color[node]=1;

    for(auto i:adj[node]){
        if(color[i]==-1){
            color[i]=1-color[node]; //opposite color
            if(!bipartitedfs(i,adj,color)) return false;
        }
        else if(color[i]==color[node]) return false;

    }
    return true;
}

bool checkBipartite(vector<int>adj[],int n){
    //color array
    int color[n];
    memset(color,-1,sizeof color); // it basically copies character from one to another
    for(int i=0;i<n;i++){
        if(color[i]==-1){
            if(!bipartitedfs(i,adj,color)){
                return false;
            }
        }
    }
    return true;

}

int main(){
    int n,m;cin>>n>>m;
    vector<int>adj[n];
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    if(checkBipartite(adj,n)){
        cout<<"yes";
    }
    else cout<<"no";
    return 0;
}