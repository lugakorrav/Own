#include <iostream>
using namespace std;

int len(int number) // Длина числа
{
	int i = 0;
	while (number > 0)
	{
		number /= 10;
		i++;
	}
	return i;
};

int numeral(int number, int place) // Взять цифру с номером "place" (справа налево) из числа number
{
	number /= pow(10, place - 1);
	return (number % 10);
};

int append(int a, int b) // Приписать ЦИФРУ b к ЧИСЛУ a справа
{
	a *= 10;
	a += b;
	return a;
};

int calcdevident(int startnumber, int devident, int devisor, int& marker) // Рассчитать промежуточный делитель
{
	int smalldevident = startnumber;
	while ((smalldevident / devisor == 0) && (marker > 0))
	{
		smalldevident = append(smalldevident, numeral(devident, marker));
		marker--;
	};
	return smalldevident;
};

int calcstart(int smalldevident, int devident, int devisor, int& marker);


void printspace(ostream& out, int spacesize)
{
	for (int i = 0; i < spacesize; i++)
		out << " ";
};

void printline(ostream& out, int linesize)
{
	for (int i = 0; i < linesize; i++)
		out << "-";
};

int main()
{
	setlocale(LC_ALL, "rus");
	int devident; // Делимое
	int devisor; // Делитель
	int result; // Частное
	int sub; // Вычитаемое
	int marker; // "Указатель" на цифру делимого
	int smalldevident = 0;
	int startnumber = 0;
	int spacesize = 1; // Отступ слева
	cout << "Введите делимое" << endl;
	cin >> devident;
	cout << "Введите делитель" << endl;
	cin >> devisor;
	marker = len(devident);
	result = devident / devisor;
	smalldevident = calcdevident(startnumber, devident, devisor, marker);
	startnumber = smalldevident % devisor;
	sub = smalldevident - (smalldevident % devisor);
	printspace(cout, spacesize);
	cout << devident << "|" << devisor << endl;
	printspace(cout, spacesize - 1);
	cout << "-";
	printspace(cout, len(smalldevident) - len(sub));
	cout << sub;
	printspace(cout, len(devident) - len(smalldevident));
	cout << "|";
	if (result > devisor)
	{
		printline(cout, len(result));
	}
	else
	{
		printline(cout, len(devisor));
	};
	cout << endl;
	printspace(cout, spacesize);
	printline(cout, len(smalldevident));
	printspace(cout, len(devident) - len(smalldevident));
	cout << "|" << result << " (Частное)" << endl;
	spacesize += (len(sub) - len(startnumber));
	smalldevident = calcdevident(startnumber, devident, devisor, marker);
	while (smalldevident >= devisor)
	{
		printspace(cout, spacesize);
		sub = smalldevident - (smalldevident % devisor);
		cout << smalldevident << endl;
		printspace(cout, spacesize - 1);
		cout << "-";
		printspace(cout, len(smalldevident) - len(sub));
		cout << sub << endl;
		printspace(cout, spacesize);
		printline(cout, len(smalldevident));
		cout << endl;
		startnumber = smalldevident % devisor;
		smalldevident = calcdevident(startnumber, devident, devisor, marker);
	};
	printspace(cout, spacesize);
	cout << smalldevident << " (Остаток)" << endl;


	return 0;
}
