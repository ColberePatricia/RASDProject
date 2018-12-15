#include "Output.h"
#include "Input.h"


// We choose to represent the time in the week beginning on Monday 9am and ending on the next Monday 9am, 
// so that we begin with the short, medium and large queues, and end with the huge queue
int main() {
	// The nodes, the time, the scheduler and the set of users are unique in each simulation,
	// so we generate them at the beginning
	Node node;
	// time represents the current hour of the week, the simulation stops at the end of the week, 
	// when time is greater than the number of machine hours available during the week, 168 hours
	int time = 0;
	int numberOfMachineHoursAvailable = 168;
	// We choose the operational cost per hour to be so that the machine is costing less than it produces value
	// when the machine is used half of its available hours
	// The cost of a queue is on average 6 per hour, so it gives us an operational cost of:
	double operationalCostPerHour = 6 / 2;
	double operatingCost = (double) operationalCostPerHour * numberOfMachineHoursAvailable;
	Scheduler sch;

	// We generate our users inside of the simulation with 2 IT staff, 5 researchers, 20 students
	// We use the default values for the budgets so that we do not have to enter them manually,
	// but we can choose to enter them manually by using true instead of false
	UsersGenerator ug(2, 5, 20, false);

	Input input;
	// Each user generates jobs at certain times up to its budget
	while (time <= numberOfMachineHoursAvailable) {
		input.timeStep(time, ug, sch, node);
		time++;
	}

	// The run of the simulation is finished, we can now show the output
	Output out;
	out.outputResultsOfTheSimulation(sch, node, ug, numberOfMachineHoursAvailable, operatingCost);

	Test test;
	test.testSimulation();

	EvaluatorOfScheduler eval;
	eval.evaluation();


	return 0;
}



