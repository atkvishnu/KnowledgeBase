#include <stdio.h>
#define SIZE 10
int hash(int key)       // hash function
{
    return key%SIZE;
}

int probe(int H[],int key)              // this probe() fn. finds out the next free space linearly
{
    int index=hash(key);
    int i=0;
    while(H[(index+i)%SIZE]!=0)         
        i++;
    return (index+i)%SIZE;
}

void Insert(int H[],int key)
{
    int index=hash(key);
    
    if(H[index]!=0)                     // if index is free or not
        index=probe(H,key);             // probe finds out next free space
    H[index]=key;
}

int Search(int H[],int key)             // search for key
{
    int index=hash(key);
    
    int i=0;
    // This probe is to find the key value
    while(H[(index+i)%SIZE]!=key)       // if key is not found, then perform linear probing     // This loop is for linear probing, the other probe function is for insertion purpose
        i++;                            // probe finds out next free space
    
    return (index+i)%SIZE;
}

int main()
{
    int HT[10]={0};
    
    Insert(HT,12);
    Insert(HT,25);
    Insert(HT,35);
    Insert(HT,26);
    
    printf("\nKey found at %d\n",Search(HT,35));
    return 0;
}