#include "Output.h"
#include "Input.h"

double evaluatorOfScheduler();

// We choose to represent the time in the week beginning on Monday 9am and ending on the next Monday 9am, 
// so that we begin with the short, medium and large queues, and end with the huge queue
int main() {
	// The nodes, the time and the scheduler are unique in each simulation, so we generate them at the beginning
	Node node;
	// time represents the current hour of the week, the simulation stops at the end of the week, 
	// when time is greater than the number of machine hours available during the week, 168 hours
	int time = 0;
	int numberOfMachineHoursAvailable = 168;
	// We choose the operational cost per hour to be 7;
	double operationalCostPerHour = 7;
	double operatingCost = (double) operationalCostPerHour * numberOfMachineHoursAvailable;
	Scheduler sch;

	// First, we generate our users inside of the simulation with 10 IT staff, 100 researchers, 1000 students
	// We use the default values for the budgets
	UsersGenerator ug(2, 5, 20, false);

	// Test test;


	// Each user generates jobs at certain times up to its budget
	while (time <= numberOfMachineHoursAvailable) {
		Input input;
		input.timeStep(time, ug, sch, node);
		time++;
	}

	// The run of the simulation is finished, we can now show the output
	Output out;
	out.numberOfJobsProcessedInEachQueue(sch);
	out.actualNumberOfMachineHoursConsumedByEachJob(sch);
	out.utilizationRatio(node, numberOfMachineHoursAvailable);
	out.pricePaidByTheUsers(ug);
	out.averageWaitTimeInEachQueue(sch);
	out.averageTurnaroundTimeRatio(sch);
	out.economicBalanceOfTheCentre(ug, operatingCost);

	out.showTraditionalNodes(node);
	out.showAcceleratedNodes(node);
	out.showSpecializedNodes(node);

	return 0;
}

double evaluatorOfScheduler() {
	double t1, t2;
	t1 = 0;
	t2 = 0;
	// test multiple situations
	return t2 - t1;
}

