#include<iostream>
#include<vector>
using namespace std;
void bubbleSort(vector<vector<int>> &nums){
    int n=nums.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
          if(nums[j][0]>nums[j+1][0]){
            swap(nums[j],nums[j+1]);
          }
        }
    }
}
void display(vector<vector<int>> &nums,bool b){
   for(int i=0,n=nums.size();i<n;i++)
   cout<<nums[i][b]<<" "; 
   cout<<endl;
}
int main(){
    int n;
    cout<<"Number of elements of the array: ";
    cin>>n;
    cout<<"Input the elements of the array: ";
    vector<vector<int>>nums(n,vector<int>(2,0));
    for(int i=0;i<n;i++){
        cin>>nums[i][0];
        nums[i][1]=i+1;
    }
    cout<<"Before sorting array is (first row is index and second row has array elements) :\n";
    display(nums,1);
    display(nums,0);
    bubbleSort(nums);
     cout<<"After bubble sort array elements are (first row is index and second row has array elements) :\n";
    display(nums,1);
    display(nums,0); 
     return 1;
}
