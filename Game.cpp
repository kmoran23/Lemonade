//CS1300 Spring 2020
//Author: Patricia Chin & Kyra Moran
//Project 3

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include "Stand.h"
#include "Location.h"
#include "Game.h"
using namespace std;

Game::Game()
{
	Stand playerStand;
	numLocations=0;
	dayNumber=1;
	storeVisits=0;
}

void Game::initNames()
{
	string playerName_;
	cout << "Please enter your username:" << endl; 
	getline(cin, playerName_);
	playerStand.setPlayerName(playerName_);
	cout << endl;

	string standName_;
	cout << "Please enter the name of your stand:" << endl;
	getline (cin, standName_);
	playerStand.setStandName(standName_);
}

void Game::visitStore() //store that player visits at the beginning of the game; type in negative number to change
{
	bool inStore = true;
    int option; //Define option integer to be processed
    
	while (inStore)
    {
		cout << endl;
		cout << "===========Store Menu==========" << endl;
		cout << "Welcome to the store! Buy the supplies for your lemonade stand here." << endl;
		cout << "Select a numerical option:" << endl;
    	cout << "1. Buy Lemons" << endl;
    	cout << "2. Buy Sugar" << endl;
    	cout << "3. Buy Ads" << endl;
		cout << "4. Buy Baskets" << endl;
    	cout << "5. Buy Coolers" << endl;
    	cout << "6. Buy Umbrellas" << endl;
    	cout << "7. Quit: Return to Game" << endl;
		cin >> option; //Get lines from the file as a string
		cout << "===============================" << endl;
		cout << endl;

		if (option < 1 || option > 7)
		{
			cout << "Invalid option." << endl;
			continue;
		}

		switch(option)
		{
			case 1:
			{
				double lemonPrice;
				int numLemons_; 

				cout << "One lemon costs $0.10. It is recommended that you buy at least 500 lemons." << endl;
				cout << "Enter the number of lemons you want to buy:" << endl;
				cin >> numLemons_;
				lemonPrice = (numLemons_ * 0.10) * 1.0; //calculating price of lemons

				while(numLemons_ < 0 || lemonPrice > playerStand.getSpendAssets()) //enter negative number or cannot affor amount entered
				{
					if(numLemons_ < 0)
						cout << "Invalid amount. Please enter a positive value:" << endl;
					if(lemonPrice > playerStand.getSpendAssets())
						cout << "Insufficient funds. Please enter a smaller quantity:" << endl;

					cin >> numLemons_;
					lemonPrice = (numLemons_ * 0.10) * 1.0; //calculating price of lemons
				}
				
				if(numLemons_ > 0 && lemonPrice < playerStand.getSpendAssets())
				{
					playerStand.setSpendAssets(playerStand.getSpendAssets() - lemonPrice); //updates bank account 
					playerStand.setNumLemons(playerStand.getNumLemons() + numLemons_); //updates numLemons
				}
					 
				displayStats();
				break;
			} 

			case 2:
			{
				double sugarPrice; 
				int numSugar_; 
				cout << "One sugar cube costs $0.05. It is recommended that you buy at least 1000 sugar cubes." << endl;
				cout << "Enter the number of sugar cubes you want to buy:" << endl;
				cin >> numSugar_; //Store the input into basket
				sugarPrice = (numSugar_ * 0.05) * 1.0; //calculating price of sugar

				while(numSugar_ < 0 || sugarPrice > playerStand.getSpendAssets()) //enter negative number or cannot affor amount entered
				{
					if(numSugar_ < 0)
						cout << "Invalid amount. Please enter a positive value:" << endl;
					if(sugarPrice > playerStand.getSpendAssets())
						cout << "Insufficient funds. Please enter a smaller quantity:" << endl;

					cin >> numSugar_;
					sugarPrice = (numSugar_ * 0.05) * 1.0; //calculating price of sugar
				}
				
				if(numSugar_ > 0 && sugarPrice < playerStand.getSpendAssets())
				{
					playerStand.setSpendAssets(playerStand.getSpendAssets() - sugarPrice); //updates bank account 
					playerStand.setNumSugar(playerStand.getNumSugar() + numSugar_); //updates numSugar
				}
				
				displayStats();
				break;
			}

			case 3:
			{
				double adPrice;
				int numAdvert_; 

				cout << "One ad costs $0.75. It is recommended that you buy at least 20 ads." << endl;
				cout << "Enter the number of ads you want to buy:" << endl;
				cin >> numAdvert_; //Store the input into basket
				adPrice = (numAdvert_ * 0.75) * 1.0; //calculating price of ads

				while(numAdvert_ < 0 || adPrice > playerStand.getSpendAssets()) //enter negative number or cannot affor amount entered
				{
					if(numAdvert_ < 0)
						cout << "Invalid amount. Please enter a positive value:" << endl;
					if(adPrice > playerStand.getSpendAssets())
						cout << "Insufficient funds. Please enter a smaller quantity:" << endl;

					cin >> numAdvert_;
					adPrice = (numAdvert_ * 0.75) * 1.0; //calculating price of ads
				}
				
				if(numAdvert_ > 0 && adPrice < playerStand.getSpendAssets())
				{
					playerStand.setSpendAssets(playerStand.getSpendAssets() - adPrice); //updates bank account 
					playerStand.setNumAdvert(playerStand.getNumAdvert() + numAdvert_); //updates numAdvert
				}
					
				displayStats();
				break;
			}

			case 4:
			{
				double basketPrice;
				int numBaskets_; 
				
				cout << "One basket costs $4.00. It is recommended that you buy at least 2 baskets." << endl;
				cout << "Enter the number of baskets you want to buy:" << endl;
				cin >> numBaskets_; //Store the input into basket
				basketPrice = (numBaskets_ * 4.0) * 1.0; //calculating price of baskets

				while(numBaskets_ < 0 || basketPrice > playerStand.getSpendAssets()) //enter negative number or cannot affor amount entered
				{
					if(numBaskets_ < 0)
						cout << "Invalid amount. Please enter a positive value:" << endl;
					if(basketPrice > playerStand.getSpendAssets())
						cout << "Insufficient funds. Please enter a smaller quantity:" << endl;

					cin >> numBaskets_;
					basketPrice = (numBaskets_ * 4.0) * 1.0; //calculating price of basket
				}
				
				if(numBaskets_ > 0 && basketPrice < playerStand.getSpendAssets())
				{
					playerStand.setSpendAssets(playerStand.getSpendAssets() - basketPrice); //updates bank account 
					playerStand.setNumBaskets(playerStand.getNumBaskets()+numBaskets_); //updates numBaskets
				}
					
				displayStats();
				break;
			}

			case 5:
			{
				double coolerPrice;
				int numCoolers_; 

				cout << "One cooler costs $2.00. It is recommended that you buy at least 4 coolers." << endl;
				cout << "Enter the number of coolers you want to buy:" << endl;
				cin >> numCoolers_;
				coolerPrice = (numCoolers_ * 2.0) * 1.0; //calculating price of coolers
							
				while(numCoolers_ < 0 || coolerPrice > playerStand.getSpendAssets()) //enter negative number or cannot affor amount entered
				{
					if(numCoolers_ < 0)
						cout << "Invalid amount. Please enter a positive value:" << endl;
					if(coolerPrice > playerStand.getSpendAssets())
						cout << "Insufficient funds. Please enter a smaller quantity:" << endl;

					cin >> numCoolers_;
					coolerPrice = (numCoolers_ * 2.0) * 1.0; //calculating price of coolers
				}
				
				if(numCoolers_ > 0 && coolerPrice < playerStand.getSpendAssets())
				{
					playerStand.setSpendAssets(playerStand.getSpendAssets() - coolerPrice); //updates bank account 
					playerStand.setNumCoolers(playerStand.getNumCoolers() + numCoolers_); //updates numCoolers
				}

				displayStats();
				break;
			}

			case 6:
			{
				double umbrellaPrice;
				int numUmbrellas_; 

				cout << "One umbrella costs $2.00. It is recommended that you buy at least 4 umbrellas." << endl;
				cout << "Enter the number of umbrellas want to buy:" << endl;
				cin >> numUmbrellas_;
				umbrellaPrice = (numUmbrellas_ * 2.0) * 1.0; //calculating price of umbrellas

				while(numUmbrellas_ < 0 || umbrellaPrice > playerStand.getSpendAssets()) //enter negative number or cannot affor amount entered
				{
					if(numUmbrellas_ < 0)
						cout << "Invalid amount. Please enter a positive value:" << endl;
					if(umbrellaPrice > playerStand.getSpendAssets())
						cout << "Insufficient funds. Please enter a smaller quantity:" << endl;

					cin >> numUmbrellas_;
					umbrellaPrice = (numUmbrellas_ * 2.0) * 1.0; //calculating price of umbrellas
				}
				
				if(numUmbrellas_ > 0 && umbrellaPrice < playerStand.getSpendAssets())
				{
					playerStand.setSpendAssets(playerStand.getSpendAssets() - umbrellaPrice); //updates bank account 
					playerStand.setNumUmbrellas(playerStand.getNumUmbrellas()+numUmbrellas_); //updates numUmbrellas
				}
				
				displayStats();
				break;
			}

			case 7:
			{
				cout << "Thanks for visiting the store!" << endl;
				cout << endl;
				inStore = false;
				break;
			}
		}
    }
}

