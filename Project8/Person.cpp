#include "Person.h"

Person::Person()
{
	this->name = "";
	this->age = 0;
}
Person::Person(string name, int age)
{
	this->name = name;
	this->age = age;
}
Person::Person(const Person& p)
{
	age = p.age;
	name = p.name;
}
Person::~Person() {}
istream& operator>>(istream& in, Person& p)
{
	cout << "name: ";
	in >> p.name;
	cout << "age: ";
	in >> p.age;
	return in;
}
ostream& operator<<(ostream& out, const Person& p)
{
	return (out << p.name << " : " << p.age);
}
void Person::set_name(string name)
{
	this->name = name;
}
void Person::set_age(int age)
{
	this->age = age;
}
string Person::get_name()
{
	return name;
}
int Person::get_age() 
{
	return age;
}
void Person::Show()
{
	cout << endl << name << ": " << age << endl;
}

void Person::HandleEvent(const TEvent& ev)
{
	if (ev.what == evMessage)
	{
		switch (ev.command)
		{
		case cmGet:
			cout << *this; 
			break;
		}
	}
}