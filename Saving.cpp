
/*
Saving.cpp
Teng Zhao: 40089560
Thomas Flynn: 40034877
*/

#include "Saving.h"
#include "Customer.h"

Saving::Saving():Account() {
	maxTransaction = 0;
	interestRate = 0;
}

Saving::Saving(string a, double b, double c, int d, double e) : Account(a, b, c) {
	maxTransaction = d;
	interestRate = e;
}

void Saving::setMaxTransaction(int a) {
	maxTransaction = a;
}

void Saving::setInterestRate(double a) {
	interestRate = a;
}

void Saving::printAccount() {
	cout << "----- Saving Account -----" << endl;
	cout << "ID: " << accountNumber << endl;
	cout << "Balance: " << balance << endl;
	cout << "Transaction Fee: " << fee << endl;
	cout << "Owner(s): " << endl;
	for (auto& i : ownerList) {
		if (i != nullptr) {
			cout << "- " << i->getCustomerFirst() << " ";
			cout << i->getCustomerLast() << endl;
		}
	}
	cout << "Max Transactions: " << maxTransaction << endl;
	cout << "Interest Rate: " << interestRate << endl;
}