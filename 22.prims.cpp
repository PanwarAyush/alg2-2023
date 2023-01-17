
#include<bits/stdc++.h>
#include<exception>
using namespace std;

class Solution
{
    public:
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int sum=0,node,weight;
        pq.push({0,0});
        vector<bool>vis(V,false);
        while(!pq.empty()){
            weight=pq.top().first;
            node=pq.top().second;
            pq.pop();
            if(vis[node])
              continue;
              vis[node]=true;
              sum+=weight;
              cout<<weight;
            for(auto &i:adj[node]){
               if(!vis[i[0]]){
                     pq.push({i[1],i[0]});
                 }
            }
        }
        return sum;
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

