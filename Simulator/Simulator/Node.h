#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include <fstream>
#include "matrix.h"
using namespace std;


class Node {
public:
	// By default we make 64 traditional nodes, 32 accelerated nodes and 32 specialized nodes.
	// There are ... hours per week, so
	Node(int nbTraditionalNodes = 64, int nbAcceleratedNodes = 32, int nbSpecializedNodes = 32);

	void useNodes(Matrix nodes, int duration, int startTime, int nbOfNodes);

	int nbOfHoursPerWeek;
	int nbOfTraditionalNodes;
	int nbOfAcceleratedNodes;
	int nbOfSpecializedNodes;

	// We represent each set of nodes for each hour of the week,
	// with 0 if the node is free, 1 if it is used
	// traditionalNodes =  Matrix(nbOfHoursPerWeek, nbOfTraditionalNodes);
	// The Matrix class used is being reused from an exercise correction in c++ course
	Matrix traditionalNodes;
	Matrix acceleratedNodes;
	Matrix specializedNodes;

#endif 
