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
		bool sex;
		std::string name;

	public:
		Human(std::string Aname, bool Asex);
		~Human();

		void addparent(Human* Aparent);
		void addchild(Human* Achild);
		void addpartner(Human* Apartner);

		void delparent(Human* Aparent);
		void delchild(Human* Achild);
		void delpartner(Human* Apartner);

		std::string getname();
		//Human* checkchildren(Human* h);
		void show();
	};

	std::map<std::string, Human*> founders;
	std::map<std::string, Human*> all;
	Human* find(std::string Aname);
	void showinfo(Human* h);
public:
	void addhuman(const std::string Aname, bool Asex);
	void addlink(std::string ParentName, std::string ChildName);
	void addpartner(std::string p1, std::string p2);
	void delhuman(std::string);
	void dellink(std::string ParentName, std::string ChildName);
	void delpartner(std::string p1, std::string p2);
	void findinfo(std::string);
};
