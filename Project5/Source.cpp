#include"Header.h"

int main()
{
	system("chcp 1251 >> null");

	Vector vec(2);
	triad tr;
	Time tim;
	int x, y, z;

	cout << "Enter the triad:\n";
	cout << "Enter the first number of the triad: ";
	cin >> x;
	tr.setFirst(x);

	cout << "Enter the second number of the triad: ";
	cin >> y;
	tr.setSecond(y);

	cout << "Enter the third number of the triad: ";
	cin >> z;
	tr.setThird(z);

	cout << "Triad: ";
	tr.print();

	cout << "\n\nEnter the time:\n";
	cin >> tim;
	cout << tim;	

	triad* pr = &tr;
	vec.fillVector(pr);

	pr = &tim;
	vec.fillVector(pr);
	
	cout << "\n\nVector:\n";
	cout << vec;

	return 0;
}