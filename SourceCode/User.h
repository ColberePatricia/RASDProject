#pragma once
#ifndef USER_H
#define USER_H

#include "IncludeFiles.h"
#include "Job.h"
#include "ShortJobQueue.h"
#include "MediumJobQueue.h"
#include "LargeJobQueue.h"
#include "HugeJobQueue.h"
#include "Scheduler.h"


class User {
public:
	// cap is the instantaneous cap of of maximum useable budget
	// By default it is the maximum budget we have chosen for the users
	// For the students it is lower as they can be prevented from starting a job
	// because of this cap
	User(double userBudget, int userId, double cap = 1680.0);

	double getBudget();
	double getBudgetSpent();
	int getId();
	double getInstantaneousCap();
	void spendBudget(double budgetUserSpent);

	// typeNode = 0 for a traditional node, 1 for an accelerated node, 2 for a specialized node
	Job createJobAndSendTosendJobToJobQueue(int nbOfNodes, int nbOfHours, int typeNode, JobQueue &jobq, Node &node, int time, Scheduler &sch);

private:
	double budget;
	double budgetSpent;
	int id;
	double instantaneousCap;
};

#endif 