int Game::getStoreVisits()
{
	return storeVisits;
}

void Game::setStoreVisits(int storeVisits_)
{
	storeVisits = storeVisits_;
}

void Game::gameStore() //store that player can visit during the game; prices are higher each time a user visits the store
{
	bool inStore = true;
    int option; //Define option integer to be processed
    
	while (inStore)
    {
		cout << endl;
		cout << "======Store Menu=====" << endl;
		cout << "Welcome to the store! Buy the supplies for your lemonade stand here." << endl;
		cout <<  "Select a numerical option:" << endl;
    	cout << "1. Buy Lemons" << endl;
    	cout << "2. Buy Sugar" << endl;
    	cout << "3. Buy Ads" << endl;
		cout << "4. Buy Baskets" << endl;
    	cout << "5. Buy Coolers" << endl;
    	cout << "6. Buy Umbrellas" << endl;
    	cout << "7. Quit: Return to Game" << endl;
		cin >> option; //Get lines from the file as a string
		cout << "======================" << endl;
		cout << endl;

		if (option < 1 || option > 7)
		{
			cout << "Invalid option." << endl;
			continue;
		}

		switch(option) 
		{
			case 1:
			{
				double lemonPrice;
				int numLemons_; 

				cout << fixed << "One lemon costs $" << setprecision(2) << (0.10 * (1 + (.1 * storeVisits))) << endl;
				cout << "Enter the number of lemons you want to buy:" << endl;
				cin >> numLemons_; 
				lemonPrice = (numLemons_ * (.10 * (1 + (.1 * storeVisits)))) * 1.0; //calculating price of lemons
				
				while(numLemons_ < 0 || lemonPrice > playerStand.getSpendAssets()) //enter negative number or cannot affor amount entered
				{
					if(numLemons_ < 0)
						cout << "Invalid amount. Please enter a positive value:" << endl;
					if(lemonPrice > playerStand.getSpendAssets())
						cout << "Insufficient funds. Please enter a smaller quantity:" << endl;

					cin >> numLemons_;
					lemonPrice = (numLemons_ * (.10 * (1 + (.1 * storeVisits)))) * 1.0; //calculating price of lemons
				}
				
				if(numLemons_ > 0 && lemonPrice < playerStand.getSpendAssets())
				{
					playerStand.setSpendAssets(playerStand.getSpendAssets() - lemonPrice); //updates bank account 
					playerStand.setNumLemons(playerStand.getNumLemons() + numLemons_); //updates numLemons
				}
				
				displayStats();
				break;
			} 

			case 2:
			{
				double sugarPrice; 
				int numSugar_;

				cout << fixed << "One sugar cube costs $" << setprecision(2) << (0.05 * (1 + (.1 * storeVisits))) << endl; 
				cout << "Enter the number of sugar cubes you want to buy:" << endl;
				cin >> numSugar_; //Store the input into basket		
				sugarPrice = (numSugar_ * .05 * (1 + (.1 * storeVisits))) * 1.0; //calculating price of sugar
				
				while(numSugar_ < 0 || sugarPrice > playerStand.getSpendAssets()) //enter negative number or cannot affor amount entered
				{
					if(numSugar_ < 0)
						cout << "Invalid amount. Please enter a positive value:" << endl;
					if(sugarPrice > playerStand.getSpendAssets())
						cout << "Insufficient funds. Please enter a smaller quantity:" << endl;

					cin >> numSugar_;
					sugarPrice = (numSugar_ * .05 * (1 + (.1 * storeVisits))) * 1.0; //calculating price of sugar
				}
				
				if(numSugar_ > 0 && sugarPrice < playerStand.getSpendAssets())
				{
					playerStand.setSpendAssets(playerStand.getSpendAssets() - sugarPrice); //updates bank account 
					playerStand.setNumSugar(playerStand.getNumSugar() + numSugar_); //updates numSugar
				}
			
				displayStats();
				break;
			}

			case 3:
			{
				double adPrice;
				int numAdvert_; 

				cout << fixed << "One ad costs $" << setprecision(2) << (0.50 * (1 + (.1 * storeVisits))) << endl; 
				cout << "Enter the number of ads you want to buy:" << endl;
				cin >> numAdvert_; //Store the input into basket
				adPrice = (numAdvert_ * (.75 * (1 + (.1 * storeVisits)))) * 1.0; //calculating price of ads
					
				while(numAdvert_ < 0 || adPrice > playerStand.getSpendAssets()) //enter negative number or cannot affor amount entered
				{
					if(numAdvert_ < 0)
						cout << "Invalid amount. Please enter a positive value:" << endl;
					if(adPrice > playerStand.getSpendAssets())
						cout << "Insufficient funds. Please enter a smaller quantity:" << endl;

					cin >> numAdvert_;
					adPrice = (numAdvert_ * (.75 * (1 + (.1 * storeVisits)))) * 1.0; //calculating price of ads
				}
				
				if(numAdvert_ > 0 && adPrice < playerStand.getSpendAssets())
				{
					playerStand.setSpendAssets(playerStand.getSpendAssets() - adPrice); //updates bank account 
					playerStand.setNumAdvert(playerStand.getNumAdvert() + numAdvert_); //updates numAdvert
				}
					
				displayStats();
				break;
			}

			case 4:
			{
				double basketPrice;
				int numBaskets_; 

				cout << fixed << "One basket costs $" << setprecision(2) << (1.00 * (1 + (.1 * storeVisits))) << endl;
				cout << "Enter the number of baskets you want to buy:" << endl;
				cin >> numBaskets_; //Store the input into basket
				basketPrice = (numBaskets_ * (4.00 * (1 + (.1 * storeVisits)))) * 1.0; //calculating price of coolers
					
				while(numBaskets_ < 0 || basketPrice > playerStand.getSpendAssets()) //enter negative number or cannot affor amount entered
				{
					if(numBaskets_ < 0)
						cout << "Invalid amount. Please enter a positive value:" << endl;
					if(basketPrice > playerStand.getSpendAssets())
						cout << "Insufficient funds. Please enter a smaller quantity:" << endl;

					cin >> numBaskets_;
					basketPrice = (numBaskets_ * (4.00 * (1 + (.1 * storeVisits)))) * 1.0; //calculating price of coolers
				}
				
				if(numBaskets_ > 0 && basketPrice < playerStand.getSpendAssets())
				{
					playerStand.setSpendAssets(playerStand.getSpendAssets() - basketPrice); //updates bank account 
					playerStand.setNumBaskets(playerStand.getNumBaskets()+numBaskets_); //updates numBaskets
				}
					
				displayStats();
				break;
			}

			case 5:
			{
				double coolerPrice;
				int numCoolers_; 

				cout << fixed << "One cooler costs $" << setprecision(2) << (1.00 * (1 + (.1 * storeVisits))) << endl;
				cout << "Enter the number of coolers you want to buy:" << endl;
				cin >> numCoolers_; //Store the input into basket
				coolerPrice = (numCoolers_ * (2.00 * (1 + (.1 * storeVisits)))) * 1.0; //calculating price of coolers
			
				while(numCoolers_ < 0 || coolerPrice > playerStand.getSpendAssets()) //enter negative number or cannot affor amount entered
				{
					if(numCoolers_ < 0)
						cout << "Invalid amount. Please enter a positive value:" << endl;
					if(coolerPrice > playerStand.getSpendAssets())
						cout << "Insufficient funds. Please enter a smaller quantity:" << endl;

					cin >> numCoolers_;
					coolerPrice = (numCoolers_ * (2.00 * (1 + (.1 * storeVisits)))) * 1.0; //calculating price of coolers
				}
				
				if(numCoolers_ > 0 && coolerPrice < playerStand.getSpendAssets())
				{
					playerStand.setSpendAssets(playerStand.getSpendAssets() - coolerPrice); //updates bank account 
					playerStand.setNumCoolers(playerStand.getNumCoolers() + numCoolers_); //updates numCoolers
				}
				
				displayStats();
				break;
			}

			case 6:
			{
				double umbrellaPrice;
				int numUmbrellas_; 

				cout << fixed << "One umbrella costs $" << setprecision(2) << (1.00 * (1 + (.1 * storeVisits))) << endl;
				cout << "Enter the number of umbrellas want to buy:" << endl;
				cin >> numUmbrellas_; //Store the input into basket
				umbrellaPrice = (numUmbrellas_ * (2.00 * (1 + (.1 * storeVisits)))) * 1.0; //calculating price of umbrellas
					
				while(numUmbrellas_ < 0 || umbrellaPrice > playerStand.getSpendAssets()) //enter negative number or cannot affor amount entered
				{
					if(numUmbrellas_ < 0)
						cout << "Invalid amount. Please enter a positive value:" << endl;
					if(umbrellaPrice > playerStand.getSpendAssets())
						cout << "Insufficient funds. Please enter a smaller quantity:" << endl;

					cin >> numUmbrellas_;
					umbrellaPrice = (numUmbrellas_ * (2.00 * (1 + (.1 * storeVisits)))) * 1.0; //calculating price of umbrellas
				}
				
				if(numUmbrellas_ > 0 && umbrellaPrice < playerStand.getSpendAssets())
				{
					playerStand.setSpendAssets(playerStand.getSpendAssets() - umbrellaPrice); //updates bank account 
					playerStand.setNumUmbrellas(playerStand.getNumUmbrellas()+numUmbrellas_); //updates numUmbrellas
				}
				
				displayStats();
				break;
			}

			case 7:
			{
				cout << "Thanks for visiting the store!" << endl;
				cout << endl;
				inStore = false;
				break;
			}
		}
    }
}

