#include "ShortJobQueue.h"

ShortJobQueue::ShortJobQueue() {
	costPerMachineHour = 5;
	maxNbOfHours = 1;
	maxNbOfNodes = 2;
	lambda = 1.0;
	exponentialDistributionFactor = 1;
}
