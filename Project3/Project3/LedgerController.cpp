/*
 *      File  : LedgerController.cpp
 *      Author: Randy Quimby
 *      Course: COP3014
 *      Proj  : Project 03
 *      Descr : The class that controls the logic (business logic)
 *              of the system.  All functions perform some kind of
 *              action.
 */
#include "pch.h"
#include "LedgerController.h"
#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

LedgerController::LedgerController()
{
	srand(time(NULL));
	initializeArray();
}

LedgerController::~LedgerController()
{
	for (int i = 0; i < ARR_SIZE; i++) {
		delete transactions[i];
		transactions[i] = NULL;
	}	

	delete[] *transactions;
	*transactions = NULL;
}

LedgerController::LedgerController(const LedgerController & controller)
{
	cout << "Copy constructor called." << endl;
	for (int i = 0; i < ARR_SIZE; i++) {
		transactions[i] = new Transaction;
		*transactions[i] = *(controller.transactions[i]);
	}
}

LedgerController & LedgerController::operator=(const LedgerController & controller)
{
	for (int i = 0; i < ARR_SIZE; i++) {
		if (this != &controller) {           // 1. Don't self-assign
			delete transactions[i];          // 2. Delete old transaction
			transactions[i] = new Transaction;               // 3. Allocate new dataObj
			*transactions[i] = *(controller.transactions[i]); // 4. Copy dataObj
		}
	}
	return *this;
}

void LedgerController::voidTransaction(int transactionID) 
{
	bool isVoided = false;
	for (int i = 0; i < ARR_SIZE; i++) {
		if (transactions[i]->getID() == transactionID) {
			delete transactions[i];
			transactions[i] = new Transaction();
			isVoided = true;
		}
	}

	if (isVoided) {
		cout << "The item has been voided." << endl;
	} 
	else {
		cout << "Could not find the entered ID!!  To view a list of IDs, please print a transaction summary." << endl;
	}
}

void LedgerController::createTransaction(int* times, double* itemDetails, std::string name)
{
	Item item(name, *itemDetails, *(itemDetails + 1));
	int pos = -1;
	for (int i = 0; i < ARR_SIZE; i++) {
		//this->transactions[i]->setID(generateID());
		if (this->transactions[i]->getID() == 0) {
			pos = i;
		}
	}

	if (pos == -1) {
		cout << endl;
		cout << "You have reached the maximum transactions for the day.  Please void a transaction to make another." << endl;
		cout << endl;
	}
	else {
		delete transactions[pos];
		this->transactions[pos] = new Transaction(*times, *(times + 1), *(times + 2), item);
		this->transactions[pos]->setID(generateID()); 
	}
}

void LedgerController::printTransactionSummary()
{
	cout << "\nInfo for the transaction data follows: " << endl;
	cout << "***********************************************************************" << endl;
	for (int i = 0; i < ARR_SIZE; i++) {
		if (this->transactions[i]->getID() != 0) {
			cout << "Time: " << this->transactions[i]->getHour() << ":" << this->transactions[i]->getMinute() <<
				":" << this->transactions[i]->getSecond() << "\nID: " << this->transactions[i]->getID() << "\nName: " <<
				this->transactions[i]->getItem().getName() << ", Selling Price: $" << this->transactions[i]->getItem().getSellingPrice() <<
				", Cost Price: $" << this->transactions[i]->getItem().getCostPrice() << ", Profit: $" <<
				this->transactions[i]->getItem().getProfit() << endl;
		}
	}

	cout << "***********************************************************************" << endl;
	calculateAvgProfit();
	cout << "***********************************************************************" << endl;
	// Essentially clears the array 'transactionItemNames[]' to begin fresh again after averaging
	std::fill(std::begin(transactionItemNames), std::end(transactionItemNames), "");
	printTotalProfit();
}

void LedgerController::initializeArray()
{
	for (int i = 0; i < ARR_SIZE; i++) {
		this->transactions[i] = new Transaction;
	}
}

/*
 * Insertion sort to sort by name.
 */
void LedgerController::sortByName()
{
	Transaction* key = NULL;
	int pre;

	for (int i = 0; i < ARR_SIZE; i++) {
		pre = i - 1;
		key = transactions[i];
		while (pre >= 0 && transactions[pre]->getItem().getName() > key->getItem().getName()) {
			transactions[pre + 1] = transactions[pre];
			pre = pre - 1;
		}

		transactions[pre + 1] = key;
	}
}

void LedgerController::sortByID()
{
	Transaction* key = NULL;
	int pre;

	for (int i = 0; i < ARR_SIZE; i++) {
		pre = i - 1;
		key = transactions[i];
		while (pre >= 0 && transactions[pre]->getID() > key->getID()) {
			transactions[pre + 1] = transactions[pre];
			pre = pre - 1;
		}

		transactions[pre + 1] = key;
	}
}

void LedgerController::sortByProfit()
{
	Transaction* key = NULL;
	int pre;

	for (int i = 0; i < ARR_SIZE; i++) {
		pre = i - 1;
		key = transactions[i];
		while (pre >= 0 && transactions[pre]->getItem().getProfit() > key->getItem().getProfit()) {
			transactions[pre + 1] = transactions[pre];
			pre = pre - 1;
		}

		transactions[pre + 1] = key;
	}
}

void LedgerController::calculateAvgProfit() 
{
	cout << "Average profit for each item: " << endl;
	cout << endl;
	for (int i = 0; i < ARR_SIZE; i++) {
		int counter = 0;
		double total = 0;
		double avg = 0;
		string transactionItemName = transactions[i]->getItem().getName();
		// If there is an item more than once in the transactions, total and count the number of occurences
		for (int j = 0; j < ARR_SIZE; j++) {
			if (transactionItemName == transactions[j]->getItem().getName()) {
				++counter;
				total += transactions[j]->getItem().getProfit();
			}
		}

		avg = total / counter;
		transactionItemNames[i] = transactionItemName;
		printAvgProfit(transactionItemName, avg);
	}
}

void LedgerController::printAvgProfit(string transactionItemName, double avg) const
{
	int counter = 0;
	// Counts number of recurences of the same item
	for (int i = 0; i < ARR_SIZE; i++) {
		string tmp = transactionItemNames[i];
		if (transactionItemNames[i] == transactionItemName) {
			++counter;
		}
	}
	// Prints the average of each item only once
	if ((transactionItemName != "") && !(counter > 1)) {
		cout << transactionItemName << ": " << " average profit = $" << avg << endl;
	}	
	
}

void LedgerController::printTotalProfit() const
{
	double totalProfit = 0.0;
	for (int i = 0; i < ARR_SIZE; i++) {
		totalProfit += transactions[i]->getItem().getProfit();
	}
	cout << "Total profit for all transactions: $" << totalProfit << endl;
	cout << "***********************************************************************" << endl;
}

int LedgerController::generateID()
{
	bool isInBucket = true;
	int randomNum = 0;
	while (isInBucket) {
		randomNum = rand() % 900 + 101;
		int i = 0;
		for ( ; i < ARR_SIZE - 1; i++) {
			if (iDBucket[i] == randomNum) {
				isInBucket = true;
				break;
			}
			isInBucket = false;
		}
		if (!isInBucket) {
			iDBucket[i] = randomNum;
			break;
		}
	} 

	return randomNum;
}
