/*
 *      File  : Item.cpp
 *      Author: Randy Quimby
 *      Course: COP3014
 *      Proj  : Project 03
 *      Descr : Data model for items (holds data for items and their profit).
 */
#include "pch.h"
#include "Item.h"
#include<iostream>
#include<string>
using namespace std;

Item::Item()
{
	this->costPrice = 0.0;
	this->sellingPrice = 0.0;
	this->profit = 0.0;
	this->name = "";
}

Item::Item(string name, double sellingPrice, double costPrice)
{
	setName(name);
	setSellingPrice(sellingPrice);
	setCostPrice(costPrice);
	calculateProfit();
}

Item::~Item()
{
}

string Item::getName() const
{
	return name;
}

void Item::setName(string name)
{
	this->name = name;
}

double Item::getSellingPrice() const
{
	return sellingPrice;
}

void Item::setSellingPrice(double sellingPrice)
{
	if(sellingPrice > this->costPrice) {
		this->sellingPrice = sellingPrice;					   
	}
	else {
		cout << "Selling price must be greater than cost price!\nCost price is currently: " << this->costPrice << endl;
		this->sellingPrice = 0.0;
	}
}

double Item::getCostPrice() const
{
	return costPrice;
}

void Item::setCostPrice(double costPrice)
{
	if (costPrice < this->sellingPrice) {
		this->costPrice = costPrice;
	}
	else {
		cout << "Cost price must be greater than zero!" << endl;
		this->costPrice = 0.0;
	}
}

double Item::getProfit() const
{
	return profit;
}

void Item::calculateProfit()
{
	this->profit = sellingPrice - costPrice;
}
