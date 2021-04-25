//Aaron Fehir
//April 23, 2021
//Data Structures and Analysis
//Project Two

#include <iostream>
#include <fstream>
#include <sstream>
#include "LoadStructure.h"
#include "MenuOptions.h"

//Instantiate MenuOptions object
MenuOptions menu;

//Initialize static variable
vector<Course> LoadStructure::courseList;

void LoadStructure::loadVector() {

	Course course;

	//Input file stream
	ifstream inFS;

	// Try to open file
	cout << "Opening file courses.txt." << endl;

	inFS.open("courses.txt");
	if (!inFS.is_open()) {
		cout << "Could not open file courses.txt." << endl;
		exit(1); // 1 indicates error
	}

	string line;
	istringstream iss;
	//Read to the end of the file
	while(!inFS.eof()) {
		getline(inFS, line);
		iss.str(line);

		string lineItem;
		char delim = ',';
		if (getline(iss, lineItem, delim)) {
			course.courseName = lineItem;
		}
		if (getline(iss, lineItem, delim)) {
			course.courseTitle = lineItem;
		}
		while (getline(iss, lineItem, delim)) {
			course.prerequisites.push_back(lineItem);
		}
		courses.push_back(course);
		courseList = courses; //Copy vector to static vector to cement data integrity for the duration of the program
		course.prerequisites.clear();
		iss.clear();
	}

	cout << "Courses successfully loaded" << endl << endl;

    //Return to menu
    menu.DisplayMenu();

}
