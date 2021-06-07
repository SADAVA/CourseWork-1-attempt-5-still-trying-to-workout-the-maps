
// And it is time for the 5th attempt!
// Those damn maps just don't want to work for some hell of a reason.
// 7.06.2021, just a few days until the deadline and I am stuck on the very first coursework, guess I am doomed.
// C'mon! C++! WORK PLEASE. Can you give me more informative error messages??

#include <iostream>


#include "Data.h"

std::string task_log_prefix = "[---TASK---] ";
std::string test_log_prefix = "[TEST] ";

int main()
{
	// A little heading
    std::cout << std::endl << std::endl << std::endl;

	
	// --- // --- // --- //

	
    std::cout << task_log_prefix << "[1.] Create object containing 300 items. Use methods PrintAll()" << std::endl;
    std::cout << task_log_prefix << "and CountItems() to check the created object."                   << std::endl;
    std::cout << task_log_prefix << "P.S. I have reduced the amount of *printed* items to 20 because" << std::endl;
    std::cout << task_log_prefix << "     there is no point trashing the console output."             << std::endl;
    std::cout << std::endl;

    auto items_count = 300;

    std::cout << test_log_prefix << "Creating a new `Data` object with items_count: " << items_count << std::endl;
	auto* const data_1 = new Data(items_count);

    std::cout << test_log_prefix << "Calling: data_1->PrintAll();" << std::endl;
    data_1->PrintAll();

    std::cout << test_log_prefix << "CountItems() result: " << data_1->CountItems() << ", whereas expected count is: " << items_count << std::endl;

	
    // --- // --- // --- //


    std::cout << std::endl << std::endl << std::endl;
    std::cout << task_log_prefix << "[2.] Select a group.Condition: there must be at least one subgroup"       << std::endl;
    std::cout << task_log_prefix << "containing at least two items."                                           << std::endl;
    std::cout << task_log_prefix << "Apply methods PrintGroup() and CountGroupItems() for the selected group." << std::endl;
    std::cout << std::endl;

    char selected_group_key_2 = NULL;

    for (auto group = data_1->structure_.begin(); group != data_1->structure_.end(); ++group)
    {
    	// First condition
    	if (!group->second->empty()) continue;
    	
        for (auto subgroup = group->second->begin(); subgroup != group->second->end(); ++subgroup)
        {
        	// Second condition
            if (subgroup->second->size() < 2) continue;

            selected_group_key_2 = group->first;
        }
    }

    if (selected_group_key_2 == NULL) {
        selected_group_key_2 = 'a';
        std::cout << "There were no group selected, that is strange, but... whatever, let our selected group just be: " << selected_group_key_2 << std::endl;
    } else {
        std::cout << "The selected selected_group_key_2 is: " << selected_group_key_2 << std::endl;
    }
	
    std::cout << test_log_prefix << "Calling: CountGroupItems(selected_group_key_2);" << std::endl;
    data_1->CountGroupItems(selected_group_key_2);

    std::cout << test_log_prefix << "Calling: PrintGroup(selected_group_key_2);" << std::endl;
    data_1->PrintGroup(selected_group_key_2);
	
        

	// --- // --- // --- //

	
	// Footer
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "Done" << std::endl;
    std::cout << std::endl << std::endl << std::endl;
}
