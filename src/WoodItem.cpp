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

/*
* Find the shipping time based on BF
*/
double WoodItem::shippingTime(int bf) {
	if (bf >= 1 && bf <= 100)
		return 1;
	if (bf >= 101 && bf <= 200)
		return 2;
	if (bf >= 201 && bf <= 300)
		return 3;
	if (bf >= 301 && bf <= 400)
		return 4;
	if (bf >= 401 && bf <= 500)
		return 5;
	if (bf >= 501 && bf <= 1000)
		return 5.5;
	return 0;
}