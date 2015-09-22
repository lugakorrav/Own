#include <iostream>
#include <iomanip>
#include <fstream>
#define POS 22

using namespace std;

void printspace(int num, ofstream& out)
{
	for (int i = 0; i < num; i++)
		out << " ";
};

void print(ofstream& out)
{
	out << "N|";
	printspace(POS - 2, out);
	out << "S |";
	printspace(POS - 2, out);
	out << "a |";
	printspace(POS - 3, out);
	out << "Ea |";
	printspace(POS - 3, out);
	out << "Er\n";
	for (int i = 0; i < (POS + 1) * 4 + 2; i++)
		out << "=";
	out << endl;
}

void TSeries_Float(float x, ofstream& out)
{
	float min = 0.00001;
	float e = exp(-x);
	float a, S, Ea, Er;
	int N;
	out << "\nx = " << x << "\n\n";
	out << "Первый способ: \n";
	print(out);
	for (N = 0, a = 1, S = 1, Ea = abs(S - e), Er = Ea / e; abs(a) > min; N++)
	{
		Ea = abs(S - e);
		Er = Ea / e;
		out << setw(2) << N << " ";
		out << setw(POS) << S << " ";
		out << setw(POS) << a << " ";
		out << setw(POS) << Ea << " ";
		out << setw(POS) << Er << endl;
		a = a*(-x) / (N + 1);
		S += a;
	}
	out << "\nВторой способ: \n";
	print(out);
	for (N = 0, a = 1, S = 1, Ea = abs(S - e), Er = Ea / e; abs(a) > min; N++)
	{
		Ea = abs(1 / S - e);
		Er = Ea / e;
		out << setw(2) << N << " ";
		out << setw(POS) << 1 / S << " ";
		out << setw(POS) << a << " ";
		out << setw(POS) << Ea << " ";
		out << setw(POS) << Er << endl;
		a = a*x / (N + 1);
		S += a;
	}
}

void TSeries_Double(double x, ofstream& out)
{
	double min = 0.00001;
	double e = exp(-x);
	double a, S, Ea, Er;
	int N;
	out << "\nx = " << x << "\n\n";
	out << "Первый способ: \n";
	print(out);
	for (N = 0, a = 1, S = 1, Ea = abs(S - e), Er = Ea / e; abs(a) > min; N++)
	{
		Ea = abs(S - e);
		Er = Ea / e;
		out << setw(2) << N << " ";
		out << setw(POS) << S << " ";
		out << setw(POS) << a << " ";
		out << setw(POS) << Ea << " ";
		out << setw(POS) << Er << endl;
		a = a*(-x) / (N + 1);
		S += a;
	}
	out << "\nВторой способ: \n";
	print(out);
	for (N = 0, a = 1, S = 1, Ea = abs(S - e), Er = Ea / e; abs(a) > min; N++)
	{
		Ea = abs(1 / S - e);
		Er = Ea / e;
		out << setw(2) << N << " ";
		out << setw(POS) << 1 / S << " ";
		out << setw(POS) << a << " ";
		out << setw(POS) << Ea << " ";
		out << setw(POS) << Er << endl;
		a = a*x / (N + 1);
		S += a;
	}
}

int main()
{
	ofstream out("out.txt");
	out << fixed;
	out << "Одинарная точность: \n\n";
	TSeries_Float(0.5, out);
	TSeries_Float(5, out);
	TSeries_Float(10, out);
	out << "Двойная точность: \n\n";
	TSeries_Double(0.5, out);
	TSeries_Double(5, out);
	TSeries_Double(10, out);
}
