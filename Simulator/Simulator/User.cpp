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

void User::spendBudget(double budgetSpent) {
	budget = budget - budgetSpent;
}

Job User::createJobAndSendTosendJobToShortJobQueue(int nbOfNodes, int nbOfHours) {
	ShortJobQueue sjq;
	double jobBudget = sjq.costPerMachineHour * nbOfHours;
	Job job = Job(jobBudget, nbOfNodes, nbOfHours);
	// Check wether the user has enough budget to create the job
	if (jobBudget > budget) {
		cout << "Not enough budget to create this job!\n";
		return Job(NULL, NULL, NULL);
	}

	if (job.nbHours <= sjq.maxNbOfHours && job.nbNodes <= sjq.maxNbOfNodes) {

	}
	else {
		cout << "The number of hours or of nodes is too high for this queue!\n";
		return Job(NULL, NULL, NULL);
	}


	
}