int Game::getDayNumber()
{
	return dayNumber;
}

void Game::setDayNumber(int dayNumber_)
{
	dayNumber = dayNumber_;
}

int Game::getNumLocations()
{
	return numLocations;
}

Location Game::getChosenLocation()
{
	return chosenLocation;
}

void Game::setChosenLocation(Location location)
{
	chosenLocation = location;
}

int Game::readLocations(string fileName)
{
    ifstream inFile;
	inFile.open(fileName);
	
	if (inFile.fail()) //if file canNt be opened, return -1
		return -1;

	string locName_;
		
	while(numLocations < 10 && getline(inFile, locName_))
	{

		if(locName_.length()==0) //if line is empty go back to beginning of while loop
		{
			continue;
		}

		string stringSpend;
		getline(inFile, stringSpend);
		double avgSpend_ = stod(stringSpend);

		locations[numLocations] = Location(locName_, avgSpend_);
	    numLocations++;
	}
	
	inFile.close();
	
	return numLocations;
}

void Game::chooseLocation() //generate a random number between 0 and numLocations
{
	int locationNum; 
	locationNum = (rand() % numLocations);
	setChosenLocation(locations[locationNum]);
}

string Game::getChosenWeather()
{
	return chosenWeather;
}

void Game::setChosenWeather(string weather)
{
	chosenWeather = weather;
}

