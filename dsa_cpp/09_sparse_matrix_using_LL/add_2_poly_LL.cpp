#include <bits/stdc++.h>
#include<math.h>

using namespace std;

class node {
    public:
        int coeff;
    int ex;
    node * next;
};

class poly {
    private:
        node * p, * q, * r;
    public:
        poly();
    void insert1();
    void insert2();
    void display1();
    void display2();
    void answer(int x);
    void add();
    void display3();
}a;

poly::poly() {
    p = NULL;
    q = NULL;
    r = NULL;
}

void poly::insert1() {
    node * t, * last;
    int x;
    cout << "no.of elements";
    cin >> x;
    cout << "enter coeff and exp";
    for (int i = 0; i < x; i++) {
        t = new node;
        cin >> t -> coeff >> t -> ex;
        t -> next = NULL;
        if (p == NULL) {
            p = last = t;
        } else {
            last -> next = t;
            last = t;
        }
    }
}

void poly::insert2() {
    node * t, * last;
    int x;
    cout << "no.of elements";
    cin >> x;
    cout << "enter coeff and exp";
    for (int i = 0; i < x; i++) {
        t = new node;
        cin >> t -> coeff >> t -> ex;
        t -> next = NULL;
        if (q == NULL) {
            q = last = t;
        } else {
            last -> next = t;
            last = t;
        }
    }
}

void poly::display1() {
    node * p = this -> p; //changes Here
    while (p) {
        printf("%dx%d+", p -> coeff, p -> ex);
        p = p -> next;
    }
    cout << endl;
}

void poly::display2() {
    node * q = this -> q; //changes here
    while (q) {
        printf("%dx%d+", q -> coeff, q -> ex);
        q = q -> next;
    }
    cout << endl;

}

void poly::add() {
    node * p = this -> p; //changes here
    node * q = this -> q;
    node * t, * last;
    while (p != NULL && q != NULL) {
        if (p -> ex > q -> ex) {
            t = new node;
            t -> coeff = p -> coeff;
            t -> ex = p -> ex;
            p = p -> next;
            t -> next = NULL;
            if (r == NULL) r = last = t;
            else {
                last -> next = t;
                last = t;
            }
        } else if (p -> ex < q -> ex) {
            t = new node;
            t -> coeff = q -> coeff;
            t -> ex = q -> ex;
            q = q -> next;
            t -> next = NULL;
            if (r == NULL) r = last = t;
            else {
                last -> next = t;
                last = t;
            }
        }

        if (p -> ex == q -> ex) {
            t = new node;
            t -> coeff = p -> coeff + q -> coeff;
            t -> ex = p -> ex; //logical error
            p = p -> next;
            q = q -> next;
            t -> next = NULL;
            if (r == NULL) r = last = t;
            else {
                last -> next = t;
                last = t;
            }
        }
    }
    if (p) { //further logic added
        while (p) {
            t = new node;
            t -> coeff = p -> coeff;
            t -> ex = p -> ex;
            t -> next = NULL;

            if (r == NULL) {
                r = last = t;
            } else {
                last -> next = t;
                last = t;
            }
            p = p -> next;
        }
    }

    if (q) {
        while (q) {
            t = new node;
            t -> coeff = q -> coeff;
            t -> ex = q -> ex;
            t -> next = NULL;
            if (r == NULL) {
                r = last = t;
            } else {
                last -> next = t;
                last = t;
            }
            q = q -> next;
        }
    }
}



void poly::display3() {
    node * r = this -> r; //changes
    while (r) {
        printf("%dx%d+", r -> coeff, r -> ex);
        r = r -> next;
    }
    cout << endl;
}

int main() {
    a.insert1();
    a.display1();
    a.insert2();
    a.display2();
    a.add();
    a.display3();
}