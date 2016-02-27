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
	using namespace std;
	void student_parameters(vector<::StudentRecord>& database){
		cout << "Enter student's details (<name> <surname> <student number> <grades>):" << endl;
		string line;
		string temp;
		cin >> temp;
		getline(cin, line);
		add_student(temp+line, database);
		cout << "Student added." << endl;
	}
	
	void add_student(string line, vector<::StudentRecord>& database){
		stringstream ss;
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
	
	void read_database(){
		vector<::StudentRecord> database;
		load_database(database);
		cout << "\t\t\t*****DATABASE*****" << endl;
		// Print title
		printStudentRecord("Name", "Surname","Student Number","Grades");
		// Print database
		for (int i=0; i<database.size(); i++){
			::StudentRecord student = database.at(i);
			printStudentRecord(student.name, student.surname,student.student_number,student.grades);
		}
	}
	
	void printStudentRecord (string name, string surname, string student_number, string grades){
		int width = 20;
		// Set format
		cout.setf(ios::left, ios::adjustfield);
		cout << std::setw(width) << name;
		cout << std::setw(width) << surname;
		cout << std::setw(width) << student_number;
		cout << grades << endl;
		// Unset format
		cout.unsetf(ios::adjustfield);
	}
	
	::StudentRecord get_student(string student_number, vector<::StudentRecord>& database){
		for (int i=0; i<database.size(); i++) {
			::StudentRecord student = database.at(i);
			if(student.student_number == student_number){
				return student;
			}
		}
	}
	
	void display_student(vector<::StudentRecord>& database){
		cout << "Enter student number in capital letter: ";
		string student_number;
		cin >> student_number;
		printStudentRecord("Name", "Surname","Student Number","Grades");
		::StudentRecord student = get_student(student_number, database);
		cout << "Student's details" << endl;
		printStudentRecord(student.name, student.surname,student.student_number,student.grades);
	}
	
	void save_database(vector<::StudentRecord>& database){
		string file_name = "data.txt";
		ofstream file (file_name);
		if (file.is_open()){
			for (int i=0; i<database.size(); i++){
				::StudentRecord student = database.at(i);
				file << student.name + " ";
				file << student.surname + " ";
				file << student.student_number + " ";
				file << student.grades+ "\n";
			}
			file.close();
			cout << "Database saved." << endl;
		}
		else cout << "Unable to open " << file_name << endl;
	}
	
	double grade_student(std::vector<::StudentRecord>& database){
		cout << "Enter student number in capital letter: ";
		string student_number;
		cin >> student_number;
		::StudentRecord student = get_student(student_number, database);
		// Calculate grade
		stringstream ss;
		ss.str(student.grades);
		string mark;
		double sum = 0;
		int number_of_mark = 0;
		while (ss >> mark){
			number_of_mark++;
			sum += stoi(mark);
		}
		double result = sum/number_of_mark;
		cout << student.name << "'s average is: " << result << endl;
	}
	
	void load_database(vector<::StudentRecord>& database){
		string file_name = "data.txt";
		ifstream file(file_name.c_str());
		if (!file){
			cout << "Unable to open file " << file_name << endl;
			return ;
		}
		database.clear();
		int counter = 0;
		string line;
		while (getline(file, line)){	// For every line in the file
			add_student(line, database);
		}
		file.close();
	}
}

