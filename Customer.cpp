
/*
Customer.cpp
Teng Zhao: 40089560
Thomas Flynn: 40034877
*/

#include "Customer.h"
#include "Account.h"

Customer::Customer() {
	customerID = " ";
	firstName = " ";
	lastName = " ";
	customerAddress = " ";
	customerNumber = " ";
	customerEmail = " ";
	for (auto& i: accountList) {
		i = nullptr;
	}
}

Customer::Customer(string a, string b, string c, string d, string e, string f) {
	customerID = a;
	firstName = b;
	lastName = c;
	customerAddress = d;
	customerNumber = e;
	customerEmail = f;
	for (auto& i : accountList) {
		i = nullptr;
	}
}

void Customer::setFirstName(string a) {
	firstName = a;
}

void Customer::setLastName(string a) {
	lastName = a;
}

void Customer::setCustomerAddress(string a) {
	customerAddress = a;
}

void Customer::setCustomerNumber(string a) {
	customerNumber = a;
}

void Customer::setCustomerEmail(string a) {
	customerEmail = a;
}

void Customer::addAccount(Account* a) {

	bool isAccountThere = false;
	bool success = false;

	for (auto& i : accountList) { //Check if account already in accoutList
		if (i != nullptr) {
			if (a->getAccountNumber() == i->getAccountNumber()) {
				cout << "Customer already has this account." << endl;
				isAccountThere = true;
				break;
			}
		}
	}

	if (isAccountThere == false) {
		for (auto&i : accountList) {
			if (i == nullptr) {
				if (a->addOwner1(this)) { //add customer to the account's ownerList
					i = a;
					success = true;
					break;
				}
			}
		}
	}

	if (success == true) {
		cout << "Success: Account added." << endl;
	}
	else if (success == false) {
		cout << "Fail: All accounts slot have been set, please remove an account and try again." << endl;
	}
}

bool Customer::addAccount1(Account* a) { //used only by addOwner member function located in Account.cpp

	bool isAccountThere = false;

	for (auto& i : accountList) { //Check if account is already in accountList array
		if (i != nullptr) {
			if (i->getAccountNumber() == a->getAccountNumber()) {
				isAccountThere = true;
				return true;
			}
		}
	}
	
	if (isAccountThere == false) { //if account is not in array then adds the account to it
		for (auto& i : accountList) {
			if (i == nullptr) {
				i = a;
				return true;
			}
		}
	}

	return false;
}

void Customer::removeAccount(string a) { //done

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
					if (i->removeOwner(this)) { //remover owner from ownerList
						i = nullptr; //remove account from accountList
						success = true;
					}
					break;
				}
			}
		}
	}

	if (success == true) {
		cout << "Success: Account removed." << endl;
	}
	else if (success == false) {
		cout << "Account does not have owner/ owner does not exit." << endl;
	}
}

bool Customer::removeAccount(Account* a) { //used by removeOwner function in Account.cpp only (was "removeAccount1()")

	for (auto&i : accountList) { //remove account from accountList
		if (i != nullptr) {
			if (i->getAccountNumber() == a->getAccountNumber()) {
				i = nullptr;
				return true;
			}
		}
	}
	return false;
}

string Customer::getCustomerID() const{
	return customerID;
}

string Customer::getCustomerFirst() const{
	return firstName;
}

string Customer::getCustomerLast() const{
	return lastName;
}

void Customer::listAccount() const{
	for (auto& i : accountList) {
		if (i != nullptr) {
			cout << i->getAccountNumber() << endl;
		}
	}
}

void Customer::listChequing() const {
	cout << this->getCustomerFirst() << "'s Chequing Account Number(s): " << endl;
	for (auto& i : accountList) {
		if (i != nullptr) {
			if (static_cast<string>(typeid(*i).name()) == "class Chequing") {
				cout << "- " << i->getAccountNumber() << endl;
			}
		}
	}
}

void Customer::listSaving() const {
	cout << this->getCustomerFirst() << "'s Saving Account Number(s): " << endl;
	for (auto& i : accountList) {
		if (i != nullptr){

			if (static_cast<string>(typeid(*i).name()) == "class Saving") { 
				cout << "- " << i->getAccountNumber() << endl;
			}
		}
	}
}

void Customer::printCustomer() {
	cout << "----- Customer -----" << endl;
	cout << "ID: " << customerID << endl;
	cout << "First Name: " << firstName << endl;
	cout << "Last Name: " << lastName << endl;
	cout << "Address: " << customerAddress << endl;
	cout << "Phone Number: " << customerNumber << endl;
	cout << "Email: " << customerEmail << endl;
}
