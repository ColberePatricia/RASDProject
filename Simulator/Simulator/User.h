#ifndef USER_H
#define USER_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include <fstream>
using namespace std;


class User {
public:
	User(double userBudget, int userId);
	double getBudget();
	int getId();
	void setBudget(double newBudget);

private:
	double budget;
	int id;
};

#endif 
