#include "UsersGenerator.h"

// Creates the users generated for the simulation
UsersGenerator::UsersGenerator(int nbITStaff, int nbResearchers, int nbStudents, bool isBudgetInInput) {
	nbOfITStaff = nbITStaff;
	nbOfResearchers = nbResearchers;
	nbOfStudents = nbStudents;
	double budget;

	int id = 0;
	for (unsigned int i = 0; i < nbOfITStaff; i++) {
		if (isBudgetInInput) {
			cout << "Input Budget for the IT staff number " << i << ":\n";
			cin >> budget;
		}
		else {
			budget = 168;
		}
		ITStaffList.push_back(ITStaff(budget, id));
		id++;
	}
	for (unsigned int i = 0; i < nbOfResearchers; i++) {
		if (isBudgetInInput) {
			cout << "Input Budget for the researcher number " << i << ":\n";
			cin >> budget;
		}
		else {
			budget = 80 + (rand() % 81);
		}
		ResearcherList.push_back(Researcher(budget, id));
		id++;
	}
	for (unsigned int i = 0; i < nbOfStudents; i++) {
		if (isBudgetInInput) {
			cout << "Input Budget for the student number " << i << ":\n";
			cin >> budget;
		}
		else {
			budget = 48;
		}
		StudentList.push_back(Student(budget, id));
		id++;
	}
}

double UsersGenerator::getBudgetITStaff() {
	double totalBudget = 0;
	for (unsigned int i = 0; i < ITStaffList.size(); i++) {
		totalBudget += ITStaffList[i].getBudget();
	}
	return totalBudget;
}

double UsersGenerator::getBudgetResearchers() {
	double totalBudget = 0;
	for (unsigned int i = 0; i < ResearcherList.size(); i++) {
		totalBudget += ResearcherList[i].getBudget();
	}
	return totalBudget;
}

double UsersGenerator::getBudgetStudents() {
	double totalBudget = 0;
	for (unsigned int i = 0; i < StudentList.size(); i++) {
		totalBudget += StudentList[i].getBudget();
	}
	return totalBudget;
}

double UsersGenerator::getBudgetSpentITStaff() {
	double totalBudget = 0;
	for (unsigned int i = 0; i < ITStaffList.size(); i++) {
		totalBudget += ITStaffList[i].getBudgetSpent();
	}
	return totalBudget;
}
double UsersGenerator::getBudgetSpentResearchers() {
	double totalBudget = 0;
	for (unsigned int i = 0; i < ResearcherList.size(); i++) {
		totalBudget += ResearcherList[i].getBudgetSpent();
	}
	return totalBudget;
}
double UsersGenerator::getBudgetSpentStudents() {
	double totalBudget = 0;
	for (unsigned int i = 0; i < StudentList.size(); i++) {
		totalBudget += StudentList[i].getBudgetSpent();
	}
	return totalBudget;
}

