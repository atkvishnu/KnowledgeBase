# **Linked List**

1. Insertion of a node in Linked List (On the basis of some constraints)
2. Delete a given node in Linked List (under given constraints)
3. Compare two strings represented as linked lists
4. Add Two Numbers Represented By Linked Lists
5. Merge A Linked List Into Another Linked List At Alternate Positions
6. Reverse A List In Groups Of Given Size
7. Union And Intersection Of 2 Linked Lists
8. Detect And Remove Loop In A Linked List
9. Merge Sort For Linked Lists
10. Select A Random Node from A Singly Linked List



----
# 1. Insertion of a node in Linked List (On the basis of some constraints)
Given a sorted linked list and a value to insert, write a function to insert the value in a sorted way.  
Initial Linked List   
 

![SortedLinked List](https://media.geeksforgeeks.org/wp-content/cdn-uploads/2009/09/SortedLinked-List.gif)

Linked List after insertion of 9   
 

![UpdatedSortedLinked List](https://media.geeksforgeeks.org/wp-content/cdn-uploads/2009/09/UpdatedSortedLinked-List1.gif)

**Algorithm:**   
Let input linked list is sorted in increasing order.   
 

1) If Linked list is empty then make the node as head and return it.
2) If the value of the node to be inserted is smaller than the value of the head node, then insert the node at the start and make it head.
3) In a loop, find the appropriate node after which the input node (let 9) is to be inserted. 
   To find the appropriate node start from the head, keep moving until you reach a node GN (10 in the below diagram) who's value is greater than the input node. The node just before GN is the appropriate node (7).
4) Insert the node (9) after the appropriate node (7) found in step 3.

**Implementation:**

```cpp
/* Program to insert in a sorted list */
#include <bits/stdc++.h>
using namespace std;
  
/* Link list node */
class Node {
public:
    int data;
    Node* next;
};
  
/* function to insert a new_node 
in a list. Note that this 
function expects a pointer to 
head_ref as this can modify the 
head of the input linked list 
(similar to push())*/
void sortedInsert(Node** head_ref,
                  Node* new_node)
{
    Node* current;
    /* Special case for the head end */
    if (*head_ref == NULL
        || (*head_ref)->data
               >= new_node->data) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else {
        /* Locate the node before the
 point of insertion */
        current = *head_ref;
        while (current->next != NULL 
&& current->next->data 
< new_node->data) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}
  
/* BELOW FUNCTIONS ARE JUST 
UTILITY TO TEST sortedInsert */
  
/* A utility function to 
create a new node */
Node* newNode(int new_data)
{
    /* allocate node */
    Node* new_node = new Node();
  
    /* put in the data */
    new_node->data = new_data;
    new_node->next = NULL;
  
    return new_node;
}
  
/* Function to print linked list */
void printList(Node* head)
{
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
  
/* Driver program to test count function*/
int main()
{
    /* Start with the empty list */
    Node* head = NULL;
    Node* new_node = newNode(5);
    sortedInsert(&head, new_node);
    new_node = newNode(10);
    sortedInsert(&head, new_node);
    new_node = newNode(7);
    sortedInsert(&head, new_node);
    new_node = newNode(3);
    sortedInsert(&head, new_node);
    new_node = newNode(1);
    sortedInsert(&head, new_node);
    new_node = newNode(9);
    sortedInsert(&head, new_node);
    cout << "Created Linked List\n";
    printList(head);
  
    return 0;
}
```

**Output:** 

Created Linked List
1 3 5 7 9 10 

**Complexity Analysis:**   
 

-   **Time Complexity:** O(n).   
    Only one traversal of the list is needed.
-   **Auxiliary Space:** O(1).   
    No extra space is needed.
	
	**Shorter Implementation using double pointers:**   
Thanks to **Murat M Ozturk** for providing this solution. Please see Murat M Ozturk’s comment below for complete function. The code uses double-pointer to keep track of the next pointer of the previous node (after which new node is being inserted).  
Note that below line in code changes _current_ to have address of next pointer in a node.   
 

   current = &((*current)->next);

Also, note below comments.   
 

    /* Copies the value-at-address current to
      new_node's next pointer*/ 
    new_node->next = *current; 

    /* Fix next pointer of the node (using its address) 
       after which new_node is being inserted */ 
    *current = new_node;  

**Time Complexity:** O(n)
	
	
	
	
	
	


