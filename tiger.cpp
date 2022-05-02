/******************************************************************************
** Program name : Project 2
** Author : Jeffrey Ngo
** Date : 10 / 27 / 2019
** Description : Tiger class that inherits from base class animal
******************************************************************************/
#include <iostream>
#include "zoo.hpp"
#include "animal.hpp"
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"
#include <cstdlib>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;


// Default constructor 
Tiger::Tiger() : Animal()
{
}

// Constructor with parameters
Tiger::Tiger(int age, double cost, int numberOfBabies, double baseFoodCost,
	double payoff) : Animal(age, cost, numberOfBabies, baseFoodCost, payoff)
{
}



