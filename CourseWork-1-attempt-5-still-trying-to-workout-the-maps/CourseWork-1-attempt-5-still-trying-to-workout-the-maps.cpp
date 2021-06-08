
// And it is time for the 5th attempt!
// Those damn maps just don't want to work for some hell of a reason.
// 7.06.2021, just a few days until the deadline and I am stuck on the very first coursework, guess I am doomed.
// C'mon! C++! WORK PLEASE. Can you give me more informative error messages??

#include <iostream>


#include "Data.h"
#include "utils.h"

std::string task_log_prefix = "[---TASK---] ";
std::string test_log_prefix = "[TEST] ";
std::string error_log_prefix = "[ *** ERROR *** ] ";

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


    // --- // --- // --- //


    std::cout << std::endl << std::endl << std::endl;
    std::cout << task_log_prefix << "[6.] Apply method PrintItem() for an existing item" << std::endl;
    std::cout << task_log_prefix << "and for a non-existing item." << std::endl;
    std::cout << std::endl;

    Item* selected_item_6 = nullptr;

    for (auto group = data_1->structure_.begin(); group != data_1->structure_.end(); ++group)
    {
        // First condition
        if (group->second->empty()) continue;

        for (auto subgroup = group->second->begin(); subgroup != group->second->end(); ++subgroup)
        {
            // Second condition
            if (subgroup->second->empty()) continue;

            selected_item_6 = (*subgroup->second->begin());

            break;
        }

        if (selected_item_6 != nullptr) break;
    }

    if (selected_item_6 == nullptr)
    {
        std::cout << test_log_prefix << "There were no item selected, that is strange, it could only happen if structure is empty... idk, we're skipping this step." << std::endl;
    }
    else {
        std::cout << test_log_prefix << "Calling print item for the selected item:" << std::endl;
        data_1->PrintItem(selected_item_6);
    }

    std::cout << test_log_prefix << "Created item:" << std::endl;
    Item* non_existant_item_6 = new Item('z', 999, "NON_EXISTANT");
    data_1->PrintItem(non_existant_item_6);

    std::cout << test_log_prefix << "Calling PrintItem for a previously created item" << std::endl;
    std::cout << test_log_prefix << "an item that does not exists in a structure:" << std::endl;
    data_1->PrintItem(non_existant_item_6->get_group(), non_existant_item_6->get_subgroup(), non_existant_item_6->get_name());


    // --- // --- // --- //


    std::cout << std::endl << std::endl << std::endl;
    std::cout << task_log_prefix << "[7.] Create object containing 30 items and apply method PrintAll()." << std::endl;
    std::cout << std::endl;
	
    std::cout << test_log_prefix << "Creating new Data with 30 random initial items." << std::endl;
    auto data_7 = new Data(30);

    std::cout << test_log_prefix << "Calling data_7->PrintAll();" << std::endl;
    data_7->PrintAll();
	

    // --- // --- // --- //


    std::cout << std::endl << std::endl << std::endl;
    std::cout << task_log_prefix << "[8.] Apply methods PrintGroup() and CountGroupItems() for a non - existing group." << std::endl;
    std::cout << std::endl;

    char non_existant_group_key_8 = 'Z';
    std::cout << test_log_prefix << "Selected as non existant group key (non_existant_group_key_8): " << non_existant_group_key_8 << std::endl;

    std::cout << test_log_prefix << "Calling data_7->PrintGroup();" << std::endl;
    data_7->PrintGroup(non_existant_group_key_8);
	
    std::cout << test_log_prefix << "Calling data_7->CountGroupItems();" << std::endl;
    std::cout << "Result: " << data_7->CountGroupItems(non_existant_group_key_8);


    // --- // --- // --- //


    std::cout << std::endl << std::endl << std::endl;
    std::cout << task_log_prefix << "[9.] Apply method InsertItem() if:" << std::endl;
    std::cout << std::endl;


    std::cout << task_log_prefix << "[9.a] The new item will be a member of an existing group and an existing subgroup." << std::endl;

    char group_key_9_a = NULL;
    int subgroup_key_9_a = NULL;
	
    for (auto group = data_7->structure_.begin(); group != data_7->structure_.end(); ++group)
    {
        if (group->second->empty()) continue;

    	for (auto subgroup = group->second->begin(); subgroup != group->second->end(); ++subgroup)
    	{
            if (subgroup->second->empty()) continue;

            subgroup_key_9_a = subgroup->first;
            group_key_9_a = group->first;

            break;
    	}

    	if (group_key_9_a != NULL && subgroup_key_9_a != NULL)
			break;
    }

	if (group_key_9_a == NULL || subgroup_key_9_a == NULL)
	{
        std::cout << error_log_prefix << "Either group_key_9_a or subgroup_key_9_a is NULL!" << std::endl;
        std::cout << error_log_prefix << "It could be the structure is too small or is corrupted." << std::endl;
        std::cout << error_log_prefix << "9.a will be skipped!" << std::endl;
	}
    else
    {
        std::cout << test_log_prefix << "Selected group: " << group_key_9_a << std::endl;
        std::cout << test_log_prefix << "Selected subgroup: " << subgroup_key_9_a << std::endl;

        auto item_9_a = new Item(group_key_9_a, subgroup_key_9_a, "newItem9a");

        std::cout << test_log_prefix << "Created new item:" << std::endl;
        data_7->PrintItem(item_9_a);

        data_7->InsertItem(item_9_a);
        std::cout << test_log_prefix << "Item {9.a} inserted into data_7!" << std::endl;
    }

    std::cout << std::endl;
    std::cout << task_log_prefix << "[9.b] The new item will be a member of an existing group but the subgroup does not exist." << std::endl;

    char group_key_9_b = NULL;
    int subgroup_key_9_b = NULL;

    for (auto group = data_7->structure_.begin(); group != data_7->structure_.end(); ++group)
    {
        if (group->second->empty()) continue;

        for (auto i = 0; i < 10; ++i)
        {
            if (data_7->GetSubgroup(group->second, i) != nullptr) continue;

            group_key_9_b = group->first;
            subgroup_key_9_b = i;

            break;
        }

        if (group_key_9_b != NULL && subgroup_key_9_b != NULL)
            break;
    }

    if (group_key_9_b == NULL || subgroup_key_9_b == NULL)
    {
        std::cout << error_log_prefix << "Either group_key_9_b or subgroup_key_9_b is NULL!" << std::endl;
        std::cout << error_log_prefix << "It could be the structure is too small or is corrupted." << std::endl;
        std::cout << error_log_prefix << "9.b will be skipped!" << std::endl;
    }
    else
    {
        std::cout << test_log_prefix << "Selected group: " << group_key_9_b << std::endl;
        std::cout << test_log_prefix << "Selected subgroup: " << subgroup_key_9_b << std::endl;

        auto item_9_b = new Item(group_key_9_b, subgroup_key_9_b, "newItem9b");

        std::cout << test_log_prefix << "Created new item:" << std::endl;
        data_7->PrintItem(item_9_b);

        data_7->InsertItem(item_9_b);
        std::cout << test_log_prefix << "Item {9.b} inserted into data_7!" << std::endl;
    }

    std::cout << std::endl;
    std::cout << task_log_prefix << "[9.c] The new item will be a member of a non-existing group." << std::endl;

    char selected_group_9_c = NULL;

	for (auto c = 'a'; c < 'z'; c++)
	{
        if (data_7->GetGroup(c) != nullptr) continue;

        selected_group_9_c = c;

        break;
	}

	if (selected_group_9_c == NULL)
    {
        std::cout << error_log_prefix << "selected_group_9_c is NULL!" << std::endl;
        std::cout << error_log_prefix << "It could be the structure is too small or is corrupted." << std::endl;
        std::cout << error_log_prefix << "9.c will be skipped!" << std::endl;
    }
    else
    {
        std::cout << test_log_prefix << "Selected group: " << selected_group_9_c << std::endl;

        auto item_9_c = new Item(selected_group_9_c, "newItem9c");

        std::cout << test_log_prefix << "Created new item:" << std::endl;
        data_7->PrintItem(item_9_c);

        data_7->InsertItem(item_9_c);
        std::cout << test_log_prefix << "Item {9.c} inserted into data_7!" << std::endl;
    }

    std::cout << std::endl;
    std::cout << task_log_prefix << "[9.d] This item already exists." << std::endl;

    Item* selected_item_9_d = nullptr;

    for (auto group = data_7->structure_.begin(); group != data_7->structure_.end(); ++group)
    {
        if (group->second->empty()) continue;

        for (auto subgroup = group->second->begin(); subgroup != group->second->end(); ++subgroup)
        {
            if (subgroup->second->empty()) continue;

            selected_item_9_d = *(subgroup->second->begin());

            break;
        }

        if (selected_item_9_d != nullptr)
            break;
    }

    if (selected_item_9_d == nullptr)
    {
        std::cout << error_log_prefix << "selected_item_9_d is nullptr!" << std::endl;
        std::cout << error_log_prefix << "It could be the structure is too small or is corrupted." << std::endl;
        std::cout << error_log_prefix << "9.d will be skipped!" << std::endl;
    }
    else
    {
        std::cout << test_log_prefix << "Selected item:" << std::endl;
        data_7->PrintItem(selected_item_9_d);

        auto item_9_d = new Item(selected_item_9_d->get_group(), selected_item_9_d->get_subgroup(), selected_item_9_d->get_name(), selected_item_9_d->get_timestamp());

        std::cout << test_log_prefix << "Created new item:" << std::endl;
        data_7->PrintItem(item_9_d);

        data_7->InsertItem(item_9_d);
        std::cout << test_log_prefix << "Item {9.d} inserted into data_7!" << std::endl;
    }
	
    std::cout << std::endl;
    std::cout << task_log_prefix << "[9.e] Apply method PrintAll() to check the results." << std::endl;

    data_7->PrintAll();


    // --- // --- // --- //


    std::cout << std::endl << std::endl << std::endl;
    std::cout << task_log_prefix << "[10.] Apply method InsertSubgroup() if" << std::endl;
    std::cout << std::endl;

    std::cout << task_log_prefix << "[10.a] The new subgroup will be a member of an existing group." << std::endl;

    char selected_group_10_a = NULL;
    int selected_subgroup_10_a = NULL;
	
    for (auto group = data_7->structure_.begin(); group != data_7->structure_.end(); ++group)
    {
        if (group->second->empty()) continue;

        for (auto i = 0; i < 10; ++i)
        {
	        if (data_7->GetSubgroup(group->second, i) == nullptr)
	        {
                selected_group_10_a = group->first;
                selected_subgroup_10_a = i;

                break;
	        }
        }

    	if (selected_group_10_a != NULL && selected_subgroup_10_a != NULL)
	        break;
    }
	 
    if (selected_group_10_a == NULL || selected_subgroup_10_a == NULL)
    {
        std::cout << error_log_prefix << "Either selected_group_10_a or selected_subgroup_10_a is NULL!" << std::endl;
        std::cout << error_log_prefix << "It could be the structure is too small or is corrupted." << std::endl;
        std::cout << error_log_prefix << "10.a will be skipped!" << std::endl;
    }
    else
    {
        std::cout << test_log_prefix << "Selected group: " << selected_group_10_a << std::endl;
        std::cout << test_log_prefix << "Selected subgroup: " << selected_subgroup_10_a << std::endl;

        std::cout << test_log_prefix << "Creating a list with 5 new items." << std::endl;
        std::initializer_list<Item*> items = {new Item, new Item, new Item, new Item, new Item};

        std::cout << test_log_prefix << "Inserting the {10.a} list." << std::endl;
        data_7->InsertSubgroup(selected_group_10_a, selected_subgroup_10_a, items);
    }


    std::cout << std::endl;
    std::cout << task_log_prefix << "[10.b] The new subgroup will be a member of a non-existing group." << std::endl;

	
    char selected_group_10_b = NULL;
    int selected_subgroup_10_b = random_subgroup();

    for (auto c = 'a'; c < 'z'; c++)
    {
        if (data_7->GetGroup(c) != nullptr) continue;

        selected_group_10_b = c;

        break;
    }

	if (selected_group_10_b == NULL)
	{
        std::cout << error_log_prefix << "Could not select, selected_group_10_a is NULL!" << std::endl;
        std::cout << error_log_prefix << "It could be the structure is too small or is corrupted." << std::endl;
        std::cout << error_log_prefix << "10.a will be skipped!" << std::endl;
	}
    else
    {
        std::cout << test_log_prefix << "Selected group: " << selected_group_10_b << std::endl;
        std::cout << test_log_prefix << "Selected subgroup: " << selected_subgroup_10_b << std::endl;

        std::cout << test_log_prefix << "Creating a list with 5 new items." << std::endl;
        std::initializer_list<Item*> items = { new Item, new Item, new Item, new Item, new Item };
    	
        data_7->InsertSubgroup(selected_group_10_b, selected_subgroup_10_b, items);
    }

	
    std::cout << std::endl;
    std::cout << task_log_prefix << "[10.c] The subgroup already exists." << std::endl;


    char group_key_10_c = NULL;
    int subgroup_key_10_c = NULL;

    for (auto group = data_7->structure_.begin(); group != data_7->structure_.end(); ++group)
    {
        if (group->second->empty()) continue;

        for (auto subgroup = group->second->begin(); subgroup != group->second->end(); ++subgroup)
        {
            group_key_10_c = group->first;
            subgroup_key_10_c = subgroup->first;

            break;
        }

        if (group_key_10_c != NULL && subgroup_key_10_c != NULL)
            break;
    }

    if (group_key_10_c == NULL || subgroup_key_10_c == NULL)
    {
        std::cout << error_log_prefix << "Either group_key_10_c or subgroup_key_10_c is NULL!" << std::endl;
        std::cout << error_log_prefix << "It could be the structure is too small or is corrupted." << std::endl;
        std::cout << error_log_prefix << "9.b will be skipped!" << std::endl;
    }
    else
    {
        std::cout << test_log_prefix << "Selected group: " << group_key_10_c << std::endl;
        std::cout << test_log_prefix << "Selected subgroup: " << subgroup_key_10_c << std::endl;


        std::cout << test_log_prefix << "Creating a list with 5 new items." << std::endl;
        std::initializer_list<Item*> items = { new Item, new Item, new Item, new Item, new Item };

        data_7->InsertSubgroup(group_key_10_c, subgroup_key_10_c, items);
    }


    std::cout << std::endl;

	std::cout << task_log_prefix << "[10.d] Apply method PrintAll() to check the results." << std::endl;
    data_7->PrintAll();
	
    // --- // --- // --- //

	
	// Footer
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "Done" << std::endl;
    std::cout << std::endl << std::endl << std::endl;
}
