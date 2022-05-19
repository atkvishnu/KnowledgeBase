#include<stdio.h>

#include<stdlib.h>

struct node {
    struct node * lchild;
    struct node * rchild;
    int data;
};
struct queue {
    int front;
    int rear;
    int size;
    struct node ** Q;
};
struct stack {
    int top;
    int size;
    long int * st;
};
void createstack(struct stack * s, int size) {
    s -> top = -1;
    s -> size = size;
    s -> st = (long int * ) malloc(s -> size * sizeof(long int));
}
int isemptystack(struct stack * s) {
    return s -> top == -1;
}
void push(struct stack * s, long int t) {
    if (s -> top == s -> size - 1) {
        printf("The stack is beng full\n");
    } else {
        s -> top++;
        s -> st[s -> top] = t;
    }
}
long int pop(struct stack * s) {
    if (s -> top == -1) {
        printf("The stack is empty\n");
        return 0;
    } else {
        return s -> st[s -> top--];
    }
}
void createque(int size, struct queue * q) {
    q -> size = size;
    q -> front = q -> rear = -1;
    q -> Q = (struct node ** ) malloc(sizeof(struct node * ) * (q -> size));
}
void enq(struct queue * q, struct node * x) {
    if (q -> front == q -> size - 1)
        printf("The queue is being full\n");
    else {
        q -> rear = q -> rear + 1;
        q -> Q[q -> rear] = x;
    }
}
//performing the dequeue operation
struct node * deq(struct queue * q) {
    struct node * x = NULL;
    if (q -> front == q -> rear)
        printf("The queue is being empty\n");
    else {
        q -> front = q -> front + 1;
        x = q -> Q[q -> front];
    }
    return x;
}
int isempty(struct queue * q) {
    return q -> rear == q -> front;
}
struct node * root = NULL;
///code for making the binary tree
void createtree() {
    int x;
    struct node * p, * t;
    struct queue q;
    createque(100, & q);
    printf("\nEnter the root value pls\n");
    scanf("%d", & x);
    root = (struct node * ) malloc(sizeof(struct node));
    root -> data = x;
    root -> lchild = root -> rchild = NULL;
    enq( & q, root);
    while (!isempty( & q)) {
        p = deq( & q);
        printf("Enter the left child of the %d\n", p -> data);
        scanf("%d", & x);
        if (x != -1) {
            t = (struct node * ) malloc(sizeof(struct node));
            t -> data = x;
            t -> lchild = t -> rchild = NULL;
            p -> lchild = t;
            enq( & q, t);
        }
        printf("Enter the right child of the %d\n", p -> data);
        scanf("%d", & x);
        if (x != -1) {
            t = (struct node * ) malloc(sizeof(struct node));
            t -> data = x;
            t -> lchild = t -> rchild = NULL;
            p -> rchild = t;
            enq( & q, t);
        }
    }
}
void postorder1(struct node * p) {
    if (p) {
        postorder1(p -> lchild);
        postorder1(p -> rchild);
        printf("%d ", p -> data);
    }
}
//writing the main function
//functions for the iterative traversal of the postoder and preoder and inorder traversal of the binary tree
void iterativepostorder(struct node * t) {
    struct stack b;
    createstack( & b, 100);
    long int temp;
    while (t != NULL || !isemptystack( & b)) {
        if (t != NULL) {
            push( & b, (long int) t);
            t = t -> lchild;
        } else {
            temp = pop( & b);
            if (temp > 0) {
                push( & b, -temp);
                t = ((struct node * ) temp) -> rchild;
            } else {
                temp = -temp;
                printf("%d ", ((struct node * ) temp) -> data);
                t = NULL;
            }
        }
    }
}
int main() {
    //struct stack b;
    createtree();
    printf("\nThe recursive postorder of the binary tree is");
    postorder1(root);
    printf("\nThe iterative postorder of the binary tree is");
    iterativepostorder(root);
    return 0;
}