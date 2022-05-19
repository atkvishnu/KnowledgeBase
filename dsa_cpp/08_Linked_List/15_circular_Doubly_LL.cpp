#include <iostream>

using namespace std;

struct Node {
    Node * prev;
    int data;
    Node * next;
}* head = NULL;

void Create(Node * p, int A[], int n) {
    Node * t;
    Node * last = new Node;
    head = new Node;

    head -> data = A[0];
    head -> prev = head;
    head -> next = head;
    last = head;

    for (int i = 1; i < n; i++) {
        t = new Node;
        t -> data = A[i];
        t -> prev = last;
        t -> next = head;
        last -> next = t;
        last = t;
    }
    head -> prev = last;
}

void Display(Node * p) {
    do {
        cout << p -> data << "->";
        p = p -> next;
    } while (p != head);

    cout << endl;
}

int Length(Node * p) {
    int len = 0;
    if (p == NULL)
        return len;
    do {
        len++;
        p = p -> next;
    } while (p != head);
    return len;
}

void Insert(Node * p, int index, int x) {
    if (index < 0 || index > Length(p))
        return;

    Node * t = new Node;
    if (index == 0) {
        t -> data = x;
        if (head == NULL) {
            t -> next = t;
            t -> prev = t;
            head = t;
        } else {
            t -> prev = head -> prev;
            head -> prev -> next = t;
            t -> next = head;
            head -> prev = t;
            head = t;
        }
    } else {
        t -> data = x;
        for (int i = 0; i < index - 1; i++) {
            p = p -> next;
        }
        t -> next = p -> next;
        p -> next = t;
        t -> next -> prev = t;
        t -> prev = p;
    }
}

int Delete(Node * p, int index) {
    int x = -1;
    if (index < 1 || index >= Length(p))
        return x;

    if (index == 1) {
        x = p -> data;
        p = p -> next;
        if (p == head) {
            delete p;
            head = NULL;
        } else {
            p -> prev = head -> prev;
            head -> prev -> next = p;
            delete head;
            head = p;
        }
    } else {
        Node * q = new Node;
        for (int i = 0; i < index - 1; i++) {
            q = p;
            p = p -> next;
        }
        x = p -> data;
        q -> next = p -> next;
        p -> next -> prev = q;
        delete p;
    }
    return x;
}

void Append(Node * p, int x) {
    Node * last = new Node;
    if (head == NULL) {
        head -> data = x;
        head -> next = head;
        head -> prev = head;
        last = head;
    } else {
        last = head -> prev;
        Node * t = new Node;
        t -> data = x;
        t -> next = head;
        t -> prev = last;
        last -> next = t;
        last = t;
        head -> prev = last;
    }
}

void SortedInsertion(Node * p, int x) {
    Node * t = new Node;
    t -> data = x;

    // checking if linked list is empty or not
    if (head == NULL) {
        t -> next = t;
        t -> prev = t;
        head = t;
    }

    // checking this condtition
    // because if  length is one 
    // then p->next == head always and this will
    // false main condition and didn't 
    // insert element at last or begin
    // so we handle this situation differently
    else if (Length(head) == 1) {
        t -> next = p;
        t -> prev = p;
        p -> prev = t;
        p -> next = t;
        if (p -> data > x)
            head = t;
    } else {
        Node * q = NULL;
        while (p -> data < x && p -> next != head) {
            q = p;
            p = p -> next;
        }

        // this is the condition when the element is inserted at last
        if (p -> data < x) {
            t -> next = p -> next;
            t -> prev = p;
            p -> next = t;
            t -> next -> prev = t;
        }

        // condition when element is inserted at the begining
        else if (q == NULL) {
            t -> next = p;
            t -> prev = p -> prev;
            t -> prev -> next = t;
            p -> prev = t;
            head = t;
        }

        // condition when element is inserted any position 
        // neither at last nor at begin 
        else {
            t -> next = p;
            t -> prev = q;
            p -> prev = t;
            q -> next = t;

        }
    }
}

int main() {

    // Checking my all functions working fine or not!!

    int A[] = {2,5,8,11};
    Create(head, A, 4);
    cout << head << endl;
    cout << head -> next << endl;
    Display(head);

    Insert(head, 2, 67);
    Display(head);

    cout << Delete(head, 4) << endl;
    Display(head);

    Append(head, 4);
    Append(head, 12);
    Display(head);
    Append(head, 18);
    Display(head);

    SortedInsertion(head, 4);
    cout << Length(head) << endl;
    Display(head);
    SortedInsertion(head, 9);
    SortedInsertion(head, 1);
    SortedInsertion(head, 5);
    SortedInsertion(head, 12);
    SortedInsertion(head, 8);
    SortedInsertion(head, 4);

    Display(head);
    SortedInsertion(head, 0);
    Display(head);

    return 0;
}