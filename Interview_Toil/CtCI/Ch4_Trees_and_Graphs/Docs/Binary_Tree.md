# Binary Tree


A tree of degree 1: 
![](https://assets.alexandria.raywenderlich.com/books/alg/images/508d22caa1902be997feacfdedc6203a311f33df3c5ebbe78314279a23d46c35/original.png)


A tree of degree 2 (i.e., every node can have maxm. 2 childrens not more than 2 children)

* It can have less than 2 childrens but not more than 2 childrens.
    
```
                 A
                /  \
               B    C
              /\    /\
             /  \  /  \
            D   E  F   G
```

A: B, C
B: D, E
C: F, G

degree(T) = 2
children = {0,1,2} -> not more than 2.

# Number of Binary Tree using N nodes

2 types of nodes:
* Unlabeled nodes - Nodes aren't labelled.
* Labelled nodes


`Catalan Number`: Formula to calculate the no. of trees being formed.


T(3) = 5
T(4) = 14
T(5) = (2*5)C5 / (5+1) = 10C5/6 = 42
T(6) = 132


####  Formulas for Unlabelled Nodes:

    * `Combination Formula`:  `T(n) = 2nCn / (n+1);`


    * `Recursive formula` for catalan numbers: 
    ![](data:image/png;base64,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)




Question: If we are given 3 nodes then how many different binary trees can be generated?

![](https://i0.wp.com/studyalgorithms.com/wp-content/uploads/2014/11/different_trees.png?ssl=1)





#### Labelled Nodes Formula

`T(n) = 2n C n * ( n! / (n+1)) = number of shapes`( T(n) = 2nCn / (n+1);)` * label fillings`(n!)``

``

# Height v/s Nodes in Binary Tree
