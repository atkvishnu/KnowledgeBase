#include <iostream>
using namespace std;
 
class MaxHeap
{
    public:
    int *hp;
    int capacity;
    int n;
    MaxHeap(int size);
    void insert(int item);
    int pop_max();
    int peek_max();
    private:
    void swim();
    void sink();
    void swap(int i, int j);
};
 
MaxHeap::MaxHeap(int size)
{
    hp = new int[size+1];
    n = 0;
    capacity = size;
}
 
void MaxHeap::insert(int item)
{
    if (n < capacity)
    {
        hp[++n] = item;
        swim();
    }
}
 
int MaxHeap::pop_max()
{
    int max_item = -1;
    if (n >= 1)
    {
        max_item = hp[1];
        swap(1, n--);
        sink();
    }
    return max_item;
}
 
void MaxHeap::swim()
{
    int i = n; // start at newly inserted element
    while (i > 1 && hp[i] > hp[i/2]) // keep swapping while parent is less than child
    {
        swap(i, i/2);
        i /= 2;
    }
}
 
void MaxHeap::sink()
{
    int i = 1; // start at root
    int j = 2; // left child of root
    while (j <= n) // While there is still a valid child to compare to
    {
        if (j < n && hp[j+1] > hp[j]) j++; // Check which child is greater
        if (hp[j] > hp[i]) // If either child is greater than the parent
        {
            swap(i, j); // swap
            i = j;      // move i down to where greater child was
            j = j * 2;  // set j to the left child of new i
        } else break;
    }
}
 
int MaxHeap::peek_max()
{
    if (n >= 1)
        return hp[1];
    cout << "Heap is empty.\n";
    return -1;
}
 
void MaxHeap::swap(int i, int j)
{
    int t = hp[i];
    hp[i] = hp[j];
    hp[j] = t;
}