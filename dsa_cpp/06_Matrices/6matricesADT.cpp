#include <iostream>


using namespace std;

int main()

{

    cout << "Menu Driven program" << endl;

    int i, j, * A, n, size, ele;

    A = new int[10];

    while (1)

    {

        cout << "Enter the following for matrix " << endl;
        cout << "1) Add" << endl;
        cout << "2) Display" << endl;
        cout << "3) Exit" << endl;
        cout << "Enter choice ";
        cin >> n;

        switch (n)

        {
            //while loop removed from here
        case 1:
            cout << "Enter the indexes and the number itself ";
            scanf("%d%d%d", & i, & j, & ele);
            if (i == j)
                A[i] = ele;
            break;
        case 2:
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++)
                {
                    if (i == j)
                        cout << A[i] << " ";
                    else
                        cout << "0" << " ";
                }
                cout << endl;
            }
            break;
        case 3:
            return 0;
        }
    }
    return 0;

}