#include<bits/stdc++.h>
using namespace std;
struct compare{
    boolean operator(node *a,node *b){
      return a->freq> b->freq;
    }
}
struct node{
   char data;
   int freq;
   node *left,*right;
   node(char *,int y):data(x),freq(y),left(nullptr),right(nullptr){}     
}
void display(node *pq,string str){
    if(!pq)
        return;
    if(pq->data!='@'){
        cout<<pq->data<<": "<<str<<endl;
    }
    display(top->left,str+'0');
    display(top->right,str+'1');
}
void solve(){
    int n,a,b;
    cin>>n;
    node * left,*right;
    priority_queue<node *,vector<node*>,compare> pq;
    vector<char>data(n);
    vector<int>freq(n);
    for(int i=0;i<n;i++){
        cin>>data[i];
    }
    for(int i=0;i<n;i++){
        cin>>freq[i]
    }
    for(int i=0;i<n;i++){
        pq.push(new node(data[i],freq[i]));
    }
    while(pq.size()!=1){
    left=pq.top();
    pq.pop();
    right=pq.top();
    pq.pop();
    node * t=new node('@',left->freq+right->freq);
    t->left=left;
    t->right=right;
   }
   display(pq.top(),"");
}
int main(){
    solve();
    return 0;
}
