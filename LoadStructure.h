//Aaron Fehir
//April 23, 2021
//Data Structures and Analysis
//Project Two

#ifndef LOADSTRUCTURE_H_
#define LOADSTRUCTURE_H_

#include <string>
#include <vector>
using namespace std;

struct Course {
	string courseName;
	string courseTitle;
	vector<string> prerequisites;
};

class LoadStructure {

public:
	void loadVector();
	vector<Course> courses;
	static vector<Course> courseList;

};

#endif /* LOADSTRUCTURE_H_ */
