
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
    group* selected_group_2 = nullptr;

    for (auto group = data_1->structure_.begin(); group != data_1->structure_.end(); ++group)
    {
    	// First condition
    	if (group->second->empty()) continue;
    	
        for (auto subgroup = group->second->begin(); subgroup != group->second->end(); ++subgroup)
        {
        	// Second condition
            if (subgroup->second->size() < 2) continue;

            selected_group_key_2 = group->first;
            selected_group_2 = group->second;

            break;
        }

        if (selected_group_key_2 != NULL) break;
    }

    if (selected_group_key_2 == NULL) {
        selected_group_key_2 = 'a';
        std::cout << test_log_prefix << "There were no group selected, that is strange, but... whatever, let our selected group just be: " << selected_group_key_2 << std::endl;
    } else {
        std::cout << test_log_prefix << "The selected selected_group_key_2 is: " << selected_group_key_2 << std::endl;
    }
	
    std::cout << test_log_prefix << "Calling: CountGroupItems(selected_group_key_2);" << std::endl;
    std::cout << test_log_prefix << "Result: " << data_1->CountGroupItems(selected_group_key_2) << std::endl;

    std::cout << test_log_prefix << "Calling: PrintGroup(selected_group_key_2);" << std::endl;
    data_1->PrintGroup(selected_group_key_2);

	
    // --- // --- // --- //


    std::cout << std::endl << std::endl << std::endl;
    std::cout << task_log_prefix << "[3.] From the selected group select a subgroup containing at least two items." << std::endl;
    std::cout << task_log_prefix << "Apply methods PrintSubgroupByNames(), PrintSubgroupByDates()" << std::endl;
    std::cout << task_log_prefix << "and CountSubgroupItems() for the selected subgroup." << std::endl;
    std::cout << std::endl;

    int selected_subgroup_key_3 = NULL;

    if (selected_group_2 != nullptr) {
        for (auto subgroup = selected_group_2->begin(); subgroup != selected_group_2->end(); ++subgroup)
        {
            if (subgroup->second->size() < 2) continue;

            selected_subgroup_key_3 = subgroup->first;

            break;
        }
    } else std::cout << task_log_prefix << "Could not select a subgroup because selected_group_2 is nullptr." << std::endl;

	if (selected_subgroup_key_3 == NULL)
	{
        selected_subgroup_key_3 = 1;
        std::cout << test_log_prefix << "There were no subgroup selected, that is strange, but... whatever, let our selected subgroup just be: " << selected_subgroup_key_3 << std::endl;
    } else {
        std::cout << test_log_prefix << "The selected selected_subgroup_key_3 is: " << selected_subgroup_key_3 << std::endl;
    }

    std::cout << test_log_prefix << "Calling: PrintSubgroupByNames(selected_subgroup_key_3);" << std::endl;
    data_1->PrintSubgroupByNames(selected_group_2, selected_subgroup_key_3);

    std::cout << test_log_prefix << "Calling: PrintSubgroupByDates(selected_subgroup_key_3);" << std::endl;
    data_1->PrintSubgroupByDates(selected_group_2, selected_subgroup_key_3);


    // --- // --- // --- //


    std::cout << std::endl << std::endl << std::endl;
    std::cout << task_log_prefix << "[4.] From the selected group select a subgroup containing only one item." << std::endl;
    std::cout << task_log_prefix << "Apply methods PrintSubgroupByNames(), PrintSubgroupByDates() and CountSubgroupItems()" << std::endl;
    std::cout << task_log_prefix << "for the selected subgroup." << std::endl;
    std::cout << std::endl;

    int selected_subgroup_key_4 = NULL;

    if (selected_group_2 != nullptr) {
        for (auto subgroup = selected_group_2->begin(); subgroup != selected_group_2->end(); ++subgroup)
        {
            if (subgroup->second->size() != 1) continue;

            selected_subgroup_key_4 = subgroup->first;

            break;
        }
    }
    else std::cout << task_log_prefix << "Could not select a subgroup because selected_group_2 is nullptr." << std::endl;

    if (selected_subgroup_key_4 == NULL)
    {
        selected_subgroup_key_4 = 1;
        std::cout << test_log_prefix << "There were no subgroup selected, that is strange, but... whatever, let our selected subgroup just be: " << selected_subgroup_key_3 << std::endl;
    }
    else {
        std::cout << test_log_prefix << "The selected selected_subgroup_key_4 is: " << selected_subgroup_key_4 << std::endl;
    }

    std::cout << test_log_prefix << "Calling: PrintSubgroupByNames(selected_subgroup_key_4);" << std::endl;
    data_1->PrintSubgroupByNames(selected_group_2, selected_subgroup_key_4);

    std::cout << test_log_prefix << "Calling: PrintSubgroupByDates(selected_subgroup_key_4);" << std::endl;
    data_1->PrintSubgroupByDates(selected_group_2, selected_subgroup_key_4);

    std::cout << test_log_prefix << "Calling: CountGroupItems(selected_subgroup_key_4);" << std::endl;
    std::cout << test_log_prefix << "Result: " << data_1->CountSubgroupItems(selected_group_2, selected_subgroup_key_4) << std::endl;


    // --- // --- // --- //


    std::cout << std::endl << std::endl << std::endl;
    std::cout << task_log_prefix << "[5.] Apply methods PrintSubgroupByNames(), PrintSubgroupByDates() and CountSubgroupItems()" << std::endl;
    std::cout << task_log_prefix << "for a non - existing subgroup." << std::endl;
    std::cout << std::endl;

    int non_existant_subgroup_key_5 = 99;


    std::cout << test_log_prefix << "Calling: PrintSubgroupByNames(non_existant_subgroup_key_5);" << std::endl;
    data_1->PrintSubgroupByNames(selected_group_2, non_existant_subgroup_key_5);

    std::cout << test_log_prefix << "Calling: PrintSubgroupByDates(non_existant_subgroup_key_5);" << std::endl;
    data_1->PrintSubgroupByDates(selected_group_2, non_existant_subgroup_key_5);

    std::cout << test_log_prefix << "Calling: CountGroupItems(non_existant_subgroup_key_5);" << std::endl;
    std::cout << test_log_prefix << "Result: " << data_1->CountSubgroupItems(selected_group_2, non_existant_subgroup_key_5) << std::endl;
	
	// Footer
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "Done" << std::endl;
    std::cout << std::endl << std::endl << std::endl;
}
