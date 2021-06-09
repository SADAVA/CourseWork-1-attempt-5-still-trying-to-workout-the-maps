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
		std::left << std::setw(27) << "Name" <<
		std::setw(6) << "Group" <<
		std::setw(9) << "Subgroup" <<
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
	if (item == nullptr) return;

	std::cout << *item << std::endl;
}

group* Data::GetGroup(char c)
{
	auto search = structure_.find(c);

	if (search == structure_.end())
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

	if (search == group->end())
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
	if (subgroup_ == nullptr) return;

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
	if (subgroup_ == nullptr) return;

	subgroup* copy(subgroup_);

	copy->sort(CompareDates);

	PrintSubgroup(copy);
}

bool Data::CompareNames(Item* first, Item* second)
{
	return first->get_name() < second->get_name();
}

bool Data::CompareDates(Item* first, Item* second)
{
	return first->get_timestamp() < second->get_timestamp();
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
	// Subgroup already exists.
	if (structure_.count(s) != 0)
		if ((*structure_[s]).count(i) != 0)
			return nullptr;

	// Create missing group
	if (structure_.count(s) == 0)
	{
		structure_[s] = new group;
	}

	return (*structure_[s])[i] = new subgroup(items);
}

group* Data::InsertGroup(char c, std::initializer_list<int> subgroups, std::initializer_list<std::initializer_list<Item*>> items)
{
	if (structure_.count(c) != 0)
		return nullptr;

	structure_[c] = new group;

	auto s = subgroups.begin();
	auto i = items.begin();

	while (s != subgroups.end())
	{
		InsertSubgroup(c, *s, *i);

		++s;
		++i;
	}

	return structure_[c];
}

bool Data::RemoveItem(char c, int i, std::string s)
{
	if (structure_.count(c) == 0)
		return false;

	if ((*structure_[c]).count(i) == 0)
		return false;

	const auto group = structure_[c];
	const auto subgroup = (*structure_[c])[i];

	for (auto item = subgroup->begin(); item != subgroup->end(); ++item)
	{
		if ((*item)->get_name() == s)
		{
			subgroup->remove(*item);

			if (subgroup->empty())
				structure_[c]->erase(i);

			if (group->empty())
				structure_.erase(c);

			return true;
		}
	}

	return false;
}

bool Data::RemoveSubgroup(char c, int i)
{
	if (structure_.count(c) == 0)
		return false;

	if ((*structure_[c]).count(i) == 0)
		return false;

	const auto subgroup = (*structure_[c])[i];

	if (!subgroup->empty())
	{
		for (auto item = subgroup->begin(); item != subgroup->end(); ++item)
		{
			subgroup->remove(*item);
		}
	}

	structure_[c]->erase(i);

	return true;
}

bool Data::RemoveGroup(char c)
{
	if (structure_.count(c) == 0)
		return false;

	if (!structure_[c]->empty())
	{
		for (auto subgroup = structure_[c]->begin(); subgroup != structure_[c]->end(); ++subgroup)
		{
			RemoveSubgroup(c, subgroup->first);
		}
	}

	structure_.erase(c);

	return true;
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
	return CountGroupItems(GetGroup(c));
}

int Data::CountGroupItems(group* group)
{
	if (group == nullptr) return 0;

	int result = 0;

	for (auto subgroup = group->begin(); subgroup != group->end(); ++subgroup)
	{
		result += CountSubgroupItems(subgroup->second);
	}

	return result;
}

int Data::CountSubgroupItems(char c, int i)
{
	return CountSubgroupItems(GetGroup(c), i);
}

int Data::CountSubgroupItems(group* group, int i)
{
	return CountSubgroupItems(GetSubgroup(group, i));
}

int Data::CountSubgroupItems(subgroup* subgroup)
{
	if (subgroup == nullptr) return 0;

	int result = 0;

	for (auto item = subgroup->begin(); item != subgroup->end(); ++item)
	{
		++result;
	}

	return result;
}

Item* Data::InsertItem(Item* item)
{
	if (item == nullptr) return nullptr;

	if (structure_.count(item->get_group()) == 0)
		structure_[item->get_group()] = new group;

	if ((*structure_[item->get_group()]).count(item->get_subgroup()) == 0)
		(*structure_[item->get_group()])[item->get_subgroup()] = new subgroup;

	(*structure_[item->get_group()])[item->get_subgroup()]->push_back(item);

	return item;
}
