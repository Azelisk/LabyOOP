#pragma once

#include <list>
#include <algorithm>

void fill_list(list<Pair>& lst)
{
	int n;
	cout << "Input size: "; cin >> n; cout << endl;

	for (size_t i = 0; i < n; i++)
	{
		Pair p((rand() % 300 - 50) / 10, (double)(rand() % 300 - 50) / 10);
		lst.push_back(p);
	}
}

void show_list(list<Pair>& lst)
{
	cout << "List: ";
	for (auto& i : lst)
		cout << i << " ";
	cout << endl;
}

Pair add_average(Pair& p)
{
	Pair temp;
	temp = temp + p;
}

void foo1()
{
	list<Pair> lst;
	pair<int, double> t;

	fill_list(lst);
	show_list(lst);
	min_element(lst.begin(), lst.end());
}