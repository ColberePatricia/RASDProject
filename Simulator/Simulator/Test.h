#pragma once
#ifndef TEST_H
#define TEST_H

#include "IncludeFiles.h"
#include "Input.h"
#include "Output.h"


class Test {
public:
	void testSimulation();

	void testInput();
	void testOutput();
	void testJob();
	void testNode();
	void testScheduler();
	void testUsersGenerator();

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
