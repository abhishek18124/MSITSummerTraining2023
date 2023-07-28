#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class customer {

public:

	string name;
	int age;
	char gender;
	double credits;

	customer(string name, int age, char gender, double credits) {
		this->name = name;
		this->age = age;
		this->gender = gender;
		this->credits = credits;
	}
};

/*
	return 'true' when a swap isn't required.

*/

bool myCustomerAgeCompartor(customer c1, customer c2) {
	if (c1.age < c2.age) {

		// you don't need a swap to sort customer vector in the inc. order based on customer age

		return true;

	}

	// you need a swap to sort customer vector in the inc. order based on customer age

	return false;
}

bool myCustomerCreditsCompartor(customer c1, customer c2) {
	if (c1.credits > c2.credits) {

		// you don't need a swap to sort customer vector in the dec. order based on customer credit

		return true;

	}

	// you need a swap to sort customer vector in the dec. order based on customer credit

	return false;
}

int main() {

	vector<customer> v;

	v.push_back(customer("shubham", 20, 'M', 1000));
	v.push_back(customer("siya", 18, 'F', 500));
	v.push_back(customer("kunal", 21, 'M', 1200));
	v.push_back(customer("sania", 19, 'F', 600));
	v.push_back(customer("aditya", 22, 'M', 200));
	v.push_back(customer("yukta", 17, 'F', 1300));

	// sort(v.begin(), v.end(), myCustomerAgeCompartor);

	sort(v.begin(), v.end(), myCustomerCreditsCompartor);

	for (customer c : v) {
		cout << c.name << " " << c.age << " " << c.credits << endl;
	}

	return 0;
}



