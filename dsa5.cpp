// implementation of stack using array
#include<bits/stdc++.h>
using namespace std;

int top=-1;
void push(int n,int stack[]){
    int val;
    cout<<"enter the data: ";
    cin>>val;
    if(top==n-1) cout<<"Memory exceed"<<"\n";
    else{
        top++;
        stack[top]=val;
    }
}
void pop(int stack[]){
    int item;
    if(top==-1) cout<<"underflow";
    else{
        item=stack[top];
        top--;
        cout<<item<<"is removed from stack"<<"\n";
    }
}
void peek(int stack[]){
    if(top==-1) cout<<"underflow";
    else {
        cout<<stack[top]<<"\n";
    }
}
void display(int stack[]){
    for (int i = top; i >= 0; i--)
    {
        cout<<stack[i]<<" ";
    }
}

int main(){
    int n;
    cout<<"enter size of stack: ";
    cin>>n;
    int stack[n];
    for (int i = 0; i < n; i++)
    {
        push(n,stack);
    }
    peek(stack);
    display(stack);


}