#include<iostream>

using namespace std;

class customer {
public :
	char name[100];
	int age;
	char gender;
	double credits;

	customer() {
		cout << "I am inside the default constructor of the customer class" << endl;
	}

	customer(char* n, int a, char g, double c) {

		cout << "I am inside the parameterised constructor of the customer class" << endl;
		strcpy(name, n);
		age = a;
		gender = g;
		credits = c;

	}

	customer(char* n, int a, char g) {
		cout << "I am inside the parameterised constructor 2 of the customer class" << endl;

		strcpy(name, n);
		age = a;
		gender = g;
		credits =  0;
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

	customer c("naruto", 32, 'M', 5000);

	c.printCustomerInfo();

	customer c1("sasuke", 31, 'M');

	c1.printCustomerInfo();

	customer c2;

	return 0;
}