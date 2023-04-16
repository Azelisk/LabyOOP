#include"Header.h"

void fraction::Init(double F, double S)
{
	first = F;
	second = S;
}

void fraction::Write()
{
	cout << "first = "; cin >> first;
	cout << "\nsecond = "; cin >> second;
}

void fraction::Show()
{
	cout << "\nfirst = " << first;
	cout << "\nsecond = " << second;
	cout << "\n";
}

double fraction::schet(double x1, double y1)
{
	return (sqrt(pow(x1 - first, 2) + pow(y1 - second, 2)));
}