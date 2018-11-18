#include "JobQueue.h"


// Returns the job queues
vector<int> JobQueue::getJobQueue() {
	return jobQueue;
}

// Add an element to the job queue
void JobQueue::addToJobQueue(int jobId) {
	jobQueue.push_back(jobId);
}

// Remove the element number i of the job queues,
// returns the id of the job removed
int JobQueue::removeFromJobQueue(int i) {
	jobQueue.erase(jobQueue.begin() + i);
}
