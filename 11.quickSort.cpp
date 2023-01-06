#include<iostream>
#include<vector>
using namespace std;
void display(vector<int> &nums){
for(auto &i:nums)
  cout<<i<<" ";
cout<<endl;
}
int seperate(vector<int>&arr,int l,int r){
    int pivot=arr[r],j=l;
    for(int i=l;i<r;i++){
        if(arr[i]<pivot)
        swap(arr[j++],arr[i]);
    }
    swap(arr[j],arr[r]);
    return j;
}
void quickSort(vector<int> &nums,int l,int r){ 
  if(l>=r)
    return;
  int x=seperate(nums,l,r);
  quickSort(nums,l,x-1);
  quickSort(nums,x+1,r);
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
    quickSort(nums,0,n-1);
    cout<<"\nAfter quick sort array elements are :";
    display(nums);
    return 1;
}
