#include<iostream>

using namespace std;

class customer {
public :
	char name[100];
	int age;
	char gender;
	double credits;

	void printCustomerInfo() {
		cout << "\ncustomer information\n";
		cout << "name : " << name << endl;
		cout << "age : " << age << endl;
		cout << "gender : " << gender << endl;
		cout << "credits : " << credits << endl;
	}


};


// void printCustomerInfo(customer c) {
// 	cout << "\ncustomer information\n";
// 	cout << "name : " << c.name << endl;
// 	cout << "age : " << c.age << endl;
// 	cout << "gender : " << c.gender << endl;
// 	cout << "credits : " << c.credits << endl;
// }

int main() {

	customer c1;

	c1.age = 20;
	c1.gender = 'M';
	c1.credits = 1000;
	strcpy(c1.name, "Shubham");

	// cout << "\ncustomer information\n";
	// cout << "name : " << c1.name << endl;
	// cout << "age : " << c1.age << endl;
	// cout << "gender : " << c1.gender << endl;
	// cout << "credits : " << c1.credits << endl;

	// printCustomerInfo(c1);

	c1.printCustomerInfo();

	customer c2;

	c2.age = 19;
	c2.gender = 'F';
	c2.credits = 500;
	strcpy(c2.name, "siya");

	// cout << "\ncustomer information\n";
	// cout << "name : " << c2.name << endl;
	// cout << "age : " << c2.age << endl;
	// cout << "gender : " << c2.gender << endl;
	// cout << "credits : " << c2.credits << endl;

	// printCustomerInfo(c2);

	c2.printCustomerInfo();

	return 0;
}