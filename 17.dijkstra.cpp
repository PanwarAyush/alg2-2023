//Dijkstra algorithm can be applied to both directed as well as undirected graph
//Dijkstra algorithm is used to find shortest path from a node to all other nodes.
//It is applied on weighted graph
//starting node is initialized with 0 and all other nodes with infinite distance
//Compute Distance for each relative node if d[ui]+di<d[vi] then d[vi]=d[ui]+di and move to shortest distant node. 
//no negative weight cycle
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

using pii= pair<int,int>;
void solve(){
    ll n,m,source,end,weight,s,e;
    cin>>n>>m;
    vector<pair<ll,ll>>graph[n+1];
    ll rem[n+1];
    for(ll i=1;i<=m;i++){
        cin>>source>>end>>weight;
        graph[source].push_back({weight,end});
        graph[end].push_back({weight,source});
    }
    cin>>s>>e;
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    pq.push({0,s});
    vector<ll> dis(n+1,1e18);
    pii u;
    ll node;
    while(!pq.empty()){
        u=pq.top();
        pq.pop();
        weight=u.first;
        node=u.second;
      for(auto it:graph[node]){
         if(it.first+weight<dis[it.second]){
            rem[it.second]=node;
            dis[it.second]=it.first+weight;
            pq.push({dis[it.second],it.second});
         }
      }
    }
    if(dis[n]==1e18){
        cout<<-1<<endl;
        return;
    }
    m=1;
    n=e;
    dis[0]=n;
    while(rem[n]!=1){
        dis[m++]=rem[n];
        n=rem[n];
    }
    dis[m]=1;
    for(int i=m;i>=0;i--){
        cout<<dis[i]<<" ";
    }
    cout<<endl;
}
int main(){
  solve();
  return 0;
}
