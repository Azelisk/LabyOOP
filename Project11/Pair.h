#pragma once

#include <iostream>
#include <iomanip>
using namespace std;

class Pair
{
	friend ostream& operator<<(ostream& out, const Pair& ob);
	friend istream& operator>>(istream& in, Pair& ob);

public:
	Pair();
	Pair(double first, double second);
	Pair(const Pair& ob);

	Pair operator+(Pair& pair) const;

	double f(Pair p);
	double s(Pair p);
	double frst(Pair p);
	double scnd(Pair p);
	bool operator<(const Pair& p) const;

	~Pair();
protected:
	double first;
	double second;
};

