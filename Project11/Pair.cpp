#include "Pair.h"

Pair::Pair()
{
	//cout << "Вызвался конструктор по умолчанию для объекта: " << this << endl;
	first = 0;
	second = 0;
}
Pair::Pair(double first, double second)
{
	//cout << "Вызвался конструктор с параметрами для объекта: " << this << endl;
	this->first = first;
	this->second = second;
}
Pair::Pair(const Pair& ob)
{
	this->first = ob.first;
	this->second = ob.second;
}

Pair Pair::operator+(Pair& pair) const
{
	Pair temp = *this;
	temp.first += pair.first;
	temp.second += pair.second;
	return temp;
}

double Pair::f(Pair p)
{
	static double sumF = 0;
	sumF += p.first;
	return sumF;
}
double Pair::s(Pair p)
{
	static double sumS = 0;
	sumS += p.second;
	return sumS;
}

double Pair::frst(Pair p)
{
	return p.first;
}

double Pair::scnd(Pair p)
{
	return p.second;
}

bool Pair::operator<(const Pair& p) const
{
	if (this->first < p.first && this->second < p.second)
		return true;
	return false;
}

ostream& operator<<(ostream& out, const Pair& ob)
{
	out << "(" << ob.first << ":" << ob.second << ")";
	return out;
}
istream& operator>>(istream& in, Pair& ob)
{
	cout << "first: "; in >> ob.first;
	cout << "second: "; in >> ob.second;
	return in;
}

Pair::~Pair()
{
	//cout << "Вызвался деструктор для объекта: " << this << endl;
}