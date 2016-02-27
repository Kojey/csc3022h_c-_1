/**
 * Header file for the interface library
 * Author: Othniel Konan
 * Date: Feb 2016
 */

#ifndef LIBS_INTERFACE_H
#define LIBS_INTERFACE_H

struct StudentRecord {
	char name[40];
	char surname[40];
	char student_number[9];
	std::vector<int> grades;
};

namespace KNNOTH001 {
	void student_parameters();
	void add_student(std::string name, std::string surname, std::string student_number, std::string class_record);
	void read_database();
	void save_database();
	void display_student();
	void grade_student();
	void load_database(std::vector<::StudentRecord>& students);
}


#endif
