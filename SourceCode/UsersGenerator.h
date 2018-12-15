#pragma once
#ifndef USERSGENERATOR_H
#define USERSGENERATOR_H

#include "IncludeFiles.h"
#include "ITStaff.h"
#include "Researcher.h"
#include "Student.h"


class UsersGenerator {
public:
	// Creates the users generated for the simulation
	UsersGenerator(int nbITStaff, int nbResearchers, int nbStudents, bool isBudgetInInput);

	// Returns the total budget of all the members of a user class
	double getBudgetITStaff();
	double getBudgetResearchers();
	double getBudgetStudents();

	// Returns the total budget spent by all the members of a user class
	double getBudgetSpentITStaff();
	double getBudgetSpentResearchers();
	double getBudgetSpentStudents();


	int nbOfITStaff;
	int nbOfResearchers;
	int nbOfStudents;
	
	// Vectors containing the list of the users generated for each class
	vector<ITStaff> ITStaffList;
	vector<Researcher> ResearcherList;
	vector<Student> StudentList;


};

#endif 
