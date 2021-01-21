//CS1300 Spring 2020
//Author: Patricia Chin & Kyra Moran
//Project 3

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Stand.h"
#include "Location.h"
#include "Game.h"
using namespace std;

int main()
{
	//welcome screen with game rules
	cout << endl;
	cout << "WELCOME TO LEMONADE!" << endl;
	cout << endl;
	cout << "In this game, you will be running a lemonade stand. You will have 15 days to raise $200 that will go towards starting a lemonade manufacturing company. With your initial assets of $150, you will be able to buy all of the supplies needed to run your stand. Throughout the game, you will be able to buy more supplies, but the prices will be higher each time you choose to do so." << endl;
	cout << endl;
	cout << "On each day, you will be able to set a price per cup for your lemonade and decide how many advertisements you want to use to increase customer traffic. At the end of each day, your lemonade stand will move to a new city; the city you’re in will impact the price customers are willing to pay for the lemonade. Weather will also impact your sales; expect to sell less during rainy or cloudy days. Sell your lemonade for a higher price when it’s hot and sunny. If it is rainy, you will need to use an umbrella to protect your stand, and if it is sunny and hot, you will need to use a cooler to protect your stand. If you do not have this equipment when this weather arises, your maintenance status will go down." << endl;
	cout << endl;
	cout << "Be prepared because misfortunes may come your way! It is possible that lemons go bad, advertisements are vandalized, your weather protection equipment breaks, or that you are raided by a competing stand. Your maintenance value will also go down every three days from using the stand. Outside of selling lemonade, you will be able to raid other stands in order to gain supplies or close the stand for a day to increase your stand’s maintenance status. Keep in mind that you will lose a day if you close the stand." << endl;
	cout << endl;
	cout << "If you can manage to make $200 dollars within 15 days, you win the game! However, if you run out of supplies to make lemonade, your maintenance status gets too low (maintenance value reaches 0), or you do not make enough money in 15 days, you will sadly lose the game and your lemonade stand will be sent to the dump. Good luck!" << endl;
	cout << endl;
	
	//code from https://stackoverflow.com/questions/21257544/c-wait-for-user-input
	do 
	{
		cout << '\n' << "Press Enter to Start Game:" << endl;
	} 
	while (cin.get() != '\n');
	
	//Start Game
	Game playerGame; //create Game object that initializes data members and Stand object
	srand(time(NULL)); //seeds all of our random functions with computer time
	
	//set player name and stand name
	playerGame.initNames(); 

	// visit store
	playerGame.visitStore();

	//read locations list
	playerGame.readLocations("locations.txt");

	//turns
	bool inGame = true;

	while (playerGame.getDayNumber() <= 15 && inGame)
	{
		int option;

		cout << "===========Game Menu==========" << endl;
		cout << "Select a numerical option:" << endl;
		cout << "1. Sell Lemonade" << endl;
		cout << "2. Take a Day Off" << endl;
		cout << "3. Raid Another Stand" << endl;
		cout << "4. Check Supplies" << endl;
		cout << "5. Buy More Supplies" << endl;
		cout << "6. Quit Game" << endl; 
		cin >> option;
		cout << "==============================" << endl;
		cout << endl;

		if (option < 1 || option > 6)
		{
			cout << "Invalid option. Please enter a number between 1 and 5." << endl;
			continue;
		}

		switch(option)
		{
			case 1: //Sell Lemonade
			{
				bool sellLemonade = false;
	
				while(!sellLemonade)
				{
					string option;
					cout << endl;
					cout << "You can sell lemonade to make profit. However, one day will pass and your lemons and sugar will decrease based on how many cups you sell. One cup of lemonade is one lemon and two sugars." << endl; 
					cout << "Would you like to sell lemonade? (Y/N)" << endl;
					cin >> option;
					cout << endl;

					if(option != "Y" && option != "N")
					{
						cout << "Invalid option. Please answer Y or N." << endl; 
						continue;
					}

					if(option == "Y")
					{
						cout << endl;
						cout << "--------Day " << playerGame.getDayNumber() << " of 15--------" << endl;
						playerGame.setDayNumber(playerGame.getDayNumber()+1); //staring the game on day 1 

						playerGame.chooseLocation(); //also able to access avg spend price at the given location 
						playerGame.chooseWeather();
						playerGame.displayStats();

						cout << "--------------------------------------------------------------------------------" << endl;
						cout << "Location: " << playerGame.getChosenLocation().getLocName() << endl;
						cout << "Weather: " << playerGame.getChosenWeather() << endl;
						cout << endl;
			
						cout << fixed << "The average amount that people in " << playerGame.getChosenLocation().getLocName() << " are willing to spend per cup is $" << setprecision(2) << playerGame.getChosenLocation().getAvgSpend() << "." << endl;
						cout << "--------------------------------------------------------------------------------" << endl;
						cout << endl;

						playerGame.setCupPrice();
						playerGame.setNumAds();
						// playerGame.comparePrices();
						
						playerGame.calcProfits();
						playerGame.decreaseMainVal(); //only does this every three days

						string gameStatus = playerGame.checkGameStatus();

						if(gameStatus == "win" || gameStatus == "lose") //if they win the game
						{
							inGame = false; //leave the while loop/game menu
						} 

						playerGame.chooseMisfortune();

						sellLemonade = true;

					} //end of yes option

					if(option == "N")
						sellLemonade = true;

				} //end of while loop
				break;  
			} //end of case 1
			
			case 2: //Take a Day Off
			{
				playerGame.displayStats();
				cout << "--------Day " << playerGame.getDayNumber() << " of 15--------" << endl;
				playerGame.dayOff();

				string gameStatus = playerGame.checkGameStatus();

				if(gameStatus == "win" || gameStatus == "lose") //if they win the game
				{
					inGame = false; //leave the while loop/game menu
				} 

				break;  
			}
			
			case 3: //Raid Another Stand
			{
				playerGame.displayStats();
				playerGame.raidStand();

				string gameStatus = playerGame.checkGameStatus();

				if(gameStatus == "win" || gameStatus == "lose") //if they win the game
				{
					inGame = false; //leave the while loop/game menu
				} 

				break;  
			}

			case 4: //Check Supplies
			{
				playerGame.displayStats();
				break;  
			}

			case 5: //buy more supplies 
			{
				bool buyMore = false;
	
				while(!buyMore)
				{
					string option;
					cout << "You can visit the store again to buy more supplies. However, the prices of supplies will increase by 10% upon each visit." << endl; 
					cout << "Would you like to buy more supplies? (Y/N)" << endl;
					cin >> option;

					if(option != "Y" && option != "N")
					{
						cout << "Invalid option. Please answer Y or N." << endl; 
						continue;
					}

					if(option == "Y")
					{
						playerGame.setStoreVisits(playerGame.getStoreVisits()+ 1); //setting the number of times the player visits the store 
						playerGame.gameStore();
						buyMore = true;
					}
					
					if(option == "N")
						buyMore = true; 

				} //end of while loop
				break;
			} //end of case 5
			
			case 6: //Quit Game
			{
				cout << "Thanks for playing Lemonade!" << endl;
				inGame = false; //leave the while loop/game menu
				break;  
			}
		} // end of switch statements
	} //end of while loop	
} //end of main



