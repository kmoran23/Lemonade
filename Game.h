//CS1300 Spring 2020
//Author: Patricia Chin & Kyra Moran
//Project 3

#include <iostream>
#include <string>
#include "Stand.h"
#include "Location.h"
using namespace std;

#ifndef GAME_H
#define GAME_H

//defining the Game class

class Game
{
	public:
		//STARTING GAME FUNCTIONS
		Game(); //default constructor

		void initNames(); //sets player name and stand name
		void visitStore(); //allows user to visit store and buy supplies through menu options


		//LOCATION FUNCTIONS
		int readLocations(string fileName); //reads locations from text file, populates locations array and run
		void printLocations(); //prints out locations and average spending after locations have been read from text file
		int getNumLocations();
		Location getChosenLocation();
		void setChosenLocation(Location location);

		//WEATHER FUNCTIONS
		string getChosenWeather();
		void setChosenWeather(string weather);


		//DAY NUMBER FUNCTIONS
		int getDayNumber(); //returns what day the user is on
		void setDayNumber(int dayNumber_); //sets what day the user is on


		//START NEW DAY
		void startDay();
		void chooseLocation(); 	
		void chooseWeather();
	

		//END OF DAY
		void chooseMisfortune();	
		bool makePuzzle();
		string checkGameStatus(); //checks win conditions to see if player has won
		void decreaseMainVal();	


		//-----MENU----//

		void gameStore();

		int getStoreVisits();
		void setStoreVisits(int storeVisits_);

		//1. SELL LEMONADE
		void sellLemonade();

		double getSetPrice();
		void setSetPrice(double setPrice_);

		int getPriceVal();
		void setPriceVal(int priceVal_);

		int getWeatherVal();
		void setWeatherVal(int weatherVal_);

		int getSetAds();
		void setSetAds(int setAds_);

		void setCupPrice();
		// 	//user enters price per cup that they want to sell at
		// 	//returns pricePer as a double
			
		void setNumAds();
		// 	//user enters the number of ads they want to use
		// 	//returns numAds as an integer

		void comparePrices();

		void calcProfits();

		//2. CHECK SUPPLIES
		void displayStats(); //displays stats on each turn or when they select menu option to check supplies
		
		//3. TAKE DAY OFF
		void dayOff();

		//4. RAID ANOTHER STAND
		void raidStand();

		//5. QUIT GAME
			
	private:
		int numLocations;
		Location locations[10];
		Location chosenLocation;
		string chosenWeather;
		int priceVal;
		int weatherVal;

		int dayNumber;
		double setPrice;
		int setAds;

		Stand playerStand;
		int storeVisits;
};

#endif