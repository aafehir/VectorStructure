//Aaron Fehir
//April 23, 2021
//Data Structures and Analysis
//Project Two

#include <string>
#include <ctype.h>
#include <algorithm>
#include <iterator>
#include <iostream>
#include "PrintCourse.h"
#include "LoadStructure.h"
#include "MenuOptions.h"
using namespace std;

MenuOptions menuOptions;

//Function for making user input upper case for comparison purposes
string make_uppercase( const string& in )
{
  string out;
  transform(in.begin(), in.end(), back_inserter(out), :: toupper );
  return out;
}

void PrintCourse::printCourseInformation(string name) {

	//Get user input
	cout << "What course would you like to know about?" << endl;
	cin >> name;

	//Print course information if match, including any prerequisites
	int matchCount = LoadStructure::courseList.size();
	for (unsigned int i = 0; i < LoadStructure::courseList.size(); ++ i) {
		Course course = LoadStructure::courseList.at(i);
		if (course.courseName == make_uppercase(name)) {
			cout << course.courseName << " | " << course.courseTitle << endl;
			cout << "Prerequisites: " << endl;
			if (course.prerequisites.size() == 0) {
				cout << "None" << endl;
			}
			for (unsigned int i = 0; i < course.prerequisites.size(); ++i) {
				string prerequisite = course.prerequisites.at(i);
				cout << prerequisite << endl;
			}
			cout << endl;
		}
		else {
			matchCount -= 1;
		}
	}
    //Indicate if no course match
	if (matchCount == 0) {
		 cout << "Not a valid course selection" << endl << endl;
	}

//Return to menu
menuOptions.DisplayMenu();

}



