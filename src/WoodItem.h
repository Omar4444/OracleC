/*
 * WoodItem.h
 *
 *  Created on: Aug 24, 2015
 *      Author: Esteban
 */


#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>

#ifndef WOODITEM_H_
#define WOODITEM_H_

class WoodItem {

public:

	std::string type;
	double baseDeliveryTime;
	double price;

	int cherry;
	int cMaple;
	int gMaho;
	int wenge;
	int wOak;
	int sawdust;

	// Member functions declaration
	WoodItem();
	WoodItem(std::string woodType, double deliveryTime, double itemPrice);
	double shippingTime(int bf);

};

#endif /* WOODITEM_H_ */
