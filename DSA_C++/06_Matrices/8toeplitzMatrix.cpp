#include<iostream>

using namespace std;

class Toepliz {
    private:
        int Dimen;
    int * Array;
    public:
        Toepliz(int Dimen) {
            int Size = 2 * Dimen - 1;
            this -> Dimen = Dimen;
            this -> Array = new int[Size];
        }
    void Set(int i, int j, int x) {
        if (i == 0) {
            Array[j] = x;
        } else if (j == 0)
            Array[Dimen + i] = x;
    }
    void Display() {
        for (int i = 0; i < Dimen; i++) {
            for (int j = 0; j < Dimen; j++) {
                if (i <= j)
                    cout << Array[j - i] << " ";
                else
                    cout << Array[Dimen + i - j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int x;
    Toepliz Matrix(5);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 0) {
                cin >> x;
                Matrix.Set(i, j, x);
            } else if (j == 0) {
                cin >> x;
                Matrix.Set(i, j, x);
            }
        }
    }
    Matrix.Display();
}