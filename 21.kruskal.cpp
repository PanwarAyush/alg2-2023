#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class DSU{
private:
  vector<int>weigh,parent;
public:
  DSU(int n){ //O(N) time & space complextiy for initialization of size and nodes.
    weigh.resize(n,1);
    parent.resize(n);
    for(int i=0;i<n;i++)
      parent[i]=i;
  } 
  inline int find(int x){
     if(parent[x]==x)
        return x;
      return parent[x]=find(parent[x]);
  }
inline bool Union(int a,int b){   //O(k) time complexity, here k<4 
     a=find(a);
     b=find(b);
     if(a==b) 
       return false;
     if(weigh[a]>weigh[b])
      swap(a,b);
     parent[a]=b;
     weigh[b]+=weigh[a];
     return true;
  }
};
int kruskal(vector<vector<int>>&edges,int n){
 sort(edges.begin(),edges.end());
 DSU d(n);
 int minCost=0;
 for(auto &edge:edges){
   if(d.Union(edge[1],edge[2])){
     minCost+=edge[0];
   }
 }
 return minCost;
}
int main(){
 int n,edgeWeight,a,b,nodes;
 cout<<"Enter the number of edges :";
 cin>>n;
 vector<vector<int>>edges(n);
 for(int i=0;i<n;i++){
  cout<<"Enter the weight/distance of the edge: ";
  cin>>edgeWeight;
  cout<<"Enter 2 endpoints of edge: ";
  cin>>a>>b;
  edges[i].push_back(edgeWeight);
  edges[i].push_back(a);
  edges[i].push_back(b);
 }
 cout<<"Enter the number of nodes: ";
 cin>>nodes;
 int minCost=kruskal(edges,nodes);
 cout<<"Minimum Cost to connect all nodes is :"<<minCost;
 return 0;
}