----
# 2. Delete a given node in Linked List (under given constraints)
Given a Singly Linked List, write a function to delete a given node. Your function must follow following constraints:   
1) It must accept a pointer to the start node as the first parameter and node to be deleted as the second parameter i.e., a pointer to head node is not global.   
2) It should not return a pointer to the head node.   
3) It should not accept pointer to pointer to the head node.  
You may assume that the Linked List never becomes empty.  
Let the function name be deleteNode(). In a straightforward implementation, the function needs to modify the head pointer when the node to be deleted is the first node. As discussed in [previous post](https://www.geeksforgeeks.org/how-to-write-functions-that-modify-the-head-pointer-of-a-linked-list/), when a function modifies the head pointer, the function must use one of the [given approaches](https://www.geeksforgeeks.org/how-to-write-functions-that-modify-the-head-pointer-of-a-linked-list/), we can’t use any of those approaches here.   
**Solution**   
We explicitly handle the case when the node to be deleted is the first node, we copy the data of the next node to head and delete the next node. The cases when a deleted node is not the head node can be handled normally by finding the previous node and changing next of the previous node. The following are the implementation.


```cpp
// C++ program to delete a given node
// in linked list under given constraints
#include <bits/stdc++.h>
using namespace std;
 
/* structure of a linked list node */
class Node
{
    public:
    int data;
    Node *next;
};
 
void deleteNode(Node *head, Node *n)
{
    // When node to be deleted is head node
    if(head == n)
    {
        if(head->next == NULL)
        {
            cout << "There is only one node." <<
                    " The list can't be made empty ";
            return;
        }
 
        /* Copy the data of next node to head */
        head->data = head->next->data;
 
        // store address of next node
        n = head->next;
 
        // Remove the link of next node
        head->next = head->next->next;
 
        // free memory
        free(n);
 
        return;
    }
 
 
    // When not first node, follow
    // the normal deletion process
 
    // find the previous node
    Node *prev = head;
    while(prev->next != NULL && prev->next != n)
        prev = prev->next;
 
    // Check if node really exists in Linked List
    if(prev->next == NULL)
    {
        cout << "\nGiven node is not present in Linked List";
        return;
    }
 
    // Remove node from Linked List
    prev->next = prev->next->next;
 
    // Free memory
    free(n);
 
    return;
}
 
/* Utility function to insert a node at the beginning */
void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}
 
/* Utility function to print a linked list */
void printList(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
 
/* Driver code */
int main()
{
    Node *head = NULL;
 
    /* Create following linked list
    12->15->10->11->5->6->2->3 */
    push(&head,3);
    push(&head,2);
    push(&head,6);
    push(&head,5);
    push(&head,11);
    push(&head,10);
    push(&head,15);
    push(&head,12);
 
    cout<<"Given Linked List: ";
    printList(head);
 
    /* Let us delete the node with value 10 */
    cout<<"\nDeleting node "<< head->next->next->data<<" ";
    deleteNode(head, head->next->next);
 
    cout<<"\nModified Linked List: ";
    printList(head);
 
    /* Let us delete the first node */
    cout<<"\nDeleting first node ";
    deleteNode(head, head);
 
    cout<<"\nModified Linked List: ";
    printList(head);
    return 0;
}
```

**Output:**   
 

Given Linked List: 12 15 10 11 5 6 2 3

Deleting node 10:
Modified Linked List: 12 15 11 5 6 2 3

Deleting first node
Modified Linked List: 15 11 5 6 2 3








----
# 3. Compare two strings represented as linked lists
Given two strings, represented as linked lists (every character is a node in a linked list). Write a function compare() that works similar to strcmp(), i.e., it returns 0 if both strings are the same, 1 if the first linked list is lexicographically greater, and -1 if the second string is lexicographically greater.  
**Examples:**   
 

Input: list1 = g->e->e->k->s->a
       list2 = g->e->e->k->s->b
Output: -1

Input: list1 = g->e->e->k->s->a
       list2 = g->e->e->k->s
Output: 1

Input: list1 = g->e->e->k->s
       list2 = g->e->e->k->s
Output: 0

```cpp
// C++ program to compare two strings represented as linked
// lists
#include<bits/stdc++.h>
using namespace std;
  
// Linked list Node structure
struct Node
{
    char c;
    struct Node *next;
};
  
// Function to create newNode in a linkedlist
Node* newNode(char c)
{
    Node *temp = new Node;
    temp->c = c;
    temp->next = NULL;
    return temp;
};
 
int compare(Node *list1, Node *list2)
{   
    // Traverse both lists. Stop when either end of a linked
    // list is reached or current characters don't match
    while (list1 && list2 && list1->c == list2->c)
    {        
        list1 = list1->next;
        list2 = list2->next;
    }
     
    //  If both lists are not empty, compare mismatching
    //  characters
    if (list1 && list2)
        return (list1->c > list2->c)? 1: -1;
 
    // If either of the two lists has reached end
    if (list1 && !list2) return 1;
    if (list2 && !list1) return -1;
     
    // If none of the above conditions is true, both
    // lists have reached end
    return 0;
}
 
// Driver program
int main()
{
    Node *list1 = newNode('g');
    list1->next = newNode('e');
    list1->next->next = newNode('e');
    list1->next->next->next = newNode('k');
    list1->next->next->next->next = newNode('s');
    list1->next->next->next->next->next = newNode('b');
 
    Node *list2 = newNode('g');
    list2->next = newNode('e');
    list2->next->next = newNode('e');
    list2->next->next->next = newNode('k');
    list2->next->next->next->next = newNode('s');
    list2->next->next->next->next->next = newNode('a');
 
    cout << compare(list1, list2);
  
    return 0;
}

```


**Output:** 

1









----
# 4. Add Two Numbers Represented By Linked Lists
Given two numbers represented by two linked lists, write a function that returns the sum list. The sum list is linked list representation of the addition of two input numbers. It is not allowed to modify the lists. Also, not allowed to use explicit extra space (Hint: Use Recursion).

**Example** :
Input:
  First List: 5->6->3  
  Second List: 8->4->2 
Output
  Resultant list: 1->4->0->5


We have discussed a solution [here](https://www.geeksforgeeks.org/archives/15194) which is for linked lists where a least significant digit is the first node of lists and the most significant digit is the last node. In this problem, the most significant node is the first node and the least significant digit is the last node and we are not allowed to modify the lists. Recursion is used here to calculate sum from right to left.

Following are the steps.   
**1)** Calculate sizes of given two linked lists.   
**2)** If sizes are same, then calculate sum using recursion. Hold all nodes in recursion call stack till the rightmost node, calculate the sum of rightmost nodes and forward carry to the left side.   
**3)** If size is not same, then follow below steps:   
….**a)** Calculate difference of sizes of two linked lists. Let the difference be _diff_   
….**b)** Move _diff_ nodes ahead in the bigger linked list. Now use step 2 to calculate the sum of the smaller list and right sub-list (of the same size) of a larger list. Also, store the carry of this sum.   
….**c)** Calculate the sum of the carry (calculated in the previous step) with the remaining left sub-list of a larger list. Nodes of this sum are added at the beginning of the sum list obtained the previous step.

Below is a dry run of the above approach:

![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/20190628120906/AdditionOfTwoLinkedLists.png)


