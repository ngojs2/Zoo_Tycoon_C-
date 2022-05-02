/******************************************************************************
** Program name : Project 2
** Author : Jeffrey Ngo
** Date : 10 / 27 / 2019
** Description : Tiger class that inherits from base class animal
******************************************************************************/
#include <iostream>
#include "animal.hpp"
#include <cstdlib>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;

#ifndef TIGER_HPP
#define TIGER_HPP

// Inherits from base class Animal
class Tiger : public Animal
{

public:

	// Default constructor
	Tiger();

	// Constructor with parameters
	Tiger(int age, double cost, int numberOfBabies, double baseFoodCost, double payoff);
};
#endif