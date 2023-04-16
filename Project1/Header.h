#pragma once
#include <iostream>
using namespace std;
struct fraction
{
	double first;
	double second;
	void Init(double, double);//метод для инициализации полей
	void Write();//метод для чтения значений полей
	void Show();//метод для вывода значений полей
	double schet(double x1, double y1);//вычисление расстояния
};
