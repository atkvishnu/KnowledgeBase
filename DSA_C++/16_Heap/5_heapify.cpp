// heapify is a faster way of creating heap

// Heapify method rearranges the elements of an array where the left and right sub-tree of ith element obeys the heap property.
// Algorithm: Max-Heapify(numbers[], i) 
// leftchild := numbers[2i] 
// rightchild := numbers [2i + 1] 
// if leftchild ≤ numbers[].size and numbers[leftchild] > numbers[i] 
//    largest := leftchild 
// else 
//    largest := i 
// if rightchild ≤ numbers[].size and numbers[rightchild] > numbers[largest] 
//    largest := rightchild 
// if largest ≠ i 
//    swap numbers[i] with numbers[largest] 
//    Max-Heapify(numbers, largest)

// When the provided array does not obey the heap property, Heap is built based on the following algorithm 
// Build-Max-Heap (numbers[]).

// Algorithm: Build-Max-Heap(numbers[]) 
// numbers[].size := numbers[].length 
// fori = ⌊ numbers[].length/2 ⌋ to 1 by -1 
//    Max-Heapify (numbers[], i) 




#include <iostream>
 
using namespace std;
 
class heap
{
public:
    int *a;
    int size;
    int length;
    heap()
    {
        a=NULL;
        size=0;
        length=0;
    }
    void createarray()
    {
        cout<<"Enter size\n";
        cin>>size;
        a=new int[size];
        cout<<"Enter no. of Elements\n";
        cin>>length;
        cout<<"Enter elements\n";
        for(int i=0;i<length;i++)
            cin>>a[i];
   }
   void display()
   {
       for(int i=0;i<length;i++)
        cout<<a[i]<<" ";
   }
   void heapify()
   {   int flag=0,i,j;
       i=length/2-1;
       j=2*(i+1);
       while(i>=0 && i<=length/2-1)
       {
               if(a[j-1]>a[j])
                j=j-1;
               if(a[i]<a[j])
               {
                   swap(a[i],a[j]);
               }
               if(i==0)
                flag=1;
               if(flag==0)
              {
                 i--;
                 j=2*(i+1);
               }
               else
               {
                   i++;
                   j=2*(i+1);
               }
       }
    }
};
int main()
{
    heap h;
    h.createarray();
    h.heapify();
    h.display();
    return 0;
}