//Node.c
 
#include "Queue.h"
#include "Stack.h"
 
void createNode()
{
    struct Node *p, *t;
    int x;
    printf("Enter The Value of Root : ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(root);
    while (!isQueueEmpty())
    {
        p = dequeue(); //pop the item from queue and link it to lchild and rchild
        printf("Enter the left child of %d :  ", p->data);
        scanf("%d", &x);
        //Check for leaf node
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(t); //Insert the address of lchild in queue
        }
        printf("Enter the right child of %d : ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(t);
        }
    }
}
 
//Traversal using Recursion
 
void preOrder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}
 
void inOrder(struct Node *p)
{
    if (p)
    {
 
        inOrder(p->lchild);
        printf("%d ", p->data);
        inOrder(p->rchild);
    }
}
 
void postOrder(struct Node *p)
{
    if (p)
    {
        postOrder(p->lchild);
        postOrder(p->rchild);
        printf("%d ", p->data);
    }
}
 
//Traversal Using Iteration
void IPreOrder(struct Node *p)
{
    long int temp;
 
    while (p || !isStackEmpty())
    {
        if (p)
        {
            printf("%d ", p->data);
            push((long int)p);
            p = p->lchild;
        }
        else
        {
            temp = pop();
            p = (struct Node *)temp;
            p = p->rchild;
        }
    }
}
 
void IInOrder(struct Node *p)
{
    long int temp;
    while (p || !isStackEmpty())
    {
        if (p)
        {
 
            push((long int)p);
            p = p->lchild;
        }
        else
        {
            temp = pop();
            p = (struct Node *)temp;
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}
 
void IPostOrder(struct Node *p)
{
    long int temp;
    while (p || !isStackEmpty())
    {
        if (p)
        {
            push((long int)p);
            p = p->lchild;
        }
        else
        {
            temp = pop();
            if (temp > 0)
            {
                push(-temp);
                p = (struct Node *)temp;
                p = p->rchild;
            }
            else
            {
                p = (struct Node *)-temp;
                printf("%d ", p->data);
                p = NULL;
            }
        }
    }
}


void Levelorder(struct Node *root)
{
    struct Queue *q;
    // create(&q,100);

    printf("%d ", root->data);
    enqueue(root);

    while(!isQueueEmpty(q))
    {
        root = dequeue(&q);
        if(root->lchild)
        {
            printf("%d ", root->lchild->data);
            enqueue(root->lchild);
        }
        if(root->rchild)
        {
            printf("%d ", root->rchild->data);
            enqueue(root->rchild);
        }
    }
    printf("\n");
}

 
int main()
{
    createNode();
    printf("\nPreorder Traversal is : ");
    IPreOrder(root);
    printf("\n");
    printf("\nInorder Traversal is : ");
    IInOrder(root);
    printf("\n");
    printf("\nPostorder Traversal is : ");
    IPostOrder(root);
    printf("\n");
    printf("\nLevelorder Traversal is : ");
    Levelorder(root);
    return 0;
}