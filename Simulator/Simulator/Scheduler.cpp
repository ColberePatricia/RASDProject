#include "Scheduler.h"


void Scheduler::treatJobInQueue(JobQueue jobQueue, Node node, int time) {
	Job job = jobQueue.getJobQueue()[0];
	int nodeType = job.typeOfNode;

	// We find the first available nodes of the right type
	// at the current time, if there are not enough nodes available
	// we go to the next time step
	if (nodeType == 0) {
		node.useNodes(node.traditionalNodes, job.nbHours, time, job.nbNodes, jobQueue);
	} else if (nodeType == 1) {
		node.useNodes(node.acceleratedNodes, job.nbHours, time, job.nbNodes, jobQueue);
	} else if (nodeType == 2) {
		node.useNodes(node.specializedNodes, job.nbHours, time, job.nbNodes, jobQueue);
	}
	else {
		cout << "This type of node does not exist!";
	}


	jobQueue.numberOfJobsProcessedPlus1();
	jobQueue.removeFromJobQueue(0);
}
