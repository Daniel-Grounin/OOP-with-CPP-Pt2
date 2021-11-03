#include "Department.h"

Department::Department(){
	depName = "unknown";
	numOfRoles = 0;
	numOfWorkers = 0;
}

Department::Department(const Department& other) {//cpy ctor
	this->numOfRoles = other.numOfRoles;
	this->numOfWorkers = other.numOfWorkers;
	this->depName = other.depName;
	this->workersArr = new Worker * [numOfWorkers];
	for (int i = 0; i < numOfWorkers; i++) {
		workersArr[i] = new Worker(*(other.workersArr[i]));
	}
	this->workerRoles = new Role * [numOfRoles];
	for (int i = 0; i < numOfRoles; i++) {
		workerRoles[i] = new Role(*(other.workerRoles[i]));
	}
}

Department::Department(string name){ //ctor
	depName = name;
	numOfRoles = 0;
	numOfWorkers = 0;
}

Department::Department(string name, Role** roles, int num){
	depName = name;
	numOfRoles = num;
	numOfWorkers = 0;
	workerRoles = new Role * [numOfRoles];
	for (int i = 0; i < numOfRoles; i++) {
		workerRoles[i] = new Role(*(roles[i]));
	}
}

Department::~Department(){
	/*for (int i = 0; i < numOfWorkers; i++) {
		delete workersArr[i];
	}
	delete[] workersArr;*/

	for (int i = 0; i < numOfRoles; i++) {
		delete[] workerRoles[i];
	}
	delete[] workerRoles;
}

Department Department::operator=(const Department& other){
	for (int i = 0; i < numOfWorkers; i++) {
		delete[] workersArr[i];
	}
	delete[] workersArr;
	for (int i = 0; i < numOfRoles; i++) {
		delete[] workerRoles[i];
	}
	delete[] workerRoles;

	this->numOfRoles = other.numOfRoles;
	this->numOfWorkers = other.numOfWorkers;
	this->depName = other.depName;
	this->workersArr = new Worker * [numOfWorkers];
	for (int i = 0; i < numOfWorkers; i++) {
		workersArr[i] = new Worker(*(other.workersArr[i]));
	}
	this->workerRoles = new Role * [numOfRoles];
	for (int i = 0; i < numOfRoles; i++) {
		workerRoles[i] = new Role(*(other.workerRoles[i]));
	}


	return *this;
}

Worker Department::operator[](int index){
	if (index >= 0 && index < numOfWorkers)
		return *(workersArr[index]);
	cout << "Error ,index out of boundries" << endl;

	return Worker();
}

void Department::addWorker(Worker obj){
	int num = numOfWorkers + 1;
	Worker** newList = new Worker * [num];
	for (int i = 0; i < numOfWorkers; i++) {
		newList[i] = workersArr[i];
	}
	newList[numOfWorkers] = &obj;
	numOfWorkers = num;
	workersArr = newList;
	this->addRole(obj.getRole().getRoleName(), obj.getRole().getroleDisc(),obj.getRole().getRoleSalary());

}

void Department::addRole(string name, string disc, int salary){
	int num = numOfRoles + 1;
	Role** nRoleList = new Role * [num];
	for (int i = 0; i < numOfRoles; i++) {
		nRoleList[i] = workerRoles[i];
	}
	nRoleList[numOfRoles] = new Role(name, disc, salary);
	numOfRoles = num;
	workerRoles = nRoleList;
}

bool Department::operator==(string name){
	return this->depName == name;
}

int Department::get_numRoles(){
	return numOfRoles;
}

Role** Department::getRolesArr(){
	return this->workerRoles;
}

ostream& operator<<(ostream& output, const Department& obj){
	output << "The Dept name: " << obj.depName << endl << "The Num of workers: " << obj.numOfWorkers << endl;
	for (int i = 0; i < obj.numOfRoles; i++) {
		output << *(obj.workerRoles[i]) << endl;
	}
	output << "The Workers name are: " << endl;
	for (int i = 0; i < obj.numOfWorkers; i++) {
		output << (obj.workersArr[i]->get_Name()) << endl;
	}
	return output;
}

istream& operator>>(istream& input,Department& obj) {
	cout << "Enter department name: " << endl;
	input >> obj.depName;
	cout << "Enter number of roles: " << endl;
	input >> obj.numOfRoles;
	obj.workerRoles = new Role * [obj.numOfRoles];
	for (int i = 0; i < obj.numOfRoles; i++)
	{
		obj.workerRoles[i] = new Role();
		input >> *(obj.workerRoles[i]);
	}
	obj.numOfWorkers = 0;
	return input;
}