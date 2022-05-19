#include <iostream>
using namespace std;

class Element
{
public:
	int i;
	int j;
	int x;
};

class Sparse{
private:
	int m;
	int n;
	int num;
	Element *ele;
public:
	Sparse(){};
	Sparse(int m, int n, int num)
	{
		this->m = m;
		this->n = n;
		this->num = num;
		ele = new Element[this->num];
	}
	~Sparse()
	{
		delete [] ele;
	}
	void read();
	void display();
};

void Sparse::read()
{
	cout << "Enter non zero elements ";
	for(int i=0;i<num;i++)
	{// this will read all the elements from the sparse matrix
		cin >> ele[i].i >> ele[i].j >> ele[i].x;
	}
}

void Sparse::display()
{
	int k = 0;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(ele[k].i == i && ele[k].j == j)
				cout << ele[k++].x << " ";
			else
				cout << "0 ";
		}
		cout << endl;
	}
}




int main(){
	Sparse s1(5,5,5);
	s1.read();
	s1.display();

	return 0;
}