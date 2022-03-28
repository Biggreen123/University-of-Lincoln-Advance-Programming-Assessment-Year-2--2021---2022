#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <chrono>
#include <vector>
#include <ctime>
#include "Savings.h"

Savings::Savings(double b, string a, bool t) 
{
	balance = b;
	Account_type = a;
	isa = t;
}
//does the interest calc
double Savings::computeInterest(int years, double interest)  {
	total = balance * pow((1 + interest / 100), years);
	cout << "Balance: " << balance << " Projected interest: ";
	return total;
}

double  Savings::deposit(double a)  {
	balance = balance + a;
	return balance;
}

double  Savings::withdraw(double b) {
	balance = balance - b;
	if (b > balance)
	{
		cout << "You are out of money" << endl;
		balance = 0;
	}
	return balance;
}
//deposit and withdraws balance while also checking if you are out of money
void Savings::toString() 
{
	cout << Account_type << " | Balance: " << balance << endl;
}
//prints out what account it is and the balance, if I was smarter I would use the bool to change that from savings account to ISA
//accessors:

vector<string> Savings::getHistory()
{
	for (int i = 0; i < history.size(); i++) {
		cout << history[i] << ' ' << endl;;
		return history;
	};
}
bool Savings::getIsa() { return isa; }

//mutators
void Savings::setIsa(bool i)
{
	i = isa;
}

void Savings::setHistory(string h, string j, string k)//sets history
{
	history.push_back(h + j + k);
}
//sets if it is a isa or not 
