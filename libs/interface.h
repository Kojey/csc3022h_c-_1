/**
 * Header file for the interface library
 * Author: Othniel Konan
 * Date: Feb 2016
 */
#include <vector>
#include <string>
#ifndef LIBS_INTERFACE_H
#define LIBS_INTERFACE_H

struct StudentRecord {
	std::string name;
	std::string surname;
	std::string student_number;
	std::string grades;
};

namespace KNNOTH001 {
	void student_parameters(std::vector<::StudentRecord>& database);
	void add_student(std::string line,std::vector<::StudentRecord>& database);
	void read_database();
	void printStudentRecord (std::string name, std::string surname, std::string student_number, std::string grades);
	void save_database(std::vector<::StudentRecord>& database);
	::StudentRecord get_student(std::string student_number, std::vector<::StudentRecord>& database);
	void display_student(std::vector<::StudentRecord>& database);
	double grade_student(std::vector<::StudentRecord>& database);
	void load_database(std::vector<::StudentRecord>& database);
}


#endif
