#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <string>
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
		bool gender;
		std::string name;

	public:
		Human(std::string Aname, bool Agender);
		~Human();

		void addparent(Human* Aparent);
		void addchild(Human* Achild);
		void addpartner(Human* Apartner);

		void delparent(Human* Aparent);
		void delchild(Human* Achild);
		void delpartner();

		std::string getname();
		//Human* checkchildren(Human* h);
		void show();
	};

	std::map<std::string, Human*> founders;
	std::map<std::string, Human*> all;
	Human* find(std::string Aname);
	void showinfo(Human* h);
public:
	void addhuman(const std::string Aname, bool Agender);
	void addlink(std::string ParentName, std::string ChildName);
	void addpartner(std::string p1, std::string p2);
	void delhuman(std::string);
	void dellink(std::string ParentName, std::string ChildName);
	void delpartner(std::string p);
	void findinfo(std::string);
	void dialog();
};
