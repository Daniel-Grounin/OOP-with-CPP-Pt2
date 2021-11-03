#include "Department.h"

class Menu
{
public:
	Menu();
	~Menu();
	void Run();

private:
	Department** dept_Arr;
	Worker** menu_Workers;
	int num_Of_depts;
	int num_Of_Workers;
	void add_New_Worker();
	void add_New_dept();
	void add_new_Role();
	void add_New_Register();
	void print_menu();
	void add_raise();
	void print_dept();
	void print_worker_info();
};

