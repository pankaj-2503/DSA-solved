#include<bits/stdc++.h>
using namespace std;
// for all pair shortest path 
const int N=500;
const int INF=1e9+10;

int dist[N][N]; // distance array

int main(){
    //set distance initially infinity except for same node(make it 0)
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j) dist[i][j]=0;
            else dist[i][j]=INF;
        }
    }
    int n,m;cin>>n>>m; // no. of nodes and edges
    for(int i=0;i<m;i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        dist[x][y]=wt;
    }
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                dist[i][j]=min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }

     for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
               if(dist[i][j]==INF){
                cout<<"I"<<endl;
               }
               else cout<<dist[i][j]<<" ";
            }
            cout<<endl;
        }
    return 0;
}