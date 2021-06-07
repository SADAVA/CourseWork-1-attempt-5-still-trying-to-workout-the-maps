#include "Data.h"


#include <iomanip>
#include <iostream>

Data::Data(int n)
{
	for (auto i = 0; i < n; i++)
		InsertItem(new Item);
}

Data::Data()
{
	//
}

Data::~Data()
{
	//
}

void Data::PrintAll()
{
	std::cout <<
		std::left  << std::setw(27) << "Name" <<
		              std::setw(6)  << "Group" <<
		              std::setw(9)  << "Subgroup" <<
		              std::setw(11) << "Timestamp" <<
		              std::endl;

	// It is not spagetti, it is pasta!
	int difficult_problems_require_hard_measures_hard_coded_console_trimmer = 0;
	
	for (auto group = structure_.begin(); group != structure_.end(); ++group)
	{
		for (auto subgroup = group->second->begin(); subgroup != group->second->end(); ++subgroup)
		{
			for (auto item = subgroup->second->begin(); item != subgroup->second->end(); ++item)
			{
				std::cout << **item << std::endl;

				++difficult_problems_require_hard_measures_hard_coded_console_trimmer;

				if (difficult_problems_require_hard_measures_hard_coded_console_trimmer > 20)
				{
					std::cout << " *** Output was trimmed *** " << std::endl;
					return;
				}
			}
		}
	}
}

void Data::PrintGroup(char c)
{
	//
}

group* Data::GetGroup(char c)
{
	auto search = structure_.find(c);

	if (search->second == nullptr)
		return nullptr;
	else
		return search->second;
}

subgroup* Data::GetSubgroup(char c, int i)
{
	return nullptr;
}

subgroup* Data::GetSubgroup(group* group, int i)
{
	return nullptr;
}

void Data::PrintSubgroupByNames(char c, int i)
{
	//
}

void Data::PrintSubgroupByDates(char c, int i)
{
	//
}


Item* Data::GetItem(char c, int i, std::string s)
{
	return nullptr;
}

void Data::PrintItem(char c, int i, std::string s)
{
	//
}

Item* Data::InsertItem(char c, int i, std::string s, Date d)
{
	return nullptr;
}

subgroup* Data::InsertSubgroup(char s, int i, std::initializer_list<Item*> items)
{
	return nullptr;
}

group* Data::InsertGroup(char c, std::initializer_list<int> subgroups, std::initializer_list<std::initializer_list<Item*>> items)
{
	return nullptr;
}

bool Data::RemoveItem(char c, int i, std::string s)
{
	return false;
}

bool Data::RemoveSubgroup(char c, int i)
{
	return false;
}

bool Data::RemoveGroup(char c)
{
	return false;
}

// Added

int Data::CountItems()
{
	int result = 0;
	
	for (auto group = structure_.begin(); group != structure_.end(); ++group)
	{
		result += CountGroupItems(group->second);
	}

	return result;
}

int Data::CountGroupItems(char c)
{
	auto group = GetGroup(c);

	if (group == nullptr)
		return 0;
	else return CountGroupItems(group);
}

int Data::CountGroupItems(group* group)
{
	int result = 0;

	for (auto subgroup = group->begin(); subgroup != group->end(); ++subgroup)
	{
		result += CountSubgroupItems(subgroup->second);
	}

	return result;
}

int Data::CountSubgroupItems(char c, int i)
{
	auto group = GetGroup(c);

	if (group == nullptr)
		return 0;
	else return CountSubgroupItems(group, i);
}

int Data::CountSubgroupItems(group* group, int i)
{
	auto subgroup = GetSubgroup(group, i);

	if (subgroup == nullptr)
		return 0;
	else return CountSubgroupItems(subgroup);
}

int Data::CountSubgroupItems(subgroup* subgroup)
{
	int result = 0;

	for (auto item = subgroup->begin(); item != subgroup->end(); ++item)
	{
		++result;
	}

	return result;
}

Item* Data::InsertItem(Item* item)
{
	if (structure_[item->get_group()] == nullptr)
		structure_[item->get_group()] = new group;

	if ((*structure_[item->get_group()])[item->get_subgroup()] == nullptr)
		(*structure_[item->get_group()])[item->get_subgroup()] = new subgroup;

	(*structure_[item->get_group()])[item->get_subgroup()]->push_back(item);
	
	return item;
}
