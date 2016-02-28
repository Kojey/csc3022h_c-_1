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
		/*
		 * Process the line representing the student's data and add 
		 * the student to the database
		 * */
		cout << "Enter student's details (<name> <surname> <student number> <grades>):" << endl;
		string line;
		string temp;
		cin >> temp;
		getline(cin, line);
		add_student(temp+line, database, false);
	}
	
	void add_student(string line, vector<::StudentRecord>& database, bool load){
		/*
		 * Add a student to the database if he/she is not already in it,
		 * otherwise it updates the student's data
		 * */
		stringstream ss;
		ss.str(line);
		string name;
		string surname; 
		string student_number;
		string grades;
		// Processing a line representing the student's data
		ss >> name;
		line = line.erase(0, line.find_first_not_of(name)+1);
		ss.str(line);
		ss >> surname;	
		line = line.erase(0, line.find_first_not_of(surname)+1);
		ss.str(line);
		ss >> student_number;
		line = line.erase(0, line.find_first_not_of(student_number)+1);
		ss.str(line);
		grades = ss.str();
		// student not in database
		if (get_student(student_number, database).student_number == "void"){
			// Create a student record
			::StudentRecord student;
			student.name = name;
			student.surname = surname;
			student.student_number = student_number;
			student.grades = grades;
			// Add student to database
			database.push_back(student);
			if (!load) cout << student_number << " was added to the database." << endl;
		}
		// student in database
		else { 
			// find student's position in database and change student's detail in database
			for (int i=0; i<database.size(); i++) {
				::StudentRecord student = database.at(i);
				if(student.student_number == student_number){
					database.at(i).name = name;
					database.at(i).surname = surname;
					database.at(i).grades = grades;
					break;
				}
			}
			if (!load) cout << student_number << " 's details was updated." << endl;
		}
	}	
	
	void read_database(){
		/*
		 * Load the database from disk and display its content 
		 * */
		vector<::StudentRecord> database;
		load_database(database); // Load database to vector database
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
		/*
		 * Print database's content in a specific format
		 * */
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
		/*
		 * Return the student in the database who has the corresponding student number
		 * */
		for (int i=0; i<database.size(); i++) {
			::StudentRecord student = database.at(i);
			if(student.student_number == student_number){
				return student;
			}
		}
		::StudentRecord empty;
		empty.student_number = "void";
		return empty;
	}
	
	void display_student(vector<::StudentRecord>& database){
		/*
		 * Display student's details given his/her student number
		 * */
		cout << "Enter student number in capital letter: ";
		string student_number;
		cin >> student_number;
		// look for student
		::StudentRecord student = get_student(student_number, database);
		if (student.student_number == "void"){
			cout << "Student number does not exist." << endl;
			return;
		}
		// print his/her details
		cout << "Student's details" << endl;
		printStudentRecord("Name", "Surname","Student Number","Grades");
		printStudentRecord(student.name, student.surname,student.student_number,student.grades);
	}
	
	void save_database(vector<::StudentRecord>& database){
		/*
		 * Save the database
		 * */
		string file_name = "database/data.txt";
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
	
	double grade_student(vector<::StudentRecord>& database){
		/*
		 * Compute the student's grade given his/her student's number
		 * */
		cout << "Enter student number in capital letter: ";
		string student_number;
		cin >> student_number;
		::StudentRecord student = get_student(student_number, database);
		if (student.student_number == "void"){
			cout << "Student number does not exist." << endl;
			return 0;
		}
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
		/*
		 * Load database from disk
		 * */
		string file_name = "database/data.txt";
		ifstream file(file_name.c_str());
		if (!file){
			cout << "Unable to open file " << file_name << endl;
			return ;
		}
		database.clear();
		int counter = 0;
		string line;
		while (getline(file, line)){	// for every line in the file
			add_student(line, database, true);
		}
		file.close();
	}
}