void Game::chooseWeather() //based on probability
{
	int weatherNum = (rand()%10+1);
	// cout << "Weather Number: " << weatherNum << endl;
		
	if (weatherNum == 1 || weatherNum == 2) //rainy
	{
		setChosenWeather("rainy");
		cout << "It is rainy today. You must use an umbrella or your maintenance status will go down." << endl;
		cout << endl;

		while(playerStand.getNumUmbrellas() != 0) 
		{
			string umbAnswer;
			cout << "Would you like to use an umbrella? (Y/N)" << endl;
			cin >> umbAnswer;
			
			if(umbAnswer != "Y" && umbAnswer != "N")
			{
				cout << "Invalid option. Please answer Y or N." << endl; 
				continue;
			}
			
			if(umbAnswer == "Y") //one umbrella is taken from supply
			{ 
				playerStand.setNumUmbrellas(playerStand.getNumUmbrellas()-1); 
				cout << endl;
				cout << "You are now using an umbrella." << endl;
				cout << "Umbrellas Remaining: " << playerStand.getNumUmbrellas() << endl;
				cout << endl;
				break;
			}
			
			if(umbAnswer == "N") //if no umbrella is used, lemonade cant be sold for the day, maintenance is lowered by 2 
			{ 
				playerStand.setMainVal(playerStand.getMainVal()-2);
				playerStand.setMainStatus();
				cout << "Your maintenance status went down." << endl;
				cout << "Maintenance Value: " << playerStand.getMainVal() << endl;
				cout << "Maintenance Status: " << playerStand.getMainStatus() << endl;
				break;
			}
		}

		if(playerStand.getNumUmbrellas() == 0) //if the user does not have an umbrella, lemonade cant be sold for the day, maintenance is lowered by 2 
		{ 
			playerStand.setMainVal(playerStand.getMainVal()-2);
			playerStand.setMainStatus();
			cout << "You do not have an umbrella. Your maintenance status went down." << endl;
			cout << "Maintenance Value: " << playerStand.getMainVal() << endl;
			cout << "Maintenance Status: " << playerStand.getMainStatus() << endl;
		}

		setWeatherVal(-20);
	}

	else if (weatherNum == 3 || weatherNum == 4 || weatherNum == 5) //cloudy
	{
		setChosenWeather("cloudy");
		setWeatherVal(-10); 
	}

	else if (weatherNum == 6 || weatherNum == 7 || weatherNum == 8) //partly sunny
	{
		setChosenWeather("partly sunny");
		setWeatherVal(30);
	}
	
	else if (weatherNum == 9 || weatherNum == 10) //hot and sunny
	{
		setChosenWeather("hot and sunny");
		cout << "It is hot and sunny today. You must use a cooler or your maintenance status will go down." << endl;

		while(playerStand.getNumCoolers() != 0) 
		{
			string coolAnswer;
			cout << "Would you like to use a cooler? (Y/N)" << endl;
			cin >> coolAnswer;
			
			if(coolAnswer != "Y" && coolAnswer != "N")
			{
				cout << "Invalid option. Please answer Y or N." << endl; 
				continue;
			}
			
			if(coolAnswer == "Y") //one cooler is take from supply
			{ 
				playerStand.setNumCoolers(playerStand.getNumCoolers()-1); 
				cout << "You are now using a cooler." << endl;
				cout << "Coolers Remaining: " << playerStand.getNumCoolers() << endl;
				break;
			}
			
			if(coolAnswer == "N") //if N cooler is used, lemonade cant be sold for the day, maintenance is lowered by 2 
			{ 
				playerStand.setMainVal(playerStand.getMainVal()-2);
				playerStand.setMainStatus();
				cout << "Your maintenance status went down." << endl;
				cout << "Maintenance Value: " << playerStand.getMainVal() << endl;
				cout << "Maintenance Status: " << playerStand.getMainStatus() << endl;
				break;
			}
		}

		if(playerStand.getNumCoolers() == 0) //if N cooler is used, lemonade cant be sold for the day, maintenance is lowered by 2 
		{ 
			playerStand.setMainVal(playerStand.getMainVal()-2);
			playerStand.setMainStatus();
			cout << "You do not have any cooler. Your maintenance status went down." << endl;
			cout << "Maintenance Value: " << playerStand.getMainVal() << endl;
			cout << "Maintenance Status: " << playerStand.getMainStatus() << endl;
		}
		setWeatherVal(40);
	}
}

