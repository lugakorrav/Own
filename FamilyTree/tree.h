#include <set>
#include <map>
#include <queue>
#include <iostream>
#pragma once

class Tree
{
private:
	class Human
	{
	private:
		Human* partner;
		Human* father;
		Human* mother;
		std::map<std::string, Human*> children;
		std::string name;

	public:
		Human(std::string Aname);
		void addparent(Human* Aparent);
		void addchild(Human* Achild);
		void addpartner(Human* Apartner);
		std::string getname();
		//Human* checkchildren(Human* h);
		void show();
	};

	std::map<std::string, Human*> founders;
	std::map<std::string, Human*> all;
	Human* find(std::string Aname);
	void showinfo(Human* h);
public:
	void addhuman(const std::string Aname);
	void addlink(std::string ParentName, std::string ChildName);
	void addpartner(std::string p1, std::string p2);
	void delhuman(std::string h);
	void dellink(std::string h);
	void delpartner(std::string h);
	void findinfo(std::string Aname);
};
