//bellmanford helps to detect negative weight cycle in a graph
//it works on directed graph
//if you are given a undirected graph just change it to a directed graph, two side edge having same weight
//O(V*E) time complexity
#include<bits/stdc++.h>
using namespace std;
 vector<int> bellmanFord(int V, vector<vector<int>>& edges, int S) {
       vector<int> dis(V,1e8);
       dis[S]=0;
       for(int i=1;i<V;i++){
           for(auto &edge:edges){
               if(dis[edge[0]]+edge[2]<dis[edge[1]])
                   dis[edge[1]]=dis[edge[0]]+edge[2];               
           }
       }
         for(auto &edge:edges){
               if(dis[edge[0]]+edge[2]<dis[edge[1]])
                   return {-1};
           }
           return dis;
  }
int  main(){
  int n,nodes=0,startNode,weight,a,b;
  cout<<"Enter the number of edges :";
  cin>>n;
  vector<vector<int>> edges(n);
  for(auto &edge:edges){
    cout<<"Enter weight of the edge: ";
    cin>>weight;
    cout<<"Enter the nodes that connect edge: ";
    cin>>a>>b;    
    edge.push_back(a);
    edge.push_back(b);
    edge.push_back(weight);
    nodes=max({nodes,edge[0],edge[1]});
  }
  nodes++;
  cout<<"To Find the shortest distance of all the vertex's from the source vertex S enter its value: ";
  cin>>startNode; 
  vector<int> dis=bellmanFord(nodes,edges,startNode);
  if(dis[0]==-1){
   cout<<"GRAPH contains negative cycle";
  }else{
   for(int i=0;i<nodes;i++){
     if(i==startNode)continue;
     printf("Shortest Distance from node %d to node %d =%d\n",startNode,i,dis[i]); 
   }
  }
  return 0;
  }
