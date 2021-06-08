#include "Item.h"


#include <iomanip>
#include <iostream>


#include "utils.h"

Item::Item()
{
	Group = random_group();
	Subgroup = random_subgroup();
	Name = random_name();
	Timestamp = random_timestamp();
}

Item::Item(char group, int subgroup, std::string name, Date timestamp)
{
	Group = group;
	Subgroup = subgroup;
	Name = name;
	Timestamp = timestamp;
}

Item::Item(const Item& item)
{
	Group = item.Group;
	Subgroup = item.Subgroup;
	Name = item.Name;
	Timestamp = item.Timestamp;
}

Item::Item(char c, std::string s)
{
	Group = c;
	Subgroup = random_subgroup();
	Name = s;
	Timestamp = random_timestamp();
}

Item::Item(char c, int i, std::string s)
{
	Group = c;
	Subgroup = i;
	Name = s;
	Timestamp = random_timestamp();
}

// No pointers, nothing to delete.
Item::~Item() = default;

char Item::get_group()
{
	return Group;
}

int Item::get_subgroup()
{
	return Subgroup;
}

std::string Item::get_name()
{
	return Name;
}

Date Item::get_timestamp()
{
	return Timestamp;
}

std::ostream& operator<<(std::ostream& out, const Item& item)
{
	return out <<
		std::left  << std::setw(27) << item.Name <<
		              std::setw(6)  << item.Group <<
		              std::setw(9)  << item.Subgroup <<
		              std::setw(11) << item.Timestamp;
}
