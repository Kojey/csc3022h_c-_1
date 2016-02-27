/**
 *  Implementation for the interface library
 *  Author: Othniel Konan
 *  Date: Feb 2016
 */

#include <iostream>
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
	
	void read_database(std::vector<::StudentRecord>& database){
		std::cout << "function read_database called" << std::endl;
		//std::cout << std::setw(10) << "aaaaaa";
		//std::cout << std::setw(10) << "bbbbbb";
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
		
		::StudentRecord student;
		int counter = 0;
		std::string line;
		char ch = '*';
		while (std::getline(file, line, ch)){
			std::cout << line << std::endl;
			std::cout << "In" << std::endl;
		}
		file.close();
	}
}

