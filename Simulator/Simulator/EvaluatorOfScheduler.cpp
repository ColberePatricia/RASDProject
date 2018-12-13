#include "EvaluatorOfScheduler.h"
#include <ctime>


double EvaluatorOfScheduler::evaluation() {
	clock_t t1, t2;
	double duration;

	Scheduler sch;
	Node node;
	// We create a job with a budget of 50, taking 100 traditional nodes for approximately 5 hours, the user id is 32
	Job job = Job(50, 100, 5, 0, 32);
	for (unsigned int times = 0;times < 1000;times++) {
		sch.mjq.addToJobQueue(job);
	}

	t1 = clock();

	// We do the standard example to see how long the scheduler takes
	// We do this 1000 times to get a better approximation
	for (unsigned int times = 0;times < 1000 ;times++) {
		// We treat the job we have added to the queue at starting time 15
		sch.treatJobInQueue(sch.mjq, node, 15);
	}


	t2 = clock();
	duration = 0.001 * (t2 - t1) / (double)CLOCKS_PER_SEC;

	cout << "The scheduler has taken " << duration << " seconds to operate on a standard example\n\n";
	return duration;
}