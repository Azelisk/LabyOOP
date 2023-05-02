#pragma once

typedef list<double> lst;

lst make_list(int n)
{
	lst l;
	for (int i = 0; i < n; i++)
	{
		double a = (double)(rand() % 300 - 10) / 10;
		l.push_back(a);
	}
	return l;
}

void print_list(const lst& l)
{
	for (auto i = l.cbegin(); i != l.cend(); ++i)
		cout << *i << "\t";
}

double sr_znach(lst l)
{
	double sum = 0;
	for (auto i = l.cbegin(); i != l.cend(); ++i)
		sum += (*i);
	return sum / l.size();
}

void add_list(lst& l, double el)
{
	l.push_back(el);
}

void del_list(lst& l, double st, double end)
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

double min(lst& l)
{
	auto m = l.begin();
	for (auto i = l.begin(); i != l.end(); ++i)
	{
		if (*m > *i)
			m = i;
	}
	return *m;
}
double max(lst& l)
{
	auto m = l.begin();
	for (auto i = l.begin(); i != l.end(); ++i)
	{
		if (*m < *i)
			m = i;
	}
	return *m;
}
void add(lst& l, double sum)
{
	for (auto i = l.begin(); i != l.end(); ++i)
		*i += sum;
}

int foo1()
{
	srand(time(NULL));

	try
	{
		list<double> l1;
		int n;
		cout << "Size list: ";
		cin >> n;
		l1 = make_list(n);
		if (!l1.empty())
			print_list(l1);
		else
		{
			cout << "List is empty!\n";
			return 0;
		}

		cout << "\n\nList with average at the end:\n";
		add_list(l1, sr_znach(l1));
		print_list(l1);

		if (!l1.empty())
		{
			double s, t;
			cout << "\n\nEnter the interval to remove:\n";
			cout << "Start: ";cin >> s;
			cout << "End: ";cin >> t;
			cout << endl << "\nList after delete elements:\n";
			del_list(l1, s, t);
			if (!l1.empty())
				print_list(l1);
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

		double sum = min(l1) + max(l1);
		add(l1, sum);
		cout << endl << "\nList with sum(min+max):\n";
		print_list(l1);
		cout << endl;
	}
	catch (int)
	{
		cout << "mistake!!!";
	}

	return 0;
}