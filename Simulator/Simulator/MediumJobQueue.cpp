#include "MediumJobQueue.h"

MediumJobQueue::MediumJobQueue() {
	costPerMachineHour = 3;
	maxNbOfHours = 8;
	maxPercentageOfCores = 0.1;
}
