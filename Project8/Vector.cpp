#include "Vector.h"
using namespace std;

Vector::Vector()
{
	beg = 0;
	size = 0;
	cur = 0;
}
Vector::~Vector()
{
	if (beg != 0) 
		delete[] beg;
	beg = 0;
}

Vector::Vector(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}

void Vector::Add(Object* p) {
	if (cur < size)
	{
		beg[cur] = p;
		cur++;
	}
}

ostream& operator<<(ostream& out, const Vector& v)
{
	if (v.size == 0) out << "Empty" << endl;
	Object** p = v.beg;
	for (int i = 0; i < v.cur; i++)
	{
		(*p)->Show();
		p++;
	}
	return out;
}

void Vector::Add()
{
	Object* obj;
	cout << "\nWho to add: \n1. Person\n2. Student\n";
	int n;
	cin >> n;
	cout << "\n";
	switch (n)
	{
	case 1:
	{
		Person* p = new Person();
		cin >> *p;
		obj = p;
		Add(obj);
		break;
	}
	case 2:
	{
		Student* s = new Student();
		cin >> *s;
		obj = s;
		Add(obj);
		break;
	}
	default:
	{
		cout << "There is no such option!";
		break;
	}
	}
}

void Vector::Show()
{
	if (cur == 0)
		cout << "Empty\n";
	Object** p = beg;
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();
		++p;
	}
}

void Vector::Del()
{
	if (cur == 0)
		return;
	cur--;
}

int Vector::operator ()()
{
	return size;
}
void Vector::HandleEvent(const TEvent& ev)
{
	if (ev.what == evMessage)
	{
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			(*p)->HandleEvent(ev);
			p++;
		}
	}
}

void Vector::rAge()
{
	int a = 0;
	if (cur == 0)
	{
		cout << "Empty";
		return;
	}
	Object** p = beg;
	for (int i = 0; i < cur; i++)
	{
		a += (*p)->rAge();
		p++;
	}
	cout << "Average age of people: " << a / cur << '\n';
}