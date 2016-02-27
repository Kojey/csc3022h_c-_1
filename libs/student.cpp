/**
 * Representation of a student's record
 * Author: Othniel Konan
 * Date: Feb 2016
 */
#include <vector>

struct StudentRecord {
	char name[40];
	char surname[40];
	char student_number[9];
	vector<int> grades;
}
