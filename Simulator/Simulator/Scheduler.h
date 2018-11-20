#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include <fstream>
#include "Job.h"
#include "JobQueue.h"
#include "ShortJobQueue.h"
#include "MediumJobQueue.h"
#include "LargeJobQueue.h"
#include "HugeJobQueue.h"
#include "Node.h"
using namespace std;


class Scheduler {
public:
	// Will use the nodes and block them for the time asked
	// Since it is a First In, First Out scheduler, the index of the job treated 
	// in the job queue is 0
	void treatJobInQueue(Job job, JobQueue jobQueue);

	ShortJobQueue sjq;
	MediumJobQueue mjq;
	LargeJobQueue ljq;
	HugeJobQueue hjq;
};

#endif 
