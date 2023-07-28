#include<iostream>

using namespace std;

class customer {

public :

	string name;
	int age;
	char gender;
	double credits;

	customer(string n, int a, char g, double c) {
		cout << "\ninside parameterised constructor of \'customer\' class\n";
		name = n;
		age = a;
		gender = g;
		credits = c;
	}

	void printCustomerInfo() {
		cout << "\nCustomer Information\n";
		cout << "Name : " << name << endl;
		cout << "Age : " << age << endl;
		cout << "Gender : " << gender << endl;
		cout << "Credits : " << credits << endl;
	}

};

int main() {

	customer c("misaka", 19, 'F', 500);

	customer* cptr = &c;

	// cout << "name = " << (*cptr).name << endl;
	// cout << "age = " << (*cptr).age << endl;
	// cout << "credits = " << (*cptr).credits << endl;
	// cout << "gender = " << (*cptr).gender << endl;


	cout << "name = " << cptr->name << endl;
	cout << "age = " << cptr->age << endl;
	cout << "credits = " << cptr->credits << endl;
	cout << "gender = " << cptr->gender << endl;

	// (*cptr).printCustomerInfo();

	cptr->printCustomerInfo();

	return 0;
}