#include "Transaction.h"
//accessors:
void Transaction::setTimeStamp() 
{
	time_t t;
	time(&t);
	timestamp = ctime(&t);
}
void Transaction::setDesc(string d)
{
	desc = d;
}
void Transaction::setValue(string v)
{
	value = v;
}
//mutators:
string Transaction::getTimeStamp() { return timestamp; } //gets current date/time from system clock
string Transaction::getDesc() { return desc; } //gets description from main
string Transaction::getValue() { return value; } //gets value from parameter
