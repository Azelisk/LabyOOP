#include<iostream>
#include<string>
using namespace std;

class employe
{
private:
	string name;
	string position;
	double salary;
public:
	employe()
	{
		cout << "\nKonsr without par "<<this<<endl;
		this->name = "...";
		this->position = "...";
		this->salary = 0.0;
		cout << endl;
	}
	
	employe(string name, string position, double salary)
	{
		cout<< "\nKonst withn par " << this << endl;
		this->name = name;
		this->position = position;
		this->salary = salary;
		cout << endl;
	}

	employe(const employe& men)
	{
		cout << "\nKonstr Copy " << this << endl;
		this->name = men.name;
		this->position = men.position;
		this->salary = men.salary;
		cout << endl;
	}

	void setName(string name)
	{
		this->name = name;
	}
	void setPosition(string position)
	{
		this->position = position;
	}
	void setSalary(double salary)
	{
		this->salary = salary;
	}

	string getName(string name)
	{
		return this->name;
	}
	string getPosition(string position)
	{
		return this->position;
	}
	double getSalary(double salary)
	{
		return this->salary;
	}

	void print()
	{
		cout << "Full name: " << name << endl;
		cout << "Position: " << position << endl;
		cout << "Salary: " << salary << endl;
	}

	~employe()
	{
		cout << "\nDestr " << this;
		cout << endl;
	}
};

int main()
{
	system("chcp 1251 >> null");

	employe human1;
	string name, position;
	double salary;

	human1.print();

	cout << "\nEnter the first person's full name: ";
	getline(cin,name);
	cout << "Enter the position of the first person: ";
	getline(cin, position);
	cout << "Enter the salary of the first person: ";
	cin >> salary;
	cin.get();

	employe human2(name, position, salary);
	human2.print();

	employe human3 = human2;
	human3.print();

	cout << "------------------------------\n";
	cout << "\nEnter the full name of the second person: ";
	getline(cin, name);
	cout << "Enter the position of the second person: ";
	getline(cin, position);
	cout << "Enter the salary of the second person: ";
	cin >> salary;
	cin.get();

	human3.setName(name);
	human3.setPosition(position);
	human3.setSalary(salary);
	human3.print();

	return 0;
}