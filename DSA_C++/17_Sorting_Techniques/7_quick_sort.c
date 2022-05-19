#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;

    do
    {
        do
        {
            i++;
        } while (A[i] <= pivot);        // `i` should increment as long as element is less than or equal to pivot
        do
        {
            j--;
        } while (A[j] > pivot);         // `j` should decrement as long as element is greater than pivot

        if (i < j)
            swap(&A[i], &A[j]);
    } while (i < j);                

    swap(&A[l], &A[j]);                // swap pivot with the element at j
    return j;
}
void QuickSort(int A[], int l, int h)
{
    int j;

    if (l < h)
    {
        j = partition(A, l, h);     // partition the array and get the index of pivot
        QuickSort(A, l, j);         // sort left part of the array
        QuickSort(A, j + 1, h);     // sort right part of the array
    }
}
int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3, 65535}, n = 10, i;

    QuickSort(A, 0, n);

    for (i = 0; i < 10; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}