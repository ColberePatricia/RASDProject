#include "JobQueue.h"


// Returns the job queues
vector<Job> JobQueue::getJobQueue() {
	return jobQueueVector;
}

// Add an element to the job queue
void JobQueue::addToJobQueue(Job job) {
	jobQueueVector.push_back(job);
}

// Remove the element number i of the job queues,
// returns the id of the job removed
int JobQueue::removeFromJobQueue(int i) {
	jobQueueVector.erase(jobQueueVector.begin() + i);
}
