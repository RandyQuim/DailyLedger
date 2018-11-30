/*
 *      File  : Transaction.cpp
 *      Author: Randy Quimby
 *      Course: COP3014
 *      Proj  : Project 03
 *      Descr : Data model for individualized transaction objects.
 */
#include "pch.h"
#include "Transaction.h"
#include<iostream>

Transaction::Transaction()
{
	this->hour = 0;
	this->minute = 0;
	this->second = 0;
	this->iD = 0;
}

Transaction::Transaction(int hour, int minute, int second, Item item)
{
	setHour(hour);
	setMinute(minute);
	setSecond(second);
	setItem(item);
}

Transaction::~Transaction()
{
	
}

void Transaction::setHour(int hour)
{
	this->hour = hour;
}

int Transaction::getHour() const
{
	return hour;
}

void Transaction::setMinute(int minute)
{
	this->minute = minute;
}

int Transaction::getMinute() const
{
	return minute;
}

void Transaction::setSecond(int second)
{
	this->second = second;
}

int Transaction::getSecond() const
{
	return second;
}

void Transaction::setID(int iD)
{
	this->iD = iD;
}

int Transaction::getID() const
{
	return iD;
}

void Transaction::setItem(Item item)
{
	this->item = item;
}

Item Transaction::getItem() const
{
	return item;
}


