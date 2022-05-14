# Arrays

## 1. Moving elements ahead to free up space for a element (insert operation).

-   We have to start the shifting from the end of the array (till the index)!

*   for pushing the elements right, freeing up a space!

index = 2, value_to_insert = 3

        index           i

| 2 | 4 | 6 | 8 | 10 | 12 | | |  
 0 1 2 3 4 5 6 7

```cpp
for(int i = length-1; i >= index; i--) {
	A[i+1] = A[i];
}
```

Output:
| 2 | 4 | | 6 | 8 | 10 | 12 | |  
 0 1 2 3 4 5 6 7

-   This won't work:

```cpp
for(int i = index; i <= length-1; i++) {
	A[i+1] = A[i];
}
```

Output:
| 2 | 4 | | 6 | 6 | 6 | 6 | |  
 0 1 2 3 4 5 6 7

-   While DELETING a element, this can be used:

*   for bringing the element left, and filling the empty space!

```cpp
for(int i = index; i < length-1; i++) {
      A[i] = A[i+1];
}
```

---

# 1.7 Matrix Rotation - Layer wise

![image](https://1.bp.blogspot.com/-pL9d0Wl3KrU/WDx1ISvF0uI/AAAAAAAABfU/YEhUYrOgnlAUx2G2pEYjeujpPknXv28QQCLcB/s1600/rotate-matrix-by-90-degree.png)

-   I had come up with the formula to rotate the array by making an new vector of vector.

    > Row-column mapping:  
    > Clockwise: i <- j && j <- N-i-1 [`M[j][N-i-1]=M[i][j]`]  
    > Anti-Clockwise: i <- n-j-1 && j <- i [`M[n-j-1][i]=M[i][j]`]

-   This process can be done in-place too!

![](https://s3.ap-south-1.amazonaws.com/afteracademy-server-uploads/rotate-matrix-inplace-rotate-visual1-png-45569d4545097967.jpg)

![image](https://1.bp.blogspot.com/-r_u5YwtHgTQ/WDz858yg7lI/AAAAAAAABf8/WluTMfHyAdI5ytSSGqml8ASxwe3BekIdgCLcB/s640/rotate-matrix-by-90-degree-layers.png)

![](https://3.bp.blogspot.com/-fXRXC_xOt4c/WDx238D6DAI/AAAAAAAABf4/2pSw7WtsE-ELsWtW1d9X7nIPubh-sgwWgCPcB/s640/rotate-matrix-by-90-degree-algorithm.png)

![](https://yellowcoding.com/wp-content/uploads/2020/12/rotateMatrix-669x500.png)

-   First layer is the elements on the outer edge.

> Indexs in 4x4 matrix corresponding to 1st layer: (0,0),(0,1),(0,2),(0,3),(1,3),(2,3),(3,3),(3,2),(3,1),(3,0),(2,0),(1,0).
> Map this on pen&paper to get a better overview.
> When i = 0, j = 0, n-i-1 = 3, n-j-1 = 3:

-   1st rotation: temp <- M[0][0]; M[0][0] = M[0][3]; M[0][3] = M[3][3]; M[3][3] = M[3][0]; M[3][0] = temp;

> i and j increments, value of n-i-1 & n-j-1 also increases....
> Map this on pen&paper to get a better overview.

> take n = 4 for example

```pseudocode
for(i=0 to n/2]{      // i = 0 & 1
  for(j=i to n-i-1]{    // j = i & 3-i
    int temp = M[i][j];
    M[i][j]=M[j][n-i-1];
    M[j][n-i-1]=M[n-i-1][n-j-1];
    M[n-i-1][n-j-1]=M[n-j-1][i];
    M[n-j-1][i]=temp;
  }
}
```

-   Second layer is the elements on the inner part of the matrix.

> Indexs in 4x4 matrix corresponding to 2nd layer: (1,1),(1,2),(2,2),(2,1).

---
