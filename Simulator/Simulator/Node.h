#pragma once
#ifndef NODE_H
#define NODE_H

#include "IncludeFiles.h"
#include "JobQueue.h"

class Node {
public:
	// By default we make 64 traditional nodes, 32 accelerated nodes and 32 specialized nodes.
	// There are 168 hours per week, so 168 rows for each matrix
	Node(int nbTraditionalNodes = 64, int nbAcceleratedNodes = 32, int nbSpecializedNodes = 32);

	void useNodes(Matrix &nodes, int startTime, int nbOfNodes, JobQueue &jobQueue);
	int getTotalNumberOfMachineHoursConsumed();

	int nbOfHoursPerWeek;
	int nbOfTraditionalNodes;
	int nbOfAcceleratedNodes;
	int nbOfSpecializedNodes;

	// We represent each set of nodes for each hour of the week,
	// with 0 if the node is free, 1 if it is used
	// traditionalNodes =  Matrix(nbOfHoursPerWeek, nbOfTraditionalNodes);
	// The Matrix class used is being reused from an exercise correction in the C++ course
	Matrix traditionalNodes;
	Matrix acceleratedNodes;
	Matrix specializedNodes;
};

#endif 
