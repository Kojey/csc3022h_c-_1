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
void process_input(int input);
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
		if (choice <=3 && choice >=0) {::process_input(choice);}
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

void process_input(int input){
	switch(input){
		case 0:
			KNNOTH001::student_parameters();
			break;
		case 1:
			KNNOTH001::read_database();
			break;
		case 2:
			KNNOTH001::save_database();
			break;
		case 3:
			KNNOTH001::display_student();
			break;
	}
}

void clear(void) { system("clear"); }

