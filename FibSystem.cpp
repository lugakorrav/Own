#include<iostream>
#include<fstream>
using namespace std;
int CalcSize(int number)
{
	int count=1;
	int fibmin=1;
	int fibmax=1;
	int buffer=0;
	while (fibmax<number)
	{
		buffer=fibmax;
		fibmax=fibmax+fibmin;
		fibmin=buffer;
		if (fibmax<=number)
			count++;
	}
	return count;
}
int* FibCreate(int Size)
{
	int* Arr = new int[Size];
	Arr[0]=1;
	Arr[1]=2;
	for (int i=2; i<Size; i++)
	{
		Arr[i]=Arr[i-1]+Arr[i-2];
	}
	return Arr;
}
int main()
{
	ifstream in("in.txt");
	ofstream out("out.txt");
	int number;
	int fibnumber=0;
	int nextnumber;
	int Size=0;
	int* Arr;
	while (!in.fail())
	{
		fibnumber=0;
		nextnumber=0;
		in>>number;
		if (in.fail())
			break;
		if (number==0)
		{
			out<<0<<" ";
			continue;
		}
		Size=CalcSize(number);
		Arr=FibCreate(Size);
		for (int i=0; i<Size; i++)
		{
			nextnumber=fibnumber+Arr[Size-i-1];
			if (nextnumber<=number)
			{
				fibnumber=nextnumber;
				out<<1;
			}
			else
				out<<0;
		}
		out<<" ";
		delete[] Arr;
	}
	return 0;
}
