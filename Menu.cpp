#include "Menu.h"
#include "Department.h"
using namespace std;

void Menu::print_menu(){
	cout << "\n---------------------------------------\n";
	cout << "                  MENU: " << endl;
	cout << "1. ADD Worker" << endl;
	cout << "2. ADD Department" << endl;
	cout << "3. ADD new Role" << endl;
	cout << "4. Register new Worker" << endl;
	cout << "5. ADD new Raise" << endl;
	cout << "6. PRINT Department" << endl;
	cout << "7. PRINT Worker info" << endl;
	cout << "8. EXIT "<< endl;
	cout << "\n---------------------------------------\n";
}

void Menu::add_raise(){
	int num,raise;
	cout << "enter number of worker: ";
	cin >> num;
	Worker* work = nullptr;
	for (int i = 0; i < num_Of_Workers; i++)
		if (menu_Workers[i]->get_number() == num) {
			work = menu_Workers[i];
			break;
		}
	if (work == nullptr) {
		cout << "worker not fount" << endl;
	}
	else {
		cout << "enter raise: ";
		cin >> raise;
		work += raise;
	}
}

void Menu::print_dept(){
	string name;
	cout << "Enter department name: ";
	cin >> name;
	Department* dept = nullptr;
	for (int i = 0; i < num_Of_depts; i++) {
		if (*dept_Arr[i] == name)
			dept = dept_Arr[i];
		break;
	}
	if (dept == nullptr) {
		cout << name << " not found!" << endl;
	}
	else {
		cout << *dept;
	}
}

void Menu::print_worker_info(){
	int num;
	cout << "enter number of worker: ";
	cin >> num;
	Worker* work = nullptr;
	for (int i = 0; i < num_Of_Workers; i++)
		if (menu_Workers[i]->get_number() == num) {
			work = menu_Workers[i];
			break;
		}
	if (work == nullptr) {
		cout << "worker not fount" << endl;
	}
	else {
		cout << *work;
	}
}

Menu::Menu():num_Of_depts(0),num_Of_Workers(0){

}

Menu::~Menu(){
	for (int i = 0; i < num_Of_Workers; i++) {
		delete menu_Workers[i];
	}
	delete[] menu_Workers;
	for (int i = 0; i < num_Of_depts; i++) {
		delete dept_Arr[i];
	}
	delete[] dept_Arr;
}

void Menu::Run(){
	int choice;
	bool isRunning = true;
	while (isRunning) {
		print_menu();
		cin >> choice;

		switch (choice)
		{
		case 1: add_New_Worker();
			break;
		case 2: add_New_dept();
			break;
		case 3: add_new_Role();
			break;
		case 4: add_New_Register();
			break;
		case 5: add_raise();
			break;
		case 6: print_dept();
			break;
		case 7: print_worker_info();
			break;
		
		default:
			isRunning = false;
			break;
		}
	}
}

void Menu::add_New_Worker(){
	cout << "Enter name of the new worker: " << endl;
	string name;
	Worker* workers,**worker_h;
	cin >> name;
	workers = new Worker(name);
	worker_h = new Worker * [num_Of_Workers + 1];
	for (int i = 0; i < num_Of_Workers; i++) {
		worker_h[i] = menu_Workers[i];
	}
	worker_h[num_Of_Workers] = workers;
	menu_Workers = worker_h;
	num_Of_Workers++;
}

void Menu::add_New_dept(){
	string name;
	int num_roles;
	Department* dept, ** dept_h;
	cout << "Enter the name of the Department: ";
	cin >> name;
	cout << endl << "Enter the num of Roles at the Department: ";
	cin >> num_roles;
	dept = new Department(name);
	dept_h = new Department * [num_Of_depts + 1];
	for (int i = 0; i < num_Of_depts; i++) {
		dept_h[i] = dept_Arr[i];
	}
	dept_h[num_Of_depts] = dept;
	dept_Arr = dept_h;
	num_Of_depts++;
}

void Menu::add_new_Role(){
	cout << "Enter the wanted Department name: ";
	string name,description;
	cin >> name;
	Department* dept = nullptr;
	for (int i = 0; i < num_Of_depts; i++) {
		if (*dept_Arr[i] == name)
			dept = dept_Arr[i];
		break;
	}
	if (dept == nullptr) {
		cout << "enter role name ,description & payment" << endl;
		int payment;
		cin >> name >> description >> payment;
		dept->addRole(name, description, payment);
	}
}

void Menu::add_New_Register(){
	string name, role;
	int numOfworker;
	cout << "Enter department name to register new worker" << endl;
	cin >> name;
	Department* dept = nullptr;
	for (int i = 0; i < num_Of_depts; i++) {
		if (*dept_Arr[i] == name)
			dept = dept_Arr[i];
		break;
	}
	if (dept == nullptr) {
		cout << name << " not found!" << endl;
	}
	else {
		cout << "Enter worker number & roleName" << endl;
		cin >> numOfworker >> role;
		Worker* work = nullptr;
		for (int i = 0; i < num_Of_Workers; i++)
			if (menu_Workers[i]->get_number() == numOfworker) {
				work = menu_Workers[i];
				break;
			}
		if (work == nullptr) {
			cout << "worker not fount" << endl;
		}
		else {
			Role** roles = dept->getRolesArr();
			Role* rolePtr = new Role(role,"",0);
			for (int i = 0; i < dept->get_numRoles(); i++) {
				if (*rolePtr == *(roles[i])) {
					work->set_role(*(roles[i]));
					dept->addWorker(*work);
				}
			}
		}
	}
}

