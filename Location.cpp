//CS1300 Spring 2020
//Author: Patricia Chin & Kyra Moran
//Project 3

#include <iostream>
#include <string>
#include "Location.h"
using namespace std;

Location::Location()
{
	locName="";
	avgSpend=0;
}

Location::Location(string locName_, double avgSpend_)
{
	locName=locName_;
	avgSpend=avgSpend_;
}

string Location::getLocName()
{
	return locName;
}

double Location::getAvgSpend()
{
	return avgSpend;
}
	
void Location::setLocName(string locName_)
{
	locName = locName_;
}
	
void Location::setAvgSpend(double avgSpend_)
{
	avgSpend = avgSpend_;
}
	

