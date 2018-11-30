/*
 *      File  : Menu.h
 *      Author: Randy Quimby
 *      Course: COP3014
 *      Proj  : Project 03
 *      Descr : The declaration of the class that contains menues
 *              and input prompts.
 */
#pragma once
#ifndef MENU_H_
#define MENU_H_
#include "LedgerController.h"
#include<string>

class Menu {
public:
	Menu();
	~Menu();
	bool mainMenu();
	void sortTransactionMenu();
private:
	LedgerController controller;
	int* obtainTime() const;
	void obtainHour(int* hour) const;
	void obtainMinute(int* minute) const;
	void obtainSecond(int* second) const;
	double* obtainItemDetails() const;
	std::string obtainItemName() const;
	int obtainID() const;
};

#endif /* MENU_H_ */