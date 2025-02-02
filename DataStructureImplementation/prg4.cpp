#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};


class Queue{
node *front = NULL;
node *rear = NULL;
public:
    void enque(int x){
        node *newnode = new node;
        newnode->data=x;
        newnode->next=NULL;
        if(front==0 && rear==0){
            front=rear=newnode;
        }
        else{
            rear->next=newnode;
            rear = newnode;
        }
    }
    void display(){
        node *temp = front;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }cout<<"\n";
    }
    void dequess(){
        node *deletenode=front;
        front = front->next;
        free(deletenode);
    }
};

int main(){
    Queue que;
    Queue q;
    q.enque(5);
    q.enque(25);
    q.enque(56);
    que.enque(10);
    que.enque(1240);
    que.enque(19);
    que.enque(50);
    que.enque(650);
    que.enque(199);
    que.display();
    que.dequess();
    que.display();
    q.display();
}