/*
 * WoodItem.cpp
 *
 *  Created on: Aug 24, 2015
 *      Author: USER
 */

#include "WoodItem.h"
/*
 * Empty constructor
 */
WoodItem::WoodItem() {
	type = "";
	baseDeliveryTime = 0.0;
	price = 0.0;

	cherry = 0;
	cMaple = 0;
	gMaho = 0;
	wenge = 0;
	wOak = 0;
	sawdust = 0;
}

/*
 * Method to initialize a tic tac toe game
 * Initializes board and turn
 */
WoodItem::WoodItem(std::string woodType, double deliveryTime, double itemPrice) {
	type = woodType;
	baseDeliveryTime = deliveryTime;
	price = itemPrice;
}

