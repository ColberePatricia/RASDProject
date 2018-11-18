#include "LargeJobQueue.h"

LargeJobQueue::LargeJobQueue() {
	costPerMachineHour = 2;
	maxNbOfHours = 16;
	maxPercentageOfCores = 0.5;
}
