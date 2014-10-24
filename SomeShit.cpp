#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
using namespace std;
int main()
{
	int i=0,j=0;
	char* t = new char[];
	char* out = new char[];
	char min1='а', min2='А', max1='я', max2='Я';
	cin.getline(t,'/n');
	int len = strlen(t);
	for (int k=0; k<len; k++)
		cout<<t[k];
	if (t[i]=min1)
		cout<<t[i];
	while (i<len)
	{
		cout<<t[i];
		while (((t[i]>=min1)&&(t[i]<=max1))||((t[i]>=min2)&&(t[i]<=max2)))
		{
			cout<<t[i];
			if ((t[i]='а')||(t[i]='в')||(t[i]='е')||(t[i]='к')||(t[i]='м')||(t[i]='н')||
				(t[i]='о')||(t[i]='р')||(t[i]='с')||(t[i]='т')||(t[i]='х')||
				(t[i]='А')||(t[i]='В')||(t[i]='Е')||(t[i]='К')||(t[i]='М')||
				(t[i]='Н')||(t[i]='О')||(t[i]='Р')||(t[i]='С')||(t[i]='Т')||(t[i]='Х'))
			{
				cout<<t[i];
				out[j]=t[i];
				cout<<t[i];
				i++; j++;
			}
			else
			{
				while (((t[i]>'а')&&(t[i]<'я'))||(t[i]>'А')||(t[i]<'Я'))
				{
					i++;
				}
				break;
			}
		}
		i++;
	}
	system("pause");
	return 0;
}
