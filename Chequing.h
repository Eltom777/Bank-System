#pragma once

/*
Chequing.h
Teng Zhao: 40089560
Thomas Flynn: 40034877
*/

#include "Account.h"
class Customer;

class Chequing : public Account {
public:
	Chequing();
	Chequing(string, double, double, bool, double);
	void setCheque(bool);
	void setOverdraft(double);
	void printAccount(); //prints account information

protected:
	bool cheque;
	double overdraft;
};
