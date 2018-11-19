#include "LargeJobQueue.h"

LargeJobQueue::LargeJobQueue() {
	costPerMachineHour = 2;
	maxNbOfHours = 16;
	maxNbOfNodes = 1024;
}
