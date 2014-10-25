#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
using namespace std;
void lang()
{
	setlocale(LC_ALL, "Russian");
	ifstream text("D:/text/text.txt");
	if (!text.is_open())
		cout<<"лох"<<endl;
	char ch;
	for(int i=0; i<33; i++)
	{
		text>>ch;
		cout<<(int)ch<<" ";
		text.close();
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	lang();
	return 0;
}
