#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,nodes=0,startNode,weight,a,b;
  cout<<"Enter the number of edges :";
  cin>>n;
  vector<vector<int>> edges(n);
  for(auto &edge:edges){
    cout<<"Enter weight of the edge: ";
    cin>>weight;
    cout<<"Enter the nodes that connect edge: ";
    cin>>a>>b;    
    edge.push_back(weight);
    edge.push_back(a);
    edge.push_back(b);
    nodes=max({nodes,edge[1],edge[2]});
  }
  nodes++;
  long mat[nodes][nodes];
  for(int i=0;i<nodes;i++){
    for(int j=0;j<nodes;j++){
      mat[i][j]=INT_MAX;
    }
  }
  for(auto &edge:edges){
   mat[edge[1]][edge[2]]=edge[0];
   mat[edge[2]][edge[1]]=edge[0];
   mat[edge[1]][edge[1]]=0;
   mat[edge[2]][edge[2]]=0;
  }
  for(int k=0;k<nodes;k++){
    for(int i=0;i<nodes;i++){
      for(int j=0;j<nodes;j++){
         if(mat[i][k]+mat[k][j]<mat[i][j])
            mat[i][j]=mat[i][k]+mat[k][j];
      }
    }
  }
  for(int i=0;i<nodes;i++){
   for(int j=i;j<nodes;j++){
     if(mat[i][j]!=INT_MAX){
       printf("\nShortest distance from node %d to %d is : %ld",i,j,mat[i][j]);
     }
   }
  }
  return 0;
}
