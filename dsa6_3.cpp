#include<bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n,char a,char b,char c){
    if(n==1){
        cout<<"Disc shifted from "<<a<<" to "<<c<<"\n";
    }
    else{
        towerOfHanoi(n-1,a,c,b);
        towerOfHanoi(1,a,b,c);
        towerOfHanoi(n-1,b,a,c);
    }
}

int main(){
    int n;
    cout<<"enter no discs: ";
    cin>>n;
    char a='A',b='B',c='C';
    towerOfHanoi(n,a,b,c);
}