void Game::chooseMisfortune() 
{
	int misfortuneChance = (rand()%10+1); //rand number from 1-10 
	
	if (misfortuneChance > 0 && misfortuneChance < 5) //40% chance of misfortune happening so 1,2,3, or 4
	{
		int misfortuneNum = (rand()%4+1);// new rand from 1-4 that goes into switch statement 
	
		switch(misfortuneNum)
		{
			case 1: //lemons rot 
			{
				int lemonsLost; 
				if (playerStand.getNumLemons() < 50) //don't have 50 lemons to lose
				{
					lemonsLost = playerStand.getNumLemons();
					playerStand.setNumLemons(0);
				}
				else
				{
					lemonsLost = 50;
					playerStand.setNumLemons(playerStand.getNumLemons()-50);
				}
				cout << endl;
				cout << "Unfortunately, some of your lemons have rotted. You have lost " << lemonsLost << " lemons." << endl;
				cout << "Remaining Lemons: " << playerStand.getNumLemons() << endl;
				cout << endl;
				break;
			}
					
			case 2: //ads vandalized 
			{
				int adsLost;
				if(playerStand.getNumAdvert() < 4) //don't have 4 advertisements to lose
				{
					adsLost = playerStand.getNumAdvert();
					playerStand.setNumAdvert(0);
				}
				else
				{
					adsLost = 4;
					playerStand.setNumAdvert(playerStand.getNumAdvert()-4);
				}
				cout << endl;
				cout << "Unfortunately, some of your ads have been vandalized. You have lost " << adsLost << " ads." << endl;
				cout << "Remaining Ads: " << playerStand.getNumAdvert() << endl;
				cout << endl;
				break;
			}

			case 3: //equipment is broken 
			{
				int basketsLost;
				int coolersLost;
				int umbrellasLost;

				if(playerStand.getNumBaskets() > 0) //don't have enough equipment to lose
				{
					basketsLost = 1;
					playerStand.setNumBaskets(playerStand.getNumBaskets()-1);
				}
				else
					basketsLost = 0;

				if (playerStand.getNumCoolers() > 0)
				{
					coolersLost = 1;
					playerStand.setNumCoolers(playerStand.getNumCoolers()-1);
				}
				else
					coolersLost = 0;
				
				if(playerStand.getNumUmbrellas() > 0)
				{
					umbrellasLost = 1;
					playerStand.setNumUmbrellas(playerStand.getNumUmbrellas()-1);
				}
				else
					umbrellasLost = 0;
				
				cout << endl;
				cout << "Unfortunately, some of your equipment has broken. You have lost " << basketsLost << " basket, " << coolersLost << " cooler, and " << umbrellasLost << " umbrella." << endl;
				cout << "Remaining Baskets: " << playerStand.getNumBaskets() << endl;
				cout << "Remaining Coolers: " << playerStand.getNumCoolers() << endl;
				cout << "Remaining Umbrellas: " << playerStand.getNumUmbrellas() << endl;
				cout << endl;
				break;
			}

			case 4: //stand is raided  
			{
				string strategy;
				bool valid = false; //assuming non valid user input
				cout << "Your lemonade stand is being raided. You must choose whether you want to run and lose supplies, surrender and lose assets, or fight back to avoid losing anything. If your stand gets raided, your maintenance value will go down." << endl;
				
				while(!valid) //while valid is true 
				{
					cout << "Type R to Run, S to Surrender, or F to Fight Back" << endl;
					cin >> strategy;

					if(strategy != "R" && strategy != "S" && strategy != "F")
					{
						cout << "Invalid option. Please type R, S, or F to select your strategy." << endl;
						continue;
					}
					
					if(strategy=="R")//if run, supplies will be lost 
					{
						int lemonsLost;
						int sugarLost;
						int basketsLost;
						int coolersLost;
						int umbrellasLost;

						if(playerStand.getNumLemons() < 50)
						{
							lemonsLost = playerStand.getNumLemons();
							playerStand.setNumLemons(0);
						}
						else
						{
							lemonsLost = 50;
							playerStand.setNumLemons(playerStand.getNumLemons()-50);
						}
						
						if(playerStand.getNumSugar() < 100)
						{
							sugarLost = playerStand.getNumSugar();
							playerStand.setNumSugar(0);
						}
						else
						{
							sugarLost = 100;
							playerStand.setNumSugar(playerStand.getNumSugar()-100);
						}
						
						if(playerStand.getNumBaskets() > 0)
						{
							basketsLost = 1;
							playerStand.setNumBaskets(playerStand.getNumBaskets()-1);
						}
						else
							basketsLost = 0;
						
						if(playerStand.getNumCoolers() > 0)
						{
							coolersLost = 1;
							playerStand.setNumCoolers(playerStand.getNumCoolers()-1);
						}
						else
							coolersLost = 0;

						if(playerStand.getNumUmbrellas() < 1)
						{
							umbrellasLost = 1;
							playerStand.setNumUmbrellas(playerStand.getNumUmbrellas()-1);
						}
						else
							umbrellasLost = 0;

						playerStand.setMainVal(playerStand.getMainVal()-1);
						playerStand.setMainStatus();

						cout << endl;
						cout << "You have chosen to run and some of your supplies have been stolen. Your maintenance value has also gone down." << endl;
						cout << "You have lost " << lemonsLost << " lemons, " << sugarLost << " sugar cubes, " << basketsLost << " basket, " << coolersLost << " cooler, and " << umbrellasLost << " umbrella." << endl;
						cout << "Maintenance Value: " << playerStand.getMainVal() << endl;
						cout << "Maintenance Status: " << playerStand.getMainStatus() << endl;
						cout << "Remaining Lemons: " << playerStand.getNumLemons() << endl;
						cout << "Remaining Sugar: " << playerStand.getNumSugar() << endl;
						cout << "Remaining Baskets: " << playerStand.getNumBaskets() << endl;
						cout << "Remaining Coolers: " << playerStand.getNumCoolers() << endl;
						cout << "Remaining Umbrellas: " << playerStand.getNumUmbrellas() << endl;
						cout << endl;
						valid = true;
					}

					if (strategy=="S")//if stand surrenders assets will be lost 
					{
						int assetsLost;

						if (playerStand.getSpendAssets() < 5) //checking if there are suffient supplies 
						{
							assetsLost = playerStand.getSpendAssets();
							playerStand.setSpendAssets(0);
						}
						else
						{
							assetsLost = 5;
							playerStand.setSpendAssets(playerStand.getSpendAssets()-5);
						}

						playerStand.setMainVal(playerStand.getMainVal()-1);
						playerStand.setMainStatus();

						cout << endl;
						cout << "You have chosen to surrender and some of your assets have been stolen. You have lost $" << assetsLost << " in spendable assets. Your maintenance value has also gone down." << endl;
						cout << "Maintenance Value: " << playerStand.getMainVal() << endl;
						cout << "Maintenance Status: " << playerStand.getMainStatus() << endl;
						cout << "Remaining Assets: " << playerStand.getSpendAssets() << endl;
						cout << endl;
						valid = true;
					}
					
					if(strategy=="F") //if stand fights back, stand will not lose anything 
					{
						cout << "You have chosen to fight back. You will have three tries to guess a number between 1 and 10. If you guess correctly, you will avoid losing any supplies." << endl;
						bool checkWin = makePuzzle();
						if(checkWin == true)
						{
							cout << "You have avoided the raid and have not lost any supplies!" << endl;
							valid = true;
						}

						else
						{
							int lemonsLost;
							int sugarLost;
							int basketsLost;
							int coolersLost;
							int umbrellasLost;

							if(playerStand.getNumLemons() < 50)
							{
								lemonsLost = playerStand.getNumLemons();
								playerStand.setNumLemons(0);
							}
							else
							{
								lemonsLost = 50;
								playerStand.setNumLemons(playerStand.getNumLemons()-50);
							}
							
							if(playerStand.getNumSugar() < 100)
							{
								sugarLost = playerStand.getNumSugar();
								playerStand.setNumSugar(0);
							}
							else
							{
								sugarLost = 100;
								playerStand.setNumSugar(playerStand.getNumSugar()-100);
							}
							
							if(playerStand.getNumBaskets() > 0)
							{
								basketsLost = 1;
								playerStand.setNumBaskets(playerStand.getNumBaskets()-1);
							}
							else
								basketsLost = 0;
							
							if(playerStand.getNumCoolers() > 0)
							{
								coolersLost = 1;
								playerStand.setNumCoolers(playerStand.getNumCoolers()-1);
							}
							else
								coolersLost = 0;

							if(playerStand.getNumUmbrellas() < 1)
							{
								umbrellasLost = 1;
								playerStand.setNumUmbrellas(playerStand.getNumUmbrellas()-1);
							}
							else
								umbrellasLost = 0;

							playerStand.setMainVal(playerStand.getMainVal()-1);
							playerStand.setMainStatus();

							cout << endl;
							cout << "You have chosen to run and some of your supplies have been stolen." << endl;
							cout << "You have lost " << lemonsLost << " lemons, " << sugarLost << " sugar cubes, " << basketsLost << " basket, " << coolersLost << " cooler, and " << umbrellasLost << " umbrella. Your maintenance value has also gone down." << endl;
							cout << "Maintenance Value: " << playerStand.getMainVal() << endl;
							cout << "Maintenance Status: " << playerStand.getMainStatus() << endl;
							cout << "Remaining Lemons: " << playerStand.getNumLemons() << endl;
							cout << "Remaining Sugar: " << playerStand.getNumSugar() << endl;
							cout << "Remaining Baskets: " << playerStand.getNumBaskets() << endl;
							cout << "Remaining Coolers: " << playerStand.getNumCoolers() << endl;
							cout << "Remaining Umbrellas: " << playerStand.getNumUmbrellas() << endl;
							cout << endl;
							valid = true;
						} //end of else from losing puzzle
					} //end of fight back
				} //end of while loop
				break; 	
			} //end of case 4 stand was raided	
		} //end of switch cases	
	} //end of misfortunes chance of 40%
}

