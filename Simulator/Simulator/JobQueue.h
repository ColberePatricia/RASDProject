#ifndef JOBQUEUE_H
#define JOBQUEUE_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include <fstream>
using namespace std;


class JobQueue {
public:
	// Returns the job queues
	vector<int> getJobQueue();

	// Add an element to the job queue
	void addToJobQueue(int jobId);

	// Remove the ith element of the job queues,
	// returns the id of the job removed
	int removeFromJobQueue(int i);

private:
	// The queues of jobs are represented by vectors of int, 
	// each int representing the id of each job in the queue.
	vector<int> jobQueue;
	double costPerMachineHour;
	int maxSubsetOfMachine;
	int maxNbOfHours;
};

#endif 
