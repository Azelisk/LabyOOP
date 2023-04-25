#include "List.h"
#include "Error.h"

int main()
{
	system("color F0");
	system("chcp 1251 >> null");

	try
	{
		List lst;
		lst.push_back(10);
		lst.push_back(11);
		lst.push_back(12);
		lst.show_list();
	}
	catch (Error& err)
	{
		err.what();
	}

	return 0;
}