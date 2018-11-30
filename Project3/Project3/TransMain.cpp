/*
 *      File  : TransMain.cpp
 *      Author: Randy Quimby
 *      Course: COP3014
 *      Proj  : Project 03
 *      Descr : This file contains the 'main' function. Program execution begins and
 *              ends there.
 */
#include "pch.h"
#include "Menu.h"
#include "LedgerController.h"
#include<iostream>

using namespace std;

int main()
{		
	Menu menu;
	while (menu.mainMenu()) {}
}