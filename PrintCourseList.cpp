//Aaron Fehir
//April 23, 2021
//Data Structures and Analysis
//Project Two

#include <iostream>
#include "PrintCourseList.h"
#include "LoadStructure.h"
#include "MenuOptions.h"
using namespace std;

//Instantiate menuOptions object
MenuOptions options;

void PrintCourseList::printSampleSchedule() {
    //Sort vector elements by courseName
	//define min as int (index of the current minimum bid)
	int min = 0;
	// check size of courseList vector
	// set size_t platform-neutral result equal to courseList.size()
	int size_t = LoadStructure::courseList.size();
	// pos is the position within bids that divides sorted/unsorted
	for (int pos = 0; pos < size_t - 1; ++pos) {
		// Find index of smallest remaining element
		min = pos;
	    // loop over remaining elements to the right of position
		for (int element = pos + 1; element < size_t; ++element) {
		// if this element's name is less than minimum name
	    	    if ( LoadStructure::courseList[element].courseName < LoadStructure::courseList[min].courseName ) {
	    	        // this element becomes the minimum
	    	        min = element;
	    	    }
	    	}
	        // swap the current minimum with smaller one found
		    Course temp = LoadStructure::courseList[pos];
		    LoadStructure::courseList[pos] = LoadStructure::courseList[min];
		    LoadStructure::courseList[min] = temp;
		}

    //Print sorted course list

	cout << "Here is the schedule of courses: " << endl << endl;

    for (unsigned int i = 0; i < LoadStructure::courseList.size(); ++ i) {
		Course course = LoadStructure::courseList.at(i);
		cout << course.courseName << " | " << course.courseTitle << endl;
	}
	cout << endl;

	//Return to menu
	options.DisplayMenu();

}

