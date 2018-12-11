#include "Output.h"
#include "Input.h"

double evaluatorOfScheduler();
void timeStep(int time, UsersGenerator ug, Scheduler sch, Node node);
void startJobsBeginningOfWeek(int time, UsersGenerator ug, Scheduler sch, Node node);
void startJobsEndOfWeek(int time, UsersGenerator ug, Scheduler sch, Node node);

int getNbOfNodes(int typeNode, Node node, JobQueue jq);
// If the queue is short, typeOfQueue is 0, if it is medium 1, large 2, huge 3
int getNbOfHours(int typeOfQueue, JobQueue jq);
int getTypeOfNodes();

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
		timeStep(time, ug, sch, node);
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

	/*
	out.showTraditionalNodes(node);
	out.showAcceleratedNodes(node);
	out.showSpecializedNodes(node);
	*/

	return 0;
}

double evaluatorOfScheduler() {
	double t1, t2;
	t1 = 0;
	t2 = 0;
	// test multiple situations
	return t2 - t1;
}

void timeStep(int time, UsersGenerator ug, Scheduler sch, Node node) {
	// If we are before Friday 5pm, where time is 104 hours, we use the short, medium and large queues
	// else we use the huge queue
	
	// We randomly choose which user will submit a job at this time ad what job it will be
	if (time < 104) {
		// The jobs are submitted to the short, medium and large queues
		startJobsBeginningOfWeek(time, ug, sch, node);
	}
	else {
		// The jobs are submitted to the huge queue
		startJobsEndOfWeek(time, ug, sch, node);
	}
}

void startJobsBeginningOfWeek(int time, UsersGenerator ug, Scheduler sch, Node node) {
	// If the duration of the job makes it last after Friday 5pm, it is not accepted so that the machine is free for the weekend queue
	// TODO
}

void startJobsEndOfWeek(int time, UsersGenerator ug, Scheduler sch, Node node) {
	// Every job is sent to the huge queue
	// We choose the users who will send a job, each user can send one or no job at each time step,
	// each user will have a chance of 1/20 to send a job
	for (unsigned int itStaff = 0; itStaff < ug.ITStaffList.size(); itStaff++) {
		if (rand() % 20 == 0) {
			// The user sends a job to the huge queue
			// We choose the number of nodes of the job, its number of hours and its type of node
			int typeNode = getTypeOfNodes();
			int nbOfNodes = getNbOfNodes(typeNode, node, sch.hjq);
			int nbOfHours = getNbOfHours(3, sch.hjq);
			ug.ITStaffList[itStaff].createJobAndSendTosendJobToJobQueue(nbOfNodes, nbOfHours, typeNode, sch.hjq, node, time, sch);
		}
	}

	for (unsigned int researcher = 0; researcher < ug.ResearcherList.size(); researcher++) {
		if (rand() % 20 == 0) {
			// The user sends a job to the huge queue
			// We choose the number of nodes of the job, its number of hours and its type of node
			int typeNode = getTypeOfNodes();
			int nbOfNodes = getNbOfNodes(typeNode, node, sch.hjq);
			int nbOfHours = getNbOfHours(3, sch.hjq);
			ug.ResearcherList[researcher].createJobAndSendTosendJobToJobQueue(nbOfNodes, nbOfHours, typeNode, sch.hjq, node, time, sch);
		}
	}

	for (unsigned int student = 0; student < ug.StudentList.size(); student++) {
		if (rand() % 20 == 0) {
			// The user sends a job to the huge queue
			// We choose the number of nodes of the job, its number of hours and its type of node
			int typeNode = getTypeOfNodes();
			int nbOfNodes = getNbOfNodes(typeNode, node, sch.hjq);
			int nbOfHours = getNbOfHours(3, sch.hjq);
			ug.StudentList[student].createJobAndSendTosendJobToJobQueue(nbOfNodes, nbOfHours, typeNode, sch.hjq, node, time, sch);
		}
	}
}

int getNbOfNodes(int typeNode, Node node, JobQueue jq) {
	// We decide that the number of nodes taken by a job are between 4 and the max number of nodes of the queue
	int nbNodes;
	if (typeNode == 1)
		nbNodes = 4 + rand() % (jq.maxNbOfNodes - 3);
	else if (typeNode == 2)
		nbNodes = 4 + rand() % (jq.maxNbOfNodes - 3);
	else // We default to traditional nodes if the type is 0 or false
		nbNodes = 4 + rand() % (jq.maxNbOfNodes - 3);

	return nbNodes;
}

int getNbOfHours(int typeOfQueue, JobQueue jq) {
	int nbHours;
	if (typeOfQueue == 0)
		nbHours = 1;
	else if (typeOfQueue == 1)
		nbHours = 2 + rand() % (jq.maxNbOfHours - 1);
	else if (typeOfQueue == 2)
		nbHours = 9 + rand() % (jq.maxNbOfHours - 8);
	else if (typeOfQueue == 3)
		nbHours = 1 + rand() % (jq.maxNbOfHours);

	return nbHours;
}

int getTypeOfNodes() {
	// typeNode = 0 for a traditional node, 1 for an accelerated node, 2 for a specialized node
	// We choose randomly with a chance of 1/2 to have traditional, 1/4 accelerated and 1/4 specialized nodes
	int typeNode = rand()%4; // typeNode is between 0 and 3
	// If typeNode is 0, 1 or 2 it keeps its value, if it is 3 it becomes the value 0 of the traditional nodes
	if (typeNode == 3)
		typeNode = 0;

	return typeNode;
}
