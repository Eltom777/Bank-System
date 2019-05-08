
/*
Account.cpp
Teng Zhao: 40089560
Thomas Flynn: 40034877
*/

#include "Account.h"
#include "Customer.h"

Account::Account() {
	accountNumber = " ";
	balance = 0;
	fee = 0;
	for (auto& i : ownerList) {
		i = nullptr;
	}
}

Account::Account(string a, double b, double c) {
	accountNumber = a;
	balance = b;
	fee = c;
	for (auto& i : ownerList) {
		i = nullptr;
	}
}

void Account::setBalance(double a) {
	balance = a;
}

void Account::setFee(double a) {
	fee = a;
}

string Account::getAccountNumber() {
	return accountNumber;
}

void Account::addOwner(Customer* &a) {

	bool isOwnerThere = false;
	bool success = false;

	for (auto& i : ownerList) { //Check if customer is already in ownerList
		if (i != nullptr) {
			if (a->getCustomerID() == i->getCustomerID()) {
				cout << "Account already has this owner." << endl;
				isOwnerThere = true;
				break;
			}
		}
	}

	if (isOwnerThere == false) {
		for (auto& i : ownerList) {
			if (i == nullptr) {
				if (a->addAccount1(this)) { //add account to the customer's accountList
					i = a;
					success = true;
					break;
				}
			}	
		}
	}

	if (success == true) {
		cout << "Success: Owner added." << endl;
	}
	else if (success == false) {
		cout << "Fail: All customer slot have been set, please remove a customer and try again." << endl;
	}
}

bool Account::addOwner1(Customer* a) { //used only by addAccount member function located in Customer.cpp

	bool isOwnerThere = false;

	for (auto&i : ownerList) { //Check if customer is already in ownerList array
		if (i != nullptr) {
			if (i->getCustomerID() == a->getCustomerID()) {
				isOwnerThere = true;
				return true;
			}
		}
	}

	if (isOwnerThere == false) { //if customer is not in array then adds the customer to it
		for (auto& i : ownerList) {
			if (i == nullptr) {
				i = a;
				return true;
			}
		}
	}

	return false;
}

void Account::removeOwner(string a) {

	bool isOwnerThere = false;
	bool success = false;

	for (auto& i : ownerList) { //Check if owner is in ownerList
		if (i != nullptr) {
			if (i->getCustomerID() == a) {
				isOwnerThere = true;
				break;
			}
		}
	}

	if (isOwnerThere == true) {
		for (auto&i : ownerList) {
			if (i != nullptr) {
				if (i->getCustomerID() == a) {
					if (i->removeAccount(this)) {
						i = nullptr;
						success = true;
					}
					break;
				}
			}
		}
	}

	if (success == true) {
		cout << "Success: Customer/owner removed." << endl;
	}
	else if(success == false) {
		cout << "Customer does not own this account/ the account does not exist." << endl;
	}
}

bool Account::removeOwner(Customer* a) { //used only by removeAccount funciton in Customer.cpp only (was "removeOwner1()")

	for (auto& i : ownerList) { //remove owner from ownerList
		if (i != nullptr) {
			if (i->getCustomerID() == a->getCustomerID()) {
				i = nullptr;
				return true;
			}
		}
	}
	return false;
}

void Account::printOwner() const{
	for (auto& i : ownerList) {
		if (i != nullptr) {
			i->printCustomer();
		}
	}
}

Customer* Account::returnOwnerList(int a) {
	return this->ownerList[a];
}

int Account::sizeOfOwnerList() {
	return ownerList.size();
}