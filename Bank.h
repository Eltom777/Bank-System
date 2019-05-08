#pragma once

/*
Bank.h
Teng Zhao: 40089560
Thomas Flynn: 40034877
*/

#include <iostream>
#include <string>
#include <array>
#include "Branch.h"
using namespace std;

class Bank {
public:
	Bank();
	Bank(string, string, string, string);
	void setName(string);
	void setBankAddress(string);
	void setBankNumber(string);
	void addBranch(Branch*);
	void removeBranch(string);
	void listAccount(string); //list given branch's accounts
	void listCustomer(string); //list given branch's customers
	void printBranch(string); //print given branch's information
	void printAccount(string); //print given account's information
	void printCustomer(string); //print given customer's information
	void printBank();

protected:
	string bankID;
	string name;
	string bankAddress;
	string bankNumber;
	array <Branch*, 3> branchList;
};
