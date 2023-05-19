#include<bits/stdc++.h>
using namespace std;

int parent[100000];
int rank[1000000];

void makeSet(){
    for(int i=1;i<=100000;i++){
        parent[i]=i;
        rank[i]=0;
    }
}

int findPar(int node)
{  // time commplexity -O(4*alpha)
    if(node==parent[node]){
        return node;
    }
    //path compression
    return parent[node]=findPar(parent[node]);
}

void union(int u,int v){
     u=findPar(u);
     v=findPar(v);
    if(rank[u]<rank[v]){
       parent[u]=v;
    }
    else if(rank[v]<rank[u]){
       parent[v]=u;
    }
    else{
        parent[v]=u;
        rank[u]++;
    }

}
void main(){
    makeSet();
    int m;cin>>m;
    while(m--){
        int u,v;
        union(u,v);
    }
    //if 2 or 3 belong to same component or not
    if(findPar(2)!=findPar(3)) cout<<"Different component"<<endl;
    else cout<<"Same component"<<endl;
}