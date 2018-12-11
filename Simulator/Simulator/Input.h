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
#include "TestOutput.h"
#include "ShortJobQueue.h"
#include "Student.h"
#include "UsersGenerator.h"
#include "Test.h"

class Input {
public:
	void timeStep(int time, UsersGenerator &ug, Scheduler &sch, Node &node);

	void startJobsInJobQueue(int time, UsersGenerator &ug, Scheduler &sch, Node &node, JobQueue &jq);

	int getNbOfNodes(int typeNode, Node &node, JobQueue &jq);
	// If the queue is short, typeOfQueue is 0, if it is medium 1, large 2, huge 3
	int getNbOfHours(int typeOfQueue, JobQueue &jq);
	int getTypeOfNodes();

};

#endif 
