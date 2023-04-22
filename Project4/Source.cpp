#include"Header.h"

int main()
{
	system("chcp 1251 >> null");
	int x, y, z;
	cout << "Enter three integers: ";
	cin >> x >> y >> z;
	triad tr1(x, y, z);
	cout << "\nThe first triad: ";
	tr1.print();

	cout << "\n\nEnter three integers: ";
	cin >> x >> y >> z;
	triad tr2(x, y, z);
	cout << "\nThe second triad: ";
	tr2.print();

	if (tr1 == tr2)
		cout << "\nTriads are equal\n";
	else
		cout << "\nTriads are unequal\n";

	Time t1;
	cin >> t1;
	cout << "\nEntered time: "<<t1;

	Time t2;
	cout << "\n\nEnter a new time\n";
	cin >> t2;
	cout << "\nEntered time: " << t2;

	if (t1 > t2)
		cout << "\n\nThe first time is more\n" << t1;
	else if (t1 < t2)
		cout << "\n\nThe second time is longer\n"<<t2;
	else
		cout << "\nThe time intervals are equal" << t1 << " = " << t2;

	Time t3 = t2;
	cout << endl<<endl<<t3;

	return 0;
}