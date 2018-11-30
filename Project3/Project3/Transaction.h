/*
 *      File  : Transaction.h
 *      Author: Randy Quimby
 *      Course: COP3014
 *      Proj  : Project 03
 *      Descr : The declaration of the class that contains the
 *              data model of a transaction.
 */
#pragma once
#ifndef TRANSACTION_H_
#define TRANSACTION_H_
#include "Item.h"

class Transaction {
public:
	Transaction();
	Transaction(int hour, int minute, int second, Item item);
	~Transaction();
	void setHour(int hour);
	int getHour() const;
	void setMinute(int minute);
	int getMinute() const;
	void setSecond(int second);
	int getSecond() const;
	void setID(int iD);
	int getID() const;
	void setItem(Item item);
	Item getItem() const;
private:
	int hour;
	int minute;
	int second;
	int iD;
	Item item;	
};
#endif /* TRANSACTION_H_ */
