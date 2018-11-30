/*
 *      File  : Item.h
 *      Author: Randy Quimby
 *      Course: COP3014
 *      Proj  : Project 03
 *      Descr : The declaration of the class that contains the
 *              data model of an item.
 */
#pragma once
#ifndef ITEM_H_
#define ITEM_H_
#include<string>

class Item {
public:
	Item();
	Item(std::string name, double sellingPrice, double costPrice);
	~Item();
	std::string getName() const;
	void setName(std::string name);
	double getSellingPrice() const;
	void setSellingPrice(double sellingPrice);
	double getCostPrice() const;
	void setCostPrice(double costPrice);
	double getProfit() const;
private:
	double costPrice;
	double sellingPrice;
	double profit;
	std::string name;
	void calculateProfit();
};
#endif /* ITEM_H_ */
