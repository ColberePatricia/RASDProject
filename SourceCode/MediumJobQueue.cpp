#include "MediumJobQueue.h"

MediumJobQueue::MediumJobQueue() {
	costPerMachineHour = 3;
	maxNbOfHours = 8;
	maxNbOfNodes = 204;
	lambda = 1.0;
	exponentialDistributionFactor = 40;
}
