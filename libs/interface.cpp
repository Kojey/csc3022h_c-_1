/**
 *  Implementation for the interface library
 *  Author: Othniel Konan
 *  Date: Feb 2016
 */

#include <iostream>
#include "interface.h"

namespace KNNOTH001 {
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
	
	void load_database(){
		std::cout << "function load_database called" << std::endl;
	}
	
}
