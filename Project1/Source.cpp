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

	cout << "Введите координаты первой точки:\n";
	one.Write();
	one.Show();

	cout << "\nВведите координаты доп.точки(x;y):\n";
	cin >> x1 >> y1;
	cout << "\nРасстояние между точками: " << one.schet(x1, y1);

	return 0;
}