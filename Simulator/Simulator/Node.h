#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include <fstream>
using namespace std;


class Node {
public:
	int nbOfProcessorCoresTraditional;
	int nbOfProcessorCoresAccelerated;
	int nbOfProcessorCoresSpecialized;
	int nbOfTraditionalNodes;
	int nbOfAcceleratedNodes;
	int nbOfSpecializedNodes;

	// By default we make 64 traditional nodes, 32 accelerated nodes, 32 specialized nodes, and 16 processor cores per node.
	Node(int nbCoresPerTraditionalNode = 16, int nbCoresPerAcceleratedNode = 16, int nbCoresPerSpecializedNode = 16, int nbTraditionalNodes = 64, int nbAcceleratedNodes = 32, int nbSpecializedNodes = 32);
};

#endif 
