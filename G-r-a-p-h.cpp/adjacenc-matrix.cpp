#include<bits/stdc++.h>
using namespace std;
//for undirected graphs

int adjMatrix[30][30];
void addEdge(int u,int v){
    adjMatrix[u][v]=1;
    adjMatrix[v][u]=1;
}

void printGraph(int v){
   for(int i=0;i<v;i++){
    for(int j=0;j<v;j++){
        cout<<adjMatrix[i][j]<<" ";
    }
    cout<<endl;
   }
}
int main(){
    int v=6;
    addEdge(0,4);
    addEdge(0,3);
    addEdge(1,2);
    addEdge(1,4);
    addEdge(2,3);
    addEdge(2,5);
    printGraph(v);


    return 0;
}