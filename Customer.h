
/*
Customer.h
Teng Zhao: 40089560
Thomas Flynn: 40034877
*/

#include <iostream>
#include <string>
#include <array>
#include <typeinfo>
class Account;
using namespace std;

class Customer {
public:
	Customer();
	Customer(string, string, string, string, string, string);
	void setFirstName(string);
	void setLastName(string);
	void setCustomerAddress(string);
	void setCustomerNumber(string);
	void setCustomerEmail(string);
	string getCustomerID() const;
	string getCustomerFirst() const;
	string getCustomerLast() const;
	void addAccount(Account*a);
	bool addAccount1(Account*a); 
	void removeAccount(string);
	bool removeAccount(Account*a);
	void listAccount() const; //list all owned account
	void listChequing() const; //list all owned chequing account
	void listSaving() const; //list all owned saving account
	void printCustomer();

protected:
	string customerID;
	string firstName;
	string lastName;
	string customerAddress;
	string customerNumber;
	string customerEmail;
	array <Account*,4> accountList;
};
