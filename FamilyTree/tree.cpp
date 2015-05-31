#include "tree.h"

void Tree::addhuman(std::string Aname)
{
	Human* h = new Human(Aname);
	founders[Aname] = h;
	all[Aname] = h;
}

void Tree::addlink(std::string ParentName, std::string ChildName)
{
	Human* Aparent = all[ParentName];
	Human* Achild = all[ChildName];
	if (Aparent == Achild)
		return;
	Aparent->addchild(Achild);
	Achild->addparent(Aparent);
};

void Tree::addpartner(std::string p1, std::string p2)
{
	Human* Apartner1 = all[p1];
	Human* Apartner2 = all[p2];
	if (Apartner1 == Apartner2)
		return;
	Apartner1->addpartner(Apartner2);
	Apartner2->addpartner(Apartner1);
};

Tree::Human* Tree::find(std::string Aname)
{
	return all[Aname];
};

void Tree::showinfo(Human* h)
{
	if (h)
		h->show();
};

void Tree::findinfo(std::string Aname)
{
	showinfo(find(Aname));
};
