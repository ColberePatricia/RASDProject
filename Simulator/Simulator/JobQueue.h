#pragma once
#ifndef JOBQUEUE_H
#define JOBQUEUE_H

#include "IncludeFiles.h"
#include "Job.h"

class JobQueue {
public:
	// Returns the job queues
	vector<Job> getJobQueue();

	// Add an element to the job queue
	void addToJobQueue(Job job);

	// Remove the ith element of the job queues,
	// returns the id of the job removed
	void removeFromJobQueue(int i);

	void numberOfJobsProcessedPlus1();

	void addNewWaitTime(int timeWaited);
	void addNewRunTime(int timeRun);

	double getAverageWaitTime();
	double getAverageRunTime();
	double getAverageTurnaroundTimeRatio();

	// The queues of jobs are represented by vectors of jobs
	vector<Job> jobQueueVector;
	double costPerMachineHour;
	int maxNbOfHours;
	int maxNbOfNodes;

	int numberOfJobsProcessed;
	vector<int> waitTime;
	vector<int> runTime;
};

#endif 
