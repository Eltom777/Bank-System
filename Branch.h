#pragma once

/*
Branch.h
Teng Zhao: 40089560
Thomas Flynn: 40034877
*/

#include <iostream>
#include <string>
#include <array>
#include "Customer.h"
#include "Account.h"
using namespace std;

class Branch {
public:
	Branch();
	Branch(string, string, string);
	void setBranchID(string);
	void setBranchAddress(string);
	void setBranchNumber(string);
	void addAccount(Account* ); //-add account
	void removeAccount(string); //-remove array using ID
	void listAccount(); //print account info - print array
	void listCustomer(); //list customers of branch account->customerfirst
	bool searchCustomer(string); //is a customer of this branch account->searchcustomerfirst
	void printBranch();
	string getBranchID() const;
	Account* returnAccountList(int);
	int sizeOfAccountList();

protected:
	string branchID;
	string branchAddress;
	string branchNumber;
	array<Account*,4> accountList;
};
