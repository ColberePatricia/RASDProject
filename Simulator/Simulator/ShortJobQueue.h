#ifndef SHORTJOBQUEUE_H
#define SHORTJOBQUEUE_H

#include "JobQueue.h"


class ShortJobQueue: public JobQueue {
public:
	ShortJobQueue();

	int maxNbOfNodes;
};

#endif 
