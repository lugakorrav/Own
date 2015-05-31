#include <iostream>
#include "tree.h"

int main()
{
	setlocale(LC_ALL, "rus");
	Tree t;
	t.addhuman("x");
	t.addhuman("y");
	t.addlink("y", "x");
	system("pause");
	t.findinfo("y");
	system("pause");
};
