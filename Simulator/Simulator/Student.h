#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include "IncludeFiles.h"
#include "User.h"


class Student : public User {
public:
	Student(int newBudget, int newid, double cap = 100.0);
};

#endif 