```cpp
// A C++ recursive program to add two linked lists
#include <bits/stdc++.h>
using namespace std;
 
// A linked List Node
class Node {
public:
    int data;
    Node* next;
};
 
typedef Node node;
 
/* A utility function to insert
a node at the beginning of linked list */
void push(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = new Node[(sizeof(Node))];
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
/* A utility function to print linked list */
void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}
 
// A utility function to swap two pointers
void swapPointer(Node** a, Node** b)
{
    node* t = *a;
    *a = *b;
    *b = t;
}
 
/* A utility function to get size of linked list */
int getSize(Node* node)
{
    int size = 0;
    while (node != NULL) {
        node = node->next;
        size++;
    }
    return size;
}
 
// Adds two linked lists of same size
// represented by head1 and head2 and returns
// head of the resultant linked list. Carry
// is propagated while returning from the recursion
node* addSameSize(Node* head1, Node* head2, int* carry)
{
    // Since the function assumes linked lists are of same
    // size, check any of the two head pointers
    if (head1 == NULL)
        return NULL;
 
    int sum;
 
    // Allocate memory for sum node of current two nodes
    Node* result = new Node[(sizeof(Node))];
 
    // Recursively add remaining nodes and get the carry
    result->next
        = addSameSize(head1->next, head2->next, carry);
 
    // add digits of current nodes and propagated carry
    sum = head1->data + head2->data + *carry;
    *carry = sum / 10;
    sum = sum % 10;
 
    // Assign the sum to current node of resultant list
    result->data = sum;
 
    return result;
}
 
// This function is called after the
// smaller list is added to the bigger
// lists's sublist of same size. Once the
// right sublist is added, the carry
// must be added toe left side of larger
// list to get the final result.
void addCarryToRemaining(Node* head1, Node* cur, int* carry,
                         Node** result)
{
    int sum;
 
    // If diff. number of nodes are not traversed, add carry
    if (head1 != cur) {
        addCarryToRemaining(head1->next, cur, carry,
                            result);
 
        sum = head1->data + *carry;
        *carry = sum / 10;
        sum %= 10;
 
        // add this node to the front of the result
        push(result, sum);
    }
}
 
// The main function that adds two linked lists
// represented by head1 and head2. The sum of
// two lists is stored in a list referred by result
void addList(Node* head1, Node* head2, Node** result)
{
    Node* cur;
 
    // first list is empty
    if (head1 == NULL) {
        *result = head2;
        return;
    }
 
    // second list is empty
    else if (head2 == NULL) {
        *result = head1;
        return;
    }
 
    int size1 = getSize(head1);
    int size2 = getSize(head2);
 
    int carry = 0;
 
    // Add same size lists
    if (size1 == size2)
        *result = addSameSize(head1, head2, &carry);
 
    else {
        int diff = abs(size1 - size2);
 
        // First list should always be larger than second
        // list. If not, swap pointers
        if (size1 < size2)
            swapPointer(&head1, &head2);
 
        // move diff. number of nodes in first list
        for (cur = head1; diff--; cur = cur->next)
            ;
 
        // get addition of same size lists
        *result = addSameSize(cur, head2, &carry);
 
        // get addition of remaining first list and carry
        addCarryToRemaining(head1, cur, &carry, result);
    }
 
    // if some carry is still there, add a new node to the
    // front of the result list. e.g. 999 and 87
    if (carry)
        push(result, carry);
}
 
// Driver code
int main()
{
    Node *head1 = NULL, *head2 = NULL, *result = NULL;
 
    int arr1[] = { 9, 9, 9 };
    int arr2[] = { 1, 8 };
 
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
 
    // Create first list as 9->9->9
    int i;
    for (i = size1 - 1; i >= 0; --i)
        push(&head1, arr1[i]);
 
    // Create second list as 1->8
    for (i = size2 - 1; i >= 0; --i)
        push(&head2, arr2[i]);
 
    addList(head1, head2, &result);
 
    printList(result);
 
    return 0;
}
```

**Output**

1 0 1 7

Time Complexity: O(m+n) where m and n are the sizes of given two linked lists.

**Iterative Approach:**

This implementation does not have any recursion call overhead, which means it is an iterative solution.

Since we need to start adding numbers from the last of the two linked lists. So, here we will use the stack data structure to implement this.

-   We will firstly make two stacks from the given two linked lists.
-   Then, we will run a loop till both the stack become empty.
-   in every iteration, we keep the track of the carry.
-   In the end, if carry>0, that means we need extra node at the start of the resultant list to accommodate this carry.


```cpp
// C++ Iterative program to add two linked lists 
#include <bits/stdc++.h>
using namespace std;
   
// A linked List Node 
class Node 
{ 
    public:
    int data; 
    Node* next; 
};
 
// to push a new node to linked list
void push(Node** head_ref, int new_data) 
{ 
    /* allocate node */
    Node* new_node = new Node[(sizeof(Node))]; 
   
    /* put in the data */
    new_node->data = new_data; 
   
    /* link the old list off the new node */
    new_node->next = (*head_ref); 
   
    /* move the head to point to the new node */
    (*head_ref) = new_node; 
}
 
// to add two new numbers
Node* addTwoNumList(Node* l1, Node* l2) {
    stack<int> s1,s2;
    while(l1!=NULL){
        s1.push(l1->data);
        l1=l1->next;
    }
    while(l2!=NULL){
        s2.push(l2->data);
        l2=l2->next;
    }
    int carry=0;
    Node* result=NULL;
    while(s1.empty()==false || s2.empty()==false){
        int a=0,b=0;
        if(s1.empty()==false){
            a=s1.top();s1.pop();
        }
        if(s2.empty()==false){
            b=s2.top();s2.pop();
        }
        int total=a+b+carry;
        Node* temp=new Node();
        temp->data=total%10;
        carry=total/10;
        if(result==NULL){
            result=temp;
        }else{
            temp->next=result;
            result=temp;
        }
    }
    if(carry!=0){
        Node* temp=new Node();
        temp->data=carry;
        temp->next=result;
        result=temp;
    }
    return result;
}
 
// to print a linked list
void printList(Node *node) 
{ 
    while (node != NULL) 
    { 
        cout<<node->data<<" "; 
        node = node->next; 
    } 
    cout<<endl; 
}
 
// Driver Code
int main() 
{ 
    Node *head1 = NULL, *head2 = NULL; 
   
    int arr1[] = {5, 6, 7}; 
    int arr2[] = {1, 8}; 
   
    int size1 = sizeof(arr1) / sizeof(arr1[0]); 
    int size2 = sizeof(arr2) / sizeof(arr2[0]); 
   
    // Create first list as 5->6->7 
    int i; 
    for (i = size1-1; i >= 0; --i) 
        push(&head1, arr1[i]); 
   
    // Create second list as 1->8 
    for (i = size2-1; i >= 0; --i) 
        push(&head2, arr2[i]); 
     
    Node* result=addTwoNumList(head1, head2);
    printList(result); 
   
    return 0; 
}

```


**Output**

5 8 5









----
# 5. Merge A Linked List Into Another Linked List At Alternate Positions
Given two linked lists, insert nodes of second list into first list at alternate positions of first list.   
For example, if first list is 5->7->17->13->11 and second is 12->10->2->4->6, the first list should become 5->12->7->10->17->2->13->4->11->6 and second list should become empty. The nodes of second list should only be inserted when there are positions available. For example, if the first list is 1->2->3 and second list is 4->5->6->7->8, then first list should become 1->4->2->5->3->6 and second list to 7->8.  
Use of extra space is not allowed (Not allowed to create additional nodes), i.e., insertion must be done in-place. Expected time complexity is O(n) where n is number of nodes in first list.

The idea is to run a loop while there are available positions in first loop and insert nodes of second list by changing pointers. Following are implementations of this approach.


