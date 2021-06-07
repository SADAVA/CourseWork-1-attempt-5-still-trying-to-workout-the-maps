#pragma once

#include <string>

#include "Date.h"

class Item
{
private:
	char Group; // Any from range 'A'...'Z'
	int Subgroup; // Any from range 0...99
	std::string Name; // Any, but not empty
	Date Timestamp; // Any

public:
	Item(); // Fills the four fields above with preudo-random values
	Item(char, int, std::string, Date);
	Item(const Item&); // copy constructor
	~Item();

	// Added
	char get_group();
	int get_subgroup();
	std::string get_name();
	Date get_timestamp();
	friend std::ostream& operator<<(std::ostream& out, const Item& item);
};
