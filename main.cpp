#include<iostream>
#include<math.h>
#include<fstream>
#include"circle.h"
using namespace std;
circle *Arr;
bool IsCrossing(int i, int j)
{
	return (pow(pow((Arr[i].x-Arr[j].x),2.0)+pow((Arr[i].y-Arr[j].y),2.0),0.5)<=(Arr[i].r+Arr[j].r));
}
int main()
{
	setlocale(LC_ALL, "rus");
	Arr = new circle;
	int count=0;
	ifstream in("in.txt");
	while (!in.fail())
	{
		in>>Arr[0].x;
		count++;
	}
	Arr = new circle[count];
	count/=3;
	in.clear();
	in.seekg(0);
	for (int i=0; i<count; i++)
		in>>Arr[i].x>>Arr[i].y>>Arr[i].r;
	cout<<"Пересекающиеся окружности: "<<endl<<endl;
	for (int i=0; i<count-1; i++)
	{
		for (int j=i+1; j<count; j++)
		{
			if (IsCrossing(i,j))
			{
				cout<<"x: "<<Arr[i].x<<" y: "<<Arr[i].y<<" r: "<<Arr[i].r<<endl;
				cout<<"x: "<<Arr[j].x<<" y: "<<Arr[j].y<<" r: "<<Arr[j].r<<endl;
				cout<<"---------------------------------"<<endl<<endl;
			}
		}
	}
	system("pause");
	return 0;
}
