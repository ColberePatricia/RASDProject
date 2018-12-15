#include "HugeJobQueue.h"

HugeJobQueue::HugeJobQueue() {
	costPerMachineHour = 2;
	maxNbOfHours = 64;
	Node node;
	maxNbOfNodes = 2048;
	lambda = 1.0;
	exponentialDistributionFactor = 400;
}
