#include<iostream>
#include<vector>
using namespace std;
int aux[50];
void display(vector<int> &nums){
for(auto &i:nums)
  cout<<i<<" ";
cout<<endl;
}
void merge(vector<int> &nums,int l,int r){
   int i=(l+r)>>1,a=l;
   int j=i+1,k=0;
   while(l<=i&&j<=r)
    aux[k++]=nums[l]<nums[j]?nums[l++]:nums[j++];
   while(l<=i)
    aux[k++]=nums[l++];
   while(j<=r)
    aux[k++]=nums[j++];
  for(int i=0;i<k;i++)
    nums[a+i]=aux[i];
}
void mergeSort(vector<int> &nums,int l,int r){ 
  if(l>=r)
    return;
  mergeSort(nums,l,(l+r)>>1);
  mergeSort(nums,((l+r)>>1)+1,r);
  merge(nums,l,r);  
}
int main(){
    int n;
    cout<<"Number of elements of the array: ";
    cin>>n;
    cout<<"Input the elements of the array: ";
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<"Before sorting array is :";
    display(nums);
    mergeSort(nums,0,n-1);
     cout<<"\nAfter merge sort array elements are :";
     display(nums);
    return 1;
}
