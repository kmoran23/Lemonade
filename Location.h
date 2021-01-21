//CS1300 Spring 2020
//Author: Patricia Chin & Kyra Moran
//Project 3

#include <iostream>
#include <string>
using namespace std;

#ifndef LOCATION_H
#define LOCATION_H
//defining the Location class

//Nte: locations and the average amount that customers will spend will be read from a text file
class Location
{
	public:
		//constructors
		Location();
		Location(string locName_, double avgSpend_);
		
		void setLocName(string locName_);
		void setAvgSpend(double avgSpend_);
		
		string getLocName(); //returns name of neighborhood as a string
		double getAvgSpend(); //returns the average amount that customers will spend per cup
	
	private:
		string locName; //name of neighborhood
		double avgSpend; //average amount that customers will spend per cup
};

#endif