/**
 *  Implementation for the interface library
 *  Author: Othniel Konan
 *  Date: Feb 2016
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "interface.h"

namespace KNNOTH001 {
	void student_parameters(){
		std::cout << "function student_parameters called" << std::endl;
	}
	
	void add_student(std::string name, std::string surname, std::string student_number, std::string class_record){
		std::cout << "function add_student called" << std::endl;
	}	
	
	void read_database(std::vector<::StudentRecord>& database){
		load_database(database);
		std::cout << "function read_database called" << std::endl;
		int width = 20;
		// Set format
		std::cout.setf(std::ios::left, std::ios::adjustfield);
		// Print title
		std::cout << std::setw(width) << "Name";
		std::cout << std::setw(width) << "Surname";
		std::cout << std::setw(width) << "Student Number";
		std::cout << "Grade" << std::endl;
		// Print database
		for (int i=0; i<database.size(); i++){
			::StudentRecord student = database.at(i);
			std::cout << std::setw(width) << student.name;
			std::cout << std::setw(width) << student.surname;
			std::cout << std::setw(width) << student.student_number;
			std::cout << student.grades << std::endl;
		}
		// Unset format
		std::cout.unsetf(std::ios::adjustfield);
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
	
	void load_database(std::vector<::StudentRecord>& database){
		std::cout << "load_database()" << std::endl;
		std::string file_name = "data.txt";
		std::ifstream file(file_name.c_str());
		if (!file){
			std::cout << "Unable to open file " << file_name << std::endl;
			return ;
		}
		
		int counter = 0;
		std::string line;
		while (std::getline(file, line)){	// For every line in the file
			std::stringstream ss;
			ss.str(line);
			// Create a student record and store the student's information
			::StudentRecord student;
			ss >> student.name;
			line = line.erase(0, line.find_first_not_of(student.name)+1);
			ss.str(line);
			ss >> student.surname;
			line = line.erase(0, line.find_first_not_of(student.surname)+1);
			ss.str(line);
			ss >> student.student_number;
			line = line.erase(0, line.find_first_not_of(student.student_number)+1);
			ss.str(line);
			student.grades = ss.str();
			// Add student to database
			database.push_back(student);
		}
		file.close();
	}
}

