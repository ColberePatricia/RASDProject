#pragma once
#ifndef OUTPUT_H
#define OUTPUT_H

#include "IncludeFiles.h"
#include "Scheduler.h"
#include "UsersGenerator.h"

class Output {
public:
	void outputResultsOfTheSimulation(Scheduler &sch, Node &node, UsersGenerator &ug, int numberOfMachineHoursAvailable, double operatingCost);

	// The output of the simulation once it has finished running
	void numberOfJobsProcessedInEachQueue(Scheduler &sch);
	void actualNumberOfMachineHoursConsumedByEachJob(Scheduler &sch);
	void utilizationRatio(Node &node, int numberOfMachineHoursAvailable);
	void pricePaidByTheUsers(UsersGenerator &ug);
	void averageWaitTimeInEachQueue(Scheduler &sch);
	void averageTurnaroundTimeRatio(Scheduler &sch);
	void economicBalanceOfTheCentre(UsersGenerator &ug, double operatingCost);

	// The output that should which nodes were used when
	void showTraditionalNodes(Node &node);
	void showAcceleratedNodes(Node &node);
	void showSpecializedNodes(Node &node);
	void showNodes(Matrix &nodes);
};

#endif 
