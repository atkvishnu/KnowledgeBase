// sequence of steps
// 1.Allocate the memory
// 2. Assign data and link part
// 3. If root is null then attach the node to head or first
// 4. Else, attach the node at the end of the list


#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
}*first;                    // first is declared here! This becomes a global pointer

// struct Node *first;      // first can also be declared like this!

void create(int A[], int n)
{
    int i;
    struct Node *t,*last;     // temporary pointer
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last = first;

    for(i=1;i<n;i++)        // this loop will create the entire LL
    {
        t = (struct Node *)malloc(sizeof(struct Node));     // (again created Node in heap)
        t->data = A[i];                                     // (filling the data in its data part.)
        t->next=NULL;                                       //  (making its next Null.)
        last->next=t;                                       // (now in this step we are putting the address of t in the last->next which means the first Node which we created its next section. so now first node has address of this new created node in it. so now they are linked.)
        last=t;                                            // (and now we storing the address of t in last so that for next element we can repeat the same step  in order.)
    }

}

void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

int main()
{
    int A[] = {3,5,7,10,15};
    create(A,5);

    Display(first);

    return 0;
}