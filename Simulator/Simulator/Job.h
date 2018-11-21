#pragma once
#ifndef JOB_H
#define JOB_H

#include "IncludeFiles.h"


class Job {
public:
	// typeNode = 0 for a traditional node, 1 for an accelerated node, 2 for a specialized node
	Job(double jobBudget, int nbOfNodes, int nbOfHours, int typeNode, int userId);

	double budget;
	int nbNodes;
	int nbHours;

	// 0 for a traditional node, 1 for an accelerated node, 2 for a specialized node
	int typeOfNode;
};

#endif 
