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
        cout << p->data << " ";
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
        p = p->next;
    }
    return max;
}
int Rmax(struct Node *p)
{
    int x = 0;
    if(p==0)
        return 0;
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

//=================NORMAL SEARCH====================================
struct Node * LSearch(struct Node *p, int key)
{
    while(p)
    {
        if(key==p->data)
            return p;
        p = p->next;
    }    
    return NULL;
}
struct Node * RecLSearch(struct Node *p, int key)
{
    if(p==NULL)
        return NULL;

    if(key==p->data)
        return p;
    return RecLSearch(p->next, key);
}
//--------------------IMPROVISED LINEAR SEARCH--------------------
struct Node * ModLSearch(struct Node *p, int key)
{
    struct Node *q = NULL;
    while(p)
    {
        if(key==p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;          // first pointer is global!
            return p;
        }
        q = p;
        p = p->next;
    }    
    return NULL;
}


//================================================================








//==========================MAIN==================================
int main()
{
    struct Node *temp;  // for LSearch
    struct Node *temp1;  // for RecLSearch
    struct Node *temp2;  // for ModLSearch

    int A[] = {5,7,10,11,12,13,15,27};
    create(A,8);

    cout << endl << "Length is: " << Rcount(first)<< endl << endl;

    cout << "SUM ANSWERS" << endl;
    cout << "Sum is: " << sum(first) << endl;
    cout << "Recursive Sum is: " << Rsum(first) << endl << endl;

    cout << "MAXIMUM ANSWERS" << endl;
    cout << "Max. value is: " << max(first) << endl;
    cout << "Max. value is: " << Rmax(first) << endl;
    cout << "Max. value is: " << Rmax1(first) << endl << endl;

    // Linear search------------------------------------------
    cout << "LINEAR SEARCH ANSWERS" << endl;
    temp = LSearch(first, 12);
    if(temp!=NULL)
        cout << "Key is found! " << temp->data << endl << endl; 
    else
        cout << "Key not found!" << endl << endl; 

    temp1 = RecLSearch(first, 13);
    if(temp1!=NULL)
        cout << "Key is found! " << temp1->data << endl << endl; 
    else
        cout << "Key not found!" << endl << endl;

    Display(first);
    temp2 = ModLSearch(first, 15);
    if(temp2)
        cout << "Key is found! " << temp2->data << endl << endl; 
    else
        cout << "Key not found!" << endl << endl;

    temp2 = ModLSearch(first, 13);
    Display(first);
    //------------------------------------------------------------
}
//================================================================