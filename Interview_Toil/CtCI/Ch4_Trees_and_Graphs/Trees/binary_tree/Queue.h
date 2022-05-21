#ifndef Queue_h
#define Queue_h

class Node {
public:	
	Node *lchild;
	int data;
	Node *rchild;
};

class Queue {
public:
	int size;
	int front;
	int rear;
	Node **Q;	// *Q -> pointer of type array
	// Node * -> ptr. of type Node
};

void create(Queue *q, int size) {
	q->size = size;
	q->front = q->rear = 0;
	q->Q = (Node **)malloc(q->size*sizeof(Node *));		//new Node * [q->size];
}

void enqueue(struct Queue *q, Node *x) {
	if((q->rear + 1) % q->size == q->front) {
		printf("Queue is full! ");
	} else {
		q->rear = (q->rear+1) % q->size;
		q->Q[q->rear] = x;
	}
}

Node * dequeue(struct Queue *q) {
	Node *x = nullptr;
	if(q->front == q->rear) {
		printf("Queue")
	}
}