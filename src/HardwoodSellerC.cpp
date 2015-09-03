//============================================================================
// Name        : HardwoodSellerC.cpp
// Author      : Esteban Parra
// Version     : 1
// Copyright   : It's free
// Description : Main class for the Hardwood Seller
//============================================================================

#include <iostream>
#include "WoodItem.h"
#define bufSize 512
using namespace std; 
WoodItem wi;

int main(int argc, char* argv[]) { 
	if (argc != 2)
	{
		cout << "Missing or extra arguments, only specify the name of the file after the executable." << endl;
		return 1;
	}

	wi.WoodItem();
	readInputFile(argv[1]);

	return 0;
}

/*
 * Method to read the input file
 */
void readInputFile(string inputFilePath) {
	char buf[bufSize];
	char *tokT, *tokN;
	fstream fs;
	// open the specified file
	fs.open(inputFilePath, std::fstream::in);
	// read the first line of the file
	fs.getline(buf, bufSize);
	// print out the name, address, and date
	cout << strtok(buf, ";") << endl << strtok(buf, ";") << endl << strtok(buf, " ") << endl;
	// read the 2nd line of the file
	fs.getline(buf, bufSize);
	// read the order
	tokT = strtok(buf, ":");
	while (tokT != NULL)
	{
		tokN = strtok(buf, ";");
		if (strncmp("Cherry", tokT, sizeof("Cherry")))
			wi.cherry = atoi(tokN);
		else if (strncmp("Curly Maple", tokT, sizeof("Curly Maple")))
			wi.cMaple = atoi(tokN);
		else if (strncmp("Genuine Mahogany", tokT, sizeof("Genuine Mahogany")))
			wi.gMaho = atoi(tokN);
		else if (strncmp("Wengey", tokT, sizeof("Wengey")))
			wi.wenge = atoi(tokN);
		else if (strncmp("White Oak", tokT, sizeof("White Oak")))
			wi.wOak = atoi(tokN);
		else if (strncmp("Sawdust", tokT, sizeof("Sawdust")))
			wi.sawdust = atoi(tokN);
		else
			cout << tokT << " is unknown." << endl;
		tokT = strtok(buf, ":");
	}
}

/*
 * Method to compute the deliveryTime
 */
double deliveryTime() {
	double deliveryETA = 0.0;
	double next_t;
	deliveryETA = wi.shippingTime(wi.cherry) * 2.5;
	next_t = wi.shippingTime(wi.cMaple) * 1.5;
	if (deliveryETA < next_t)
		deliveryETA = next_t;
	next_t = wi.shippingTime(wi.gMaho) * 3;
	if (deliveryETA < next_t)
		deliveryETA = next_t;
	next_t = wi.shippingTime(wi.wenge) * 5;
	if (deliveryETA < next_t)
		deliveryETA = next_t;
	next_t = wi.shippingTime(wi.wOak) * 2.3;
	if (deliveryETA < next_t)
		deliveryETA = next_t;
	next_t = wi.shippingTime(wi.sawdust) * 1;
	if (deliveryETA < next_t)
		deliveryETA = next_t;
	return deliveryETA;
}
