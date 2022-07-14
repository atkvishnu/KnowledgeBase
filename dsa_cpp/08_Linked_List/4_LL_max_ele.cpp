#include <iostream>
#include <climits>

using namespace std;

struct Node 
{
    int data;
    struct Node *next;
}*first;                   

// struct Node *first;      // first can also be declared like this!

//=============================CREATE==============================
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
//================================================================

//===================DISPLAY=======================================
void Display(struct Node *p)
{
    while(p!=NULL)
    {
        cout << p->data;
        p=p->next;
    }
    printf("\n");
}
//================================================================

//=====================COUNT======================================
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
//================================================================

//=======================SUM======================================
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
//================================================================

//=========================MAX====================================
int max(struct Node *p)
{
    int max = -32768;
    while(p)
    {
        if(p->data > max)
            max = p->data;
        p = p->next;        // p should move to next element
    }
    return max;
}
int Rmax(struct Node *p)
{
    int x = 0;
    if(p==0)
        return INT32_MIN;
    else
    {
        x = max(p->next);
        if(x>p->data)
            return x;
        else
            return p->data;
    }
}
int Rmax1(struct Node *p)
{
    int x = 0;
    if(p==0)
        return 0;
    x = max(p->next);
    return x > p->data ? x : p->data;
}
//================================================================









//==========================MAIN==================================
int main()
{
    int A[] = {5,7,10,11,12,13,15,27};

    create(A,8);
    cout << "Length is: " << Rcount(first)<< endl;

    cout << "Sum is: " << sum(first) << endl;
    cout << "Recursive Sum is: " << Rsum(first) << endl;

    cout << "Max. value is: " << max(first) << endl;
    cout << "Max. value is: " << Rmax(first) << endl;
    cout << "Max. value is: " << Rmax1(first) << endl;

}
//================================================================