```cpp
// C++ program to merge a linked list into another at
// alternate positions
#include <bits/stdc++.h>
using namespace std;
 
// A nexted list node
class Node
{
    public:
    int data;
    Node *next;
};
 
/* Function to insert a node at the beginning */
void push(Node ** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
 
/* Utility function to print a singly linked list */
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
 
// Main function that inserts nodes of linked list q into p at
// alternate positions. Since head of first list never changes
// and head of second list may change, we need single pointer
// for first list and double pointer for second list.
void merge(Node *p, Node **q)
{
    Node *p_curr = p, *q_curr = *q;
    Node *p_next, *q_next;
 
    // While therre are available positions in p
    while (p_curr != NULL && q_curr != NULL)
    {
        // Save next pointers
        p_next = p_curr->next;
        q_next = q_curr->next;
 
        // Make q_curr as next of p_curr
        q_curr->next = p_next; // Change next pointer of q_curr
        p_curr->next = q_curr; // Change next pointer of p_curr
 
        // Update current pointers for next iteration
        p_curr = p_next;
        q_curr = q_next;
    }
 
    *q = q_curr; // Update head pointer of second list
}
 
// Driver code
int main()
{
    Node *p = NULL, *q = NULL;
    push(&p, 3);
    push(&p, 2);
    push(&p, 1);
    cout<<"First Linked List:\n";
    printList(p);
 
    push(&q, 8);
    push(&q, 7);
    push(&q, 6);
    push(&q, 5);
    push(&q, 4);
    cout<<"Second Linked List:\n";
    printList(q);
 
    merge(p, &q);
 
    cout<<"Modified First Linked List:\n";
    printList(p);
 
    cout<<"Modified Second Linked List:\n";
    printList(q);
 
    return 0;
}
```


**Output:** 

First Linked List:
1 2 3
Second Linked List:
4 5 6 7 8
Modified First Linked List:
1 4 2 5 3 6
Modified Second Linked List:
7 8





----
# 6. Reverse A List In Groups Of Given Size

Given a linked list, write a function to reverse every k nodes (where k is an input to the function).

**Input**: 1->2->3->4->5->6->7->8->NULL, K = 3   
**Output**: 3->2->1->6->5->4->8->7->NULL   
**Input**: 1->2->3->4->5->6->7->8->NULL, K = 5   
**Output**: 5->4->3->2->1->8->7->6->NULL

