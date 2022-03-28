#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <chrono>
#include <vector>
#include <ctime>
using namespace std;
#ifndef Account_H
#define Account_H
class Account {
protected:
	// variables stored
	double balance;
	vector <string> history;
	double total;
	bool isa;
public:
	virtual double deposit(double a) = 0;
	virtual double withdraw(double b) = 0;
	virtual void toString();
	//virtual functions ^^ to be used by derived class to deposit, withdraw and print out balance/overdraft
	virtual void setHistory(string h, string j, string k);
	virtual vector<string> getHistory(); //stores all the transaction infomation
	virtual bool getIsa(); //had no idea how to not do this :/ makes it so each savings account can be checked if its an isa or not so that the interest rate is correct
	virtual double computeInterest(int years, double interest); //same as above, when useing Account* vector I cannot derive from InterestEarning class, maybe could've pushed out the savings account and did something there but that also means I would have to check that the indez was pointing at a savings class and idk how to
};
#endif