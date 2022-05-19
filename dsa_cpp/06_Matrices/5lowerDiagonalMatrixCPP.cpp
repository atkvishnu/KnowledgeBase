// Row major formula: accessing elements:<i*(i-1)/2+j-1> , size:<2*(2+1)/2>

// Column major formula: accessing elements:<n*(j-1)-(j-2)*(j-1)/2+i-j> , size:<same>


#include <iostream> 
using namespace std; 

class lowerTriangular 
{
private:
    int *A;
    int n;
public:
    lowerTriangular()
    {
        n=2;
        A = new int[2*(2+1)/2];
    }
    lowerTriangular(int n)
    {
        this->n=n;  // 1st n is from <private: int n>, 2nd n is from <lowerTriangular(int n)>
        A = new int[n*(n+1)/2];
    }
    ~lowerTriangular()
    {
        delete []A;
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int getDimensions() {return n;}
};

void lowerTriangular::Set(int i, int j, int x)
{
    if(i>=j)
        A[i*(i-1)/2+j-1] = x;       // n*(j-1)-(j-2)*(j-1)/2+i-j
}

int lowerTriangular::Get(int i, int j)
{
    if(i>=j)
        return A[i*(i-1)/2+j-1];            // n*(j-1)-(j-2)*(j-1)/2+i-j
    return 0;
}

void lowerTriangular::Display()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i>=j)
                cout<<A[i*(i-1)/2+j-1] << " ";      // n*(j-1)-(j-2)*(j-1)/2+i-j
            else
                cout << "0 ";
        }
        cout << "\n";
    }
}

int main()
{
    int d;

    cout << "Enter dimensions: ";
    cin >> d;

    lowerTriangular lm(d);          //lm for lower triangular matrix -> This will be calling the parametrized constructor and it will be making an array of n*(n-1)/2
    // d will be set into the second n.

    int x;

    cout << "Enter all the elements: \n";

    for(int i=1; i<=d; i++)
    {
        for(int j=1; j<=d; j++)
        {
            cin >> x;
            lm.Set(i,j,x);
        }
    }

    cout << "\n";

    lm.Display();

    return 0;
}