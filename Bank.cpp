/*
Bank.cpp
Teng Zhao: 40089560
Thomas Flynn: 40034877
*/

#include "Bank.h"

Bank::Bank() {
	bankID = " ";
	name = " ";
	bankAddress = " ";
	bankNumber = " ";
	for (auto& i : branchList) {
		i = nullptr;
	}
}

Bank::Bank(string a, string b, string c, string d) {
	bankID = a;
	name = b;
	bankAddress = c;
	bankNumber = d;
	for (auto& i : branchList) {
		i = nullptr;
	}
}

void Bank::setName(string a) {
	name = a;
}

void Bank::setBankAddress(string a) {
	bankAddress = a;
}

void Bank::setBankNumber(string a) {
	bankNumber = a;
}

void Bank::addBranch (Branch* a){//add a branch to bank
	//add branch pointer to branchList
	bool isBranchThere = false;
	bool success = false;

	for (auto&i : branchList) {//Check if branch already in branchList
		if (i != nullptr) {
			if (i->getBranchID()==a->getBranchID()) {
				cout << "Bank already has this branch." << endl;
				isBranchThere = true;
				break;
			}
		}
	}

	if (isBranchThere == false) {
		for (auto&i : branchList) {
			if (i == nullptr) {
				i = a;
				success = true;
				break;
			}
		}
	}

	if (success == true) {
		cout << "Success: Branch added." << endl;
	}
	else if (success == false) {
		cout << "Fail: All Branch slot have been set, please remove a branch and try again." << endl;
	}
}

void Bank::removeBranch(string a){//remove a branch from bank
	//filter using branchID and remove it from branchList
	bool isBranchThere = false;
	bool success = false;

	for (auto& i : branchList) { //Check if branch is in accountList
		if (i != nullptr) {
			if (i->getBranchID() == a) {
				isBranchThere = true;
				break;
			}
		}
	}

	if (isBranchThere == true) {
		for (auto &i : branchList) {
			if (i != nullptr) {
				if (i->getBranchID() == a) {
					for (int j = 0; j < i->sizeOfAccountList(); j++) {
						if (i->returnAccountList(j) != nullptr) {
							i->removeAccount(i->returnAccountList(j)->getAccountNumber());
						}
					}
					i = nullptr; //remove branch from branch List
					success = true;
					break;
				}
			}
		}
	}

	if (success == true) {
		cout << "Success: Branch removed." << endl;
	}
	else if (success == false) {
		cout << "Bank does not have Branch/ Branch does not exit." << endl;
	}
}

void Bank::listAccount(string a){//list all the accounts held by a branch
	//branch->printAccountList function
	bool isBranchThere = false;
	for (auto&i : branchList) {
		if (i != nullptr) {
			if (i->getBranchID() == a) {
				i->listAccount();
				isBranchThere = true;
				break;
			}
		}
	}

	if (isBranchThere == false) {
		cout << "branchID not found." << endl;
	}
}

void Bank::listCustomer(string a){//list all Customers of a branch
	//branch->listCustomer function
	bool isBranchThere = false;
	
	for (auto&i : branchList) {
		if (i != nullptr) {
			if (i->getBranchID() == a) {
				i->listCustomer(); //the problem is within listCustomer()
				isBranchThere = true;
				break;
			}
		}
	}

	if (isBranchThere == false) {
		cout << "branchID not found." << endl;
	}
}

void Bank::printBranch(string a){ //Input a brachID and pribnt out it's information
	//branch->printBranch function
	bool isBranchThere = false;

	for (auto&i : branchList) {
		if (i != nullptr) {
			if (i->getBranchID() == a) {
				i->printBranch();
				isBranchThere = true;
				break;
			}
		}
	}

	if (isBranchThere == false) {
		cout << "branchID not found." << endl;
	}
}

void Bank::printAccount(string a){
	//filter through each branch
	//in each branch filter through account list for the account number
	//branch->accountList->printAccount
	bool isAccountThere = false;


	for (auto&i : branchList) {
		if (i != nullptr) {
			for (int j = 0; j < i->sizeOfAccountList(); j++) {
				if (i->returnAccountList(j) != nullptr) {
					if (i->returnAccountList(j)->getAccountNumber() == a) {
						i->returnAccountList(j)->printAccount();
						isAccountThere = true;
						
			
					}
				}
			}
			if(isAccountThere){
				break;
			}
		}
	}

	if (isAccountThere == false) {
		cout << "Account not found." << endl;
	}
}

void Bank::printCustomer(string a){
	//filter through each branch
	//in each branch filter through account list for the ownerList
	//ownerList->getCustomerID
	bool isCustomerThere = false;

	for (auto&i : branchList) {
		if (i != nullptr) {
			for (int j = 0; j < i->sizeOfAccountList(); j++) {
				if (i->returnAccountList(j) != nullptr) {
					for (int k = 0; k < i->returnAccountList(j)->sizeOfOwnerList(); k++) {
						if (i->returnAccountList(j)->returnOwnerList(k) != nullptr) {
							if (i->returnAccountList(j)->returnOwnerList(k)->getCustomerFirst() == a) {
								i->returnAccountList(j)->returnOwnerList(k)->printCustomer();
								isCustomerThere = true;
								break;
							}
						}
					}
					if (isCustomerThere) { 
						break; 
					}
				}
			}
			if (isCustomerThere) { 
				break; 
			}
		}
	}

	if (isCustomerThere == false) {
		cout << "Customer not found." << endl;
	}
}

void Bank::printBank() {
	cout << "----- Bank -----" << endl;
	cout << "ID: " << bankID << endl;
	cout << "Name: " << name << endl;
	cout << "Address: " << bankAddress << endl;
	cout << "Phone Number: " << bankNumber << endl;
	cout << "Branches within the Bank" << endl;
	for (auto&i : branchList) {
		if (i != nullptr) {
			cout << "- " << i->getBranchID() << endl;
		}
	}
	
}