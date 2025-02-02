#include<bits/stdc++.h>
using namespace std;

struct Queue{
    int front,rear,size;
    int *queue;
    Queue(int s){
        front=rear=0;
        size=s;
        queue=new int;
    }
    void enqueue(int data){
        if(size==rear){
            cout<<"Size is full";
            return;
        }
        queue[rear]=data;
        rear++;
        return;
    }
    void dequeue(){
        if(front==rear){
            cout<<"Queue is empty";
            return;
        }
        for (int i = 0; i < rear - 1; i++) {
            queue[i] = queue[i + 1];
        }
        rear--;
        return;
    }
    void display(){
        if (front == rear) {
            printf("\nQueue is Empty\n");
            return;
        }
        for (int i = front; i <rear ; i++)
        {
            cout<<queue[i]<<" ";
        }cout<<"\n";
    }
};

int main(){
    Queue q(4);
    q.enqueue(5);
    q.enqueue(8);
    q.enqueue(2);
    q.enqueue(32);
    q.display();
    q.dequeue();
    q.display();
}