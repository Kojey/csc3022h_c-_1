/**
 * Driver file for the database
 * Author: Othniel Konan
 * Date: Feb 2016
 */

#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include "interface.h"

void print_menu();
void process_input(int input, std::vector<::StudentRecord>& students);
void clear();

int main(){
	
	for (;;){
		// print the menu
		::print_menu();
		// get choice and clear screen
		char input;
		std::cin >> input;
		// terminate on condition
		if (input =='q'){ break;}
		// call right function
		int choice = int(input)-48;
		std::vector<::StudentRecord> database; 
		if (choice <=3 && choice >=0) {::process_input(choice, database);}
	}
	return 0;
}

void print_menu(){
	std::cout << "0 : Add a student" << std::endl;
	std::cout << "1 : read database" << std::endl;
	std::cout << "2 : save database" << std::endl;
	std::cout << "3 : display student's data" << std::endl;
	std::cout << "q : Quit" << std::endl;
}

void process_input(int input, std::vector<::StudentRecord>& database){
	switch(input){
		case 0:
			KNNOTH001::student_parameters();
			break;
		case 1:
			KNNOTH001::read_database(database);
			break;
		case 2:
			KNNOTH001::save_database();
			break;
		case 3:
			KNNOTH001::load_database(database);
			break;
	}
}

void clear(void) { system("clear"); }

