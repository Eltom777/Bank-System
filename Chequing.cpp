
/*
Chequing.cpp
Teng Zhao: 40089560
Thomas Flynn: 40034877
*/

#include "Chequing.h"
#include "Customer.h"

Chequing::Chequing() :Account() {
	cheque = false;
	overdraft = 0;
}

Chequing::Chequing(string a, double b, double c, bool d, double e) : Account(a, b, c) {
	cheque = d;
	overdraft = e;
}

void Chequing::setCheque(bool a) {
	cheque = a;
}

void Chequing::setOverdraft(double a) {
	overdraft = a;

}

void Chequing::printAccount() {
	cout << "----- Chequing Account -----" << endl;
	cout << "ID: " << accountNumber << endl;
	cout << "Balance: " << balance << endl;
	cout << "Transaction Fee: " << fee << endl;
	cout << "Owner(s): " << endl;
	for(auto& i : ownerList) {
		if (i != nullptr) {
			cout << "- " << i->getCustomerFirst() << " ";
			cout << i->getCustomerLast() << endl;
		}
	}
	cout << "Cheque Privilege: ";
	if (cheque == true)
		cout << "Yes" << endl;
	else if (cheque == false)
		cout << "No" << endl;
	cout << "Overdraft Amount: " << overdraft << endl;
}