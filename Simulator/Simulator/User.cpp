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

void User::spendBudget(double budgetSpent) {
	budget = budget - budgetSpent;
}

Job User::createJobAndSendTosendJobToJobQueue(int nbOfNodes, int nbOfHours, int typeNode, JobQueue jobq, Node node, int time, Scheduler sch) {
	double jobBudget = jobq.costPerMachineHour * nbOfHours;
	Job job = Job(jobBudget, nbOfNodes, nbOfHours, typeNode, getId());
	// Check wether the user has enough budget to create the job
	if (jobBudget > getBudget()) {
		cout << "Not enough budget to create this job!\n";
		return Job(NULL, NULL, NULL, NULL, NULL);
	}
	
	if (job.nbHours <= jobq.maxNbOfHours && job.nbNodes <= jobq.maxNbOfNodes) {
		jobq.addToJobQueue(job);
		spendBudget(jobBudget);
		sch.treatJobInQueue(jobq, node, time);
	}
	else {
		cout << "The number of hours or of nodes is too high for this queue!\n";
		return Job(NULL, NULL, NULL, NULL, NULL);
	}

	sch.numberOfMachineHoursConsumed.push_back(nbOfHours);

	return Job(jobBudget, nbOfNodes, nbOfHours, typeNode, getId());
}