void Game::decreaseMainVal() //decrease maintenance value
{
	if(dayNumber == 3 || dayNumber == 6 || dayNumber == 9 || dayNumber == 12) //every three days
	{
		playerStand.setMainVal(playerStand.getMainVal()-1);
		playerStand.setMainStatus();
	}
}

bool Game::makePuzzle()
{
	bool winGame = false;
	int guess;
	int mysteryNum = (rand()%10 + 1); //rand number between 1-10 

	for(int i = 0; i < 3; i++)
	{
		cout << "Please guess a number between 1 and 10: " << endl;
		cin >> guess;
		cout << endl;

		if(guess == mysteryNum) //correct guess 
		{
			winGame = true;
			cout << "Congratulations! You guessed the correct number!" << endl;
			break;
		}

		else
		{
			if(i < 2) //allows user for 3 guesses, displays try again twice 
			{
				cout << "You did not guess the correct number. Please try again." << endl;
				cout << endl;
			}
		}
	}

	if(winGame == false) //if the user does not guess within three tires 
	{
		cout << "You did not guess the correct number within three tries." << endl;
	}

	return winGame;
}

void Game::displayStats()
{
	cout << endl;
	cout << "++++++++++++++++++++++++++" << endl;
	cout << "Lemons: " << playerStand.getNumLemons() << endl; //expected 30
	cout << "Sugar: " << playerStand.getNumSugar() << endl; //expected 60
	cout << "Advertisments: " << playerStand.getNumAdvert() << endl; //expected 6
	cout << "Baskets: " << playerStand.getNumBaskets() << endl; //expected 4
	cout << "Coolers: " << playerStand.getNumCoolers() << endl; //expected 2
	cout << "Umbrellas: " << playerStand.getNumUmbrellas() << endl; //expected 2
	cout << fixed << "Assets: $" << setprecision(2) << playerStand.getSpendAssets() << endl; //expected 14
	cout << fixed << "Total Profit: $" << setprecision(2) << playerStand.getProfit() << endl; //expected 0
	cout << "Maintenance Value: " << playerStand.getMainVal() << endl; //expected 6
	cout << "Maintenance Status: " << playerStand.getMainStatus() << endl; //expected good
	cout << "++++++++++++++++++++++++++" << endl;
	cout << endl;

}	

