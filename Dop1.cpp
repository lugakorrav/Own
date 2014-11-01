#include <iostream>
using namespace std;
int main()
{
	int A=0,B=0,S=0,alen,blen,slen=0;
	char* a = new char[];
	char* b = new char[];
	char* s = new char[];
	char* t = new char[];
	cin.getline(a, 32, '\n');
	cin.getline(b, 32, '\n');
	for (int i=0; a[i]!=0; i++)
	{
		alen=i+1;
	}
	for (int i=0; b[i]!=0; i++)
		blen=i+1;
	for (int i=0; a[i]!=0; i++)
	{
		S=S+((int)(a[i])-(int)'0')*pow(10,alen-i-1)+((int)(b[i])-(int)'0')*pow(10,blen-i-1);
	}
	for (int i=0; S>0; i++)
	{
		s[i]=(char)((int)'0'+(S%10));
		S/=10;
		slen++;
	}
	s[slen]=0;
	for (int i=0; i<=slen-1; i++)
		t[i]=s[slen-i-1];
	t[slen]=0;
	cout<<s<<endl;;
	cout<<t;
	return 0;
}
