#pragma once
#include <list>
#include <ctime>

typedef list<Pair> lst3;

int foo3()
{
	srand(time(NULL));

	int n;
	cout << "Size list: ";
	cin >> n;
	
	List<Pair> l(n);
	cout << "\nList:\n";
	l.print();

	if(n!=0)
	{
		cout << "\n\nList with average at the end:\n";
		l.sr_zn();
		l.print();
	}

	if (!l.empty())
	{
		double s, t;
		cout << "\n\nEnter the interval to remove:\n";
		cout << "Start: ";cin >> s;
		cout << "End: ";cin >> t;
		cout << endl << "List after delete elements:\n";
		l.del(s, t);
		if (!l.empty())
			l.print();
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
	
	Pair minn = l.min();
	Pair maxx = l.max();
	cout << "\n\nMin pair: " << minn;
	cout << "\n\nMax pair: " << maxx;
	Pair sum;
	sum = minn + maxx;
	cout << "\n\nSumm: " << sum << endl;

	cout << endl << "\nList with sum(min+max):\n";
	l.add(sum);
	cout << endl;
	l.print();
	cout << endl;

	return 0;
}