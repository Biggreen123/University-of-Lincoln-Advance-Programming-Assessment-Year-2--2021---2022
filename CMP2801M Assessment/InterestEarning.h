#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <chrono>
#include <vector>
#include <ctime>
using namespace std;
#ifndef InterestEarnings_H
#define InterestEarnings_H
class InterestEarning {
public:

	virtual double computeInterest(int years, double interest) = 0;
};
//beacuse of my implmenttaion this is useless, sorry
#endif