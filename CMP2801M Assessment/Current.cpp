#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <chrono>
#include <vector>
#include <ctime>
#include "Current.h"



double Current::deposit(double a)
{
	balance = balance + a;
	return balance;
}
Current::Current(double b)
{
	balance = b;
}

double  Current::withdraw(double b)
{
	//takes away whatever the user puts in from the balance
	balance = balance - b;
	if (b > balance)
	{
		//the jankiest way to have an overdraft if the actual balance is lower then what the user wants to take out 
		//it will then subtract from the overdraft
		double temp = balance;
		balance = 0;
		temp = temp - b;
		temp = fabs(temp);
		overdraft = overdraft - temp;
		cout << "You went into your overdraft: " << overdraft << endl;
	}
	if (overdraft <= 0)
	{ //if they have no overdraft then what ever happens they will have the balance and overdraft set to 0
		cout << "you are out of money" << endl;
		balance = 0;
		overdraft = 0;
	}

	return balance, overdraft;
}

void Current::toString()
{
	cout << "Current account | Balance: " << balance << " | Overdraft: " << overdraft << endl; // shows balance and overdraft
}

void Current::setHistory(string h, string j, string k)
{
	history.push_back(h + j + k); //gets all elements of transactions and puts them in one index
}

vector<string> Current::getHistory()
{
	for (int i = 0; i < history.size(); i++) { //should print the whole history
		cout << history[i] << ' ' << endl;
		return history;
	};
}

