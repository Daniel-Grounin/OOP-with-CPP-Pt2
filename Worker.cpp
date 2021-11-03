#include "Worker.h"
using namespace std;

Worker::Worker(){ //default ctor
	set_Name("Unknown");
	workerSerial = counter++;
	workerRole = new Role();
}

Worker::Worker(string name) {
	set_Name(name);
	workerSerial = counter++;
	workerRole = new Role();
}

void Worker::set_Name(string name) {
	workerName = name;	
}

Worker::Worker(const Worker& other)  { //cpy ctor
	this->workerName = other.workerName;
	this->workerSerial = other.workerSerial;
	this->raise = other.raise;
	this->workerRole = new Role(*(other.workerRole));
}

Worker Worker::operator=(const Worker& other){ // operator =
	this->workerName = other.workerName;
	this->workerRole = new Role(*(other.workerRole));
	this->workerSerial = other.workerSerial;
	this->raise = other.raise;

		return *this;
}

Worker Worker::operator+=(int raise){ //operator +=
	this->raise += raise;
		return *this;
}

bool Worker::operator>(const Worker& other){ //operator >
	if (this->workerRole->getRoleSalary() + raise > other.workerRole->getRoleSalary() + raise) {
		return true;
	}
	return false;
}

ostream& operator<<(ostream& output, const Worker& obj){ //cout operator
	output << "The worker Name: " << obj.workerName << endl << "worker Serial: " << obj.workerSerial << endl <<"The total salary income: " << obj.workerRole->getRoleSalary() + obj.raise << endl;
		return output;
}

istream& operator >> (istream& input, Worker& obj) { //cin operator
	cout << "Enter Worker Name :";
	input >> obj.workerName;
	cout << endl << "enter raise: " ;
	input >> obj.raise;
	input >> *(obj.workerRole);
	return input;

}
bool Worker::operator==(int id){
	return this->workerSerial == id;
}

int Worker::get_number(){
	return workerSerial;
}

void Worker::set_role(Role& obj){
	this->workerRole = new Role(obj);
}

Worker::~Worker(){
	delete workerRole;
}
 