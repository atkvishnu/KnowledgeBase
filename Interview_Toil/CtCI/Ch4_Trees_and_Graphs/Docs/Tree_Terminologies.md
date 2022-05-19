#tree

- A Tree is a type of graph!



# Tree vs. Binary Tree

- A binary tree is a tree in which each node has up to two children!
- Not all trees are Binary Trees.
- Example: this tree is not a binary tree. We can call it a ternary tree

				8
			 /	|  \
			/	|	\
			4	6	10
		   /\        \
		  2  1        20



- There are occasions when you might have a tree that is not a binary tree.
- Example: Suppose we are using a tree to represent a bunch of phone numbers.
- In this case, you might use a 10-ary tree, with each node having up to 10 children (one for each digit).

- A node is called a "leaf" node if it has no children.



# Binary Tree vs. Binary Search Tree (BST)

- A Binary Search Tree(BST) is a binary tree in which every node fits a specific ordering property:
	`all left descendents <= n < all right descendents`



# Terminologies

1. `Tree`

    * Tree is a collection of `NODE/ VERTICES` and `EDGES`.
    * If there are N Nodes then there will be N-1 edges.
    * Every node has edge coming out of it, except root.

```
                                   A
                                  /|\
                                /  | \
                               B   C  D
                              /\     /|\
                             E  F   G H I
                                /\    |
                               /  \   |
                              J   K   L
                              |      /\
                              M     N  O
```                                 
                                 

    * Here, A is the `root node (or parent node)` of the tree.
    * All the nodes below B, D form a `sub-tree`.

- Tree : Tree is a `collection of nodes` among those nodes, one node is taken as `root node` & rest of the nodes are divided into `disjoint subsets`.
    Each subset is a `tree/subtree` in its own!

2. `Root` : The very first node on the top is `root`.

3. `Parent`: A node is a parent to its very next descendant. OR. Those children that are connected with just one edge.

      For B -> E & F are it's children.
      For D -> G, H  & I are it's children. [D(parent): G, H, I(children)]
      For L -> N, O are it's children [L(parent) : N, O(children)] 

5.  `Children`: A node which is descendant of any node is called CHILD node.
                             OR
                             A node which has a link from it's parent node is called as CHILD node.
                             In a tree, any parent node can have any no. of nodes.
                             In a tree, all the nodes except root are child nodes.

6. `Siblings`: Nodes that belong to the same parent are called as SIBLINGS.
                            OR
                            Nodes with the same parent are called as siblings.
                            Siblings: [G, H, I] , [J, K] , [N, O] , [B, C, D]

7. `Descendent`: The set of nodes which are its children and thier children and their children, …… are called                               Descendent.
                                OR
                                Descendent are all those set of nodes which can be reached from a particular node or under that node.
                                For B -> Descendents are: E, F, J, K, M
                                For L -> Descendents are: N, O
                                
8. `Ancestors`:  For any node all the nodes along the path from that node to root node are called it's                                          ancestors.
                               For M -> Ancestors are: J, F, B, A
                               For N -> Ancestors are: L, H, D, A
                               
9. `Degree of Node`: It's the no. of direct children it's having (not all descendants).
                               Degree of L = 2
                               Degree of D = 3
                               Degree of A = 3
                               Degree of F = 2
                               Degree of J = 1
                               Degree of N = 0
                               
                               Degree of the tree: From the tree we cannot tell what's the degree. Degree is prescribed. But if we observe, the maxm. degree of any node = 3.
                               Therefore, Degree of this tree can be minm. 3 (or it's more than 3).
                               
10. `Internal/ External Nodes`:   a.k.a Non-leaf/ leaf nodes
                                                             a.k.a non-terminal/ terminal nodes.
                                                             
                                                             Nodes with degree 0 are called as Leaf nodes/ External nodes/ Terminal nodes.
                                                             Ex. E, M, K, G, N, O, I
                                                             
                                                             Nodes with degree greater than 0 are internal nodes/ non-leaf/ non-terminal nodes.
                                                             Ex. rest of the nodes.
                                                             
                            Leaf <-> External <-> Terminal
                            * node which doesn't have a child is called LEAF node.
                            * leaf is a node with NO child.

                            non-leaf <-> internal <-> non-terminal
                            * node which has atleast 1 child are 
                            * nodes other than leaf nodes are 
                            * Root node is also said to be internal node if tree has more than one node.
                                                                 

11. `Level`: Levels of a tree starts from 1 onwards.
                          
```
Height                                                          Level
0                                 A                               1
                                 /|\
                                /  | \
1                              B   C  D                           2
                              /\     /|\
2                            E  F   G H I                         3
                                /\    |
                               /  \   |
3                             J   K   L                           4
                              |      /\
4                             M     N  O                          5
```         

![](http://www.atnyla.com/library/images-tutorials/Slide1-tree-level-0-Slide1.PNG)


![](https://www.baeldung.com/wp-content/uploads/sites/4/2020/05/Screenshot-2020-05-12-at-07.03.52-1024x695.png)


![](https://condor.depaul.edu/ntomuro/courses/416/notes/lecture3/tree.gif)






In a tree each step from top to bottom is called as a level, and the level count starts with '0' and incremented by one at each level(Step).

12. `Height`:  The total no. of edges from a leaf node to a particular node in the longest path is called as                               HEIGHT of that node.

                            [Height and level both are essential for analysis].
                            
13. `Forest`: A collection of tree is called as `forest`.                            

![alt text](https://www.researchgate.net/publication/355697744/figure/fig1/AS:1089314482077696@1636724219296/Forest-Data-Structure-Representation.ppm)


![](https://networkinterview.com/wp-content/uploads/2020/01/Differences-table-between-the-Tree-and-Forest-v0.1a.png)


                        
14. `Edge`: The connecting link b/w any 2 nodes is called as EDGE.
                       A tree with `N nodes` will have `N-1 edges`.
                       
15. `Depth`: The total no. of edges from root node to a particular node is called as DEPTH of that node.
                         
        `Depth of the tree`: The total no. of edges from root node to a leaf node in the longest path is said to be depth of the tree.
        
        
                       








