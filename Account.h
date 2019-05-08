#pragma once

/*
Account.h
Teng Zhao: 40089560
Thomas Flynn: 40034877
*/

#include <iostream>
#include <string>
#include <array>
class Customer;
using namespace std;

class Account {
public:
	Account();
	Account(string, double, double);
	void setBalance(double);
	void setFee(double);
	string getAccountNumber();
	void addOwner(Customer*&);
	bool addOwner1(Customer*);
	void removeOwner(string);
	bool removeOwner(Customer*);
	void printOwner() const; //prints owner information
	virtual void printAccount() = 0; //prints account information
	Customer* returnOwnerList(int);
	int sizeOfOwnerList();
protected:
	string accountNumber;
	double balance;
	double fee;
	array <Customer*, 4> ownerList;
};
