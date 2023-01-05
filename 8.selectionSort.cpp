#include<iostream>
#include<vector>
using namespace std;
void selectionSort(vector<int> &nums){
    int n=nums.size(),index;
    for(int i=0;i<n-1;i++){
        index=i;
        for(int j=i+1;j<n;j++){
          if(nums[j]<nums[index]){
            index=j;
          }
        }
        if(i!=index){
            swap(nums[i],nums[index]);
        }
    }
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
    for(int i=0;i<n;i++)
        cout<<nums[i]<<" ";
    selectionSort(nums);
     cout<<"\nAfter Selection sort array elements are :";
    for(int i=0;i<n;i++)
        cout<<nums[i]<<" ";
    return 1;
}
