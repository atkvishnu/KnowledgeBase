#include<stdio.h>
#ifndef QueueCpp_h
#define QueueCpp_h

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue
{
private:
    int front;
    int rear;
    int size;
    Node **Q;

public:
    Queue(){front=rear=-1;size=10;Q=new Node*[size];}
    Queue(int size){front = rear = -1; this->size=size; Q=new Node*[this->size];}
    void enqueue(Node * x);
    Node* dequeue();
    void Display();
    int isEmpty(){return front==rear;};
    bool isFull();
};

void Queue::enqueue(Node * x)
{
    if(rear==size-1)
    {
        printf("Queue is full\n");
    }
    else
    {
        rear++;
        Q[rear]=x;
    }
}

Node* Queue::dequeue()
{
    Node* x = NULL;
    if(front==rear)
        printf("Queue is empty\n");
    else
    {
        x=Q[front+1];
        front++;
    }
    return x;
}

void Queue::Display()
{
    if(front==-1)
        printf("Queue is empty\n");
    else
    {
        for(int i=front+1;i<=rear;i++)
        {
            printf("%d ",Q[i]->data);
        }
        printf("\n");
    }
}



#endif /* QueueCpp_h */