#include <iostream>
using namespace std;
int len(char* str)
{
	int i=0;
	while (str[i]!='\0')
		i++;
	return i;
}
void ch (char* str1,char* str2)
{
	int i=0;
	while (str2[i]!='\0')
	{
		str1[i]=str2[i];
		i++;
	}
	str1[i]='\0';
}
char* findLongestSubstring()
{
	setlocale(LC_ALL, "russian");
	int lenmax=1, lenmin=1;
	char* str1 = new char[];
	char* str2 = new char[];
	char* strmax = new char[];
	char* strmin = new char[];
	cout<<"Введите 1 строку"<<endl;
	cin.getline(str1,'\n');
	cout<<"Введите 2 строку"<<endl;
	cin.getline(str2,'\n');
	if (str2>str1)
	{
		ch(strmax,str2);
		ch(strmin,str1);
	}
	else
	{
		ch(strmax,str1);
		ch(strmin,str2);
	}
	lenmax=len(strmax);
	lenmin=len(strmin);
	for (int j=lenmax-1; j>=0; j--)
	{
		char* bufmax = new char[lenmax];
		for (int k=0; k+j<=lenmin-1; k++)
		{
			char* bufmax = new char[lenmax];
			int s=0;
			for (int i=0; i<=j; i++, s++)
				bufmax[i]=strmax[i+k];
			bufmax[s+1]='\0';
			for (int p=lenmin-1; p>=0; p--)
			{
				for (int q=0; q+p<=lenmin-1; q++)
				{
					char* bufmin = new char[lenmin];
					int s=0;
					for (int i=0; i<=p; i++,s++)
					{
						bufmin[i]=strmin[i+q];
						if (bufmax[i]!=bufmin[i])
						{
							bufmin="\0";
							break;
						}
					}
					if (len(bufmin)>0)
					{
						bufmin[s]='\0';
						cout<<"Результат :"<<bufmin<<endl;
						return bufmin;
					}
					delete [] bufmin;
				}
			}
			delete [] bufmax;
		}
	}
	cout<<"---"<<endl;
	return '\0';
}
int main()
{
	findLongestSubstring();
	return 0;
}
