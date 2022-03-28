#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <chrono>
#include <ctime>
#include <vector>
#include "Account.h"
using namespace std;

void Account::toString()
{
	cout << "Account created: " << balance << endl;
} 
//should never be seen didn't really matter what I put here I guess it was setting a good reminder to future me on what I wanted these functions to be
double Account::computeInterest(int years, double interest) { return total; }

void Account::setHistory(string h, string j, string k) {};

vector<string> Account::getHistory() { return history; };

bool Account::getIsa() { return isa; };
