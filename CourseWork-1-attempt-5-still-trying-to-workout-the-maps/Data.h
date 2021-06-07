#pragma once

// I am not gonna write the documentation because I've already done it many times.

#include <list>
#include <map>
#include <string>


#include "common.h"
#include "Item.h"

class Data
{
public:
	structure structure_;
	Data(int n);
	Data();
	~Data();
	void PrintAll();
	group* GetGroup(char c);
	void PrintGroup(char c);
	int CountGroupItems(char c);
	subgroup* GetSubgroup(char c, int i);
	void PrintSubgroupByNames(char c, int i);
	void PrintSubgroupByDates(char c, int i);
	int CountSubgroupItems(char c, int i);
	Item* GetItem(char c, int i, std::string s);
	void PrintItem(char c, int i, std::string s);
	Item* InsertItem(char c, int i, std::string s, Date d);
	subgroup* InsertSubgroup(char s, int i, std::initializer_list<Item*> items);
	group* InsertGroup(char c, std::initializer_list<int> subgroups, std::initializer_list<std::initializer_list<Item*>> items);
	bool RemoveItem(char c, int i, std::string s);
	bool RemoveSubgroup(char c, int i);
	bool RemoveGroup(char c);

	// Added
	int CountItems();
	Item* InsertItem(Item* item);
	int CountGroupItems(group* group);
	int CountSubgroupItems(char c, int i);
	int CountSubgroupItems(group* group, int i);
	int CountSubgroupItems(subgroup* subgroup);
	subgroup* GetSubgroup(group* group, int i);
};