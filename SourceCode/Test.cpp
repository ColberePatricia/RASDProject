#include "Test.h"


void Test::testSimulation() {
	cout << "Test of the simulation\n\n";
	testInput();
	testOutput();
	testJob();
	testNode();
	testScheduler();
	testUsersGenerator();
	testEvaluatorOfScheduler();
	testJobQueue();
	testHugeJobQueue();
	testLargeJobQueue();
	testMediumJobQueue();
	testShortJobQueue();
	testUser();
	testITStaff();
	testResearcher();
	testStudent();
	cout << "\nAll the tests have been successful!\n\n";
}




void Test::testInput() {
	Input in;
	UsersGenerator ug = UsersGenerator(5, 30, 500, false);
	Scheduler sch;
	Node node;
	in.timeStep(7, ug, sch, node);
}

void Test::testOutput() {
	Output out;
}

void Test::testJob() {
	Job job = Job(60, 10, 2, 1, 3);

	assert(job.budget == 60);
	assert(job.nbNodes == 10);
	assert(job.nbHours == 2);
	assert(job.typeOfNode == 1);
}

void Test::testNode() {
	Node node;
	Node node2(64, 128, 64);

	assert(node.nbOfTraditionalNodes == 64 && node.nbOfAcceleratedNodes == 32 && node.nbOfSpecializedNodes == 32);
	assert(node2.nbOfTraditionalNodes == 64 && node2.nbOfAcceleratedNodes == 128 && node2.nbOfSpecializedNodes == 64);
	assert(node.nbOfHoursPerWeek == 168);
	assert(node.traditionalNodes.getNrows() == node.nbOfHoursPerWeek && node.traditionalNodes.getNcols() == node.nbOfTraditionalNodes);
	assert(node.acceleratedNodes.getNrows() == node.nbOfHoursPerWeek && node.acceleratedNodes.getNcols() == node.nbOfAcceleratedNodes);
	assert(node.specializedNodes.getNrows() == node.nbOfHoursPerWeek && node.specializedNodes.getNcols() == node.nbOfSpecializedNodes);

	MediumJobQueue mjq;
	node.useNodes(node.traditionalNodes, 15, 200, mjq);
	
	Matrix resultTradiNodes = Matrix(node.nbOfHoursPerWeek, node.nbOfTraditionalNodes);
	for (int i = 15;i < 18;i++) {
		for (int j = 0;j < resultTradiNodes.getNcols();j++)
			resultTradiNodes[i][j] = 1;
	}

	for (int j = 0;j < 8;j++)
		resultTradiNodes[18][j] = 1;

	assert(node.traditionalNodes == resultTradiNodes);
	assert(mjq.getAverageWaitTime() == 0);
	assert(mjq.getAverageRunTime() == 3);

	assert(node.getTotalNumberOfMachineHoursConsumed() == 4);
}

void Test::testScheduler() {
	Scheduler sch;
	Node node;
	Job job(60, 36, 2, 0, 36);
	sch.mjq.addToJobQueue(job);
	sch.treatJobInQueue(sch.mjq, node, 16);

}

void Test::testUsersGenerator() {
	UsersGenerator ugRandomBudget(2, 10, 20, false);
	UsersGenerator ugChosenBudget(0, 0, 0, true);

	for (int i = 0;i < ugRandomBudget.ITStaffList.size();i++)
		assert(ugRandomBudget.ITStaffList[i].getBudget() == 1680.0);
	
	for (int i = 0;i < ugRandomBudget.ITStaffList.size();i++)
		assert(ugRandomBudget.ResearcherList[i].getBudget() >= 800.0 && ugRandomBudget.ResearcherList[i].getBudget() <=1600.0);

	for (int i = 0;i < ugRandomBudget.ITStaffList.size();i++)
		assert(ugRandomBudget.StudentList[i].getBudget() == 480.0);

	assert(ugRandomBudget.getBudgetITStaff() == 3360);
	assert(ugRandomBudget.getBudgetResearchers() >= 10 * 800.0 && ugRandomBudget.getBudgetResearchers() <= 10 * 1600.0);
	assert(ugRandomBudget.getBudgetStudents() == 9600);

	assert(ugRandomBudget.getBudgetSpentITStaff() == 0);
	assert(ugRandomBudget.getBudgetSpentResearchers() == 0);
	assert(ugRandomBudget.getBudgetSpentStudents() == 0);
}

void Test::testEvaluatorOfScheduler() {
	EvaluatorOfScheduler eval;
}




