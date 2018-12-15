#include "User.h"

// Creates a user generated for the simulation
User::User(double userBudget, int userId, double cap) {
	assert(userBudget > 0);
	assert(userId >= 0);

	budget = userBudget;
	id = userId;
	budgetSpent = 0;
	instantaneousCap = cap;
}


double User::getBudget() {
	return budget;
}

double User::getBudgetSpent() {
	return budgetSpent;
}

int User::getId() {
	return id;
}

double User::getInstantaneousCap() {
	return instantaneousCap;
}


void User::spendBudget(double budgetUserSpent) {
	assert(budgetUserSpent >= 0);

	budget = budget - budgetUserSpent;
	budgetSpent += budgetUserSpent;
}

Job User::createJobAndSendTosendJobToJobQueue(int nbOfNodes, int nbOfHours, int typeNode, JobQueue &jobq, Node &node, int time, Scheduler &sch) {
	assert(nbOfNodes > 0);
	assert(nbOfHours > 0);
	assert(typeNode >= 0 && typeNode <= 2);
	assert(time >= 0 && time <= 168);

	double jobBudget = jobq.costPerMachineHour * nbOfHours;
	if (jobBudget > getInstantaneousCap()) {
		cout << "Instantaneous cap too low to create this job!" << " Budget needed: " << jobBudget << " Cap: " << getInstantaneousCap() << "\n";
		return Job(NULL, NULL, NULL, NULL, NULL);
	}

	Job job = Job(jobBudget, nbOfNodes, nbOfHours, typeNode, getId());
	// Check wether the user has enough budget to create the job
	if (jobBudget > getBudget()) {
		cout << "Not enough budget to create this job!" << " Budget needed: " << jobBudget << " Budget possessed: " << getBudget() << "\n";
		return Job(NULL, NULL, NULL, NULL, NULL);
	}
	
	if (job.nbHours <= jobq.maxNbOfHours && job.nbNodes <= jobq.maxNbOfNodes) {
		jobq.addToJobQueue(job);
		spendBudget(jobBudget);
		sch.treatJobInQueue(jobq, node, time);
	}
	else if (job.nbHours > jobq.maxNbOfHours) {
		cout << "The number of hours is too high for this queue!\n";
		return Job(NULL, NULL, NULL, NULL, NULL);
	}
	else {
		cout << "The number of nodes is too high for this queue!\n";
		return Job(NULL, NULL, NULL, NULL, NULL);
	}

	sch.numberOfMachineHoursConsumed.push_back(nbOfHours);

	return Job(jobBudget, nbOfNodes, nbOfHours, typeNode, getId());
}
