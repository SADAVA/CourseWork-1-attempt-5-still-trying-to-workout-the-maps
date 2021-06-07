#pragma once
#include <list>
#include <map>

#include "Item.h"

typedef std::list<Item*> subgroup;
typedef std::map<int, subgroup*> group;
typedef std::map<char, group*> structure;
