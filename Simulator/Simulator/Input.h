#pragma once
#ifndef INPUT_H
#define INPUT_H

#include "IncludeFiles.h"
#include "HugeJobQueue.h"
#include "ITStaff.h"
#include "Job.h"
#include "LargeJobQueue.h"
#include "MediumJobQueue.h"
#include "Researcher.h"
#include "Scheduler.h"
#include "ShortJobQueue.h"
#include "Student.h"
#include "UsersGenerator.h"
#include "Test.h"
#include <random>

class Input {
public:
	// If we are before Friday 5pm, where time is 104 hours, we use the short, medium and large queues
	// else we use the huge queue
	void timeStep(int time, UsersGenerator &ug, Scheduler &sch, Node &node);

	// We choose the users who will send a job, each user can send one or no job at each time step
	// each user will have a chance to send a job modeled by an exponential probability distribution
	void startJobsInJobQueue(int time, UsersGenerator &ug, Scheduler &sch, Node &node, JobQueue &jq);

	int getNbOfNodes(Node &node, JobQueue &jq);
	// If the queue is short, typeOfQueue is 0, if it is medium 1, large 2, huge 3
	int getNbOfHours(int typeOfQueue, JobQueue &jq);
	int getTypeOfNodes();

	double generateNumberFromExponentialDistribution(double lambda);
	void printNumbersFromExponentialDistribution(double lambda, int iterations);

};

#endif 
