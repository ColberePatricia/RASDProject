#ifndef USERSGENERATOR_H
#define USERSGENERATOR_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include <fstream>
using namespace std;

#include "ITStaff.h"
#include "Researcher.h"
#include "Student.h"


class UsersGenerator {
public:
	int nbOfITStaff;
	int nbOfResearchers;
	int nbOfStudents;
	
	// Vectors containing the list of the users generated for each class
	vector<ITStaff> ITStaffList;
	vector<Researcher> ResearcherList;
	vector<Student> StudentList;

	// Creates the users generated for the simulation
	UsersGenerator(int nbITStaff, int nbResearchers, int nbStudents);
};

#endif 
