#include"Header.h"

fraction make_fraktion(double F, double S)
{
	fraction temp;
	temp.Init(F,S);
	return temp;
}

int main()
{
	system("chcp 1251 >> null");

	fraction one;
	double x1, y1;

	cout << "Enter the coordinates of the first point:\n";
	one.Write();
	one.Show();

	cout << "\nEnter the coordinates of the additional point(x;y):\n";
	cin >> x1 >> y1;
	cout << "\nDistance between points: " << one.schet(x1, y1);

	return 0;
}