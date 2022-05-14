/**
 * @defgroup   3.6 Animal Shelter
 *
 * @brief      Implement an Animal Shelter based on FIFO rule.
 * 			   An animal shelter, which holds only dogs and cats, operates on a strictly "FIFO" basis.
 * 			   People must adopt either the "oldest" (based on arrival time) of all animals at the shelter,
 * 			   or they can select whether they would prefer a dog or a cat (and will recieve the oldest animal of that type).
 * 			   They cannot select which which specific animal they would like. Create a data structure to maintain
 * 			   this system and implement operations such as enqueue, dequeueAny, dequeueDog, and dequeueCat.
 * 			   You may use the built-in LinkedList data structure.
 * 			   
 *
 * @author     Vishnu
 * @date       2022
 */


#include <iostream>
#include <queue>
using namespace std;

class animal {

private:
	queue<int> dog, cat;
	int order;

public:
	animal() {
		order = 1;
	}

	int enqueue(string a) {
		if(a == "dog") {
			dog.push(order);
			order++;
		} else if(a == "cat") {
			cat.push(order);
			order++;
		}
		return order-1;
	}

	int dequeueAny() {
		int temp;
		if(dog.front() > cat.front()) {
			temp = cat.front();
			cat.pop();
		} else {
			temp = dog.front();
			dog.pop();
		}
		return temp;
	}

	int dequeueDog() {
		if(dog.empty()) {
			cout << "There are no more dogs!\n";
			getchar();
			exit(0);
		}
		int temp = dog.front();
		dog.pop();
		return temp;
	}

	int dequeueCat() {
		if(cat.empty()) {
			cout << "There are no more cat!\n";
			getchar();
			exit(0);
		}
		int temp = cat.front();
		cat.pop();
		return temp;
	}
};


int main(){
    animal a;
    cout<<"Shelter received an dog with index "<<a.enqueue("dog")<<'\n';
    cout<<"Shelter received an cat with index "<<a.enqueue("cat")<<'\n';
    cout<<"Shelter received an cat with index "<<a.enqueue("cat")<<'\n';
    cout<<"Shelter received an dog with index "<<a.enqueue("dog")<<'\n';
    cout<<"Shelter received an cat with index "<<a.enqueue("cat")<<'\n';
    cout<<"Shelter received an dog with index "<<a.enqueue("dog")<<'\n';
    cout<<"Shelter received an cat with index "<<a.enqueue("cat")<<'\n';
    cout<<"Get an animal of any kind. The index is "<<a.dequeueAny()<<'\n';
    cout<<"Get a dog. The index is "<<a.dequeueDog()<<'\n';
    cout<<"Get a cat. The index is "<<a.dequeueCat()<<'\n';
    cout<<"Get a dog. The index is "<<a.dequeueDog()<<'\n';
    cout<<"Get a dog. The index is "<<a.dequeueDog()<<'\n';
    cout<<"Get a dog. The index is "<<a.dequeueDog()<<'\n';
}