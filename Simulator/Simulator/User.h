#ifndef USER_H
#define USER_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include <fstream>
#include "Job.h"
#include "ShortJobQueue.h"
#include "MediumJobQueue.h"
#include "LargeJobQueue.h"
#include "HugeJobQueue.h"
#include "Scheduler.h"
using namespace std;


class User {
public:
	User(double userBudget, int userId);
	double getBudget();
	int getId();
	void spendBudget(double budgetSpent);
	// typeNode = 0 for a traditional node, 1 for an accelerated node, 2 for a specialized node
	Job createJobAndSendTosendJobToJobQueue(int nbOfNodes, int nbOfHours, int typeNode, JobQueue jobq);

private:
	double budget;
	int id;
};

#endif 
