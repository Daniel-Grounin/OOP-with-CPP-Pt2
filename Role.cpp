#include "Role.h"

Role::Role(string name, string discName, int salary) {
	this->roleName = name;
	this->discRole = discName;
	this->salary = salary;
}

bool Role::operator==( Role& other) { // to know if our variables sits in the same adress
	return roleName == other.roleName;
}

void Role::salaryUpdate(int salary) {//used the same name ,so 'this' was needed
	this->salary = salary;
}

Role::Role(const Role& other) //cpy ctor
{
	this->discRole = other.discRole;
	this->roleName = other.roleName;
	this->salary = other.salary;

}

istream& operator>>(istream& input, Role& obj){ //cin operator
	cout << "Enter role name: ";
	input >> obj.roleName;
	cout << "Enter discription Role: ";
	input >> obj.discRole;
	cout << "Enter salary income: ";
	input >> obj.salary;
	return input;
}

ostream& operator<<(ostream& output, const Role& obj){ //cout operator
	output << "The Role: " << obj.roleName << endl << "The discription Role: " << obj.discRole << endl << "The slary income: " << obj.salary << endl;
	return output;
}

Role::~Role()
{

}

