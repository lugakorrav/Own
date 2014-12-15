#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int NumArr[9]={1000,500,100,50,10,9,5,4,1};
string SymArr[9]={"M","D","C","L","X","IX","V","IV","I"};
void convert(int number)
{
	for (int i=0; number>0; i++)
		while (number/NumArr[i]>0)
		{
			cout<<SymArr[i];
			number-=NumArr[i];
		}
		cout<<endl<<endl;
}
int main()
{
	int number;
	ifstream in("in.txt");
	while (!in.fail())
	{
		in>>number;
		if (in.fail())
			break;
		convert(number);
	}
	system("pause");
	return 0;
}
