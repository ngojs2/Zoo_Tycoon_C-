/******************************************************************************
** Program name : Project 2
** Author : Jeffrey Ngo
** Date : 10 / 27 / 2019
** Description : Animal class with age, cost, num of babies, food cost,
pay off setters and getters
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



Animal::Animal()
{
	// Declare Variables
	age = 0;
	cost = 0.0;
	numberOfBabies = 0;
	baseFoodCost = 0.0;
	payoff = 0.0;

}

// Constructor Definition
Animal::Animal(int age, double cost, int numberOfBabies, double baseFoodCost, double payoff)
{
	this->age = age;
	this->cost = cost;
	this->numberOfBabies = numberOfBabies;
	this->baseFoodCost = baseFoodCost;
	this->payoff = payoff;

}

// get age function
int Animal::getAnimalAge()
{
	return age;
}

// get animal cost function
double Animal::getAnimalCost()
{
	return cost;
}

// get number of babies function
int Animal::getNumberOfBabies()
{
	return numberOfBabies;
}

// get food cost function
double Animal::getAnimalBaseFoodCost()
{
	return baseFoodCost;
}

// get animal payoff function
double Animal::getAnimalPayoff()
{
	return payoff;
}

// set animal age function
void Animal::setAnimalAge(int age)
{
	this->age = age;
}

// set animal cost function
void Animal::setAnimalCost(double cost)
{
	this->cost = cost;
}

// set number of babies function
void Animal::setNumberOfBabies(int numberOfBabies)
{
	this->numberOfBabies = numberOfBabies;
}

// set base food cost function
void Animal::setAnimalBaseFoodCost(double baseFoodCost)
{
	this->baseFoodCost = baseFoodCost;
}

// set animal payoff function
void Animal::setAnimalPayoff(double payoff)
{
	this->payoff = payoff;
}


