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
using namespace std;


class User {
public:
	User(double userBudget, int userId);
	double getBudget();
	int getId();
	void setBudget(double newBudget);
	void spendBudget(double budgetSpent);
	Job createJobAndSendTosendJobToShortJobQueue(int nbOfNodes, int nbOfHours);

private:
	double budget;
	int id;
};

#endif 
