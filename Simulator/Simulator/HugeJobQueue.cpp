#include "HugeJobQueue.h"

HugeJobQueue::HugeJobQueue() {
	costPerMachineHour = 2;
	maxNbOfHours = 64;
	Node node;
	if (node.nbOfTraditionalNodes > node.nbOfAcceleratedNodes && node.nbOfTraditionalNodes > node.nbOfSpecializedNodes)
		maxNbOfNodes = node.nbOfTraditionalNodes;
	else if (node.nbOfAcceleratedNodes > node.nbOfTraditionalNodes && node.nbOfAcceleratedNodes > node.nbOfSpecializedNodes)
		maxNbOfNodes = node.nbOfAcceleratedNodes;
	else
		maxNbOfNodes = node.nbOfSpecializedNodes;
}
