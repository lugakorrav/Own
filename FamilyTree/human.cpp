#include "tree.h"
#pragma once

Tree::Human::Human(std::string Aname) : name(Aname)
{
	partner = 0;
	father = 0;
	mother = 0;
};

void Tree::Human::addchild(Human* Achild)
{
	children[Achild->name] = Achild;
};

void Tree::Human::addparent(Human* Aparent)
{
	father = Aparent;
};

void Tree::Human::addpartner(Human* Apartner)
{
	partner = Apartner;
};

std::string Tree::Human::getname()
{
	return name;
};

void Tree::Human::show()
{
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