**Algorithm**: [_reverse_](https://www.geeksforgeeks.org/reverse-a-linked-list/)_(head, k)_

-   Reverse the first sub-list of size k. While reversing keep track of the next node and previous node. Let the pointer to the next node be _next_ and pointer to the previous node be _prev_. See [this post](https://www.geeksforgeeks.org/reverse-a-linked-list/) for reversing a linked list.
-   _head->next = reverse(next, k)_ ( Recursively call for rest of the list and link the two sub-lists )
-   Return _prev_ ( _prev_ becomes the new head of the list (see the diagrams of an iterative method of [this post](https://www.geeksforgeeks.org/reverse-a-linked-list/) )

Below is image shows how the reverse function works: 

![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/20190624113820/ReverseALinkedListInAGroupofGivenSize1.png)

```cpp
// CPP program to reverse a linked list
// in groups of given size
#include <bits/stdc++.h>
using namespace std;
 
/* Link list node */
class Node {
public:
    int data;
    Node* next;
};
 
/* Reverses the linked list in groups
of size k and returns the pointer
to the new head node. */
Node* reverse(Node* head, int k)
{
    // base case
    if (!head)
        return NULL;
    Node* current = head;
    Node* next = NULL;
    Node* prev = NULL;
    int count = 0;
 
    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
 
    /* next is now a pointer to (k+1)th node
    Recursively call for the list starting from current.
    And make rest of the list as next of first node */
    if (next != NULL)
        head->next = reverse(next, k);
 
    /* prev is new head of the input list */
    return prev;
}
 
/* UTILITY FUNCTIONS */
/* Function to push a node */
void push(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = new Node();
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
/* Function to print linked list */
void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}
 
/* Driver code*/
int main()
{
    /* Start with the empty list */
    Node* head = NULL;
 
    /* Created Linked list
       is 1->2->3->4->5->6->7->8->9 */
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
 
    cout << "Given linked list \n";
    printList(head);
    head = reverse(head, 3);
 
    cout << "\nReversed Linked list \n";
    printList(head);
 
    return (0);
}
```

**Output:** 

Given Linked List
1 2 3 4 5 6 7 8 9 
Reversed list
3 2 1 6 5 4 9 8 7 

**Complexity Analysis:** 

-   **Time Complexity:** O(n).   
    Traversal of list is done only once and it has ‘n’ elements.
-   **Auxiliary Space:** O(n/k).   
    For each Linked List of size n, n/k or (n/k)+1 calls will be made during the recursion.

----
# 7. Union And Intersection Of 2 Linked Lists
Given two Linked Lists, create union and intersection lists that contain union and intersection of the elements present in the given lists. The order of elements in output lists doesn’t matter.  
**Example:**  
 

Input:
   List1: 10->15->4->20
   List2:  8->4->2->10
Output:
   Intersection List: 4->10
   Union List: 2->8->20->4->15->10

**Method 1 (Simple)**  
The following are simple algorithms to get union and intersection lists respectively.  
_Intersection (list1, list2)_  
Initialize the result list as NULL. Traverse list1 and look for every element in list2, if the element is present in list2, then add the element to the result.  
_Union (list1, list2):_  
Initialize the result list as NULL. Traverse list1 and add all of its elements to the result.  
Traverse list2. If an element of list2 is already present in the result then do not insert it to the result, otherwise insert.  
This method assumes that there are no duplicates in the given lists.

```cpp
// C++ program to find union
// and intersection of two unsorted
// linked lists
#include <iostream>
using namespace std;
 
/* Link list node */
struct Node {
    int data;
    struct Node* next;
};
 
/* A utility function to insert a
node at the beginning ofa linked list*/
void push(struct Node** head_ref, int new_data);
 
/* A utility function to check if
given data is present in a list */
bool isPresent(struct Node* head, int data);
 
/* Function to get union of two
linked lists head1 and head2 */
struct Node* getUnion(
    struct Node* head1,
    struct Node* head2)
{
    struct Node* result = NULL;
    struct Node *t1 = head1, *t2 = head2;
 
    // Insert all elements of
    // list1 to the result list
    while (t1 != NULL) {
        push(&result, t1->data);
        t1 = t1->next;
    }
 
    // Insert those elements of list2
    // which are not present in result list
    while (t2 != NULL) {
        if (!isPresent(result, t2->data))
            push(&result, t2->data);
        t2 = t2->next;
    }
    return result;
}
 
/* Function to get intersection of
two linked lists head1 and head2 */
struct Node* getIntersection(struct Node* head1,
                            struct Node* head2)
{
    struct Node* result = NULL;
    struct Node* t1 = head1;
 
    // Traverse list1 and search each element of it in
    // list2. If the element is present in list 2, then
    // insert the element to result
    while (t1 != NULL) {
        if (isPresent(head2, t1->data))
            push(&result, t1->data);
        t1 = t1->next;
    }
    return result;
}
 
/* A utility function to insert a
node at the beginning of a linked list*/
void push(struct Node** head_ref, int new_data)
{
   
    /* allocate node */
    struct Node* new_node
        = (struct Node*)malloc(
            sizeof(struct Node));
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
/* A utility function to print a linked list*/
void printList(struct Node* node)
{
    while (node != NULL) {
        cout << " " << node->data;
        node = node->next;
    }
}
 
/* A utility function that returns true if data is
present in linked list else return false */
bool isPresent(struct Node* head, int data)
{
    struct Node* t = head;
    while (t != NULL) {
        if (t->data == data)
            return 1;
        t = t->next;
    }
    return 0;
}
 
/* Driver program to test above function*/
int main()
{
   
    /* Start with the empty list */
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    struct Node* intersecn = NULL;
    struct Node* unin = NULL;
 
    /*create a linked lits 10->15->5->20 */
    push(&head1, 20);
    push(&head1, 4);
    push(&head1, 15);
    push(&head1, 10);
 
    /*create a linked lits 8->4->2->10 */
    push(&head2, 10);
    push(&head2, 2);
    push(&head2, 4);
    push(&head2, 8);
    intersecn = getIntersection(head1, head2);
    unin = getUnion(head1, head2);
    cout << "\n First list is " << endl;
    printList(head1);
    cout << "\n Second list is " << endl;
    printList(head2);
    cout << "\n Intersection list is " << endl;
    printList(intersecn);
    cout << "\n Union list is " << endl;
    printList(unin);
    return 0;
}
```
**Output**

 First list is 
10 15 4 20 
 Second list is 
8 4 2 10 
 Intersection list is 
4 10 
 Union list is 
2 8 20 4 15 10

 **Complexity Analysis:**  
 

-   **Time Complexity:** O(m*n).  
    Here ‘m’ and ‘n’ are number of elements present in the first and second lists respectively.   
    **For union:** For every element in list-2 we check if that element is already present in the resultant list made using list-1.  
    **For intersection:** For every element in list-1 we check if that element is also present in list-2.
-   **Auxiliary Space:** O(1).   
    No use of any data structure for storing values.

**Method 2 (Use Merge Sort)**  
In this method, algorithms for Union and Intersection are very similar. First, we sort the given lists, then we traverse the sorted lists to get union and intersection.   
The following are the steps to be followed to get union and intersection lists.  
 

1.  Sort the first Linked List using merge sort. This step takes O(mLogm) time. Refer [this post](https://www.geeksforgeeks.org/archives/7740) for details of this step.
2.  Sort the second Linked List using merge sort. This step takes O(nLogn) time. Refer [this post](https://www.geeksforgeeks.org/archives/7740) for details of this step.
3.  Linearly scan both sorted lists to get the union and intersection. This step takes O(m + n) time. This step can be implemented using the same algorithm as sorted arrays algorithm discussed [here](https://www.geeksforgeeks.org/archives/6873).

The time complexity of this method is O(mLogm + nLogn) which is better than method 1’s time complexity.

**Method 3 (Use Hashing)**  
_Union (list1, list2)_  
Initialize the result list as NULL and create an empty hash table. Traverse both lists one by one, for each element being visited, look at the element in the hash table. If the element is not present, then insert the element into the result list. If the element is present, then ignore it.  
_Intersection (list1, list2)_  
Initialize the result list as NULL and create an empty hash table. Traverse list1. For each element being visited in list1, insert the element in the hash table. Traverse list2, for each element being visited in list2, look the element in the hash table. If the element is present, then insert the element to the result list. If the element is not present, then ignore it.  
Both of the above methods assume that there are no duplicates.

**Complexity Analysis:**  
 

-   **Time Complexity:** O(m+n).  
    Here ‘m’ and ‘n’ are number of elements present in the first and second lists respectively.   
    **For union:** Traverse both the lists, store the elements in Hash-map and update the respective count.  
    **For intersection:** First traverse list-1, store its elements in Hash-map and then for every element in list-2 check if it is already present in the map. This takes O(1) time.
-   **Auxiliary Space:**O(m+n).  
    Use of Hash-map data structure for storing values.






----
# 8. Detect And Remove Loop In A Linked List
Write a function _detectAndRemoveLoop()_ that checks whether a given Linked List contains loop and if loop is present then removes the loop and returns true. If the list doesn’t contain loop then it returns false. Below diagram shows a linked list with a loop. _detectAndRemoveLoop()_ must change the below list to 1->2->3->4->5->NULL.

![](https://www.geeksforgeeks.org/wp-content/uploads/2009/04/Linked-List-Loop.gif)

We also recommend to read following post as a prerequisite of the solution discussed here.   
[Write a C function to detect loop in a linked list](https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/)  
Before trying to remove the loop, we must detect it. Techniques discussed in the above post can be used to detect loop. To remove loop, all we need to do is to get pointer to the last node of the loop. For example, node with value 5 in the above diagram. Once we have pointer to the last node, we can make the next of this node as NULL and loop is gone.   
We can easily use Hashing or Visited node techniques (discussed in the above mentioned post) to get the pointer to the last node. Idea is simple: the very first node whose next is already visited (or hashed) is the last node.   
We can also use [Floyd Cycle Detection](https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/) algorithm to detect and remove the loop. In the Floyd’s algo, the slow and fast pointers meet at a loop node. We can use this loop node to remove cycle. There are following two different ways of removing loop when Floyd’s algorithm is used for Loop detection.

**Method 1 (Check one by one)** We know that Floyd’s Cycle detection algorithm terminates when fast and slow pointers meet at a common point. We also know that this common point is one of the loop nodes (2 or 3 or 4 or 5 in the above diagram). Store the address of this in a pointer variable say ptr2. After that start from the head of the Linked List and check for nodes one by one if they are reachable from ptr2. Whenever we find a node that is reachable, we know that this node is the starting node of the loop in Linked List and we can get the pointer to the previous of this node.

**Output:**

Linked List after removing loop 
50 20 15 4 10 

**Method 2 (Better Solution)**  

1.  This method is also dependent on Floyd’s Cycle detection algorithm.
2.  Detect Loop using Floyd’s Cycle detection algorithm and get the pointer to a loop node.
3.  Count the number of nodes in loop. Let the count be k.
4.  Fix one pointer to the head and another to a kth node from the head.
5.  Move both pointers at the same pace, they will meet at loop starting node.
6.  Get a pointer to the last node of the loop and make next of it as NULL.

Below image is a dry run of ‘remove loop’ function in the code : 

![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/20190624115857/RemoveLoopInLinkedList.png)

Below is the implementation of the above approach:

```cpp
#include <bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct Node {
    int data;
    struct Node* next;
};
 
/* Function to remove loop. */
void removeLoop(struct Node*, struct Node*);
 
/* This function detects and removes loop in the list
  If loop was there in the list then it returns 1,
  otherwise returns 0 */
int detectAndRemoveLoop(struct Node* list)
{
    struct Node *slow_p = list, *fast_p = list;
 
    // Iterate and find if loop exists or not
    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
 
        /* If slow_p and fast_p meet at some point then there
           is a loop */
        if (slow_p == fast_p) {
            removeLoop(slow_p, list);
 
            /* Return 1 to indicate that loop is found */
            return 1;
        }
    }
 
    /* Return 0 to indicate that there is no loop*/
    return 0;
}
 
/* Function to remove loop.
 loop_node --> Pointer to one of the loop nodes
 head -->  Pointer to the start node of the linked list */
void removeLoop(struct Node* loop_node, struct Node* head)
{
    struct Node* ptr1 = loop_node;
    struct Node* ptr2 = loop_node;
 
    // Count the number of nodes in loop
    unsigned int k = 1, i;
    while (ptr1->next != ptr2) {
        ptr1 = ptr1->next;
        k++;
    }
 
    // Fix one pointer to head
    ptr1 = head;
 
    // And the other pointer to k nodes after head
    ptr2 = head;
    for (i = 0; i < k; i++)
        ptr2 = ptr2->next;
 
    /*  Move both pointers at the same pace,
      they will meet at loop starting node */
    while (ptr2 != ptr1) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
 
    // Get pointer to the last node
    while (ptr2->next != ptr1)
        ptr2 = ptr2->next;
 
    /* Set the next node of the loop ending node
      to fix the loop */
    ptr2->next = NULL;
}
 
/* Function to print linked list */
void printList(struct Node* node)
{
    // Print the list after loop removal
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}
 
struct Node* newNode(int key)
{
    struct Node* temp = new Node();
    temp->data = key;
    temp->next = NULL;
    return temp;
}
 
// Driver Code
int main()
{
    struct Node* head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
 
    detectAndRemoveLoop(head);
 
    cout << "Linked List after removing loop \n";
    printList(head);
    return 0;
}
```

**Output:** 

Linked List after removing loop 
50 20 15 4 10 

**Method 3 (Optimized Method 2: Without Counting Nodes in Loop)**   
We do not need to count number of nodes in Loop. After detecting the loop, if we start slow pointer from head and move both slow and fast pointers at same speed until fast don’t meet, they would meet at the beginning of the loop.

**How does this work?**   
Let slow and fast meet at some point after Floyd’s Cycle finding algorithm. Below diagram shows the situation when cycle is found.
  
![LinkedListCycle](http://www.geeksforgeeks.org/wp-content/uploads/LinkedListCycle.jpg)

We can conclude below from above diagram 

Distance traveled by fast pointer = 2 * (Distance traveled 
                                         by slow pointer)

(m + n*x + k) = 2*(m + n*y + k)

Note that before meeting the point shown above, fast
was moving at twice speed.

x -->  Number of complete cyclic rounds made by 
       fast pointer before they meet first time

y -->  Number of complete cyclic rounds made by 
       slow pointer before they meet first time

From above equation, we can conclude below 

    m + k = (x-2y)*n

Which means **m+k is a multiple of n**. 
Thus we can write, m + k = i*n or **m = i*n - k**.
Hence, distance moved by slow pointer: m, is equal to distance moved by fast pointer:
i*n - k or (i-1)*n + n - k (cover the loop completely i-1 times and start from n-k).

So if we start moving both pointers again at **same speed** such that one pointer (say slow) begins from head node of linked list and other pointer (say fast) begins from meeting point. When slow pointer reaches beginning of loop (has made m steps), fast pointer would have made also moved m steps as they are now moving same pace. Since m+k is a multiple of n and fast starts from k, they would meet at the beginning. Can they meet before also? No because slow pointer enters the cycle first time after m steps.

```cpp
// C++ program to detect and remove loop
#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int key;
    struct Node* next;
};
 
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->next = NULL;
    return temp;
}
 
// A utility function to print a linked list
void printList(Node* head)
{
    while (head != NULL) {
        cout << head->key << " ";
        head = head->next;
    }
    cout << endl;
}
 
// Function to detect and remove loop
// in a linked list that may contain loop
void detectAndRemoveLoop(Node* head)
{
    // If list is empty or has only one node
    // without loop
    if (head == NULL || head->next == NULL)
        return;
 
    Node *slow = head, *fast = head;
 
    // Move slow and fast 1 and 2 steps
    // ahead respectively.
    slow = slow->next;
    fast = fast->next->next;
 
    // Search for loop using slow and
    // fast pointers
    while (fast && fast->next) {
        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }
 
    /* If loop exists */
    if (slow == fast)
    {
        slow = head;
           
        // this check is needed when slow
        // and fast both meet at the head of the LL
          // eg: 1->2->3->4->5 and then
        // 5->next = 1 i.e the head of the LL
          if(slow == fast) {
              while(fast->next != slow) fast = fast->next;
        }
          else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }
 
        /* since fast->next is the looping point */
        fast->next = NULL; /* remove loop */
    }
}
 
/* Driver program to test above function*/
int main()
{
    Node* head = newNode(50);
    head->next = head;
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head;
 
    detectAndRemoveLoop(head);
 
    printf("Linked List after removing loop \n");
    printList(head);
 
    return 0;
}
```

**Output:**

Linked List after removing loop 
50 20 15 4 10 

**Method 4 Hashing: Hash the address of the linked list nodes**   
We can hash the addresses of the linked list nodes in an unordered map and just check if the element already exists in the map. If it exists, we have reached a node which already exists by a cycle, hence we need to make the last node’s next pointer NULL.

```cpp
// C++ program to detect and remove loop
#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int key;
    struct Node* next;
};
 
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->next = NULL;
    return temp;
}
 
// A utility function to print a linked list
void printList(Node* head)
{
    while (head != NULL) {
        cout << head->key << " ";
        head = head->next;
    }
    cout << endl;
}
 
// Function to detect and remove loop
// in a linked list that may contain loop
void hashAndRemove(Node* head)
{
    // hash map to hash addresses of the linked list nodes
    unordered_map<Node*, int> node_map;
    // pointer to last node
    Node* last = NULL;
    while (head != NULL) {
        // if node not present in the map, insert it in the map
        if (node_map.find(head) == node_map.end()) {
            node_map[head]++;
            last = head;
            head = head->next;
        }
        // if present, it is a cycle, make the last node's next pointer NULL
        else {
            last->next = NULL;
            break;
        }
    }
}
/* Driver program to test above function*/
int main()
{
    Node* head = newNode(50);
    head->next = head;
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
 
    // printList(head);
    hashAndRemove(head);
 
    printf("Linked List after removing loop \n");
    printList(head);
 
    return 0;
}

```
**Output**

Linked List after removing loop 
50 20 15 4 10



----
# 9. Merge Sort For Linked Lists
[Merge sort](http://en.wikipedia.org/wiki/Merge_sort) is often preferred for sorting a linked list. The slow random-access performance of a linked list makes some other algorithms (such as quicksort) perform poorly, and others (such as heapsort) completely impossible. 

![sorting image](https://media.geeksforgeeks.org/wp-content/cdn-uploads/Sort-Linked-List-768x384.png)
Let the head be the first node of the linked list to be sorted and headRef be the pointer to head. Note that we need a reference to head in MergeSort() as the below implementation changes next links to sort the linked lists (not data at the nodes), so the head node has to be changed if the data at the original head is not the smallest value in the linked list.


MergeSort(headRef)
1) If the head is NULL or there is only one element in the Linked List 
    then return.
2) Else divide the linked list into two halves.  
      FrontBackSplit(head, &a, &b); /* a and b are two halves */
3) Sort the two halves a and b.
      MergeSort(a);
      MergeSort(b);
4) Merge the sorted a and b (using SortedMerge() discussed [here](https://www.geeksforgeeks.org/merge-two-sorted-linked-lists/)) 
   and update the head pointer using headRef.
     *headRef = SortedMerge(a, b);


```cpp
// C++ code for linked list merged sort
#include <bits/stdc++.h>
using namespace std;
 
/* Link list node */
class Node {
public:
    int data;
    Node* next;
};
 
/* function prototypes */
Node* SortedMerge(Node* a, Node* b);
void FrontBackSplit(Node* source,
                    Node** frontRef, Node** backRef);
 
/* sorts the linked list by changing next pointers (not data) */
void MergeSort(Node** headRef)
{
    Node* head = *headRef;
    Node* a;
    Node* b;
 
    /* Base case -- length 0 or 1 */
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
 
    /* Split head into 'a' and 'b' sublists */
    FrontBackSplit(head, &a, &b);
 
    /* Recursively sort the sublists */
    MergeSort(&a);
    MergeSort(&b);
 
    /* answer = merge the two sorted lists together */
    *headRef = SortedMerge(a, b);
}
 
/* See https:// www.geeksforgeeks.org/?p=3622 for details of this
function */
Node* SortedMerge(Node* a, Node* b)
{
    Node* result = NULL;
 
    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
 
    /* Pick either a or b, and recur */
    if (a->data <= b->data) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}
 
/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back halves,
    and return the two lists using the reference parameters.
    If the length is odd, the extra node should go in the front list.
    Uses the fast/slow pointer strategy. */
void FrontBackSplit(Node* source,
                    Node** frontRef, Node** backRef)
{
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;
 
    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
 
    /* 'slow' is before the midpoint in the list, so split it in two
    at that point. */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}
 
/* Function to print nodes in a given linked list */
void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}
 
/* Function to insert a node at the beginning of the linked list */
void push(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = new Node();
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
/* Driver program to test above functions*/
int main()
{
    /* Start with the empty list */
    Node* res = NULL;
    Node* a = NULL;
 
    /* Let us create a unsorted linked lists to test the functions
Created lists shall be a: 2->3->20->5->10->15 */
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    push(&a, 20);
    push(&a, 3);
    push(&a, 2);
 
    /* Sort the above created Linked List */
    MergeSort(&a);
 
    cout << "Sorted Linked List is: \n";
    printList(a);
 
    return 0;
}

```

**Output:** 

Sorted Linked List is: 
2 3 5 10 15 20

**Time Complexity:** O(n*log n)

**Space Complexity:** O(n*log n)

**Approach 2:** This approach is simpler and uses log n space.

mergeSort():

1.  If the size of the linked list is 1 then return the head
2.  Find mid using The Tortoise and The Hare Approach
3.  Store the next of mid in head2 i.e. the right sub-linked list.
4.  Now Make the next midpoint null.
5.  Recursively call mergeSort() on both left and right sub-linked list and store the new head of the left and right linked list.
6.  Call merge() given the arguments new heads of left and right sub-linked lists and store the final head returned after merging.
7.  Return the final head of the merged linkedlist.

merge(head1, head2):

1.  Take a pointer say merged to store the merged list in it and store a dummy node in it.
2.  Take a pointer temp and assign merge to it.
3.  If the data of head1 is less than the data of head2, then, store head1 in next of temp & move head1 to the next of head1.
4.  Else store head2 in next of temp & move head2 to the next of head2.
5.  Move temp to the next of temp.
6.  Repeat steps 3, 4 & 5 until head1 is not equal to null and head2 is not equal to null.
7.  Now add any remaining nodes of the first or the second linked list to the merged linked list.
8.  Return the next of merged(that will ignore the dummy and return the head of the final merged linked list)

```cpp
#include<iostream>
using namespace std;
 
//Node structure
struct Node{
    int data;
    Node *next;
};
 
//function to insert in list
void insert(int x,Node **head) {
    if(*head == NULL){
        *head = new Node;
        (*head)->data = x;
        (*head)->next = NULL;
        return;
    }
    Node *temp = new Node;
    temp->data = (*head)->data;
    temp->next = (*head)->next;
    (*head)->data=x;
    (*head)->next=temp;
}
 
//function to print the list
void print(Node *head) {
    Node *temp=head;
    while(temp!=NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
 
Node *merge(Node *firstNode,Node *secondNode) {
    Node *merged = new Node;
    Node *temp = new Node;
    
    //merged is equal to temp so in the end we have the top Node.
    merged = temp;
 
    //while either firstNode or secondNode becomes NULL
    while(firstNode != NULL && secondNode != NULL) {
     
        if(firstNode->data<=secondNode->data) {
            temp->next = firstNode;
            firstNode = firstNode->next;
        }
         
        else {
            temp->next = secondNode;
            secondNode = secondNode->next;
        }
        temp = temp->next;
    }
    
   //any remaining Node in firstNode or secondNode gets inserted in the temp List
    while(firstNode!=NULL) {
        temp->next = firstNode;
        firstNode = firstNode->next;
        temp = temp->next;
    }
 
    while(secondNode!=NULL) {
        temp->next = secondNode;
        secondNode = secondNode->next;
        temp = temp->next;
    }
    //return the head of the sorted list
    return merged->next;
}
 
//function to calculate the middle Element
Node *middle(Node *head) {
    Node *slow = head;
    Node *fast = head->next;
    
    while(slow->next != NULL && (fast!=NULL && fast->next!=NULL)) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
 
//function to sort the given list
Node *sort(Node *head){
     
    if(head->next == NULL) {
        return head;
    }
 
    Node *mid = new Node;
    Node *head2 = new Node;
    mid = middle(head);
    head2 = mid->next;  
    mid->next = NULL;
    //recursive call to sort() hence diving our problem, and then merging the solution
    Node *finalhead = merge(sort(head),sort(head2)); 
    return finalhead;
}
int main(void) {
    Node *head = NULL;
    int n[]={7,10,5,20,3,2};
    for(int i=0;i<6;i++) {
        insert(n[i],&head);   //inserting in the list
    }
  cout<<"\nSorted Linked List is: \n";
    print(sort(head));     //printing the sorted list returned by sort()
    return 0;
}
```
**Output:**

Sorted Linked List is: 
2 3 5 7 10 20 

**Time Complexity**: O(n*log n)

**Space Complexity:** O(log n)




----
# 10. Select A Random Node from A Singly Linked List

Given a singly linked list, select a random node from linked list (the probability of picking a node should be 1/N if there are N nodes in list). You are given a random number generator.  
Below is a Simple Solution   
1) Count number of nodes by traversing the list.   
2) Traverse the list again and select every node with probability 1/N. The selection can be done by generating a random number from 0 to N-i for i’th node, and selecting the i’th node only if generated number is equal to 0 (or any other fixed number from 0 to N-i).   
We get uniform probabilities with above schemes. 

i = 1, probability of selecting first node = 1/N
i = 2, probability of selecting second node =
                   [probability that first node is not selected] * 
                   [probability that second node is selected]
                  = ((N-1)/N)* 1/(N-1)
                  = 1/N  

Similarly, probabilities of other selecting other nodes is 1/N  
The above solution requires two traversals of linked list.   
**How to select a random node with only one traversal allowed?**   
The idea is to use [Reservoir Sampling](https://www.geeksforgeeks.org/reservoir-sampling/). Following are the steps. This is a simpler version of [Reservoir Sampling](https://www.geeksforgeeks.org/reservoir-sampling/) as we need to select only one key instead of k keys.

(1) Initialize result as first node
   result = head->key 
(2) Initialize n = 2
(3) Now one by one consider all nodes from 2nd node onward.
    (3.a) Generate a random number from 0 to n-1. 
         Let the generated random number is j.
    (3.b) If j is equal to 0 (we could choose other fixed number 
          between 0 to n-1), then replace result with current node.
    (3.c) n = n+1
    (3.d) current = current->next

Below is the implementation of above algorithm.

```cpp
/* C++ program to randomly select a node from a singly
linked list */
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<iostream>
using namespace std;
 
/* Link list node */
class Node
{
    public:
    int key;
    Node* next;
    void printRandom(Node*);
    void push(Node**, int);
     
};
 
// A reservoir sampling based function to print a
// random node from a linked list
void Node::printRandom(Node *head)
{
    // IF list is empty
    if (head == NULL)
    return;
 
    // Use a different seed value so that we don't get
    // same result each time we run this program
    srand(time(NULL));
 
    // Initialize result as first node
    int result = head->key;
 
    // Iterate from the (k+1)th element to nth element
    Node *current = head;
    int n;
    for (n = 2; current != NULL; n++)
    {
        // change result with probability 1/n
        if (rand() % n == 0)
        result = current->key;
 
        // Move to next node
        current = current->next;
    }
 
    cout<<"Randomly selected key is \n"<< result;
}
 
/* BELOW FUNCTIONS ARE JUST UTILITY TO TEST */
 
/* A utility function to create a new node */
Node* newNode(int new_key)
{
    // allocate node
    Node* new_node = (Node*) malloc(sizeof( Node));
 
    /// put in the key
    new_node->key = new_key;
    new_node->next = NULL;
 
    return new_node;
}
 
/* A utility function to insert a node at the beginning
of linked list */
void Node:: push(Node** head_ref, int new_key)
{
    /* allocate node */
    Node* new_node = new Node;
 
    /* put in the key */
    new_node->key = new_key;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
// Driver program to test above functions
int main()
{
    Node n1;
    Node *head = NULL;
    n1.push(&head, 5);
    n1.push(&head, 20);
    n1.push(&head, 4);
    n1.push(&head, 3);
    n1.push(&head, 30);
 
    n1.printRandom(head);
 
    return 0;
}
```
Note that the above program is based on outcome of a random function and may produce different output.  
**How does this work?**   
Let there be total N nodes in list. It is easier to understand from last node.  
The probability that last node is result simply 1/N [For last or N’th node, we generate a random number between 0 to N-1 and make last node as result if the generated number is 0 (or any other fixed number]  
The probability that second last node is result should also be 1/N.   
 

The probability that the second last node is result 
          = [Probability that the second last node replaces result] X 
            [Probability that the last node doesn't replace the result] 
          = [1 / (N-1)] * [(N-1)/N]
          = 1/N

Similarly, we can show probability for 3rd last node and other nodes.


















----