#include "Output.h"

void Output::outputResultsOfTheSimulation(Scheduler &sch, Node &node, UsersGenerator &ug, int numberOfMachineHoursAvailable, double operatingCost) {
	cout << "\n\nResults of the simulation\n";
	
	numberOfJobsProcessedInEachQueue(sch);
	actualNumberOfMachineHoursConsumedByEachJob(sch);
	utilizationRatio(node, numberOfMachineHoursAvailable);
	pricePaidByTheUsers(ug);
	averageWaitTimeInEachQueue(sch);
	averageTurnaroundTimeRatio(sch);
	economicBalanceOfTheCentre(ug, operatingCost);

	showTraditionalNodes(node);
	showAcceleratedNodes(node);
	showSpecializedNodes(node);
	
	cout << "\n\n";
}

void Output::numberOfJobsProcessedInEachQueue(Scheduler &sch) {
	cout << "Number of jobs processed in each queue:\n";
	cout << "Short job queue: " << sch.sjq.numberOfJobsProcessed << "\n";
	cout << "Medium job queue: " << sch.mjq.numberOfJobsProcessed << "\n";
	cout << "Large job queue: " << sch.ljq.numberOfJobsProcessed << "\n";
	cout << "Huge job queue: " << sch.hjq.numberOfJobsProcessed << "\n";
	cout << "\n";
}

void Output::actualNumberOfMachineHoursConsumedByEachJob(Scheduler &sch) {
	cout << "Actual number of machine hours consumed by each job:\n";

	for (unsigned int i = 0; i < sch.numberOfMachineHoursConsumed.size(); i++) {
		cout << "Job " << (i+1) << ": " << sch.numberOfMachineHoursConsumed[i] << "\n";
	}

	cout << "\n";
}

void Output::utilizationRatio(Node &node, int numberOfMachineHoursAvailable) {
	assert(numberOfMachineHoursAvailable > 0);

	cout << "Utilization ratio of the machine: " << ((double)(node.getTotalNumberOfMachineHoursConsumed()))/((double)numberOfMachineHoursAvailable) << "\n";

	cout << "\n";
}

void Output::pricePaidByTheUsers(UsersGenerator &ug) {
	cout << "Price paid by each user:\n";

	cout << "By the IT staff members:\n";
	for (unsigned int i = 0; i < ug.nbOfITStaff; i++) {
		cout << "IT staff member " << (i + 1) << ": " << ug.ITStaffList[i].getBudgetSpent() << "\n";
	}
	
	cout << "By the researchers:\n";
	for (unsigned int i = 0; i < ug.nbOfResearchers; i++) {
		cout << "Researcher " << (i + 1) << ": " << ug.ResearcherList[i].getBudgetSpent() << "\n";
	}

	cout << "By the students:\n";
	for (unsigned int i = 0; i < ug.nbOfStudents; i++) {
		cout << "Student " << (i + 1) << ": " << ug.StudentList[i].getBudgetSpent() << "\n";
	}
	cout << "\n";
}

void Output::averageWaitTimeInEachQueue(Scheduler &sch) {
	cout << "Average wait time in each queue:\n";

	cout << "Short job queue: " << sch.sjq.getAverageWaitTime() << "\n";
	cout << "Medium job queue: " << sch.mjq.getAverageWaitTime() << "\n";
	cout << "Large job queue: " << sch.ljq.getAverageWaitTime() << "\n";
	cout << "Huge job queue: " << sch.hjq.getAverageWaitTime() << "\n";

	cout << "\n";
}

void Output::averageTurnaroundTimeRatio(Scheduler &sch) {
	double averageTimeRatio;
	averageTimeRatio = sch.sjq.getAverageTurnaroundTimeRatio() + sch.mjq.getAverageTurnaroundTimeRatio() + sch.ljq.getAverageTurnaroundTimeRatio() + sch.hjq.getAverageTurnaroundTimeRatio();
	averageTimeRatio = (double)(averageTimeRatio / 4);

	cout << "Average turnaround time ratio: " << averageTimeRatio << "\n";
	cout << "\n";
}

void Output::economicBalanceOfTheCentre(UsersGenerator &ug, double operatingCost) {
	assert(operatingCost >= 0);

	double totalCostOfJobs = ug.getBudgetSpentITStaff() + ug.getBudgetSpentResearchers() + ug.getBudgetSpentStudents();

	cout << "Economic balance of the center: " << (totalCostOfJobs - operatingCost) << "\n";
	cout << "\n";
}

void Output::showTraditionalNodes(Node &node) {
	cout << "\nTraditional Nodes:\n";
	showNodes(node.traditionalNodes);
}

void Output::showAcceleratedNodes(Node &node) {
	cout << "\nAccelerated Nodes:\n";
	showNodes(node.acceleratedNodes);
}

void Output::showSpecializedNodes(Node &node) {
	cout << "\nSpecialized Nodes:\n";
	showNodes(node.specializedNodes);
}

void Output::showNodes(Matrix &nodes) {
	for (unsigned int i = 0;i < nodes.getNrows();i++) {
		for (unsigned int j = 0;j < nodes.getNcols();j++) {
			cout << nodes[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	cout << "\n";
}
