/*

	STL implementation of the min_heap data structure with custom comparator.


*/

#include<iostream>
#include<queue>

using namespace std;

class customer {
public :
	string name;
	int age;
	double credits;

	customer(string name, int age, double credits) {
		this->name = name;
		this->age = age;
		this->credits = credits;
	}
};

class myCustomerCreditsComparatoor {

public :

	// return true when swap is needed otherwise return false;

	bool operator()(customer a, customer b) {
		if (b.credits < a.credits) {
			// do a swap to build a minHeap of customer based on credits
			return true;
		}
		// do not do a swap to build a minHeap of customer based on credits
		return false;
	}

};

class myCustomerAgeComparatoor {

public :

	// return true when swap is needed otherwise return false;

	bool operator()(customer a, customer b) {
		if (b.age > a.age) {
			// do a swap to build a maxHeap of customer based on age
			return true;
		}
		// do not do a swap to build a maxHeap of customer based on age
		return false;
	}

};

int main() {

	// priority_queue<customer, vector<customer>, myCustomerCreditsComparatoor> m;
	priority_queue<customer, vector<customer>, myCustomerAgeComparatoor> m;

	m.push(customer("tanmay", 20, 1000));
	m.push(customer("kunal", 19, 500));
	m.push(customer("sania", 21, 1500));
	m.push(customer("shubham", 18, 2000));
	m.push(customer("seiya", 22, 1200));
	m.push(customer("yash", 17, 1800));

	cout << m.size() << endl;

	while (!m.empty()) {
		customer c = m.top();
		cout << c.name << " " << c.age << " " << c.credits << endl;
		m.pop();
	}

	cout << endl;

	cout << m.size() << endl;

	return 0;
}