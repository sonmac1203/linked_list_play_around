#define logmsg std::clog << __PRETTY_FUNCTION__ << " "

#include "List.hpp"

#include <iostream>
#include <sstream>
#include <string>

namespace ec = ECE275Lib::containers;

void printDivider() { std::cout << "==========================\n"; };

int main (void){

	printDivider();
	
	
	logmsg << "Creating in_list" << std::endl;
	ec::List<int> int_list;
	for (unsigned int i = 0; i < 10; i++)
		int_list.push_back(i);
		
	for (unsigned int i = 0; i < int_list.size(); i++)
		std::cout << "element " << i << ": " << int_list.at(i) << std::endl;
		
	printDivider();
		
	logmsg << "Removing element 3" << std::endl;
	// Test that delete is working
	int_list.remove(3); // Delete index 3
	for (unsigned int i = 0; i < int_list.size(); i++)
		std::cout << "element " << i << ": " << int_list.at(i) << std::endl;
    
    printDivider();
    
    logmsg << "Adding data 125 at element 1" << std::endl;
    int_list.insert(1, 125);
    for (unsigned int i = 0; i < int_list.size(); i++)
		std::cout << "element " << i << ": " << int_list.at(i) << std::endl;
		
	printDivider();
	
	logmsg << "Inserting another list at element 3" << std::endl;
	ec::List<int> int_list2;
	for (unsigned int i = 100; i < 110; i++)
		int_list2.push_back(i);
	
	int_list.insert(3, int_list2);
	for (unsigned int i = 0; i < int_list.size(); i++)
		std::cout << "element " << i << ": " << int_list.at(i) << std::endl;
	
	printDivider();
	
	logmsg << "Removing elements 1 through 5" << std::endl;
	int_list.remove(1, 5);
	for (unsigned int i = 0; i < int_list.size(); i++)
		std::cout << "element " << i << ": " << int_list.at(i) << std::endl;
	printDivider();
	
	ec::List<char> char_list(5);
	logmsg << "Char list size = " << char_list.size() << std::endl;
	for (unsigned int i = 0; i < char_list.size(); i++){
		char_list.assign(i, 'a');
		std::cout << "element " << i << ": " << char_list.at(i) << std::endl;
	}
	
	printDivider();
	
    
    ec::List<std::string> str_list;
    str_list.push_back("ECE 275!");
    str_list.push_back("UArizona");
    str_list.push_back("Tucson, AZ");
    
    for (unsigned int i = 0; i < str_list.size(); i++)
        std::cout << "element i: " << str_list.at(i) << std::endl;

	printDivider();    
    
    return 0;
}
