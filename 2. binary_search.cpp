#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool binary_search(vector<int> &nums,int key){
int n=nums.size();
int l=0,r=n-1,mid;
while(l<=r){
  mid=(l+r)/2;
  if(nums[mid]==key){
    return true;
  }else if(nums[mid]>key){
    r=mid-1;  
  }else
    l=mid+1;
}
    return false;
}
int main(){
    int n,key;
    cout<<"Enter the number of input elements: ";
    cin>>n;
    cout<<"Enter elements of the array: ";
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end());
    cout<<"Input the key to be found: ";
    cin>>key;
    bool k=binary_search(nums,key);
    if(k==false){
        cout<<"Key not found ";
    }
    else{
        cout<<"key found !";
    }
    return 0;
}
