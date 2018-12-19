#pragma once
#ifndef RESEARCHER_H
#define RESEARCHER_H

#include "IncludeFiles.h"
#include "User.h"


class Researcher : public User {
public:
	Researcher(int newBudget, int newid, double cap = 1600.0);

};

#endif 