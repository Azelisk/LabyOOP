#include "List.h"

int main()
{
	system("chcp 1251 >> null");

	List a, b, c;

	a.push_back(2);
	a.push_back(3);
	a.push_back(110);
	a.push_back(-4);

	b.push_back(11);
	b.push_back(11);

	c = a * b;

	cout << "Список c: "; c.show_list();
	cout << "Размер: " << c() << endl << endl;

	cout << "вывод c[0]: " << c[0] << endl;
	cout << "присвоить c[0] = 150" << endl; c[0] = 150;

	cout << "Список c: "; c.show_list(); 

	cout << "\nСписок a: ";
	for (auto it = a.first(); it != a.last(); ++it)
		cout << (*it) << " ";
	cout << endl;

	return 0;
}
