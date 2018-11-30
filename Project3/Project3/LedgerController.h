/*
 *      File  : LedgerController.h
 *      Author: Randy Quimby
 *      Course: COP3014
 *      Proj  : Project 03
 *      Descr : The declaration of the class that controls the
 *              logic (business logic) of the system.
 */
#pragma once
#ifndef LEDGERCONTROLLER_H_
#define LEDGERCONTROLLER_H_
#include "Transaction.h"
#include<string>

class LedgerController {
public:
	static const int ARR_SIZE = 10;
	LedgerController();
	~LedgerController();
	LedgerController(const LedgerController& controller);
	LedgerController& operator=(const LedgerController& controller);
    void voidTransaction(int transactionID);
	void createTransaction(int* times, double* itemDetails, std::string name);
	void printTransactionSummary();
	void sortByName();
	void sortByID();
	void sortByProfit();
private:
	Transaction* transactions[ARR_SIZE];
	std::string transactionItemNames[ARR_SIZE];
	int iDBucket[ARR_SIZE];
	void initializeArray();
	void calculateAvgProfit();
	void printAvgProfit(std::string transactionItemName, double avg) const;
	void printTotalProfit() const;
	int generateID();
};

#endif /* LEDGERCONTROLLER_H_ */