#include "Input.h"

void Input::timeStep(int time, UsersGenerator &ug, Scheduler &sch, Node &node) {
	// We randomly choose which user will submit a job at this time ad what job it will be
	if (time < 104) {
		// The jobs are submitted to the short, medium and large queues
		// We choose randomly the queue that will be used, with 1/2 chance for the short, 1/4 for the medium and 1/4 for the large
		int typeQueue = rand() % 4;
		if (typeQueue == 3)
			typeQueue = 0;

		if (typeQueue == 0)
			startJobsInJobQueue(time, ug, sch, node, sch.sjq);
		else if (typeQueue == 1)
			startJobsInJobQueue(time, ug, sch, node, sch.mjq);
		else // By default we use the large job queue
			startJobsInJobQueue(time, ug, sch, node, sch.ljq);
	}
	else {
		// The jobs are submitted to the huge queue
		startJobsInJobQueue(time, ug, sch, node, sch.hjq);
	}
}


void Input::startJobsInJobQueue(int time, UsersGenerator &ug, Scheduler &sch, Node &node, JobQueue &jq) {

	for (unsigned int itStaff = 0; itStaff < ug.ITStaffList.size(); itStaff++) {
		// TODO
		if (rand() % 20 == 0) {
			// We choose the number of nodes of the job, its number of hours and its type of node
			int typeNode = getTypeOfNodes();
			int nbOfNodes = getNbOfNodes(typeNode, node, jq);
			int nbOfHours = getNbOfHours(3, jq);

			// If the duration of a job starting before Friday 5pm makes it last after Friday 5pm, it is not accepted so that the machine is free for the weekend queue
			if (time >= 104 || time + nbOfHours < 104)
				ug.ITStaffList[itStaff].createJobAndSendTosendJobToJobQueue(nbOfNodes, nbOfHours, typeNode, jq, node, time, sch);
			else
				cout << "The job lasts too long to be started before Friday 5pm\n";
		}
	}

	for (unsigned int researcher = 0; researcher < ug.ResearcherList.size(); researcher++) {
		if (rand() % 20 == 0) {
			// We choose the number of nodes of the job, its number of hours and its type of node
			int typeNode = getTypeOfNodes();
			int nbOfNodes = getNbOfNodes(typeNode, node, jq);
			int nbOfHours = getNbOfHours(3, jq);

			// If the duration of the job makes it last after Friday 5pm, it is not accepted so that the machine is free for the weekend queue
			if (time >= 104 || time + nbOfHours < 104)
				ug.ResearcherList[researcher].createJobAndSendTosendJobToJobQueue(nbOfNodes, nbOfHours, typeNode, jq, node, time, sch);
			else
				cout << "The job lasts too long to be started before Friday 5pm\n";
		}
	}

	for (unsigned int student = 0; student < ug.StudentList.size(); student++) {
		if (rand() % 20 == 0) {
			// We choose the number of nodes of the job, its number of hours and its type of node
			int typeNode = getTypeOfNodes();
			int nbOfNodes = getNbOfNodes(typeNode, node, jq);
			int nbOfHours = getNbOfHours(3, jq);

			// If the duration of the job makes it last after Friday 5pm, it is not accepted so that the machine is free for the weekend queue
			if (time >= 104 || time + nbOfHours < 104)
				ug.StudentList[student].createJobAndSendTosendJobToJobQueue(nbOfNodes, nbOfHours, typeNode, jq, node, time, sch);
			else
				cout << "The job lasts too long to be started before Friday 5pm\n";
		}
	}
}

int Input::getNbOfNodes(int typeNode, Node &node, JobQueue &jq) {
	//TODO
	// We decide that the number of nodes taken by a job are between 1 and the max number of nodes of the queue
	int nbNodes;
	if (typeNode == 1)
		nbNodes = 1 + rand() % jq.maxNbOfNodes;
	else if (typeNode == 2)
		nbNodes = 1 + rand() % jq.maxNbOfNodes;
	else // We default to traditional nodes if the type is 0 or false
		nbNodes = 1 + rand() % jq.maxNbOfNodes;

	return nbNodes;
}

int Input::getNbOfHours(int typeOfQueue, JobQueue &jq) {
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

int Input::getTypeOfNodes() {
	// typeNode = 0 for a traditional node, 1 for an accelerated node, 2 for a specialized node
	// We choose randomly with a chance of 1/2 to have traditional, 1/4 accelerated and 1/4 specialized nodes
	int typeNode = rand() % 4; // typeNode is between 0 and 3
	// If typeNode is 0, 1 or 2 it keeps its value, if it is 3 it becomes the value 0 of the traditional nodes
	if (typeNode == 3)
		typeNode = 0;

	return typeNode;
}
