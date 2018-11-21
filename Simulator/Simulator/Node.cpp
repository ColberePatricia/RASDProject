#include "Node.h"


Node::Node(int nbTraditionalNodes = 64, int nbAcceleratedNodes = 32, int nbSpecializedNodes = 32) {
	nbOfTraditionalNodes = nbTraditionalNodes;
	nbOfAcceleratedNodes = nbAcceleratedNodes;
	nbOfSpecializedNodes = nbSpecializedNodes;

	nbOfHoursPerWeek = 80;

	// The matrix is initialised to contain zeros, so the nodes are initialised to be free
	traditionalNodes =  Matrix(nbOfHoursPerWeek, nbOfTraditionalNodes);
	acceleratedNodes = Matrix(nbOfHoursPerWeek, nbOfAcceleratedNodes);
	specializedNodes = Matrix(nbOfHoursPerWeek, nbOfSpecializedNodes);
}

void Node::useNodes(Matrix nodes, int duration, int startTime, int nbOfNodes) {
	int indexOfTime = startTime;
	int indexOfNode = 0;
	int nbOfNodesUsed = 0;
	bool emptyNodesAtTimeStep = false;
	int i = startTime;
	int j = 0;

	// We find which is the first node we can use at a given start time
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

	// The nodes that are used take the value of 1
	while (nbOfNodesUsed < nbOfNodes) {
		nodes[indexOfTime][indexOfNode] = 1;
		if (indexOfNode == nodes.getNcols() - 1) {
			indexOfNode = 0;
			indexOfTime++;
		}
		else
			indexOfNode++;
		nbOfNodesUsed++;
	}
}

