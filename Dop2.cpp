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
	cin.getline(str1,INT_MAX,'\n');
	cout<<"Введите 2 строку"<<endl;
	cin.getline(str2,INT_MAX,'\n');
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
	cout<<strmax<<endl;
	lenmax=len(strmax);
	lenmin=len(strmin);
	char* bufmax = new char[lenmax];
	char* bufmin = new char[lenmin];
	char* res = new char[lenmin];
	res[0]='\0';
	for (int j=lenmax-1; j>=0; j--)
	{
		char* bufmax = new char[lenmax];
		for (int k=0; k+j<=lenmin-1; k++)
		{
			int s=0;
			for (int i=0; i<=j; i++)
			{
				bufmax[i]=strmax[i+k];
				s++;
			}
			bufmax[s]=0;
			for (int p=lenmin-1; p>=0; p--)
			{
				for (int q=0; q+p<=lenmin-1; q++)
				{
					int s=0;
					for (int i=0; i<=p; i++)
					{
						bufmin[i]=strmin[i+q];
						if (bufmax[i]!=bufmin[i])
						{
							bufmin[0]='\0';
							break;
						}
						s++;
					}
					bufmin[s]=0;
					if (len(bufmin)>0)
					{
						if (len(bufmin)>len(res))
							ch(res,bufmin);
					}
				}
			}
		}
	}
	cout<<"Результат :"<<res<<endl;
	return res;
}
int main()
{
	findLongestSubstring();
	return 0;
}
