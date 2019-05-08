#pragma once

/*
Saving.h
Teng Zhao: 40089560
Thomas Flynn: 40034877
*/

#include "Account.h"

class Saving : public Account {
public:
	Saving();
	Saving(string, double, double, int, double);
	void setMaxTransaction(int);
	void setInterestRate(double);
	void printAccount(); //prints account information

protected:
	int maxTransaction;
	double interestRate;
};