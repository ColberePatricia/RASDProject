#include "AcceleratedNode.h"
#include "HugeJobQueue.h"
#include "Input.h"
#include "ITStaff.h"
#include "Job.h"
#include "LargeJobQueue.h"
#include "MediumJobQueue.h"
#include "Output.h"
#include "Researcher.h"
#include "Scheduler.h"
#include "SchedulerInput.h"
#include "SchedulerOutput.h"
#include "ShortJobQueue.h"
#include "SpecializedNode.h"
#include "StorageDevice.h"
#include "Student.h"
#include "TraditionalNode.h"
#include "UsersGenerator.h"

double evaluatorOfScheduler();

int main() {
	// First, we generate our users inside of the simulation with 10 it staff, 100 researchers, 1000 students
	UsersGenerator ug(10, 100, 1000);

	// Each user generates jobs at certain times up to its budget


	return 0;
}

double evaluatorOfScheduler() {
	double t1, t2;
	// test multiple situations
	return t2 - t1;
}

