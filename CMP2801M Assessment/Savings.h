#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <chrono>
#include <vector>
#include <ctime>
#include "Account.h"
#include "InterestEarning.h"
using namespace std;
#ifndef Savings_H
#define Savings_H
class Savings : public Account, public InterestEarning {

private:
	//variables
	bool isa;
	double total;
	string Account_type;

public:
	Savings(double b, string a, bool t);
	double computeInterest(int years, double interest) override; // I did try to use the interface class but no dice
	double  deposit(double a) override;
	double  withdraw(double b) override;
	//overridden functions
	void toString() override;
	void setHistory(string h, string j, string k);
	vector<string> getHistory(); // same as current stores the transactions as one index
	void setIsa(bool i); //getters and setter to see if the savings account is the one ISA 
	bool getIsa();
};
#endif