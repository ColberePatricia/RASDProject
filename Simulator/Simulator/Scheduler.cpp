#include "Scheduler.h"


void Scheduler::treatJobInQueue(Job job, JobQueue jobQueue) {
	Node node;
	int nodeType = job.typeOfNode;

	// We find the first available nodes of the right type
	// at the current time, if there are not enough nodes available
	// we go to the next time step
	if (nodeType == 0) {
		node.traditionalNodes
	} else if (nodeType == 1) {

	} else if (nodeType == 2) {

	}
	else {
		cout << "This type of node does not exist!";
	}



	jobQueue.removeFromJobQueue(0);
}
