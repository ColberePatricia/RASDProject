#ifndef JOBQUEUE_H
#define JOBQUEUE_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include <fstream>
#include "Job.h"
using namespace std;


class JobQueue {
public:
	// Returns the job queues
	vector<Job> getJobQueue();

	// Add an element to the job queue
	void addToJobQueue(Job job);

	// Remove the ith element of the job queues,
	// returns the id of the job removed
	int removeFromJobQueue(int i);

	// The queues of jobs are represented by vectors of jobs
	vector<Job> jobQueue;
	double costPerMachineHour;
	int maxNbOfHours;
	int maxNbOfNodes;
};

#endif 
