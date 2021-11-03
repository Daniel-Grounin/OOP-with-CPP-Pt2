#pragma once
#include "Role.h"
#include <iostream>
#include <string>
using namespace std;

class Worker
{
public:
	Worker();
	~Worker();
	Worker(string);
	void set_Name(string);
	string get_Name() { return workerName; }
	Worker(const Worker&);
	Role getRole() { return *workerRole; }
	Worker operator=(const Worker&);
	Worker operator+=(int);
	bool operator>(const Worker&);
	friend ostream& operator << (ostream&, const Worker&);
	friend istream& operator >> (istream&, Worker&);
	bool operator==(int id);
	void getRoles(string);
	int get_number();
	void set_role(Role& obj);

private:
	string workerName;
	int workerSerial;
	int raise = 0;
	static int counter;
	Role* workerRole;
};


