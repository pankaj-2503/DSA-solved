#include<bits/stdc++.h>
using namespace std;


// this algorithm works for negative weight whereas dijkstra does not without negative cycle.
// i.e shortest path from source node to every other node

int bellmanford(int n,int m,int src,int desti,vector<vector<int>>&edges){
    vector<int>dist(n+1,1e9); //distance array to store distances intially infinity
    dist[src]=0;  //make source node dist 0

    //n-1 times 
    for(int i=1;i<=n;i++){
        //traverse on edges and applying formula
        for(int j=0;j<m;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int wt=edges[j][2];

            if(dist[u]!=1e9 && (dist[u] +wt )<dist[v]){ //checking if shortest distance present then updating it
                dist[u]=dist[v] +wt;
            }
        }
    }
    //check for negative cycle
    bool flag=0;
     for(int j=0;j<m;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int wt=edges[j][2];

            if(dist[u]!=1e9 && (dist[u] +wt )<dist[v]){ //checking if shortest distance present then updating it
                flag=1;
            }
        }
    if(flag==0) return dist[desti]; // shortest path present
    else return -1; // negative cycles present

}

int main(){
    return 0;
}