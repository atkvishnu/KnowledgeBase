#include <stdio.h>

void Insert(int A[], int n) {
    int i = n, temp;
    temp = A[i];    
    while (i > 1 && temp > A[i/2])  // compare and swap elements until it reaches loop OR until it reaches it's right place
    {
        A[i] = A[i/2];
        i = i/2;    // move i to parent
    }
    A[i] = temp;    
}
int Delete(int A[], int n) {
    int i, j, x, temp, val;
    val = A[1];
    x = A[n];
    A[1] = A[n];    // deleted value
    A[n] = val;
    i = 1;
    j = i * 2;
    while (j <= n - 1) {
        if (j < n - 1 && A[j + 1] > A[j])
            j = j + 1;
        if (A[i] < A[j]) 
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * j;      // j should move to lchild
        } 
        else
            break;
    }
    return val;
}
int main() {
    int H[] = {0,14,15,5,20,30,8,40};
    int i;
    for (i = 2; i <= 7; i++)        // at index 0, we have 0 and at 1 we have 1, so we start from 2; because we have taken the formula as i and i/2. For that formula to work, we have to take index starting from 1.
        Insert(H, i);



    // this is heap sort!    
    for (i = 7; i > 1; i--)
        Delete(H, i);

    for (i = 1; i <= 7; i++) 
        printf("%d ", H[i]);

    printf("\n");
    return 0;
} 