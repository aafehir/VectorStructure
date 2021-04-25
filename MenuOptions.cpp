//Aaron Fehir
//April 23, 2021
//Data Structures and Analysis
//Project Two

#include <iostream>
#include <vector>
using namespace std;

//Include classes
#include "MenuOptions.h"
#include "LoadStructure.h"
#include "PrintCourse.h"
#include "PrintCourseList.h"

//Define DisplayMenu function from MenuOptions class
void MenuOptions::DisplayMenu() {

	//Instantiate class objects
	LoadStructure load;
	PrintCourseList courseList;
	PrintCourse course;

	//Display menu of program options
	cout << "*****   PROGRAM OPTIONS   *****" << endl;
    cout << "*******************************"  << endl;
	cout << "Enter 1 to Load Structure" << endl;
	cout << "Enter 2 to Print Course List" << endl;
	cout << "Enter 3 to Print Course" << endl;
	cout << "Enter 9 to Quit" << endl;

	//Get user selection
    cin >> selection;

    //Call function appropriate to user selection; Re-prompt if user makes invalid selection
    while (true) {
    	if (selection != '1' && selection != '2' && selection != '3' && selection != '9') {
    		cout << "Please enter a valid selection" << endl;
    		cin >> selection;
    	}
    	else {
    		if (selection == '1') {
    			load.loadVector();
    		    break;
    		}
    		if (selection == '2') {
    		    courseList.printSampleSchedule();
    		    break;
    		}
    		if (selection == '3') {
    			string name;
    		    course.printCourseInformation(name);
    		    break;
    		}
    		if (selection == '9') {
    		    exit(0);
    		    break;
    		}
    	}
    }
}
