#include<bits/stdc++.h>
using namespace std;

bool bipartitebfs(int src,vector<int>adj[],int color[]){
    queue<int>q;
    q.push(src);
    color[src]=1;
    while(!q.empty()){
         int node=q.front();
         q.pop();
         for(auto i:adj[node]){
            if(color[i]==-1){
                color[i]=1-color[node];
                q.push(i);
            }
            else if(color[i]==color[node]) return false;
         }
    }
    return true;
}
bool checkBipartite(vector<int>adj[],int n){
    //color array
    int color[n];
    memset(color,-1,sizeof color); // it basically copies character from one to another
    for(int i=0;i<n;i++){
        if(color[i]==-1){
            if(!bipartitebfs(i,adj,color)){
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