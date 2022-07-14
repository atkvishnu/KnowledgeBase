#include <iostream>

using namespace std;

class Sym{
    public:
        int n;
    int * s;
    Sym() {
        n = 2;
        s = new int[2 * (2 + 1) / 2];
    }

    Sym(int n) {
            this -> n = n;
            s = new int[n * (n + 1) / 2];
        }
        ~Sym() {
            delete[] s;
        }
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
    int getdimension() {
        return n;
    }

};

void Sym::set(int i, int j, int x) {

    if (i <= j) {
        s[j * (j - 1) / 2 + i - 1] = x; //changes as formula you were using was storing is wrong way
    } else if (i > j) {
        s[i * (i - 1) / 2 + j - 1] = x;
    }
}

int Sym::get(int i, int j) {

    if (i <= j) {
        cout << s[j * (j - 1) / 2 + i - 1] << endl; //changes
    } else if (i > j) {
        cout << s[i * (i - 1) / 2 + j - 1];
    }
}

void Sym::display() {

    int i, j;

    for (i = 1; i <= n; i++) { //changes
        for (j = 1; j <= n; j++) { //changes
            if (i <= j) {
                cout << s[j * (j - 1) / 2 + i - 1];
            } else if (i > j)
                cout << s[i * (i - 1) / 2 + j - 1];
        }

        cout << endl;

    }

}

int main() {
    cout << "Enter the dimension" << endl;
    int n;
    cin >> n;
    Sym m(n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            m.set(i, j, x);
        }
    }

    m.display();
    cout << "S is stored as" << endl;
    for (int i = 0; i < n * (n + 1) / 2; i++) {
        cout << m.s[i] << " ";
    }

}