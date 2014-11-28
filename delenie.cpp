#include<iostream>
#include<string>
#include<stdio.h>
#include<iomanip>
using namespace std;
string itos(int a)
{
	string str="",buf="";
	while (a>0)
	{
		str=char('0'+a%10)+str;
		a/=10;
	}
	return str;
}
int firstnum(string str, int n)
{
	int sum=0;
	for (int i=0; i<n; i++)
		sum=(int)(str[i]*pow(10,n-i));
	return sum;
}
int main()
{
	int S=0;
	string M,N,buffer,buffer2,rez;
	setlocale(LC_ALL,"rus");
	cout<<"Введите делимое"<<endl;
	cin>>M;
	cout<<"Введите делитель"<<endl;
	cin>>N;
	int fsize=M.size()+N.size()+3;
	cout<<M<<" | "<<N<<endl;
	rez=itos(stoi(M)/stoi(N));
	buffer=itos(((int)(rez[0]-'0'))*stoi(N));
	cout<<buffer;
	cout<<right<<setw(fsize-buffer.size())<<setfill(' ')<<rez<<endl;
	buffer2=M;
	for (int i=0, j=1; stoi(buffer2)>=stoi(N); i++,j++)
	{
		cout<<"----"<<endl;
		if (stoi(buffer2)>
		buffer2=itos(firstnum(buffer2,buffer.size())-stoi(buffer))+M[buffer.size()-1+S];				
		buffer=itos((rez[j]-'0')*stoi(N));
		S+=buffer.size()-1;
		cout<<right<<setw(i)<<setfill(' ')<<buffer2<<endl;
	}
	system("pause");
	return 0;
}
