/******************************************************************************
** Program name : Project 2
** Author : Jeffrey Ngo
** Date : 10 / 27 / 2019
** Description : Zoo Class contains the game flow and most of the functions
** such as, resize array, random event, menus, animals age, cost, food and
**babies
******************************************************************************/
#include <iostream>
#include "animal.hpp"
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"
#include <cstdlib>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;


#ifndef ZOO_HPP
#define ZOO_HPP

class Zoo
{
private:

	// Declare variables
	double cashBalance;
	int numOfTigers;
	int numOfPenguins;
	int numOfTurtles;
	int capacityOfTigers;
	int capacityOfPenguins;
	int capacityOfTurtles;
	double cashProfit;
	int choice;
	int startNumTigers;
	int startNumPenguins;
	int startNumTurtles;

	//Arrays
	Tiger* tigArray;
	Penguin* pengArray;
	Turtle* turtArray;



public:
	Zoo();

	int validation(int);

	void start();

	void animalAge();
	void foodCost();
	void animalProfit();

	void resizeTiger();
	void resizePenguin();
	void resizeTurtle();

	void addTiger(Tiger);
	void addPenguin(Penguin);
	void addTurtle(Turtle);

	void addBabies();
	void sickness();
	void attendance();

	void randomEvent();

	void setCashBalance(double);
	void setTiger();
	void setPenguin();
	void setTurtle();
	double getCashBalance();
	double getProfit();
};
#endif