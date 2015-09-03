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

void readInputFile(string inputFilePath);
void printOrder();

int main(int argc, char* argv[]) { 
	if (argc != 2)
	{
		cout << "Missing or extra arguments, only specify the name of the file after the executable." << endl;
		return 1;
	}

	WoodItem();
	readInputFile(argv[1]);
	printOrder();

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
	tokT = strtok(buf, ";");
	cout << tokT << endl;
	tokT = strtok(NULL, ";");
	cout << tokT << endl;
	tokT = strtok(NULL, ";");
	cout << tokT << endl;

	// read the 2nd line of the file
	fs.getline(buf, bufSize);
	// read the order
	tokT = strtok(buf, ":");
	while (tokT != NULL)
	{
		tokN = strtok(NULL, ";");
		if (strncmp("Cherry", tokT, sizeof("Cherry")) == 0)
			wi.cherry = atoi(tokN);
		else if (strncmp("Curly Maple", tokT, sizeof("Curly Maple")) == 0)
			wi.cMaple = atoi(tokN);
		else if (strncmp("Genuine Mahogany", tokT, sizeof("Genuine Mahogany")) == 0)
			wi.gMaho = atoi(tokN);
		else if (strncmp("Wenge", tokT, sizeof("Wenge")) == 0)
			wi.wenge = atoi(tokN);
		else if (strncmp("White Oak", tokT, sizeof("White Oak")) == 0)
			wi.wOak = atoi(tokN);
		else if (strncmp("Sawdust", tokT, sizeof("Sawdust")) == 0)
			wi.sawdust = atoi(tokN);
		else
			cout << tokT << " is unknown." << endl;
		tokT = strtok(NULL, ":");
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

/*
* Print the list
*/
void printOrder(){
	cout << "\n Ordered wood\t\t BF purchased\t  price \n\n";
	if (wi.cherry != 0)
		cout << "  Cherry\t\t   " << wi.cherry << "\t\t   $" << wi.cherry * 5.95 << endl;
	if (wi.cMaple != 0)
		cout << "  Curly Maple\t\t   " << wi.cMaple << "\t\t   $" << wi.cMaple * 6 << endl;
	if (wi.gMaho != 0)
		cout << "  Genuine Mahogany\t   " << wi.gMaho << "\t\t   $" << wi.gMaho * 9.6 << endl;
	if (wi.wenge != 0)
		cout << "  Wenge\t\t\t   " << wi.wenge << "\t\t   $" << wi.wenge * 22.35 << endl;
	if (wi.wOak != 0)
		cout << "  White Oak\t\t   " << wi.wOak << "\t\t   $" << wi.wOak * 6.7 << endl;
	if (wi.sawdust != 0)
		cout << "  Sawdust\t\t   " << wi.sawdust << "\t\t   $" << wi.sawdust * 1.5 << endl;

	cout << "The estimated delivery time is: " << deliveryTime() << endl;
	cout << "The total price is: $" << wi.cherry * 5.95 + wi.cMaple * 6 + wi.gMaho * 9.6 + wi.wenge * 22.35 + wi.wOak * 6.7 + wi.sawdust * 1.5 << endl;
}