#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
vector<string>ans;
void solve(int n,int s,int a,int d) {
    if(n==1)
	{
		ans.push_back(string(1,s+'0')+" "+string(1,d+'0'));
		return;
	}
	solve(n-1,s,d,a);
	ans.push_back(string(1,s+'0')+" "+string(1,d+'0'));
	solve(n-1,a,s,d);
}
int main(){
        cout<<"Enter the number of Disks: ";
	int n;
	cin>>n;
	solve(n,1,2,3);
	cout<<"It will take "<<ans.size()<<" steps to move disk from left to right"<<endl;
	for(string i:ans)cout<<i<<endl;
	return 0;
}
