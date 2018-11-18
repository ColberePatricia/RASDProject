#include "User.h"

// Creates the users generated for the simulation
User::User(double userBudget, int userId) {
	budget = userBudget;
	id = userId;
}


double User::getBudget() {
	return budget;
}

int User::getId() {
	return id;
}

void User::setBudget(double newBudget) {
	budget = newBudget;
}
