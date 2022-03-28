#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <chrono>
#include <vector>
#include <ctime>
#include "Account.h"
using namespace std;
#ifndef Current_H
#define Current_H

class  Current : public Account {
private:
	int overdraft = 500;
	//stored variables encapsulated
public:
	Current(double b);
	double deposit(double a) override;
	double  withdraw(double b) override;
	void toString() override;
	// overridden base class functions, polymorphisem
	void setHistory(string h, string j, string k); //takes in the three different transaction functions and stores them into one index of a vector
	vector<string> getHistory(); //prints out history vector

};
#endif