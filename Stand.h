//CS1300 Spring 2020
//Author: Patricia Chin & Kyra Moran
//Project 3

#include <iostream>
#include <string>
using namespace std;

#ifndef STAND_H
#define STAND_H

class Stand
{
    public:
        //default constructor 
        Stand(); 
        
        //setter function
        void setPlayerName(string playerName_); //sets private data member playerName
        void setStandName(string standName_); //sets private data member standName
        void setNumLemons(int numLemons_); //sets private data member numLemons
        void setNumSugar(int numSugar_); //sets private data member numSugar
        void setNumAdvert(int numAdvert_); //sets private data member numAdvert
        void setNumBaskets(int numBaskets_); //sets private data member numBaskets
        void setNumUmbrellas(int numUmbrellas_); //sets private data member numUmbrellas
        void setNumCoolers(int numCoolers_); //sets private data member numCoolers
        void setSpendAssets(double spendAssets_); //sets private data member spendAssets
        void setProfit(double profit_); //sets private data member profit
        void setMainVal(int mainVal_); //sets private data member mainVal
        void setMainStatus(); //sets private data member mainStatus
        
        //getter functions
        string getPlayerName(); //Return private data member playerName
        string getStandName(); //Return private data member standName
        int getNumLemons(); //Return private data member numLemons
        int getNumSugar(); //Return private data member numSugar
        int getNumAdvert(); //Return private data member numAdvert
        int getNumBaskets(); //Return private data member numBaskets
        int getNumUmbrellas(); //Return private data member numUmbrellas
        int getNumCoolers(); //Return private data member numCoolers
        double getSpendAssets(); //Return private data member spendAssets
        double getProfit(); //Return private data member profit
        int getMainVal(); //Return private data member mainVal
        string getMainStatus(); //Return private data member mainStatus
    
    private:
        //names
        string playerName; //username of user
        string standName; //name of user's lemonade stand
        
        //supplies
        int numLemons; //number of lemons 
        int numSugar; //number of sugar cubes
        int numAdvert; //number of advertisements
        int numBaskets; //number of baskets
        int numUmbrellas; //number of umbrellas
        int numCoolers; //number of coolers
        double spendAssets; //money that the stand has to spend on supplies
        double profit; //money that the stand has made
        
        string mainStatus; //maintenance status can be good,fair, or poor
        int mainVal; //maintenance value; if 0 --> lose game; if 1 or 2 --> poor; if 3 or 4 --> fair; if 5 or 6 --> good
};

#endif