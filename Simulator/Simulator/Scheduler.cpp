#include "Scheduler.h"


void Scheduler::treatJobInQueue(JobQueue &jobQueue, Node &node, int time) {
	// We check if the time is possible within the week
	assert(time >= 0 && time <= 168);

	Job job = jobQueue.getJobQueue()[0];
	int nodeType = job.typeOfNode;

	// We find the first available nodes of the right type
	// at the current time, if there are not enough nodes available
	// we go to the next time step
	if (nodeType == 0) {
		node.useNodes(node.traditionalNodes, time, job.nbNodes, jobQueue);
	} else if (nodeType == 1) {
		node.useNodes(node.acceleratedNodes, time, job.nbNodes, jobQueue);
	} else if (nodeType == 2) {
		node.useNodes(node.specializedNodes, time, job.nbNodes, jobQueue);
	}
	else {
		cout << "This type of node does not exist!";
	}
	

	jobQueue.numberOfJobsProcessedPlus1();
	jobQueue.removeFromJobQueue(0);
}
