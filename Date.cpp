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
	int count=0;
	string str;
	while (!in.fail())
	{
		in>>str;
		if (in.fail())
			break;
		count++;
	}
	in.clear();
	in.seekg(0);
	return count;
}
string ReadDate (ifstream& in) // Чтение даты из файла
{
	string buffer;
	char bufchar=0;
	while ((bufchar!='.')&&(bufchar!='\n')&&(!in.fail()))
	{
		in>>bufchar;
		if ((bufchar=='.')||(bufchar=='\n')||(in.fail()))
			break;
		buffer+=bufchar;
	}
	return buffer;
}
void ReadArray (ifstream& in, date* d) // Чтение из файла в массив
{
	string str;
	for (int i=0; i<Size; i++)
	{
		d[i].day=stoi(ReadDate(in));
		d[i].month=stoi(ReadDate(in));
		in>>str;
		d[i].year=stoi(str);
	}
	in.seekg(0);
}
void Swap(date* d, int index1, int index2) // Перестановка элементов массива
{
	date buffer;
	buffer=d[index1];
	d[index1]=d[index2];
	d[index2]=buffer;
}
void SortArray (date* d) // Сортировка элементов массива по возрастанию
{
	for (int i=0; i<Size; i++)
	{
		for (int i=0; i<Size; i++)
			if (d[i]>d[i+1])
				Swap(d, i, i+1);
	}
}
void WriteArray (ofstream& out, date* d) // Запись из массива в файл
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
