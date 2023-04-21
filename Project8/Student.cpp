#include "Student.h"
Student::Student()
{
	name = "";
	subject = "";
	age = 0;
	reiting = 0;
}
Student::Student(string name, int age, string subject, int reiting)
{
	this->name = name;
	this->age = age;
	this->subject = subject;
	this->reiting = reiting;
}
Student::~Student() {}
Student::Student(const Student& s)
{
	name = s.name;
	age = s.age;
	subject = s.subject;
	reiting = s.reiting;
}
istream& operator>>(istream& in, Student& s)
{
	cout << "name: ";
	in >> s.name;
	cout << "age: ";
	in >> s.age;
	cout << "subject: ";
	in >> s.subject;
	cout << "reiting: ";
	in >> s.reiting;
	return in;
}
ostream& operator<<(ostream& out, const Student& s)
{
	return (out << s.name << " : " << s.age << " | " << s.subject << " : " << s.reiting);
}
void Student::Show()
{
	cout << endl << name << " : " << age << " | " << subject << " : " << reiting << endl;
}
