/*
Bank.cpp
Teng Zhao: 40089560
Thomas Flynn: 40034877

Note that as a challenge, we allowed an account to hold more than one customer. 
*/

#include "Bank.h"
#include "Saving.h"
#include "Chequing.h"
#include <iostream>

using namespace std;


int main() {

	Saving* a1 = new Saving("1", 200, 5, 3, 5);
	Chequing* a2 = new Chequing("2", 250, 5, 3, 5);
	Customer* c1 = new Customer("1","John","doe","111111 ", "111-111-1111","john.doe@gmail.com");
	Customer* c2 = new Customer("2", "Jane", "doe", "222222", "222-222-2222", "jane.doe@gmail.com");
	Branch* b1 = new Branch("1234", "1234 rue st-Catherine, Montreal", "514-000-0000");
	Bank* ba1 = new Bank("999", "Devils accountant", "666 Burning Boulevard, Hell", "999-999-9999");

	

	a1->addOwner(c1); //jane holds a saving account
	c2->addAccount(a1);//john holds  the same saving account. 
	
	a2->addOwner(c2); //jane holds chequing 
	b1->addAccount(a1);
	b1->addAccount(a2);

	
	ba1->addBranch(b1);

	ba1->printBank();
	ba1->printBranch("1234");
	ba1->listAccount("1234");
	ba1->listCustomer("1234");

	cout << "is Customer id '1' (John) present in Branch '1234' ? " << endl;
	if (b1->searchCustomer("1")) {
		cout << "Yes !" << endl;
	}
	else {
		cout << "no" << endl;
	}

	cout << endl << "Removing Branch '1234' from bank" << endl;

	ba1->removeBranch("1234");
	ba1->printBranch("1234");

	cout << endl << "Removing accounts from Branch" << endl;

	b1->removeAccount("1");
	b1->removeAccount("2");
	

	cout << endl << "Jane is testing the parameters of her account" << endl;

	c2->printCustomer();
	c2->listAccount();
	c2->listChequing();
	c2->listSaving();
	cout << endl << "Jane got divorced with John and lost her saving account" << endl;
	c2->removeAccount("1");
	
	cout << endl << "The chequing account is removing Jane from its owner list" << endl;

	a2->removeOwner("2");

	cout << endl;

	c2->listAccount(); // nothing should appear since there are no accounts in Jane's account list

	cout << endl << "John want see whom he is sharing his account with" << endl;

	a1->printAccount();
	a1->printOwner();

	
	delete a1, a2, c1, c2, b1, ba1;
	system("pause");
	return 0;
}