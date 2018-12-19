#include "Job.h"


Job::Job(double jobBudget, int nbOfNodes, int nbOfHours, int typeNode, int userId) {
	assert(jobBudget >= 0);
	assert(nbOfNodes >= 0);
	assert(nbOfHours >= 0);
	assert(typeNode >= 0 && typeNode <= 2);
	assert(userId >= 0);

	budget = jobBudget;
	nbNodes = nbOfNodes;
	nbHours = nbOfHours;
	typeOfNode = typeNode;
}

