#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define MAX 100000
void countingSort(vector<int> &nums){
  int n=nums.size();
  int cnt[MAX];
  memset(cnt,0,sizeof cnt);
  for(auto &i:nums)
    cnt[i]++;
  for(int i=0,j=0;i<MAX;i++){
    while(cnt[i]--)
     nums[j++]=i;
  }    
}
int main(){
 cout<<"Enter the number of terms: ";
 int n;
 cin>>n;
 vector<int> nums(n);
 cout<<"Enter the array elements: ";
 for(int i=0;i<n;i++){
  cin>>nums[i];
 }
 countingSort(nums);
 for(int i=0;i<n;i++)
   cout<<nums[i]<<" ";
 return 0;
}
