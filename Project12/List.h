#pragma once

#include <iostream>
#include <string>
#include <list>
#include <set>
using namespace std;


template <typename T>
class List
{
	multiset<Pair> l;
	int len;
public:
	List();
	List(int n);
	void print();
	bool empty();

	void sr_zn();
	void del(double st, double end);
	T min();
	T max();
	void add(T sum);

	~List() {};
};

template<typename T>
inline List<T>::List()
{
	len = 0;
}

template<typename T>
inline List<T>::List(int n)
{
	double x, y;
	for (int i = 0; i < n; ++i)
	{
		x = (rand() % 300 - 10) / 10;
		y = (double)(rand() % 300 - 10) / 10;
		T a(x, y);
		l.insert(a);
	}
	len - l.size();
}

template<typename T>
inline void List<T>::print()
{
	for (auto i = l.begin(); i != l.end(); ++i)
	{
		cout << *i << "    ";
	}
}

template<typename T>
inline bool List<T>::empty()
{
	return l.empty();
}

template<typename T>
inline void List<T>::sr_zn()
{
	Pair a;
	double sumF = 0, sumS = 0;
	for (auto i = l.begin(); i != l.end(); ++i)
	{
		sumF = a.f(*i);
		sumS = a.s(*i);
	}
	int x = sumF / l.size();
	double y = sumS / l.size();
	T d(x, y);
	l.insert(d);
}

template<typename T>
inline void List<T>::del(double st, double end)
{
	T a;
	auto i = l.begin();
	while (i != l.end())
	{
		if ((a.frst(*i) >= st && a.frst(*i) <= end) || (a.scnd(*i) >= st && a.scnd(*i) <= end))
		{
			i = l.erase(i);
		}
		else
			++i;
	}
}

template<typename T>
inline T List<T>::min()
{
	T a;
	auto i = l.begin();
	double minF = a.frst(*i), minS = a.scnd(*i);
	++i;
	for (i; i != l.end(); ++i)
	{
		if (minF > a.frst(*i))
			minF = a.frst(*i);
		if (minS > a.scnd(*i))
			minS = a.scnd(*i);
	}
	T d(minF, minS);
	return d;
}
template<typename T>
inline T List<T>::max()
{
	T a;
	auto i = l.begin();
	double maxF = a.frst(*i), maxS = a.scnd(*i);
	++i;
	for (i; i != l.end(); ++i)
	{
		if (maxF < a.frst(*i))
			maxF = a.frst(*i);
		if (maxS < a.scnd(*i))
			maxS = a.scnd(*i);
	}
	T d(maxF, maxS);
	return d;
}
template<typename T>
inline void List<T>::add(T sum)
{
	double x, y;
	Pair t;
	multiset<Pair> s2;
	for (auto i = l.begin(); i != l.end(); ++i)
	{
		x = t.frst(*i);
		y = t.scnd(*i);
		Pair a(x, y);
		a = a + sum;
		s2.insert(a);
	}
	l = s2;
}

