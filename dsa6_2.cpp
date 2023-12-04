#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    if(n<=1) return 1;
    return n*fact(n-1);
}

int main(){
    long long n=5;
    cout<<"the factorial of number "<<n<<" is "<<fact(n);
}