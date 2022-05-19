#include <iostream>
using namespace std;

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
        cout << p->data;
        p=p->next;
    }
    printf("\n");
}


int count(struct Node *p)
{
    int l = 0;
    while(p)
    {
        l++;
        p=p->next;
    }
    return l;
}

int Rcount(struct Node *p)
{
    if(p)
        return Rcount(p->next)+1;
    else    
        return 0;
}


int sum(struct Node *p)
{
    int sum = 0;
    while (p){
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int Rsum(struct Node *p)
{
    if(p==0)
        return 0;
    else
        return Rsum(p->next)+p->data;
}


int main()
{
    int A[] = {5,7,10,11,12,13,15,20};

    create(A,8);
    cout << "Length is: " << Rcount(first)<< endl;

    cout << "Sum is: " << sum(first) << endl;
    cout << "Recursive Sum is: " << Rsum(first) << endl;

}
