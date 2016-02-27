/**
 *  Implementation for the interface library
 *  Author: Othniel Konan
 *  Date: Feb 2016
 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "interface.h"

namespace KNNOTH001 {
	void student_parameters(){
		std::cout << "function student_parameters called" << std::endl;
	}
	
	void add_student(std::string name, std::string surname, std::string student_number, std::string class_record){
		std::cout << "function add_student called" << std::endl;
	}	
	
	void read_database(){
		std::cout << "function read_database called" << std::endl;
	}
	
	void display_student(){
		std::cout << "function display_student called" << std::endl;
	}
	
	void save_database(){
		std::cout << "function save_database called" << std::endl;
	}
	
	void grade_student(){
		std::cout << "function grade_student called" << std::endl;
		
	}
	
	void load_database(std::vector<::StudentRecord>& students){
		std::cout << "load_database()" << std::endl;
		std::string file_name = "data.txt";
		std::ifstream file(file_name.c_str());
		if (!file){
			std::cout << "Unable to open file " << file_name << std::endl;
			return ;
		}
		char array[200];
		while (!file.getline(array,200)){ // while not end of file 
			// Read a line
			while (!file){ // not end of line
				::StudentRecord student;
				// Update student's record
				// .........
				// Add student's data to vector students
				students.push_back(student);
			}
		}
		file.close();
	}
}

