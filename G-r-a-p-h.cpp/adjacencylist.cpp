#include<bits/stdc++.h>
using namespace std;
template <typename T>
class graph{
    public:
      unordered_map<T,list<T>>adj;

      void addEdge(T u,T v,bool direction){
        adj[u].push_back(v);
        if(direction==0){//here 0->means undirected ,1->means directed
            adj[v].push_back(u);
        }
      }

      void print(){
        for(auto i:adj){
            cout<<i.first<<"->";//first of adj
            for(auto j:i.second){ //for printing list element in adj list using i.second
                cout<<j<<",";
            }
            cout<<endl;
        }
      }
      
};

//or we can also do this 
 vector<vector<int>> printGraph(int V, vector<int> adj[]) {
        // Code here
        vector<vector<int>>v;
        for(int i=0;i<V;i++){
            vector<int>temp;
            temp.push_back(i);
            for(auto j:adj[i]){
                temp.push_back(j);
            }
            v.push_back(temp);
        }
        return v;
    }



int main(){
int n;
cout<<"Enter the number of nodes:"<<endl;
cin>>n;
int m;
cout<<"Enter the number of edges:"<<endl;
cin>>m;

graph<int>g;
// taking input the node that is connected to it's neighbour node
for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    g.addEdge(u,v,0);
}

g.print();

return 0;
}