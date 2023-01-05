#include<iostream>
#include<vector>
using namespace std;
void display(vector<int> &nums){
for(auto &i:nums)
  cout<<i<<" ";
cout<<endl;
}
void insertionSort(vector<int> &nums){
    int n=nums.size(),num,i,j;
    for(i=1;i<n;i++){
        j=i-1;
        num=nums[i];
        while(j>=0&&num<nums[j]){
         nums[j+1]=nums[j];
         j--;
        }
        nums[j+1]=num;
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
    display(nums);
    insertionSort(nums);
     cout<<"\nAfter insertion sort array elements are :";
     display(nums);
    return 1;
}
