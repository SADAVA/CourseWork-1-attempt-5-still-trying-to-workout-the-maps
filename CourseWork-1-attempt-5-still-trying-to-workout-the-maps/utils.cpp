#include <iostream>
#include <fstream>
#include <list>
#include <random>
#include <string>

#include "Date.h"

std::string names_filepath = "Birds.txt";
std::string names_failure;
typedef std::list<std::string> names_type;
names_type* names;

void load_names()
{
	names = new names_type;

    std::ifstream read_stream(names_filepath.c_str());
	
    if (!read_stream)
    {
		names_failure = "Cannot read the file.";

    	return;
    }

	std::string buffer;

	while (std::getline(read_stream, buffer))
    {
        if (buffer.empty() != true)
            names->push_back(buffer);
    }

	read_stream.close();
}

std::list<std::string>* get_names()
{
	if (!names_failure.empty())
	{
		std::cerr << "Cannot get names due to previous error: " << names_failure << std::endl;

		return nullptr;
	}

	if (names == nullptr || names->empty())
	{
		load_names();

		if (!names_failure.empty())
		{
			std::cerr << "Failure occured while loading names: " << names_failure << std::endl;

			return nullptr;
		}

		if (names == nullptr || names->empty())
		{
			std::cerr << "Unknown error occured, load of names failed." << std::endl;

			return nullptr;
		}
	}

	return names;
}

char random_group()
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr('a', 'z');

	return distr(eng);
}

int random_subgroup()
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(0, 9);

	return distr(eng);
}

std::string random_name()
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(0, get_names()->size());

	int index = distr(eng);
	
	return *std::next(get_names()->begin(), index);
}

Date random_timestamp()
{

	Date* from = new Date(1, 1, 2021);
	Date* until = new Date(1, 1, 2022);

	return Date::CreateRandomDate(*from, *until);
}