string Game::checkGameStatus()
{
	string gameStatus;

	if(getDayNumber() <= 15 && playerStand.getProfit() >= 200) //win condition
	{
		cout << "Congrats, " << playerStand.getPlayerName() << "! You have won the game! You now have enough money to start your lemonade manufacturing company." << endl;
		gameStatus = "win";
		return gameStatus;
	}

	else if (playerStand.getNumLemons() <= 0 || playerStand.getNumSugar() <= 0) //run out of supplies to make lemonade
	{
		cout << "Sorry, " << playerStand.getPlayerName() << ". You ran out of supplies to make lemonade and you lost the game. " << playerStand.getStandName() << " has been sent to the dump. Better luck next time!" << endl; 
		gameStatus = "lose";
		return gameStatus;
	}
	
	else if(playerStand.getMainVal() == 0) //maintenance too low
	{
		cout << "Sorry, " << playerStand.getPlayerName() << ". Your maintenance status got too low and you lost the game. " << playerStand.getStandName() << " has been sent to the dump. Better luck next time!" << endl;
		gameStatus = "lose";
		return gameStatus;
	}
	
	else if(getDayNumber() > 15 && playerStand.getProfit() < 200) //do not make enough money in 15 days
	{
		cout << "Sorry, " << playerStand.getPlayerName() << ". You did not make enough money in 15 days and you lost the game. " << playerStand.getStandName() << " has been sent to the dump. Better luck next time!" << endl;
		gameStatus = "lose";
		return gameStatus;
	}

	else //haven't won but also haven't lost
	{
		gameStatus = "inPlay";
		return gameStatus;
	}
}

double Game::getSetPrice()
{
	return setPrice;
}

void Game::setSetPrice(double setPrice_)
{
	setPrice = setPrice_;
}

int Game::getSetAds()
{
	return setAds;
}

void Game::setSetAds(int setAds_)
{
	setAds = setAds_;
}

int Game::getPriceVal()
{
	return priceVal;
}

void Game::setPriceVal(int priceVal_)
{
	priceVal = priceVal_;
}

