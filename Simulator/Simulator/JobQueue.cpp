#include "JobQueue.h"


// Returns the job queues
vector<Job> JobQueue::getJobQueue() {
	return jobQueue;
}

// Add an element to the job queue
void JobQueue::addToJobQueue(Job job) {
	jobQueue.push_back(job);
}

// Remove the element number i of the job queues,
// returns the id of the job removed
int JobQueue::removeFromJobQueue(int i) {
	jobQueue.erase(jobQueue.begin() + i);
}
