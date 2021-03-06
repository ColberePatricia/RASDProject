#include "Node.h"

Node::Node(int nbTraditionalNodes, int nbAcceleratedNodes, int nbSpecializedNodes) {
	assert(nbTraditionalNodes >= 0);
	assert(nbAcceleratedNodes >= 0);
	assert(nbSpecializedNodes >= 0);
	assert(nbTraditionalNodes + nbAcceleratedNodes + nbSpecializedNodes >= 128);

	nbOfTraditionalNodes = nbTraditionalNodes;
	nbOfAcceleratedNodes = nbAcceleratedNodes;
	nbOfSpecializedNodes = nbSpecializedNodes;

	nbOfHoursPerWeek = 168;

	// The matrix is initialised to contain zeros, so the nodes are initialised the same way
	traditionalNodes =  Matrix(nbOfHoursPerWeek, nbOfTraditionalNodes);
	acceleratedNodes = Matrix(nbOfHoursPerWeek, nbOfAcceleratedNodes);
	specializedNodes = Matrix(nbOfHoursPerWeek, nbOfSpecializedNodes);
}

void Node::useNodes(Matrix &nodes, int startTime, int nbOfNodes, JobQueue &jobQueue) {
	assert(startTime >= 0 && startTime <= nbOfHoursPerWeek);
	assert(nbOfNodes >= 0);

	int indexOfTime = startTime;
	int indexOfNode = 0;
	int nbOfNodesUsed = 0;
	bool emptyNodesAtTimeStep = false;
	int i = startTime;
	int j = 0;

	// We find which is the first node we can use from a given start time
	while (i < nodes.getNrows() && !emptyNodesAtTimeStep) {
		while (j < nodes.getNcols() && !emptyNodesAtTimeStep) {
			if (nodes[i][j] == 0) {
				emptyNodesAtTimeStep = true;
			}
			j++;
			if (!emptyNodesAtTimeStep) {
				indexOfNode++;
			}
		}
		if (!emptyNodesAtTimeStep) {
			indexOfTime++;
		}
		j = 0;
		i++;
	}

	jobQueue.addNewWaitTime(indexOfTime - startTime);
	int startJobTime = indexOfTime;

	// The nodes that are used take the value of 1
	while (nbOfNodesUsed < nbOfNodes) {
		if (indexOfTime < nodes.getNrows() && indexOfNode < nodes.getNcols())
			nodes[indexOfTime][indexOfNode] = 1;

		if (indexOfNode == nodes.getNcols() - 1) {
			indexOfNode = 0;
			indexOfTime++;
		}
		else
			indexOfNode++;
		nbOfNodesUsed++;
	}

	jobQueue.addNewRunTime(indexOfTime - startJobTime);
}

int Node::getTotalNumberOfMachineHoursConsumed() {
	// If the machine has been used at a certain time, one of the nodes will have been used
	// We check at which times at least one of the nodes has been used
	vector<int> sum_rows(traditionalNodes.getNrows(), 0);
	int totalNbHours = 0;

	for (unsigned int i = 0; i < traditionalNodes.getNrows(); i++) {
		for (unsigned int j = 0; j < traditionalNodes.getNcols(); j++) {
			sum_rows[i] += traditionalNodes[i][j];
		}
	}

	for (unsigned int i = 0; i < acceleratedNodes.getNrows(); i++) {
		for (unsigned int j = 0; j < acceleratedNodes.getNcols(); j++) {
			sum_rows[i] += acceleratedNodes[i][j];
		}
	}

	for (unsigned int i = 0; i < specializedNodes.getNrows(); i++) {
		for (unsigned int j = 0; j < specializedNodes.getNcols(); j++) {
			sum_rows[i] += specializedNodes[i][j];
		}
	}

	for (unsigned int i = 0;i < sum_rows.size();i++) {
		if (sum_rows[i] > 0)
			totalNbHours++;
	}
	
	return totalNbHours;
}

