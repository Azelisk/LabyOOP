#pragma once

typedef multiset<Pair> Set2;

Set2 fill_set(Set2& s, int n)
{
	for (int i = 0; i < n; i++)
	{
		double x = (rand() % 300 - 7) / 10;
		double y = (double)(rand() % 300 - 7) / 10;
		Pair a(x, y);
		s.insert(a);
	}
	return s;
}
void print_set(const Set2& l)
{
	for (auto i = l.cbegin(); i != l.cend(); ++i)
		cout << *i << "    ";
}

void sr_znach(Set2& l)
{
	Pair a;
	double sumF = 0, sumS = 0;
	for (auto i = l.begin(); i != l.end(); ++i)
	{
		sumF = a.f(*i);
		sumS = a.s(*i);
	}
	double x = sumF / l.size();
	double y = sumS / l.size();
	Pair d(x, y);
	l.insert(d);
}

void del_set(Set2& l, double st, double end)
{
	Pair a;
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

Pair min(Set2& l)
{
	Pair a;
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
	Pair d(minF, minS);
	return d;
}
Pair max(Set2& l)
{
	Pair a;
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
	Pair d(maxF, maxS);
	return d;
}
void add(Set2& l, const Pair sum)
{
	double x, y;
	Pair t;
	Set2 s2;
	for (auto i = l.begin(); i != l.end(); ++i)
	{
		x = t.frst(*i);
		y = t.scnd(*i);
		Pair a(x, y);
		a = a + sum;
		s2.insert(a);
	}
	print_set(s2);
}

int foo2()
{
	srand(time(0));
	Set2 st;

	int n;
	cout << "Size set: ";
	cin >> n;
	fill_set(st, n);

	if (!st.empty())
		print_set(st);
	else
	{
		cout << "Set is empty!\n";
		return 0;
	}


	cout << "\n\nSet with average:\n";
	sr_znach(st);
	print_set(st);

	if (!st.empty())
	{
		double s, t;
		cout << "\n\nEnter the interval to remove:\n";
		cout << "Start: ";cin >> s;
		cout << "End: ";cin >> t;
		cout << endl << "Set after delete elements:\n";
		del_set(st, s, t);
		if (!st.empty())
			print_set(st);
		else
		{
			cout << "Set is empty!\n";
			return 0;
		}
	}
	else
	{
		cout << "Set is empty!\n";
		return 0;
	}

	Pair minn = min(st);
	Pair maxx = max(st);
	Pair sum = minn + maxx;

	cout << endl << "\nSet with sum(min+max):\n";
	add(st, sum);


	return 0;
}