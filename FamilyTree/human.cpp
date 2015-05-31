#include "tree.h"

Tree::Human::Human(std::string Aname, bool Agender) : name(Aname)
{
	partner = 0;
	father = 0;
	mother = 0;
	gender = Agender;
};

Tree::Human::~Human()
{
	if (father)
		father->delchild(this);
	if (mother)
		mother->delchild(this);
	if (partner)
		partner->delpartner();
	for (std::map<std::string, Human*>::iterator it = children.begin(); it != children.end(); it++)
		it->second->delparent(this);
};

void Tree::Human::addchild(Human* Achild)
{
	if (Achild)
		children[Achild->name] = Achild;
};

void Tree::Human::addparent(Human* Aparent)
{
	if (!Aparent)
		return;
	if (Aparent->gender)
	{
		if (father)
			father->delchild(this);
		father = Aparent;
	}
	else
	{
		if (mother)
			mother->delchild(this);
		mother = Aparent;
	}
};

void Tree::Human::addpartner(Human* Apartner)
{
	if (!Apartner)
		return;
	if (partner)
		partner->delpartner();
	partner = Apartner;
};

void Tree::Human::delchild(Human* Achild)
{
	children.erase(Achild->name);
};

void Tree::Human::delparent(Human* Aparent)
{
	if (!Aparent)
		return;
	if (Aparent->gender)
	{
		if (Aparent == father)
			father = 0;
	}
	else
	{
		if (Aparent == mother)
			mother = 0;
	};
};

void Tree::Human::delpartner()
{
	partner->partner = 0;
	partner = 0;
};

std::string Tree::Human::getname()
{
	return name;
};

void Tree::Human::show()
{
	std::cout << "Name: " << getname().data() << '\n';
	std::cout << "Parents:";
	if (father)
		std::cout << father->getname().data();
	if (mother)
		std::cout << mother->getname().data();
	std::cout << '\n';
	std::cout << "Children: ";
	for (std::map<std::string, Human*>::iterator it = children.begin(); it != children.end(); it++)
	{
		std::cout << it->second->getname().data() << ' ';
	};
	std::cout << '\n';
};

//Tree::Human* Tree::Human::checkchildren(Human* h)
//{
//	for (std::map<std::string, Human*>::iterator it = h->children.begin(); it != h->children.end(); it++)
//	{
//		checkchildren(it->second);
//	};

