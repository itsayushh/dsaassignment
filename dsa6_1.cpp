#include<bits/stdc++.h>
using namespace std;
//fibbonaci series
int fib(int n){
    if(n<=1) return n;
    else return fib(n-1)+fib(n-2);
}

int main(){
    int x;
    cout<<"enter the position of fibonacci number ";
    cin>>x;
    cout<<x<<"th fibonacci number is "<<fib(x);
}