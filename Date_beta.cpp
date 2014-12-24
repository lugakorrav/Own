#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int Size=0;
class date
{
private:
	int day;
	int month;
	int year;
public:
	bool operator > (date& d)
	{
		if (this->year>d.year)
			return true;
		else
			if (this->year==d.year)
				if (this->month>d.month)
					return true;
				else
					if (this->month==d.month)
						if (this->day>d.day)
							return true;
						else
							return false;
					else
						return false;
			else
				return false;
	}
};
void Swap(date* d, int index1, int index2)
{
	date buffer;
	buffer=d[index1];
	d[index1]=d[index2];
	d[index2]=d[index1];
}
void SortArray (date* d)
{
	for (int i=0; i<Size; i++)
	{
		for (int i=0; i<Size; i++)
			Swap(d, i, i+1);
	}
}
void WriteArray (date* d, ifstream& in)
{
	string buffer;
	for (int i=0; i<Size; i++)
	{
		while (!buffer[i]
int CalcLenght(ifstream& in) // Подсчет количества дат
{
	int count;
	string str;
	while (!in.fail())
	{
		in>>str;
		count++;
	}
	return count;
}
int main()
{
	Size=CalcLenght(in);
	ifstream in("in.txt");
	date* Arr = new date[Size];