int Game::getWeatherVal()
{
	return weatherVal;
}

void Game::setWeatherVal(int weatherVal_)
{
	weatherVal = weatherVal_;
}

void Game::setCupPrice() //setting a price for selling lemonade 
{
	double pricePer;
	cout << "Please enter the price per cup at which you want to sell your lemonade today as a decimal number:" << endl;
	cin >> pricePer;
	cout << endl;

	setSetPrice(pricePer); 
}

void Game::setNumAds() //setting number of ads placed each day, ads increase patrons to lemonade stand
{
	int numAds;
	cout << "Please enter the number of ads you would like to use today:" << endl;
	cin >> numAds;
	cout << endl;

	playerStand.setNumAdvert(playerStand.getNumAdvert()-numAds); //subtracting the ads used 
	cout << "Remaining Ads: " << playerStand.getNumAdvert() << endl; //displaying the new number of ads 
	setSetAds(numAds);
}

void Game::calcProfits()
{
	double dailyProfit;
	double weatherSensitivity = 1 - (0.01 * getWeatherVal());
	double adSensitivity = 1 - (0.01 * getSetAds());
	double priceDifference = getSetPrice() - getChosenLocation().getAvgSpend();
	int numCustomers = round( -64 / (1 + exp(-2 * weatherSensitivity * adSensitivity * priceDifference)) + 64); //total number of customers 
	dailyProfit = (numCustomers * setPrice); //number of customers times price per cup
	playerStand.setProfit(playerStand.getProfit() + dailyProfit); //updating profit

	cout << "Number of Customers: " << numCustomers << endl;
	cout << "Daily Profit: $" << dailyProfit << endl; //profit earned on one turn/day
	cout << "Total Profit: $" << playerStand.getProfit() << endl; //total profit earned during whole game
	
	//lemonade recipe is a 1:2 ratio with one lemon and two sugars being lost per customer/cup
	int lemonsLost = numCustomers * 1;
	int sugarLost = numCustomers * 2;
	playerStand.setNumLemons(playerStand.getNumLemons() - lemonsLost); //subtracting lemons from stand
	playerStand.setNumSugar(playerStand.getNumSugar() - sugarLost); //subtracting sugar from stand
	cout << "Remaining Lemons: " << playerStand.getNumLemons() << endl;
	cout << "Remaining Sugar: " << playerStand.getNumSugar() << endl;
	cout << endl;
}

void Game::dayOff() //increases maintenance value 
{
	bool dayOff = false; //false equals day NOT taken day off 

	while(!dayOff)
	{
		string option;
		cout << "You can take a day off in order to increase the maintenance status of your stand. However, you will lose a day." << endl;
		cout << "Would you like to take a day off? (Y/N)" << endl;
		cin >> option;
		cout << endl;
		
		if(option != "Y" && option != "N") //if an anvalid option is chosen 
		{
			cout << "Invalid option. Please answer Y or N." << endl; 
			cout << endl;
			continue;
		}
		
		if(option == "Y") //increasing maintence value 
		{
			setDayNumber(getDayNumber()+1);
			playerStand.setMainVal(playerStand.getMainVal()+2);
			playerStand.setMainStatus();
			cout << "You took day " << getDayNumber() - 1 <<" off. Your maintenance status has improved." << endl;
			cout << "Maintenance Value: " << playerStand.getMainVal() << endl;
			cout << "Maintenance Status: " << playerStand.getMainStatus() << endl;
			cout << endl;
			dayOff = true;
		}

		if(option == "N")
			break;
	}
}

void Game::raidStand() //this function allows a stand to raid another stand for additional supplies, such as more lemons, sugar, coolers, and umbrellas. To successfully raid the user has three chances to guess the correct number 
{
	bool raidStand = false;
	
	while(!raidStand)
	{
		string option;
		cout << "You can raid another stand to gain supplies. However, you will lose one basket and one day." << endl; 
		cout << "Would you like to raid another stand? (Y/N)" << endl;
		cin >> option;

		if(option != "Y" && option != "N")
		{
			cout << "Invalid option. Please answer Y or N." << endl; 
			continue;
		}

		if(option == "Y")
		{
			if(playerStand.getNumBaskets() == 0) //don't have enough baskets to raid
			{
				cout << "You do not have any baskets and cannot raid another stand at this time." << endl;
				raidStand = true;
			}

			else //have enough baskets to raid
			{
				cout << "To successfully raid another stand and gain supplies, you must first guess a number between 1 and 10 within three tries. If you do not guess the number, you will not gain any supplies." << endl;
				
				playerStand.setNumBaskets(playerStand.getNumBaskets()-1); //must use 1 basket
				setDayNumber(getDayNumber()+1); //raiding a stand, also loses a day 
				
				bool checkWin = makePuzzle();

				if(checkWin == true) 
				{
					cout << "You have succesfully raided another stand and have taken take some supplies. " << endl;
					playerStand.setNumLemons(playerStand.getNumLemons()+50);
					playerStand.setNumSugar(playerStand.getNumSugar()+100);
					playerStand.setNumCoolers(playerStand.getNumCoolers()+1);
					playerStand.setNumUmbrellas(playerStand.getNumUmbrellas()+1);

					cout << "Lemons Gained: 50" << endl;
					cout << "Sugar Gained: 100 " << endl;
					cout << "Coolers Gained: 1 " << endl;
					cout << "Umbrellas Gained: 1 " << endl;
				}

				else
				{
					cout <<  "You did not successfully raid another stand and did not gain any supplies." << endl;
					cout << endl;
				}
				raidStand = true;
			}
		}	

		if(option == "N")
			break;
	}
}