// CS1300 Spring 2020
// Author: Patricia Chin & Kyra Moran
// Project 3

#include <iostream>
#include <string>
#include "Stand.h"
using namespace std;

Stand::Stand() //Constructs a stand object as a default constructor
{
    playerName=""; //setting username of user to an empty string 
    standName="";//setting stand name to an empty string 
    numLemons=0;
    numSugar=0;
    numAdvert=0;
    numBaskets=0;
    numCoolers=0;
    numUmbrellas=0;
    spendAssets=150;
    profit=0;
    mainVal=6;
    mainStatus="good"; 
}

string Stand::getPlayerName()
{
    return playerName;
}

string Stand::getStandName()
{
    return standName;
}

int Stand::getNumLemons() //gets number of Lemons 
{
    return numLemons;
}

int Stand::getNumSugar() //gets number of Sugar
{
    return numSugar; 
}

int Stand::getNumAdvert() //gets number of Adverts
{
    return numAdvert;
}

int Stand::getNumBaskets() //gets number of Baskets
{ 
    return numBaskets;
}
 
int Stand::getNumUmbrellas() //gets number of Umbrellas
{
    return numUmbrellas;
}

int Stand::getNumCoolers() //gets number of Coolers
{
    return numCoolers; 
}

double Stand::getSpendAssets() //gets Assets
{
    return spendAssets; 
}

double Stand::getProfit()
{
    return profit;
}

int Stand::getMainVal()
{
    return mainVal;
}

string Stand::getMainStatus() //gets maintenance status
{
    return mainStatus;
}

void Stand::setPlayerName(string playerName_) //sets private data member playerName
{
    playerName = playerName_;
}

void Stand::setStandName(string standName_) //sets private data member standName
{
    standName = standName_;
}

void Stand::setNumLemons(int numLemons_) //sets private data member numLemons
{
    if(numLemons_ < 0)
        numLemons = 0;
    
    else
        numLemons = numLemons_;
}

void Stand::setNumSugar(int numSugar_) //sets private data member numSugar
{
    if(numSugar_ < 0)
        numSugar = 0;
    
    else
        numSugar = numSugar_;
}

void Stand::setNumAdvert(int numAdvert_) //sets private data member numAdvert
{
    if(numAdvert_ < 0)
        numAdvert = 0;
    
    else
        numAdvert = numAdvert_;
}

void Stand::setNumBaskets(int numBaskets_) //sets private data member numBaskets
{
    if(numBaskets_ < 0)
        numBaskets = 0;

    else
        numBaskets = numBaskets_;
}

void Stand::setNumUmbrellas(int numUmbrellas_) //sets private data member numUmbrellas
{
    if(numUmbrellas_ < 0)
        numUmbrellas = 0;

    else
        numUmbrellas = numUmbrellas_;
}

void Stand::setNumCoolers(int numCoolers_) //sets private data member numCoolers
{
    if(numCoolers_ < 0)
        numCoolers = 0;

    else
        numCoolers = numCoolers_;
}

void Stand::setSpendAssets(double spendAssets_) //sets private data member assets
{
    if(spendAssets_ < 0)
        spendAssets = 0;

    else
        spendAssets = spendAssets_;
}

void Stand::setProfit(double profit_)
{
    profit = profit_;
}

void Stand::setMainVal(int mainVal_)
{
    if(mainVal_ < 0)
        mainVal = 0;

    else if(mainVal_ > 6) //mainVal cannot be greater than 6
        mainVal = 6;

    else
        mainVal = mainVal_;
}

void Stand::setMainStatus()
{
    if(mainVal == 1 || mainVal == 2)
        mainStatus = "poor";

    if(mainVal == 3 || mainVal == 4)
        mainStatus = "fair";

    if(mainVal == 5 || mainVal == 6)
        mainStatus = "good";
}



