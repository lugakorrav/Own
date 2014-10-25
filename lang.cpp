#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
using namespace std;
char t;
void lang()
{
	setlocale(LC_ALL, "Russian");
	cin>>t;
	if ((int)t==-15)
		t=-72;
	else
		if (((int)t>=-32)&&((int)t<=17))
			t=t+16;
		else
			t=t+64;
	cout<<t<<" ";
}
int main()
{
	setlocale(LC_ALL, "Russian");
	for (int i=0; i<33; i++)
		lang();
	return 0;
}
