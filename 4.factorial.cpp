#include<iostream>
using namespace std;
int main(){
 long long fact=1;
 cout<<"n=";
 int n;
 cin>>n;
 for(int i=1;i<=n;i++){
  fact*=i;
 }
 cout<<n<<"!= "<<fact<<endl;
}
