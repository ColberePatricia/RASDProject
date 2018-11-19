#ifndef JOB_H
#define JOB_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include <fstream>
using namespace std;


class Job {
public:
	Job(double jobBudget, int nbOfNodes, int nbOfHours);

	double budget;
	int nbNodes;
	int nbHours;
};

#endif 
