#include "stdafx.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "russian");

	Turn t;
	cin >> t;
	cout << t << endl;
	cout << t.Length() << endl;

	system("pause");
	return 0;
}
