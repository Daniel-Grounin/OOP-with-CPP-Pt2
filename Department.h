#pragma once
#include "Worker.h"
#include <iostream>
#include <string>
using namespace std;

class Department
{
public:
	Department();
	Department(const Department& other);
	Department(string);
	Department(string, Role**, int);
	~Department();
	Department operator=(const Department&);
	Worker operator[](int index);
	void addWorker(Worker);
	void addRole(string, string, int);
	friend ostream& operator << (ostream&, const Department&);
	friend istream& operator >> (istream&, Department&);
	bool operator==(string);
	int get_numRoles();
	Role** getRolesArr();

private:
	string depName;
	int numOfWorkers;
	Worker** workersArr;
	Role** workerRoles;
	int numOfRoles;

};

