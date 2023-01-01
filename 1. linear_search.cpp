#include<iostream>
#include<vector>
using namespace std;
int linear_search(vector<int> &nums,int key){
int n=nums.size();
    for(int i=0;i<n;i++){
        if(key==nums[i]){
            return i+1;
        }
    }
    return -1;
}
int main(){
    int n,key;
    cout<<"Enter the number of input elments: ";
    cin>>n;
    cout<<"Enter elements of the array: ";
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<"Input the key to be found: ";
    cin>>key;
    int k=linear_search(nums,key);
    if(k==-1){
        cout<<"Key not found ";
    }
    else{
        cout<<"key found at index "<<k;
    }
    return 0;
}
