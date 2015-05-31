#include "tree.h"
#include <conio.h>
#include <stdio.h>

using namespace std;

void Tree::showtip()
{
	cout << "\n--------------------------------------------------------------------------\n";
	cout << "1 - add new person; 2 - remove person; 3 - add link; 4 - remove link;\n";
	cout << "5 - add partner; 6 - remove partner; 7 - find information about person; \nesc - close" << endl;
	cout << "--------------------------------------------------------------------------\n\n";
};

void Tree::dialog()
{
	showtip();
	while (1)
	{
		char c = _getch();
		switch (c)
		{
		case '1':
		{
			string name;
			int gen;
			cout << "Enter a name\n";
			getline(cin, name);
			cout << "Enter a gender\n";
			cin >> gen;
			addhuman(name, gen);
			cin.clear();
			cin.sync();
			showtip();
			break;
		}
		case '2':
		{
			string name;
			cout << "Enter a name\n";
			getline(cin, name);
			delhuman(name);
			cin.clear();
			cin.sync();
			showtip();
			break;
		}
		case '3':
		{
			string parent, child;
			cout << "Enter the name of the parent\n";
			getline(cin, parent);
			cout << "Enter the name of the child\n";
			getline(cin, child);
			addlink(parent, child);
			cin.clear();
			cin.sync();
			showtip();
			break;
		}
		case '4':
		{
			string parent, child;
			cout << "Enter the name of the parent\n";
			getline(cin, parent);
			cout << "Enter the name of the child\n";
			getline(cin, child);
			dellink(parent, child);
			cin.clear();
			cin.sync();
			showtip();
			break;
		}
		case '5':
		{
			string partner1, partner2;
			cout << "Enter the name of the partner\n";
			getline(cin, partner1);
			cout << "Enter the name of the partner\n";
			getline(cin, partner2);
			addpartner(partner1, partner2);
			cin.clear();
			cin.sync();
			showtip();
			break;
		}
		case '6':
		{
			string partner;
			cout << "Enter the name of the partner\n";
			getline(cin, partner);
			delpartner(partner);
			cin.clear();
			cin.sync();
			showtip();
			break;
		}
		case '7':
		{
			string name;
			cout << "Enter a name\n";
			getline(cin, name);
			findinfo(name);
			cin.clear();
			cin.sync();
			showtip();
			break;
		}
		case 27:
		{
			return;
		};
		};
	};
};
