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
void JobQueue::removeFromJobQueue(int i) {
	jobQueueVector.erase(jobQueueVector.begin() + i);
}

void JobQueue::numberOfJobsProcessedPlus1() {
	numberOfJobsProcessed++;
}

void JobQueue::addNewWaitTime(int timeWaited) {
	waitTime.push_back(timeWaited);
}

void JobQueue::addNewRunTime(int timeRun) {
	runTime.push_back(timeRun);
}

double JobQueue::getAverageWaitTime() {
	double averageWaitTime = 0;
	for (int i = 0; i < waitTime.size(); i++)
		averageWaitTime += waitTime[i];
	averageWaitTime = (double)(averageWaitTime / waitTime.size());
}

double JobQueue::getAverageRunTime() {
	double averageRunTime = 0;
	for (int i = 0; i < runTime.size(); i++)
		averageRunTime += runTime[i];
	averageRunTime = (double)(averageRunTime / runTime.size());
}

double JobQueue::getAverageTurnaroundTimeRatio() {
	double ratio = 0;
	ratio += getAverageWaitTime();
	ratio += getAverageRunTime();
	ratio = (double)(ratio / getAverageRunTime());
	return ratio;
}

