/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for "LincBank" Assessment Item 1
Semester A 2021

Written by James Brown (jamesbrown@lincoln.ac.uk)

During marking, we will use the exact same notation
as provided in the brief, so make sure you follow that guideline.

You should avoid removing parts of this driver program, but
add to it the necessary code to produce your implementation.

Good luck!
------------------------------------------------------ */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <chrono>
#include <vector>
#include <ctime>
#include "Account.h"
#include "InterestEarning.h"
#include "Current.h"
#include "Savings.h"
#include "Transaction.h"
using namespace std;

int main()
{
	std::vector <std::string> parameters;
	std::string userCommand;
	vector <Account* > Accounts;
	int cCounter = 0;
	int iCounter = 0;
	// you may also want to store a collection of opened accounts here

	std::cout << "~~~ Welcome to LincBank! ~~~" << std::endl;
	cout << "open type initial_deposit: open a current (1), savings (2) or ISA (3) account\nview [index]: view balance and recent transactions\nwithdraw sum: withdraw funds from most recently viewed account\ndeposit sum: deposit funds into most recently viewed account\ntransfer src dest sum: transfer funds between accounts\nproject years: project balance forward in time\nexit: close this application\noptions: view these options again" << endl;

	while (userCommand != "exit")
	{
		parameters.clear(); // clear ready for next command
		std::cout << std::endl << ">>> ";

		std::getline(std::cin, userCommand);
		char* cstr = new char[userCommand.length() + 1];
		strcpy(cstr, userCommand.c_str());

		char* token;
		token = strtok(cstr, " ");

		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok(NULL, " ");
		}
		if (parameters.size() == 0)
			continue;

		// Define all commands as per the brief
		std::string command = parameters[0];

		if (command.compare("options") == 0)
		{
			cout << "open type initial_deposit: open a current (1), savings (2) or ISA (3) account\nview [index]: view balance and recent transactions\nwithdraw sum: withdraw funds from most recently viewed account\ndeposit sum: deposit funds into most recently viewed account\ntransfer src dest sum: transfer funds between accounts\nproject years: project balance forward in time\nexit: close this application\noptions: view these options again" << endl;

			// display the various commands to the user
		}
		else if (command.compare("open") == 0)
		{
			// allow a user to open an account
			// e.g., Account* a = new Savings(...);
			if (parameters[1].compare("1") == 0)
			{
				if (cCounter == 0) 
				{
					Current* C = new Current((stod(parameters[2])));
					Transaction c;
					cout << "Current account created!" << endl;
					C->toString();
					c.setTimeStamp();
					c.setDesc("Initial deposit : ");
					c.setValue("\x9C " + parameters[2] + " on ");
					C->setHistory(c.getDesc(),c.getValue(),c.getTimeStamp());
					C->getHistory();
					Accounts.push_back(C);
					cCounter++;
				}
				else if (cCounter >= 1) 
				{
					cout << "You can only create one current account" << endl; // yes this seems very hacky but is means only one current account is ever created so....
				}

			}
			else if (parameters[1].compare("2") == 0) 
			{
				
				Savings* S = new Savings((stod(parameters[2])),"Savings Account",false);// = new Savings;
				Transaction s;
				cout << "Savings account created!" << endl;
				s.setTimeStamp();
				s.setDesc("Initial deposit : ");
				s.setValue("\x9C " + parameters[2] + " on ");
				S->toString();
				S->setHistory( s.getDesc(), s.getValue(),s.getTimeStamp());
				S->getHistory();
				Accounts.push_back(S);
				
			}
			else if (parameters[1].compare("3") == 0) 
			{
				Savings* I = new Savings((stod(parameters[2])),"ISA Account",true);
				Transaction i;
				if (stoi(parameters[2]) >= 1000) 
				{
					if (iCounter == 0) 
					{
						cout << "Isa account created!" << endl;
						//Savings* x = dynamic_cast<Savings*>(Accounts.back());
						i.setTimeStamp();
						i.setValue("\x9C " + parameters[2] + " on ");
						i.setDesc("Initial deposit : ");
						I->toString();
						I->setHistory( i.getDesc(), i.getValue(),i.getTimeStamp());
						I->getHistory();
						Accounts.push_back(I);
						iCounter++;
					}
					else if (iCounter >= 1) 
					{
						cout << "You can only create one ISA" << endl;
					}
				}					
				}
				else { cout << "ISA initial balance must be >= £1000" << endl; }
			}
		
		else if (command.compare("view") == 0)
		{
			if (parameters.size() < 1) 
			{
				Accounts[stoi(parameters[1]) - 1]->toString();
				Accounts[stoi(parameters[1]) - 1]->getHistory();
				swap(Accounts[stoi(parameters[1]) - 1],Accounts.back());
			}
			else 
			{
				for (int i = 0; i < Accounts.size(); i++) {
					Accounts[i]->toString();
					Accounts[i]->getHistory();
				}
					
			
			}

			// display an account according to an index (starting from 1)
			// alternatively, display all accounts if no index is provided
		}
		else if (command.compare("withdraw") == 0)
		{
			if (!Accounts.empty())
			{
				Transaction W;
				Accounts.back()->withdraw(stoi(parameters[1]));
				Accounts.back()->toString();
				W.setTimeStamp();
				W.setDesc("Withdraw : ");
				W.setValue("\x9C " + parameters[1] + " on ");
				Accounts.back()->setHistory(W.getTimeStamp(), W.getDesc(), W.getValue());
			}
			else
			{
				cout << "You haven't created any accounts" << endl;
			}
			 //allow user to withdraw funds from an account
		}
		else if (command.compare("deposit") == 0)
		{
			 //allow user to deposit funds into an account
			if (!Accounts.empty())
			{
				Transaction D;
				Accounts.back()->deposit(stod(parameters[1]));
				Accounts.back()->toString();
				Accounts.back()->getHistory();
				D.setTimeStamp();
				D.setDesc("deposit : ");
				D.setValue("\x9C " + parameters[1] + " on ");
				Accounts.back()->setHistory(D.getTimeStamp(), D.getDesc(), D.getValue());
			}
			else
			{
				cout << "You haven't created any accounts" << endl;
			}
		}
		else if (command.compare("transfer") == 0)
		{
		Transaction B;
		Transaction L;
			int x = (stoi(parameters[1])) - 1; // have to do this because vectors start at 0, has to be a better way?
			int y = (stoi(parameters[2])) - 1;
			//withdraw
			Accounts[x]->withdraw(stod(parameters[3])); //this is all very ugly please look away
			L.setTimeStamp();
			L.setDesc("Transfered from account : ");
			L.setValue("\x9C " + parameters[3] + " on ");
			Accounts[x]->setHistory(L.getTimeStamp(), L.getDesc(), L.getValue());
			//deposit
			Accounts[y]->deposit(stod(parameters[3]));
			B.setTimeStamp();
			B.setDesc("Transfered to account : ");
			B.setValue("\x9C " + parameters[3] + " on ");
			Accounts[y]->setHistory(B.getTimeStamp(), B.getDesc(), B.getValue());
			// allow user to transfer funds between accounts
			// i.e., a withdrawal followed by a deposit!
			cout << "Transfer successful" << endl;
			Accounts[x]->toString();
			Accounts[x]->getHistory();
			Accounts[y]->toString();
			Accounts[y]->getHistory();
		}
		else if (command.compare("project") == 0)
		{
			// compute compound interest t years into the future
			if (Accounts.back()->getIsa() == true) 
			{
				cout << Accounts.back()->computeInterest(stoi(parameters[1]), 1.15) << endl;
			}
			else if (Accounts.back()->getIsa() == false)
			{
				cout << Accounts.back()->computeInterest(stoi(parameters[1]), 0.85) << endl;
				
			}
	
		}
		//else if (command.compare("search"))
		//{
		//	allow users to search their account history for a transaction
		//  (this is a stretch task)
		//}

	}
	for (vector<Account*>::iterator it = Accounts.begin(); it != Accounts.end(); it++) { //will delete all cpnstructors in the vector
		delete* it;
	}
	std::cout << "Press any key to quit...";
	std::getchar();
}