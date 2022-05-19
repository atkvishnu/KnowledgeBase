#include <stdio.h>
#include <stdlib.h>
 
#ifndef Queue_h
#define Queue_h
// Tree Structure
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;
 
//Queue Structure
struct Queue
{
    struct Node *qdata; //Store the address of Node
    struct Queue *next;
} *front = NULL, *rear = NULL;
 
void enqueue(struct Node *x)
{
    struct Queue *t;
    t = (struct Queue *)malloc(sizeof(struct Queue));
    if (t == NULL)
    {
        printf("Queue is Full!");
    }
    else
    {
        t->qdata = x;
        t->next = NULL;
        if (front == NULL)
        {
            front = rear = t; //When the queue doesn't exist
        }
        else
        {
            rear->next = t; //Insert from rear
            rear = t;
        }
    }
}
struct Node * dequeue()
{
    struct Node *x;
    struct Queue *t;
    if (front == NULL)
    {
        printf("Queue is Empty!");
    }
    else
    {
        t = front;
        x = t->qdata;
        front = t->next;
        free(t);
    }
    return x;
}
 
int isQueueEmpty()
{
    return front == NULL;
}
#endif