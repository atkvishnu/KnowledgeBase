#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
}*first;                   

// struct Node *first;      // first can also be declared like this!

void create(int A[], int n)
{
    int i;
    struct Node *t,*last;    
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last = first;

    for(i=1;i<n;i++)       
    {
        t = (struct Node *)malloc(sizeof(struct Node));     
        t->data = A[i];                                    
        t->next=NULL;                                      
        last->next=t;                                       
        last=t;                                            
    }

}

void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d", p->data);
        p=p->next;
    }
    printf("\n");
}

void RDisplay(struct Node *p)
{
    if(p!=NULL)
    {
        printf("%d ",p->data);
        RDisplay(p->next);
    }
}

void ReversedRecursiveDisplay(struct Node *p)
{
    // Order of execution is changed!
    if(p!=NULL)
    {
        ReversedRecursiveDisplay(p->next);
        printf("%d ",p->data);
    }
}

int main()
{
    int A[] = {3,5,7,10,15};
    create(A,5);

    // Display(first);
    // RDisplay(first);
    ReversedRecursiveDisplay(first);

    return 0;
}