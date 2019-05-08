//
///*
//testAccount.cpp
//Teng Zhao: 40089560
//Thomas Flynn: 40034877
//*/
//
//#include "Chequing.h"
//#include "Saving.h"
//#include "Customer.h"
//
//int main() {
//
//	//Account* a;
//	Saving* a1 = new Saving("1",200,5,3,5);
//	Chequing* a2 = new Chequing("2", 250, 5, 3, 5);
//	Customer* c1 = new Customer("1","John","doe","111111 ", "111-111-1111","john.doe@gmail.com");
//	Customer* c2 = new Customer("2", "Jane", "doe", "222222", "222-222-2222", "jane.doe@gmail.com");
//
//	//a1->printAccount();
//	//a2->printAccount();
//
//	//c1->printCustomer();
//	//c2->printCustomer();
//
//
//	a1->addOwner(c1); //jane holds a chequing account
//	a1->printOwner();
//	//a2->printAccount();
//
//	//c1->addAccount(a1);//john holds saving account
//	c1->listSaving();
//	c1->removeAccount("1");
//	a1->printOwner();
//	//a1->printAccount();
//
//	//c2->addAccount(a1);//both john and jane share the saving account
//	//a1->printAccount();
//
//	//cout << "John doe got divorced!!!" << endl;
//
//	//a1->removeOwner("1");
//	//a1->printAccount();
//
//	//cout << "Jane 'not doe' fled the country!!!" << endl;
//
//	//c2->setLastName("not doe");
//
//	//c2->removeAccount("1");
//	//a1->printAccount();
//	
//	//cout << "John doe got played by a gold digger !!!! " << endl;
//
//	//cout << "John can track Jane with her Chequing account!!!! " << endl;
//
//	//c2->listChequing();
//
//	delete c1, c2, a1, a2;
//
//	system("pause");
//	return 0;
//}