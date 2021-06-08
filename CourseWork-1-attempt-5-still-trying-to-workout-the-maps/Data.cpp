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

	for (auto group = structure_.begin(); group != structure_.end(); ++group)
	{
		PrintGroup(group->second);
	}
}

void Data::PrintGroup(char c)
{
	PrintGroup(GetGroup(c));
}

void Data::PrintGroup(group* group)
{
	if (group == nullptr) return;

	for (auto subgroup = group->begin(); subgroup != group->end(); ++subgroup)
	{
		PrintSubgroup(subgroup->second);
	}
}

void Data::PrintSubgroup(char c, int i)
{
	PrintSubgroup(GetGroup(c), i);
}

void Data::PrintSubgroup(group* group, int i)
{
	if (group == nullptr) return;

	PrintSubgroup(GetSubgroup(group, i));
}

void Data::PrintSubgroup(subgroup* subgroup)
{
	if (subgroup == nullptr) return;

	for (auto item = subgroup->begin(); item != subgroup->end(); ++item)
	{
		PrintItem(*item);
	}
}

void Data::PrintItem(Item* item)
{
	std::cout << *item << std::endl;
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
	return GetSubgroup(GetGroup(c), i);
}

subgroup* Data::GetSubgroup(group* group, int i)
{
	if (group == nullptr) return nullptr;

	const auto search = group->find(i);

	if (search->second == nullptr)
		return nullptr;
	else
		return search->second;
}

void Data::PrintSubgroupByNames(char c, int i)
{
	PrintSubgroupByNames(GetGroup(c), i);
}

void Data::PrintSubgroupByNames(group* group, int i)
{
	PrintSubgroupByNames(GetSubgroup(group, i));
}

void Data::PrintSubgroupByNames(subgroup* subgroup_)
{
	subgroup* copy(subgroup_);

	copy->sort(CompareNames);

	PrintSubgroup(copy);
}

void Data::PrintSubgroupByDates(char c, int i)
{
	PrintSubgroupByDates(GetGroup(c), i);
}

void Data::PrintSubgroupByDates(group* group, int i)
{
	PrintSubgroupByDates(GetSubgroup(group, i));
}

void Data::PrintSubgroupByDates(subgroup* subgroup_)
{
	subgroup* copy(subgroup_);

	copy->sort(CompareDates);

	PrintSubgroup(copy);
}

bool Data::CompareNames(Item* first, Item* second)
{
	return first->get_name() == second->get_name();
}

bool Data::CompareDates(Item* first, Item* second)
{
	return first->get_timestamp() == second->get_timestamp();
}

Item* Data::GetItem(char c, int i, std::string s)
{
	return GetItem(GetGroup(c), i, s);
}

Item* Data::GetItem(group* group, int i, std::string s)
{
	if (group == nullptr) return nullptr;
	
	return GetItem(GetSubgroup(group, i), s);
}

Item* Data::GetItem(subgroup* subgroup, std::string s)
{
	if (subgroup == nullptr) return nullptr;

	for (auto item = subgroup->begin(); item != subgroup->end(); ++item)
	{
		if ((*item)->get_name() == s)
			return *item;
	}

	return nullptr;
}

void Data::PrintItem(char c, int i, std::string s)
{
	PrintItem(GetItem(c, i, s));
}

Item* Data::InsertItem(char c, int i, std::string s, Date d)
{
	return InsertItem(new Item(c, i, s));
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
