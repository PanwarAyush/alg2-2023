#include<iostream>
#include<vector>
using namespace std;
void bubbleSort(vector<int> &nums){
    int n=nums.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
          if(nums[j]>nums[j+1]){
            swap(nums[j],nums[j+1]);
          }
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
    bubbleSort(nums);
     cout<<"\nAfter bubble sort array elements are :";
    for(int i=0;i<n;i++)
        cout<<nums[i]<<" ";
    return 1;
}
