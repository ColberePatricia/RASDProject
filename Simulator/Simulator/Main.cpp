#include "Output.h"
#include "Input.h"

double evaluatorOfScheduler();

int main() {
	// The nodes, the time and the scheduler are unique in each simulation, so we generate them at the beginning
	Node node;
	int time = 0;
	Scheduler sch;

	// Test test;

	// First, we generate our users inside of the simulation with 10 it staff, 100 researchers, 1000 students
	UsersGenerator ug(10, 100, 1000);

	// Each user generates jobs at certain times up to its budget


	return 0;
}

double evaluatorOfScheduler() {
	double t1, t2;
	t1 = 0;
	t2 = 0;
	// test multiple situations
	return t2 - t1;
}

