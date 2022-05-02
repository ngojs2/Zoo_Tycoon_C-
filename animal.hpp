/******************************************************************************
** Program name : Project 2
** Author : Jeffrey Ngo
** Date : 10 / 27 / 2019
** Description : Base class Animal that will be inherited by the other classes
** sets and gets animals age, cost, num of babies, food cost and payoff
******************************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
private:

	// Declare variables
	int age;
	double cost;
	int numberOfBabies;
	double baseFoodCost;
	double payoff;

public:

	// Default constructor
	Animal();

	// Constructor with Parameters
	Animal(int age, double cost, int numberOfBabies, double baseFoodCost, double payoff);

	//Setter functions
	void setAnimalAge(int age);
	void setAnimalCost(double cost);
	void setNumberOfBabies(int numberOfBabies);
	void setAnimalBaseFoodCost(double baseFoodCost);
	void setAnimalPayoff(double payoff);

	// Getter functions
	int getAnimalAge();
	double getAnimalCost();
	int getNumberOfBabies();
	double getAnimalBaseFoodCost();
	double getAnimalPayoff();
};
#endif