#pragma once
#ifndef OUTPUT_H
#define OUTPUT_H

#include "IncludeFiles.h"
#include "Scheduler.h"
#include "UsersGenerator.h"

class Output {
public:
	void numberOfJobsProcessedInEachQueue(Scheduler sch);
	void actualNumberOfMachineHoursConsumedByEachJob(Scheduler sch);
	void utilizationRatio(Scheduler sch, int numberOfMachineHoursAvailable);
	void pricePaidByTheUsers(UsersGenerator ug);
	void averageWaitTimeInEachQueue(Scheduler sch);

	// TO DO
	void averageTurnaroundTimeRatio(Scheduler sch);

	void economicBalanceOfTheCentre(UsersGenerator ug, double operatingCost);
};

#endif 
