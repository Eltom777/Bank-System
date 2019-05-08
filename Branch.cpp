
/*
Branch.cpp
Teng Zhao: 40089560
Thomas Flynn: 40034877
*/

#include "Branch.h"

Branch::Branch() {
	branchID = " ";
	branchAddress = " ";
	branchNumber = " ";
	for (auto& i : accountList) {
		i = nullptr;
	}
}

Branch::Branch(string a, string b, string c) {
	branchID = a;
	branchAddress = b;
	branchNumber = c;
	for (auto& i : accountList) {
		i = nullptr;
	}
}

void Branch::setBranchID(string a) {
	branchID = a;
}

void Branch::setBranchAddress(string a) {
	branchAddress = a;
}

void Branch::setBranchNumber(string a) {
	branchNumber = a;
}

void Branch::addAccount(Account* a){

	bool isAccountThere = false;
	bool success = false;

	for (auto& i : accountList) { //Check if account already in accoutList
		if (i != nullptr) {
			if (i->getAccountNumber() == a->getAccountNumber()) {
				cout << "Branch already has this account." << endl;
				isAccountThere = true;
				break;
			}
		}
	}

	if (isAccountThere == false) {
		for (auto&i : accountList) {
			if (i == nullptr) {
					i = a;
					success = true;
					break;
				
			}
		}
	}

	if(success == true) {
		cout << "Success: Account added to Branch." << endl;
	}
	else if(success == false) {
		cout << "Fail: All accounts slot have been set, please remove an account and try again." << endl;
	}
}

void Branch::removeAccount(string a){

	bool isAccountThere = false;
	bool success = false;

	for (auto& i : accountList) { //Check if account is in accountList
		if (i != nullptr) {
			if (i->getAccountNumber() == a) {
				isAccountThere = true;
				break;
			}
		}
	}

	if (isAccountThere == true) {
		for (auto &i : accountList) {
			if (i != nullptr) {
				if (i->getAccountNumber() == a) {
						i = nullptr; //remove account from accountList
						success = true;
					break;
				}
			}
		}
	}

	if (success == true) {
		cout << "Success: Account removed from branch." << endl;
	}
	else if (success == false) {
		cout << "Branch does not have Account/ Account does not exit." << endl;
	}
}

void Branch::listAccount() {
	cout << "--- Account list for Branch: " << this->getBranchID() << " ---" << endl;
	for (auto& i : accountList) {
		if (i != nullptr) {
			cout << " - " << i->getAccountNumber() << endl;
		}
	}
}

void Branch::listCustomer(){ //I am not remove duplicated customers 
	cout << "--- Customer list for Branch: " << this->getBranchID() << " ---" << endl;
	for (auto& i : accountList) {
		if (i != nullptr) {
			for (int k = 0; k < i->sizeOfOwnerList(); k++) {
				if (i->returnOwnerList(k) != nullptr) {
					cout << " - " << i->returnOwnerList(k)->getCustomerFirst() << endl;
				}
			}
		}
	}
	//go through each account and print out its owner's ignore if duplication use function returnOwnerList in Account.cpp
}

bool Branch::searchCustomer(string a){ //this might not work 
	for (auto& i : accountList) {
		if (i != nullptr) {
			for (int k = 0; k < i->sizeOfOwnerList(); k++) {
				if (i->returnOwnerList(k) != nullptr) {
					if (i->returnOwnerList(k)->getCustomerID() == a)
						return true;
				}
			}
		}
	}
	return false;
}

void Branch::printBranch() {
	cout << "----- Branch -----" << endl;
	cout << "ID: " << branchID << endl;
	cout << "Address: " << branchAddress << endl;
	cout << "Phone Number: " << branchNumber << endl;
	cout << "Accounts within branch" << endl;
	}

string Branch::getBranchID() const {
	return branchID;
}

Account* Branch::returnAccountList(int a) {
		return this->accountList[a];
}

int Branch::sizeOfAccountList() {
	return accountList.size();
}