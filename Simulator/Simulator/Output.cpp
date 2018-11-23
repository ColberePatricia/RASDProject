#include "Output.h"

void Output::numberOfJobsProcessedInEachQueue(Scheduler sch) {
	cout << "Number of jobs processed in each queue:\n";
	cout << "Short job queue: " << sch.sjq.numberOfJobsProcessed << "\n";
	cout << "Medium job queue: " << sch.mjq.numberOfJobsProcessed << "\n";
	cout << "Large job queue: " << sch.ljq.numberOfJobsProcessed << "\n";
	cout << "Huge job queue: " << sch.hjq.numberOfJobsProcessed << "\n";
}

void Output::actualNumberOfMachineHoursConsumedByEachJob(Scheduler sch) {
	cout << "Actual number of machine hours consumed by each job:\n";

	for (unsigned int i = 0; i < sch.numberOfMachineHoursConsumed.size(); i++) {
		cout << "Job " << (i+1) << ": " << sch.numberOfMachineHoursConsumed[i] << "\n";
	}

}

void Output::utilizationRatio(Scheduler sch, int numberOfMachineHoursAvailable) {
	cout << "Utilization ratio of the machine:\n";

	for (unsigned int i = 0; i < sch.numberOfMachineHoursConsumed.size(); i++) {
		cout << "Job " << (i + 1) << ": " << (double)(sch.numberOfMachineHoursConsumed[i] / numberOfMachineHoursAvailable) << "\n";
	}

}

void Output::pricePaidByTheUsers(UsersGenerator ug) {
	cout << "Price paid by each user:\n";

	cout << "By the IT staff members:\n";
	for (unsigned int i = 0; i < ug.nbOfITStaff; i++) {
		cout << "IT staff member " << (i + 1) << ": " << ug.ITStaffList[i].getBudget() << "\n";
	}
	
	cout << "By the researchers:\n";
	for (unsigned int i = 0; i < ug.nbOfResearchers; i++) {
		cout << "Researcher " << (i + 1) << ": " << ug.ResearcherList[i].getBudget() << "\n";
	}

	cout << "By the students:\n";
	for (unsigned int i = 0; i < ug.nbOfStudents; i++) {
		cout << "Student " << (i + 1) << ": " << ug.StudentList[i].getBudget() << "\n";
	}
}

void Output::averageWaitTimeInEachQueue(Scheduler sch) {
	cout << "Average wait time in each queue:\n";

	cout << "Short job queue: " << sch.sjq.getAverageWaitTime() << "\n";
	cout << "Medium job queue: " << sch.mjq.getAverageWaitTime() << "\n";
	cout << "Large job queue: " << sch.ljq.getAverageWaitTime() << "\n";
	cout << "Huge job queue: " << sch.hjq.getAverageWaitTime() << "\n";
}

void Output::averageTurnaroundTimeRatio(Scheduler sch) {

}

void Output::economicBalanceOfTheCentre(UsersGenerator ug, double operatingCost) {
	double totalCostOfJobs = ug.getBudgetITStaff() + ug.getBudgetResearchers() + ug.getBudgetStudents();

	cout << "Economic balance of the center: " << (totalCostOfJobs - operatingCost) << "\n";
}


