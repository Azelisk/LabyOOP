#include "Pair.h"

Pair::Pair()
{
	//cout << "Вызвался конструктор по умолчанию для объекта: " << this << endl;
	first = 0;
	second = 0;
}
Pair::Pair(int first, double second)
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

Pair Pair::operator-(const Pair& pair) const
{
	Pair temp = *this;
	temp.first -= pair.first;
	temp.second -= pair.second;
	return temp;
}
Pair Pair::operator+(Pair& pair) const
{
	Pair temp = *this;
	temp.first += pair.first;
	temp.second += pair.second;
	return temp;
}
Pair Pair::operator+(int data) const
{
	Pair temp = *this;
	temp.first += data;
	return temp;
}
Pair Pair::operator+(double data) const
{
	Pair temp = *this;
	temp.second += data;
	return temp;
}
Pair& Pair::operator++()
{
	++first;
	++second;
	return *this;
}
Pair Pair::operator++(int)
{
	Pair temp = *this;
	++first;
	++second;
	return temp;
}
Pair& Pair::operator=(const Pair& pair)
{
	if (this == &pair)
		return *this;
	first = pair.first;
	second = pair.second;
	return *this;
}

ostream& operator<<(ostream& out, const Pair& ob)
{
	out << "(" << ob.first << ":" << ob.second << ")";
	return out;
}
istream& operator>>(istream& in, Pair& ob)
{
	cout << "first(int): "; in >> ob.first;
	cout << "second(double): "; in >> ob.second;
	return in;
}

Pair::~Pair()
{
	//cout << "Вызвался деструктор для объекта: " << this << endl;
}