void Test::testJobQueue() {
	JobQueue jq;
	int numberOfJobsProcessedInitially = jq.numberOfJobsProcessed;
	assert(numberOfJobsProcessedInitially == 0);

	vector<Job> jobQueueVect = jq.getJobQueue();
	
	Job job = Job(30, 2, 1, 0, 0);
	jq.addToJobQueue(job);

	jq.removeFromJobQueue(0);

	jq.numberOfJobsProcessedPlus1();
	assert(jq.numberOfJobsProcessed == 1);
	jq.numberOfJobsProcessedPlus1();
	assert(jq.numberOfJobsProcessed == 2);

	jq.addNewWaitTime(3);
	jq.addNewWaitTime(5);
	assert(jq.waitTime[0] == 3);
	assert(jq.getAverageWaitTime() == 4);

	jq.addNewRunTime(4);
	jq.addNewRunTime(6);
	assert(jq.runTime[0] == 4);
	assert(jq.getAverageRunTime() == 5);

	assert(jq.getAverageTurnaroundTimeRatio() == 1.8);

}

void Test::testHugeJobQueue() {
	HugeJobQueue hjq;
	assert(hjq.costPerMachineHour == 2);
	assert(hjq.maxNbOfHours == 64);
	assert(hjq.maxNbOfNodes == 2048);
	assert(hjq.lambda == 1.0);
	assert(hjq.exponentialDistributionFactor == 400);
}

void Test::testLargeJobQueue() {
	LargeJobQueue ljq;
	assert(ljq.costPerMachineHour == 2);
	assert(ljq.maxNbOfHours == 16);
	assert(ljq.maxNbOfNodes == 1024);
	assert(ljq.lambda == 1.0);
	assert(ljq.exponentialDistributionFactor == 200);
}
void Test::testMediumJobQueue() {
	MediumJobQueue mjq;
	assert(mjq.costPerMachineHour == 3);
	assert(mjq.maxNbOfHours == 8);
	assert(mjq.maxNbOfNodes == 204);
	assert(mjq.lambda == 1.0);
	assert(mjq.exponentialDistributionFactor == 40);
}

void Test::testShortJobQueue() {
	ShortJobQueue sjq;
	assert(sjq.costPerMachineHour == 5);
	assert(sjq.maxNbOfHours == 1);
	assert(sjq.maxNbOfNodes == 2);
	assert(sjq.lambda == 1.0);
	assert(sjq.exponentialDistributionFactor == 1);
}



void Test::testUser() {
	User user(90, 34);

	assert(user.getId() == 34);
	assert(user.getBudgetSpent() == 0);

	user.spendBudget(50);
	assert(user.getBudgetSpent() == 50);
	assert(user.getBudget() == 40);

	Scheduler sch;
	Node node;
	Job job = user.createJobAndSendTosendJobToJobQueue(8, 1, 0, sch.mjq, node, 10, sch);
	assert(job.budget != NULL);
	assert(job.nbHours == 1);
	assert(job.nbNodes == 8);
	assert(job.typeOfNode == 0);

	cout << "There should not be enough budget to create this job:\n";
	job = user.createJobAndSendTosendJobToJobQueue(8, 50, 0, sch.mjq, node, 10, sch);

	User user2(600, 39, 10);
	cout << "The instantaneous cap should be too low to create this job:\n";
	job = user2.createJobAndSendTosendJobToJobQueue(8, 50, 0, sch.mjq, node, 10, sch);

	User user3(900, 40);
	cout << "The number of hours should be too high to create this job:\n";
	job = user3.createJobAndSendTosendJobToJobQueue(17, 18, 0, sch.mjq, node, 10, sch);

	cout << "The number of nodes should be too high to create this job:\n";
	job = user3.createJobAndSendTosendJobToJobQueue(205, 3, 0, sch.mjq, node, 10, sch);
}

void Test::testITStaff() {
	ITStaff itstaff(1000, 53);
	assert(itstaff.getId() == 53);
	assert(itstaff.getBudget() == 1000);
	assert(itstaff.getInstantaneousCap() == 1680.0);

	ITStaff itstaff2(1000, 54, 50.0);
	assert(itstaff2.getInstantaneousCap() == 50.0);
}

void Test::testResearcher() {
	Researcher researcher(800, 38);
	assert(researcher.getId() == 38);
	assert(researcher.getBudget() == 800);
	assert(researcher.getInstantaneousCap() == 1600.0);

	Researcher researcher2(800, 39, 55.0);
	assert(researcher2.getInstantaneousCap() == 55.0);
}

void Test::testStudent() {
	Student student(300, 95);
	assert(student.getId() == 95);
	assert(student.getBudget() == 300);
	assert(student.getInstantaneousCap() == 100.0);

	Student student2(300, 96, 10.0);
	assert(student2.getInstantaneousCap() == 10.0);
}



