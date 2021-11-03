#pragma once
#include <iostream>
#include <string>
using namespace std;

class Role
{
public:
	Role() {};
	Role(string,string,int);
	~Role();
	bool operator==(Role& other);
	void salaryUpdate(int);
	friend ostream& operator << (ostream&, const Role&);
	friend istream& operator >> (istream&, Role&);
	Role(const Role&);
	string getRoleName() { return roleName; }
	string getroleDisc() { return discRole; }
	int getRoleSalary() { return salary; }
	
private:
	string roleName;
	string discRole;
	int salary;
};

