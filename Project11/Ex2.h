#pragma once

typedef list<Pair> lst2;

void make_list(lst2& l, int n)
{
	double x, y;
	for (int i = 0; i < n; i++)
	{
		x = (double)(rand() % 300 - 10) / 10;
		y = (double)(rand() % 300 - 10) / 10;
		Pair a(x, y);
		l.push_back(a);
	}
}

void print_list(const lst2& l)
{
	for (auto i = l.cbegin(); i != l.cend(); ++i)
		cout << *i << "    ";
}

void sr_znach(lst2& l)
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
	l.push_back(d);
}

void del_list(lst2& l, double st, double end)
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

Pair min(lst2& l)
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
Pair max(lst2& l)
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
void add(lst2& l, Pair sum)
{
	for (auto i = l.begin(); i != l.end(); ++i)
		*i = *i + sum;
}

int foo2()
{
	srand(time(NULL));

	try
	{
		lst2 l;
		int n;
		cout << "Size list: ";
		cin >> n;
		make_list(l, n);
		if (!l.empty())
			print_list(l);
		else
		{
			cout << "List is empty!\n";
			return 0;
		}

		cout << "\n\nList with average at the end:\n";
		sr_znach(l);
		cout << endl;
		print_list(l);

		if (!l.empty())
		{
			double s, t;
			cout << "\n\nEnter the interval to remove:\n";
			cout << "Start: ";cin >> s;
			cout << "End: ";cin >> t;
			cout << endl << "\nList after delete elements:\n";
			del_list(l, s, t);
			if (!l.empty())
				print_list(l);
			else
			{
				cout << "List is empty!\n";
				return 0;
			}
		}
		else
		{
			cout << "List is empty!\n";
			return 0;
		}

		Pair minn = min(l);
		Pair maxx = max(l);
		cout << "\n\nMin pair: " << minn;
		cout << "\n\nMax pair: " << maxx;
		Pair sum;
		sum = minn + maxx;
		cout << "\n\nSumm: " << sum << endl;


		cout << endl << "\nList with sum(min+max):\n";
		add(l, sum);
		cout << endl;
		print_list(l);
		cout << endl;
	}
	catch (int)
	{
		cout << "mistake!!!";
	}
	return 0;
}