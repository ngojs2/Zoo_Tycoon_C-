/******************************************************************************
** Program name : Project 2
** Author : Jeffrey Ngo
** Date : 10 / 27 / 2019
** Description : penguin class that inherits from base class animal
******************************************************************************/
#include <iostream>
#include "animal.hpp"
#include <cstdlib>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;


#ifndef PENGUIN_HPP
#define PENGUIN_HPP

// Inherits from base class Animal
class Penguin : public Animal
{

public:

	//Default constructor
	Penguin();

	//Constructor with parameters
	Penguin(int age, double cost, int numberOfBabies, double baseFoodCost, double payoff);
};
#endif
