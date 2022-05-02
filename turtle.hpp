/******************************************************************************
** Program name : Project 2
** Author : Jeffrey Ngo
** Date : 10 / 27 / 2019
** Description : Turtle class that inherits from base class animal
******************************************************************************/
#include <iostream>
#include "animal.hpp"
#include <cstdlib>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;


#ifndef TURTLE_HPP
#define TURTLE_HPP

// Inherits from base class Animal
class Turtle : public Animal
{

public:

	// Default constructor
	Turtle();

	// Constructor with parameters
	Turtle(int age, double cost, int numberOfBabies, double baseFoodCost, double payoff);
};
#endif
