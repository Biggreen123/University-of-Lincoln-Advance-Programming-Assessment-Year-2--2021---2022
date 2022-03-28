#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <chrono>
#include <vector>
#include <ctime>
using namespace std;
#ifndef Transaction_H
#define Transaction_H

class Transaction {
public:
	string desc;
	string value;
	string timestamp;
	//Didn't see a point of having the variables anything other than a string it just needs to be out putted to console 
	void setTimeStamp(); //gets date/time from system clock
	string getTimeStamp();

	void setDesc(string d); //get the description on what the transaction is set in main
	string getDesc();
	void setValue(string v); //get the value from parameteres in main same as if I was setting deposit
	string getValue();
};
#endif