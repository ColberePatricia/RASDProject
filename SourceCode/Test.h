#pragma once
#ifndef TEST_H
#define TEST_H

#include "IncludeFiles.h"
#include "Input.h"
#include "Output.h"
#include "EvaluatorOfScheduler.h"


class Test {
public:
	// The test of the whole simulation
	void testSimulation();


	// The individual unit tests of each class in the simulation
	
	void testInput();
	void testOutput();
	void testJob();
	void testNode();
	void testScheduler();
	void testUsersGenerator();
	void testEvaluatorOfScheduler();

	void testJobQueue();
	void testHugeJobQueue();
	void testLargeJobQueue();
	void testMediumJobQueue();
	void testShortJobQueue();

	void testUser();
	void testITStaff();
	void testResearcher();
	void testStudent();
};

#endif 
