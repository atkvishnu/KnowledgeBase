// heap memory not used

#include<iostream>
 
using namespace std;
 
struct Array 
{
    int arr[20];
    int size;
    int length;
 
    void display()
    {
        for(int i=0; i<length; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
};
 
// searching in the array
bool elementPresentOrNot(int arr[], int l, int x)               //if present -> returns true
{
    for(int i=0; i<l; i++)
    {
        if(arr[i]==x)
            return true;
    }
    return false;
}
 
/* first copy all the elements of A to C and then copy 
those elements of B in C that is not present in C
*/
 
void unionOnUnsortedArray(Array *A, Array *B, Array *C)
{
    int i=0;
    int j=0; 
    int k=0;
 
    for(i; i<A->length; i++)
    {
        C->arr[k++] = A->arr[i];
        C->length++;
    }
 
    for(j; j<B->length; j++)
    {
        if(!elementPresentOrNot(C->arr, C->length, B->arr[j]))
        {
            C->arr[k++] = B->arr[j];
            C->length++;
        }
    }
}
 
// copy those elements of A to C which is present in B.
 
void intersectionOnUnsortedArray(Array *A, Array *B, Array *C)
{
    int k=0;
    for(int i=0; i<A->length; i++)
    {
        if(elementPresentOrNot(B->arr, B->length, A->arr[i]))
        {
            C->arr[k++] = A->arr[i];
            C->length++;
        }
    }
}
 
/* copy those elements of A to C which is not present in B.
*/
 
void differenceOnUnsortedArray(Array *A, Array *B, Array *C)
{
    int k=0;
    for(int i=0; i<A->length; i++)
    {
        if(!elementPresentOrNot(B->arr, B->length, A->arr[i]))
        {
            C->arr[k++] = A->arr[i];
            C->length++;
        }
    }
}
 
int main(){
 
    Array A = {{3, 5, 10, 4, 6}, 10, 5};
    Array B = {{12, 4, 7, 2, 5}, 10, 5};

    Array C;
 
    A.display();
    B.display();
 
    unionOnUnsortedArray(&A, &B, &C);
    // intersectionOnUnsortedArray(&A, &B, &C);
    // differenceOnUnsortedArray(&A, &B, &C);
    C.display();
 
} 