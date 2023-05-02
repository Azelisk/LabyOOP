#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef priority_queue <Pair> PQ;
typedef vector<Pair> vec;

PQ make_PQ(int n)
{
	PQ q;
	double x, y;
	for (int i = 0; i < n; i++)
	{
		x = (rand() % 300 - 10) / 10;
		y = (double)(rand() % 300 - 10) / 10;
		Pair a(x,y);
		q.push(a);
	}
	return q;
}

vec copy_pq_to_vector(PQ q)
{
	vec v;
	while (!q.empty())
	{
		v.push_back(q.top());
		q.pop();
	}
	return v;
}

PQ copy_vector_to_pq(vec v)
{
	PQ q;
	for (int i = 0; i < v.size(); ++i)
		q.push(v[i]);
	return q;
}

void print(PQ q)
{
	while (!q.empty())
	{
		cout << q.top() << "    ";
		q.pop();
	}
}

void sr_zn(PQ& q)
{
	vec v = copy_pq_to_vector(q);

	Pair a;
	double sumF = 0, sumS = 0;
	for (int i = 0; i <q.size(); ++i)
	{
		sumF = a.f(v[i]);
		sumS = a.s(v[i]);
	}
	double x = sumF / q.size();
	double y = sumS / q.size();
	Pair d(x, y);
	q.push(d);
}

PQ del(PQ& q, double st, double end)
{
	Pair a;
	vec v;
	int i = q.size();
	while(i != 0)
	{
		a = q.top();
		if (!(a.frst(a) >= st && a.frst(a) <= end || a.scnd(a) >= st && a.scnd(a) <= end))
			v.push_back(a);
		q.pop();
		
		--i;
	}
	q = copy_vector_to_pq(v);
	return q;
}

Pair min(PQ& q)
{
	vec v = copy_pq_to_vector(q);

	Pair a;
	double minF = a.frst(v[0]), minS = a.scnd(v[0]);
	
	for (int i = 1; i < v.size(); ++i)
	{
		if (minF > a.frst(v[i]))
			minF = a.frst(v[i]);
		if (minS > a.scnd(v[i]))
			minS = a.scnd(v[i]);
	}
	Pair d(minF, minS);
	return d;
}

Pair max(PQ& q)
{
	vec v = copy_pq_to_vector(q);

	Pair a;
	double maxF = a.frst(v[0]), maxS = a.scnd(v[0]);

	for (int i = 1; i < v.size(); ++i)
	{
		if (maxF < a.frst(v[i]))
			maxF = a.frst(v[i]);
		if (maxS < a.scnd(v[i]))
			maxS = a.scnd(v[i]);
	}
	Pair d(maxF, maxS);
	return d;
}

void add(Pair sum, PQ& q)
{
	vec v = copy_pq_to_vector(q);
	for (int i = 0; i < v.size(); i++)
	{
		v[i] = v[i] + sum;
	}
	q = copy_vector_to_pq(v);
}

int foo4()
{
	srand(time(NULL));

	int n;
	cout << "Size priority queue: ";
	cin >> n;

	PQ q;
	cout << "\nPriority queue:\n";
	q = make_PQ(5);
	print(q);

	if (n != 0)
	{
		cout << "\n\nPriority queue with average:\n";
		sr_zn(q);
		print(q);
	}

	if (!q.empty())
	{
		double s, t;
		cout << "\n\nEnter the interval to remove:\n";
		cout << "Start: ";cin >> s;
		cout << "End: ";cin >> t;
		cout << endl << "Priority queue after delete elements:\n";
		del(q, s, t);
		if (!q.empty())
			print(q);
		else
		{
			cout << "Priority queue is empty!\n";
			return 0;
		}
	}
	else
	{
		cout << "Priority queue is empty!\n";
		return 0;
	}

	Pair minn = min(q);
	Pair maxx = max(q);
	cout << "\n\nMin pair: " << minn;
	cout << "\n\nMax pair: " << maxx;
	Pair sum;
	sum = minn + maxx;
	cout << "\n\nSumm: " << sum << endl;

	cout << endl << "\nPriority queue with sum(min+max):\n";
	add(sum, q);
	cout << endl;
	print(q);
	cout << endl;

	return 0;
}