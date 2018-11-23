#include "UsersGenerator.h"

// Creates the users generated for the simulation
UsersGenerator::UsersGenerator(int nbITStaff, int nbResearchers, int nbStudents) {
	nbOfITStaff = nbITStaff;
	nbOfResearchers = nbResearchers;
	nbOfStudents = nbStudents;

	int id = 0;
	for (unsigned int i = 0; i < nbOfITStaff; i++) {
		ITStaffList.push_back(ITStaff(168, id));
		id++;
	}
	for (unsigned int i = 0; i < nbOfResearchers; i++) {
		ResearcherList.push_back(Researcher(80 + (rand() % 81), id));
		id++;
	}
	for (unsigned int i = 0; i < nbOfStudents; i++) {
		StudentList.push_back(Student(48, id));
		id++;
	}
}

double UsersGenerator::getBudgetITStaff() {
	double totalBudget = 0;
	for (unsigned int i = 0; i < ITStaffList.size(); i++) {
		totalBudget += ITStaffList[i].getBudget();
	}
}

double UsersGenerator::getBudgetResearchers() {
	double totalBudget = 0;
	for (unsigned int i = 0; i < ResearcherList.size(); i++) {
		totalBudget += ResearcherList[i].getBudget();
	}
}

double UsersGenerator::getBudgetStudents() {
	double totalBudget = 0;
	for (unsigned int i = 0; i < StudentList.size(); i++) {
		totalBudget += StudentList[i].getBudget();
	}
}

