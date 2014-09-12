#include <iostream>
using namespace std;
int a,b,c,d;
double x1,x2;
int main()
{
	setlocale(LC_ALL, "Russian");
	cout<<"Введите коэффициенты a,b,c"<<endl;
	cin>>a>>b>>c;
	d=b*b-4*a*c;
	if(d<0)
		cout<<"Действительных корней нет"<<endl;
	else
	{	
		x1=-b+sqrt(d);
		x2=-b-sqrt(d);
		cout<<"x1="<<x1<<" ;"<<"x2="<<x2;
	}
	system ("pause");
	return 0;
}
