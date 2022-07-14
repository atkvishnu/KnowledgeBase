// This is the implementation of column major matrix

// Formula for accessing non-zero elements in a 1D array: m.A[m.n*(j-1)-(j-2)*(j-1)/2+i-j])

#include <stdio.h>

#include <stdlib.h>     //because we are using malloc function

struct Matrix {
    int * A; // This a lower triangular mattrix, we don't know the size of the matrix. So we use a pointer and we will create a array dynamically of the required size.
    int n;
};

void Set(struct Matrix * m, int i, int j, int x) {
    if (i >= j)
        m -> A[m -> n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j] = x;
}

int Get(struct Matrix m, int i, int j) {
    if (i >= j)
        return m.A[m.n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j];
    else
        return 0;
}

void Display(struct Matrix m) {
    int i, j;
    for (i = 1; i <= m.n; i++) {
        for (j = 1; j <= m.n; j++) {
            if (i >= j)
                printf("%d ", m.A[m.n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main() {
    // main fn. does not care how the elements are stored (row or column wise)
    struct Matrix m;
    int i, j, x;

    printf("Enter Dimension: ");
    scanf("%d", & m.n);
    m.A = (int * ) malloc(m.n * (m.n + 1) / 2 * sizeof(int));
    printf("Enter all the elements: \n");

    for (i = 1; i <= m.n; i++) {
        for (j = 1; j <= m.n; j++) {
            scanf("%d", & x);
            Set( & m, i, j, x);
        }
    }
    printf("\n");

    Display(m);

    return 0;
}