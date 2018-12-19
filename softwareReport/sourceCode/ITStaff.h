#pragma once
#ifndef ITSTAFF_H
#define ITSTAFF_H

#include "IncludeFiles.h"
#include "User.h"


class ITStaff : public User {
public:
	ITStaff(int newBudget, int newid, double cap = 1680.0);
};

#endif 