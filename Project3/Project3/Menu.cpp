/*
 *      File  : Menu.cpp
 *      Author: Randy Quimby
 *      Course: COP3014
 *      Proj  : Project 03
 *      Descr : Class contains menues and input prompts for
 *              users.  Passes user choices to a menu controller.
 */
#include "pch.h"
#include "Menu.h"
#include "LedgerController.h"
#include<string>
#include<iostream>

using namespace std;

Menu::Menu()
{
	
}

Menu::~Menu()
{
	
}

bool Menu::mainMenu()
{
	int choice = 0;
	bool choosing = true;
	bool exit = false;
	while (choosing) {
		cout << endl;
		cout << "1. Create new Transaction\n2. Void Transaction\n3. Print Transaction Summary\n4. Exit program" << endl;
		cout << "Please choose an option: ";
		cin >> choice;
		switch (choice) {
		case 1:
			controller.createTransaction(obtainTime(), obtainItemDetails(), obtainItemName());
		    choosing = false;
			break;
		case 2:
			controller.voidTransaction(obtainID());
			choosing = false;
			break;
		case 3:
			sortTransactionMenu();
			controller.printTransactionSummary();
			choosing = false;
			break;
		case 4:
			choosing = false;
			exit = true;
			break;
		default:
			cout << endl;
			cout << "That is not an option.  Please try again." << endl;
			break;
		}
	}

	return !exit;
}

void Menu::sortTransactionMenu()
{
	int choice = 0;
	bool flag = false;
	while (!flag) {
		cout << endl;
		cout << "1. Sort by item name\n2. Sort by transaction ID\n3. Sort by ascending profit\nPlease choose a sort order: ";
		cin >> choice;
		switch (choice) {
		case 1:
			controller.sortByName();
			flag = true;
			break;
		case 2:
			controller.sortByID();
			flag = true;
			break;
		case 3:
			controller.sortByProfit();
			flag = true;
			break;
		default:
			cout << endl;
			cout << "That is not an option!!  Try again.." << endl;
			break;
		}
	}
}

int* Menu::obtainTime() const
{
	static int times[3];
	obtainHour(&times[0]);
	obtainMinute(&times[1]);
	obtainSecond(&times[2]);
	return times;
}

void Menu::obtainHour(int* hour) const
{
	cout << "Please enter the hour of this transaction: ";
	cin >> *hour;
}

void Menu::obtainMinute(int* minute) const
{
	cout << "Please enter the minute of this transaction: ";
	cin >> *minute;
}

void Menu::obtainSecond(int* second) const
{
	cout << "Please enter the second of this transaction: ";
	cin >> *second;
}

double* Menu::obtainItemDetails() const
{
	static double itemDetails[2];
	cout << "Please enter the cost price of the item: ";
	cin >> itemDetails[1];
	cout << "Please enter the selling price of the item: ";
	cin >> itemDetails[0];
	return itemDetails;
}

string Menu::obtainItemName() const
{
	string name = "";
	cout << endl;
	cout << "Please enter the name of this item: ";
	cin >> name;
	return name;
}

int Menu::obtainID() const
{
	int iD = 0;
	cout << endl;
	cout << "Please enter the ID of the product you wish to void (to view item IDs, print the summary): ";
	cin >> iD;
	cout << endl;
	return iD;
}
