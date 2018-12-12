#include "LargeJobQueue.h"

LargeJobQueue::LargeJobQueue() {
	costPerMachineHour = 2;
	maxNbOfHours = 16;
	maxNbOfNodes = 1024;
	lambda = 1.0;
	exponentialDistributionFactor = 200;
}
