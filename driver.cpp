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
	using namespace std;
	vector<::StudentRecord> database; 
	KNNOTH001::load_database(database);
	for (;;){
		// print the menu
		::print_menu();
		// get choice and clear screen
		char input;
		cin >> input;
		// terminate on condition
		if (input =='q'){ break;}
		// call right function
		int choice = int(input)-48;
		if (choice <=4 && choice >=0) {::process_input(choice, database);}
	}
	return 0;
}

void print_menu(){
	using namespace std;
	cout << "0 : Add a student" << endl;
	cout << "1 : read database" << endl;
	cout << "2 : save database" << endl;
	cout << "3 : display student's data" << endl;
	cout << "4 : grade student" << endl;
	cout << "q : Quit" << endl;
}

void process_input(int input, std::vector<::StudentRecord>& database){
	switch(input){
		case 0:
			KNNOTH001::add_student("Rebecca Konan KNNREB001 100 100",database);//student_parameters(database);
			break;
		case 1:
			KNNOTH001::read_database();
			break;
		case 2:
			KNNOTH001::save_database(database);
			break;
		case 3:
			KNNOTH001::display_student(database);
			break;
		case 4:
			KNNOTH001::grade_student(database);
			break;
	}
}

void clear(void) { system("clear"); }

