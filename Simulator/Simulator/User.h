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
	User(double userBudget, int userId);
	double getBudget();
	double getBudgetSpent();
	int getId();
	void spendBudget(double budgetUserSpent);
	// typeNode = 0 for a traditional node, 1 for an accelerated node, 2 for a specialized node
	Job createJobAndSendTosendJobToJobQueue(int nbOfNodes, int nbOfHours, int typeNode, JobQueue &jobq, Node &node, int time, Scheduler &sch);

private:
	double budget;
	double budgetSpent;
	int id;
};

#endif 
