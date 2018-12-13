#include "JobQueue.h"

JobQueue::JobQueue() {
	numberOfJobsProcessed = 0;
}

// Returns the job queues
vector<Job> JobQueue::getJobQueue() {
	return jobQueueVector;
}

// Add an element to the job queue
void JobQueue::addToJobQueue(Job job) {
	jobQueueVector.push_back(job);
}

// Remove the element index i of the job queues,
// returns the id of the job removed
void JobQueue::removeFromJobQueue(int i) {
	// We check that i is a possible index of the job queue vector
	assert(i >= 0);
	assert(i < jobQueueVector.size());

	jobQueueVector.erase(jobQueueVector.begin() + i);
}

void JobQueue::numberOfJobsProcessedPlus1() {
	numberOfJobsProcessed++;
}

void JobQueue::addNewWaitTime(int timeWaited) {
	assert(timeWaited >= 0);

	waitTime.push_back(timeWaited);
}

void JobQueue::addNewRunTime(int timeRun) {
	assert(timeRun >= 0);

	runTime.push_back(timeRun);
}

double JobQueue::getAverageWaitTime() {
	double averageWaitTime = 0;
	for (int i = 0; i < waitTime.size(); i++)
		averageWaitTime += waitTime[i];
	if (waitTime.size() > 0)
		averageWaitTime = (double)(averageWaitTime / waitTime.size());
	else
		averageWaitTime = 0;
	return averageWaitTime;
}

double JobQueue::getAverageRunTime() {
	double averageRunTime = 0;
	for (int i = 0; i < runTime.size(); i++)
		averageRunTime += runTime[i];
	if (runTime.size() > 0)
		averageRunTime = (double)(averageRunTime / runTime.size());
	else
		averageRunTime = 0;
	return averageRunTime;
}

double JobQueue::getAverageTurnaroundTimeRatio() {
	double ratio = 0;
	ratio += getAverageWaitTime();
	ratio += getAverageRunTime();
	if (getAverageRunTime() > 0)
		ratio = (double)(ratio / getAverageRunTime());
	else
		ratio = 0;
	return ratio;
}

