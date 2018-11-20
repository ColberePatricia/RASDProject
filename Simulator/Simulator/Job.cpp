#include "Job.h"


Job::Job(double jobBudget, int nbOfNodes, int nbOfHours, int typeNode) {
	budget = jobBudget;
	nbNodes = nbOfNodes;
	nbHours = nbOfHours;
	typeOfNode = typeNode;
}

