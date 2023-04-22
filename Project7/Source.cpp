#include "List.h"
#include "Pair.h"

int main()
{
	system("chcp 1251 >> null");

	List<int> a, b, c;

	for (int i = 0; i < 5; i++)
	{
		a.push_back(i + 2);
	}

	for (int i = 0; i < 4; i++)
	{
		b.push_back(i-1);
	}

	cout << "List à:\n";
	a.show_list();

	cout << "\nList b:\n";
	b.show_list();

	cout << "\nList ñ = a*b :\n";
	c = a * b;
	c.show_list();
	cout << "\nList size c: " << c() << endl << endl;
	cout << "\nassign c[5] = 150" << endl; c[5] = 150;
	cout << "\nList ñ:\n";
	c.show_list();

	List<Pair> p;
	Pair x;

	for (int i = 0; i < 3; i++)
	{
		cout << "\nEnter a pair:\n";
		cin >> x;
		p.push_back(x);
	}

	cout << "\nList p: ";
	p.show_list();

	return 0;
}
