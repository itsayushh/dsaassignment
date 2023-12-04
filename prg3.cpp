// immplementation stack using list
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;

    
};
struct node *top=NULL;

void push(int x){
    struct node *newnode;
    newnode = new node;
    newnode->data=x;
    newnode->next=top;
    top=newnode;
}
void pop(){
    node *deletenode;
    deletenode = top;
    top=top->next;
    free(deletenode);
}
void display(){
    node *temp;
    if(temp=NULL) return;
    else{
        temp=top;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }cout<<"\n";
    }
}
void peek(){
    cout<<top->data<<"\n";
}



int main(){
    // struct node s;
    push(15);
    push(1412);
    push(2121);
    push(21);
    push(81);
    pop();
    display();
    peek();
    // display();

}