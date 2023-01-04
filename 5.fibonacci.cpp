#include<iostream>
using namespace std;
long long recursiveFibonacci(long long n){ 
 if(n<=1) 
  return 0;
else if(n==2)
 return 1;
  return recursiveFibonacci(n-1)+recursiveFibonacci(n-2);
}
long long  iterativeFibonacci(long long n){
    if(n<1)return 0;
    else if(n<3)return n-1;
    long long a=0,b=1,c;
    while(n>2){
     c=a+b;
     a=b;
     b=c;
     n--;
    }
    return c;
}
int main(){
   int n;
   cout<<"n=";
   cin>>n;
   long long a=recursiveFibonacci(n);
   long long b=iterativeFibonacci(n);
   cout<<"Fibonacci computed recursively="<<a<<endl<<"Fibonacci computed iteratively="<<b<<endl;
}
