#pragma once


typedef multiset<double> Set;

Set fill_set(Set& s, int n)
{
	double a;
	for (int i = 0; i < n; i++)
	{
		a = (double)(rand() % 300 - 7)/10;
		s.insert(a);
	}
	return s;
}
void print_set(const Set& l)
{
	for (auto i = l.cbegin(); i != l.cend(); ++i)
		cout << *i << "\t";
}

double sr_znach(Set l)
{
	double sum = 0;
	for (auto i = l.cbegin(); i != l.cend(); ++i)
		sum += (*i);
	return sum / l.size();
}
void add_set(Set& l, double el)
{
	l.insert(el);
}

void del_set(Set& l, double st, double end)
{
	auto i = l.begin();
	while (i != l.end())
	{
		if ((*i >= st) && (*i <= end))
			i = l.erase(i);
		else
			++i;
	}
}

double min(Set& l)
{
	auto m = l.begin();
	for (auto i = l.begin(); i != l.end(); ++i)
	{
		if (*m > *i)
			m = i;
	}
	return *m;
}
double max(Set& l)
{
	auto m = l.begin();
	for (auto i = l.begin(); i != l.end(); ++i)
	{
		if (*m < *i)
			m = i;
	}
	return *m;
}
void add(Set& l, double sum)
{
	multiset<double> s1;
	for (auto& i :l)
	{
		s1.insert(i + sum);
	}
	print_set(s1);
}

int foo1()
{
	srand(time(0));
	Set st;

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


	double sr = sr_znach(st);
	cout << "\nAverage: " << sr;
	cout << "\n\nSet with average:\n";
	add_set(st, sr);
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

	double sum = min(st) + max(st);

	cout << endl << "\nSet with sum(min+max):\n";
	add(st, sum);


	return 0;
}
