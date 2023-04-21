#include "Dialog.h"
#include <iostream>
#include "windows.h"
using namespace std;

int main()
{
	system("chcp 1251 >>null");

	Dialog D;
	D.Execute();

	return 0;
}