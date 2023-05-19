#include<bits/stdc++.h>
using namespace std;
#define if INT_MAX
//for shortest path for undirected wieghted graph
int main(){

    int n,m,source;cin>>n>>m;
    vector<pair<int,int>>g[n+1];

    int a,b,wt;
    for(int i=0;i<m;i++){
        cin>>a>>b>>wt;
        g[a].push_back(make_pair(b,wt));
        g[b].push_back(make_pair(a,wt));
    }
    cin>>source;
    //Dikstra's algo begin here
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>distoSrc(n+1,if);

    distoSrc[source]=0;
    pq.push(make_pair(0,source));

    while(!pq.empty()){
       int dis=pq.top().first;
       int prev=pq.top().second;
       pq.pop();

       vector<pair<int,int>>::iterator it;
       for(auto it:g[prev]){
         int next=it.first;
         int nextdist=it.second;
         if(distoSrc[next]>dis+nextdist){
            distoSrc[next]=distoSrc[prev]+nextdist;
            pq.push(make_pair(distoSrc[next],next));
         }
       }

    }
    cout<<"distance from source "<<source<<",are:"<<endl;
    for(int i=0;i<=n;i++){
        cout<<distoSrc[i]<<" ";
    }
    cout<<endl;



    return 0;
}