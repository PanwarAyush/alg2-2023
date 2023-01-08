#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

void depthFirstSearch(vector<int> *graph,vector<bool> &vis,int u){
   if(vis[u])
     return;
   cout<<u<<" ";
   vis[u]=true;
   for(auto v:graph[u]){
     depthFirstSearch(graph,vis,v);
   }
   vis[u]=false;
}
int main(){
  int n,nodes=0,startNode;
  cout<<"Enter the number of edges :";
  cin>>n;
  vector<pair<int,int>> edges(n);
  for(auto &edge:edges){
    cout<<"Enter value of nodes that connect edge : ";
    cin>>edge.first;
    cin>>edge.second;
    nodes=max({nodes,edge.first,edge.second});
  }
  vector<int> graph[nodes+1];
  for(auto edge:edges){
    graph[edge.first].push_back(edge.second);
    graph[edge.second].push_back(edge.first);        
  }
  vector<bool> vis(nodes+1,0);
  cout<<"Enter the starting point/node from where depth First Search is to be done: ";
  cin>>startNode; 
  depthFirstSearch(graph,vis,startNode);
  cout<<endl;
  return 0;
}
