/**
 * Header file for the interface library
 * Author: Othniel Konan
 * Date: Feb 2016
 */

#ifndef LIBS_INTERFACE_H
#define LIBS_INTERFACE_H

namespace KNNOTH001 {
	void add_student(std::string name, std::string surname, std::string student_number, std::string class_record);
	void read_database();
	void save_database();
	void display_student();
	void grade_student();
	void load_database();
}

#endif
