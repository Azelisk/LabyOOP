#pragma once

#include <iostream>
#include <string>
#include <list>
#include <queue>
using namespace std;

template <typename T>
list<T> copy_pq_to_list(priority_queue<T> q)
{
	list<T> l;
	while (!q.empty())
	{
		l.push_back(q.top());
		q.pop();
	}
	return l;
}
template <typename T>
priority_queue<T> copy_list_to_pq(list<T> l)
{
	priority_queue<T> pq;
	for (auto i = l.begin(); i != l.end(); ++i)
		pq.push(*i);
	return pq;
}

template <typename T>
class List
{
	list <T> l;
	priority_queue<T> pq;
	int len;

public:
	List();
	List(int n);
	List(const List<T>&);
	void print();
	bool empty();

	void sr_zn();
	void del( double st, double end);
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
		l.push_back(a);
	}
	len - l.size();
}

template<typename T>
inline List<T>::List(const List<T>& l)
{
	len = l.len;
	list<T> lst = copy_pq_to_list(l.pq);
	pq = copy_list_to_pq(lst);
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
	l.push_back(d);
}

template<typename T>
inline void List<T>::del( double st, double end)
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
	for (auto i = l.begin(); i != l.end(); ++i)
		*i = *i + sum;
}

