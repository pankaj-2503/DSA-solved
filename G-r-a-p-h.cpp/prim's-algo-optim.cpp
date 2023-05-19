#include <bits/stdc++.h>
using namespace std;
// brute force prim's implementation
//time complexity-O(n+e)+O(nlogn)
int main()
{

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];

    // adj list
    int a, b, wt;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> wt;
        adj[a].push_back(make_pair(b, wt));
        adj[b].push_back(make_pair(a, wt));
    }

    // we need 3 arrays
    int key[n];
    bool mstSet[n];
    int parent[n];

    // initialise them
    for (int i = 0; i < n; i++)
    {
        key[i] = INT16_MAX;
        mstSet[i] = false;
        parent[i] = -1;
    }
    
    //min-heap
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    key[0] = 0;
    parent[0] = -1;
    pq.push({0,0});

    // as we would traverse till n-1 edges
    for (int count = 0; count = n - 1; count++)
    {
        // Step-1
        // iterate in key array
        int u=pq.top().second;
        pq.pop();

        // STep-2
        mstSet[u] = true;

        // Step-3 find min in adjlist
        for (auto j : adj[u])
        {  //updating key and parent
            int v = j.first;
            int weight = j.second;
            if (mstSet[v] == false && weight < key[u])
            {
                parent[v] = u;
                pq.push({key[v],v});
                key[v] = weight;
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<i<<"parent is"<<parent[i]<<endl;
    }

    return 0;
}