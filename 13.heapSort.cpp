#include<iostream>
#include<vector>
using namespace std;
void heapify(vector<int>& heap){
  int i=heap.size()-1;
  while(i>0&&(heap[(i-1)/2]>heap[i])){
	  swap(heap[(i-1)/2],heap[i]);
	  i=(i-1)/2;
	}
}
int popTop(vector<int>& heap){ //percolating down ( swap with minimum )
   int top=heap.front();
   heap[0]=heap.back();
   heap.pop_back();
   int l=heap.size(),i=0;
   while(i<l){
     if(2*i+2<l){
        if(heap[i]<=heap[2*i+1]&&heap[i]<=heap[2*i+2])break;
        if(heap[2*i+1]<heap[2*i+2]){  swapping with minimum 
          swap(heap[i],heap[2*i+1]);
          i=2*i+1;
           }
        else {
          swap(heap[i],heap[2*i+2]);
          i=2*i+2;
        }
     }
     else if(2*i+1<l){
       if(heap[i]<heap[2*i+1])break;
       swap(heap[i],heap[2*i+1]);
       i=2*i+1;
     }
     else break;
   }
   return top;
}
int main(){
  vector<int>arr={9,8,7,6,5,4,4,3,2,1};
  vector<int>heap;
  int l=arr.size();
  for(int i=0;i<l;i++){
   heap.push_back(arr[i]);
   heapify(heap);
  }
  for(int i=0;i<l;i++){
    arr[i]= popTop(heap);
  }
  for(int i=0;i<l;i++){
    cout<<arr[i]<<" ";
  }
}
