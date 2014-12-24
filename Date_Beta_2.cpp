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
	friend void ReadArray (ifstream& in, date* d);
	friend void WriteArray (ofstream& out, date* d);
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
int CalcLenght(ifstream& in) // Подсчет количества дат
{
	int count;
	string str;
	while (!in.fail())
	{
		in>>str;
		count++;
	}
	in.seekg(0);
	return count;
}
string ReadDate (ifstream& in) // Чтение даты из файла
{
	string buffer;
	char bufchar;
	while ((bufchar!='.')&&(bufchar!='\n'))
	{
		in>>bufchar;
		if ((bufchar=='.')&&(bufchar=='\n'))
			break;
		buffer+=bufchar;
	}
	return buffer;
}
void ReadArray (ifstream& in, date* d) // Запись из файла в массив
{
	for (int i=0; i<Size; i++)
	{
		d[i].day=stoi(ReadDate(in));
		d[i].month=stoi(ReadDate(in));
		d[i].year=stoi(ReadDate(in));
	}
	in.seekg(0);
}
void Swap(date* d, int index1, int index2) // Перестановка элементов массива
{
	date buffer;
	buffer=d[index1];
	d[index1]=d[index2];
	d[index2]=d[index1];
}
void SortArray (date* d) // Сортировка элементов массива по возрастанию
{
	for (int i=0; i<Size; i++)
	{
		for (int i=0; i<Size; i++)
			Swap(d, i, i+1);
	}
}
void WriteArray (ofstream& out, date* d)
{
	for (int i=0; i<Size; i++)
		out<<d[i].day<<'.'<<d[i].month<<'.'<<d[i].year<<endl;
}

int main()
{
	ifstream in("in.txt");
	ofstream out("out.txt");
	Size=CalcLenght(in);
	date* Arr = new date[Size];
	ReadArray (in, Arr);
	SortArray (Arr);
	WriteArray (out, Arr);
	return 0;
}
