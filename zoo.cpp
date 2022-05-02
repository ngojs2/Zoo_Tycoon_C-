/******************************************************************************
** Program name : Project 2
** Author : Jeffrey Ngo
** Date : 10 / 27 / 2019
** Description : Zoo Class contains the game flow and most of the functions
** such as, resize array, random event, menus, animals age, cost, food and 
**babies
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

Zoo::Zoo()
{
	//Declare Variables
	cashBalance = 100000;
	numOfTigers = 0;
	numOfPenguins = 0;
	numOfTurtles = 0;
	capacityOfTigers = 10;
	capacityOfPenguins = 10;
	capacityOfTurtles = 10;
	cashProfit = 0;
	choice = 0;
	startNumTigers = 0;
	startNumPenguins = 0;
	startNumTurtles = 0;
	
	// Arrays
	tigArray = new Tiger[capacityOfTigers];
	pengArray = new Penguin[capacityOfPenguins];
	turtArray = new Turtle[capacityOfTurtles];
}

// Function to check input valiadtion
int Zoo::validation(int val)
{
	while (!(std::cin >> val))
	{
		cout << "Please select a number" << endl;
		cin.clear();
		cin.ignore(100, '\n');
	}
	return val;
}

/*This function sets the age, cost, number of babies, food cost and payoff
of the tigers and adds it to the array*/
void Zoo::setTiger()
{
	Tiger tig1;

	tig1.setAnimalAge(1);
	tig1.setAnimalCost(10000);
	tig1.setNumberOfBabies(1);
	tig1.setAnimalBaseFoodCost(50);
	tig1.setAnimalPayoff(.2 * 10000);

	addTiger(tig1);
}
/*This function sets the age, cost, number of babies, food cost and payoff
of the penguins and adds it to the array*/
void Zoo::setPenguin()
{
	Penguin peng1;

	peng1.setAnimalAge(1);
	peng1.setAnimalCost(1000);
	peng1.setNumberOfBabies(5);
	peng1.setAnimalBaseFoodCost(1 * 10);
	peng1.setAnimalPayoff(.1 * 1000);

	addPenguin(peng1);
}
/*This function sets the age, cost, number of babies, food cost and payoff
of the turtles and adds it to the array*/
void Zoo::setTurtle()
{
	Turtle turt1;
	turt1.setAnimalAge(1);
	turt1.setAnimalCost(100);
	turt1.setNumberOfBabies(1);
	turt1.setAnimalBaseFoodCost(.5 * 10);
	turt1.setAnimalPayoff(.05 * 100);

	addTurtle(turt1);
}

/*This function starts the zoo simulation*/
void Zoo::start()
{
	// Declare variables
	bool nextDay = true;
	int day = 1;
	int buyMenu = 0;
	int buy = 0;
	int keepPlaying = 0;

	//Start menu
	cout << "Welcome to the Zoo" << endl;
	cout << "1. Start" << endl;
	cout << "2. Exit" << endl;

	while (choice != 1 && choice != 2)
	{
		cout << "Please select 1 or 2" << endl;
		choice = validation(choice);
	}

	/*This loop starts the starting buy option*/
	while (choice == 1)
	{
		cout << endl;
		cout << "To start, you must buy 1 of each of the three animals" 
			<< endl;
		cout << "Your starting cash Balance is $100,000" << endl;
		cout << endl;
		cout << "How many tigers do would you like to buy, 1 or 2?" << endl;
		startNumTigers = validation(startNumTigers);
		while (startNumTigers != 1 && startNumTigers != 2)
		{
			cout << "Please select 1 or 2" << endl;
			startNumTigers = validation(startNumTigers);

		}
		/* For each animal bought, it calls the set function to set the age
		 price, num of babies and profit and adds it to the array*/
		cout << "You bought " << startNumTigers << " tigers" << endl;
		for (int i = 0; i < startNumTigers; i++)
		{
			setTiger();
		}
		
		cout << "How many penguins would you like to buy, 1 or 2?" << endl;
		startNumPenguins = validation(startNumPenguins);
		while (startNumPenguins != 1 && startNumPenguins != 2)
		{
			cout << "Please select 1 or 2" << endl;
			startNumPenguins = validation(startNumPenguins);
		}

		/* For each animal bought, it calls the set function to set the age
		 price, num of babies and profit*/
		cout << "You bought " << startNumPenguins << " penguins" << endl;
		for (int i = 0; i < startNumPenguins; i++)
		{
			setPenguin();
		}

		cout << "How many turtles would you like to buy, 1 or 2?" << endl;
		startNumTurtles = validation(startNumTurtles);
		while (startNumTurtles != 1 && startNumTurtles != 2)
		{
			cout << "Please select 1 or 2" << endl;
			startNumTurtles = validation(startNumTurtles);
		}

		/* For each animal bought, it calls the set function to set the age
		 price, num of babies and profit*/
		cout << "You bought " << startNumTurtles << " turtles" << endl;
		for (int i = 0; i < startNumTurtles; i++)
		{
			setTurtle();
		}

		while (nextDay != false)
		{
			cout << endl;
			cout << "Day: " << day++ << endl;
			cout << "Cash Balance $" << getCashBalance() << endl;
			
			/*Call function to add age, deduct food cost, select random event
			and calculate profit each day*/
			animalAge();
			foodCost();
			randomEvent();
			animalProfit();
			
			// Asks user if they would like to buy another animal
			cout << "Would you like to buy another animal?" << endl;
			cout << "1. Yes" << endl;
			cout << "2. Skip buying" << endl;
			buyMenu = validation(buyMenu);
			while (buyMenu != 1 && buyMenu != 2)
			{
				cout << "Please select 1 or 2" << endl;
				buyMenu = validation(buyMenu);
			}
			// Menu to buy type of animal
			if (buyMenu == 1)
			{
				cout << endl;
				cout << "What animal would you like to buy?" << endl;
				cout << "1. Tiger" << endl;
				cout << "2. Penguin" << endl;
				cout << "3. Turtle" << endl;
				buy = validation(buy);
				while (buy != 1 && buy != 2 && buy != 3)
				{
					cout << "Please select 1, 2 or 3" << endl;
					buy = validation(buy);
				}

				if (buy == 1)
				{
					setTiger();
					cout << "You bought a tiger" << endl;
				}

				if (buy == 2)
				{
					setPenguin();
					cout << "You bought a penguin" << endl;
				}
				
				if (buy == 3)
				{
					setTurtle();
					cout << "You bought a turtle" << endl;
				}
			}

			// Menu to keep playing
			cout << endl;
			cout << "Would you like to keep playing?" << endl;
			cout << "1. Yes" << endl;
			cout << "2. No exit game" << endl;
			keepPlaying = validation(keepPlaying);
			while (keepPlaying != 1 && keepPlaying != 2)
			{
				cout << "Please select 1 or 2" << endl;
				keepPlaying = validation(keepPlaying);
			}
			//If user selects 1 keep playing
			if (keepPlaying == 1)
			{
			}

			// If cash balance goes to 0 or negative exit  game
			else if (getCashBalance() <= 0)
			{
				cout << "You ran out of money" << endl;
				return;
			}
			// Exits if user selects 2 exit game
			else if (keepPlaying == 2)
			{
				return;
			}
			

			cout << "Your current profit $" << getProfit() << endl;
			cout << "Your Cash Balance after profit $" << getCashBalance() 
				+ getProfit() << endl;
			// Adds profit to cash balance
			setCashBalance(getCashBalance() + getProfit());
		}
	}
}

/*This function uses a loop to increase the age for all the tigers, 
penguins and turtles */
void Zoo::animalAge()
{
	
	for (int i = 0; i < numOfTigers; i++)
	{
		tigArray[i].setAnimalAge(tigArray[i].getAnimalAge() + 1);
	}

	for (int i = 0; i < numOfPenguins; i++)
	{
		pengArray[i].setAnimalAge(pengArray[i].getAnimalAge() + 1);
	}

	for (int i = 0; i < numOfTurtles; i++)
	{
		turtArray[i].setAnimalAge(turtArray[i].getAnimalAge() + 1);
	}
}

/*This function calculates the food cost for the animals and 
subtract it from the cash balance*/
void Zoo::foodCost()
{
	for (int i = 0; i < numOfTigers; i++)
	{
		cashBalance -= tigArray[i].getAnimalBaseFoodCost();
	}

	for (int i = 0; i < numOfPenguins; i++)
	{
		cashBalance -= pengArray[i].getAnimalBaseFoodCost();
	}

	for (int i = 0; i < numOfTurtles; i++)
	{
		cashBalance -= turtArray[i].getAnimalBaseFoodCost();
	}
}

// Function to calculate profit for each number of animals
void Zoo::animalProfit()
{
	for (int i = 0; i < numOfTigers; i++)
	{
		cashProfit += tigArray[i].getAnimalPayoff();
	}
	for (int i = 0; i < numOfPenguins; i++)
	{
		cashProfit += pengArray[i].getAnimalPayoff();
	}

	for (int i = 0; i < numOfTurtles; i++)
	{
		cashProfit += turtArray[i].getAnimalPayoff();
	}
}

// Function to set the cash balance
void Zoo::setCashBalance(double balance)
{
	cashBalance = balance;
}

// Function to return the cash balance
double Zoo::getCashBalance()
{
	return cashBalance;
}


// Function to return the total profit from the animals
double Zoo::getProfit()
{
	return cashProfit;
}

// Function to resize the tiger array if number reaches capacity
void Zoo::resizeTiger()
{

	Tiger* tempArr = new Tiger[capacityOfTigers * 2];
	for (int i = 0; i < capacityOfTigers * 2; i++)
	{
		tempArr[i] = tigArray[i];
	}
	// Free memory
	delete[]tigArray;
	tigArray = tempArr;
}

// Function to resize the penguin array if number reaches capacity
void Zoo::resizePenguin()
{
	Penguin* tempArr = new Penguin[capacityOfPenguins * 2];
	for (int i = 0; i < capacityOfPenguins * 2; i++)
	{
		tempArr[i] = pengArray[i];
	}
	// Free memory
	delete[]pengArray;
	pengArray = tempArr;
}

// Function to resise the turtle array if number reaches capacity
void Zoo::resizeTurtle()
{
	Turtle* tempArr = new Turtle[capacityOfTurtles * 2];
	for (int i = 0; i < capacityOfTurtles * 2; i++)
	{
		tempArr[i] = turtArray[i];
		
	}
	//Free memory
	delete[]turtArray;
	turtArray = tempArr;
		
}

/*Function to add tiger and deduct its cost from the cash balance
If the number of tigers reaches the array capacity
It calls to resize the array*/
void Zoo::addTiger(Tiger newTiger)
{
	if (numOfTigers == capacityOfTigers)
	{
		resizeTiger();
	}

	tigArray[numOfTigers] = newTiger;
	numOfTigers++;
	cashBalance -= newTiger.getAnimalCost();
}

/*Function to add penguin and deduct its cost from the cash balance
If the number of penguins reaches the array capacity
It calls to resize the array*/
void Zoo::addPenguin(Penguin newPenguin)
{
	if (numOfPenguins == capacityOfPenguins)
	{
		resizePenguin();
	}

	pengArray[numOfPenguins] = newPenguin;
	numOfPenguins++;
	cashBalance -= newPenguin.getAnimalCost();
 }

//Function to add turtle and deduct its cost from the cash balance
// If the number of turtles reaches the array capacity
// It calls to resize the array
void Zoo::addTurtle(Turtle newTurtle)
{
	if (numOfTurtles == capacityOfTurtles)
	{
		resizeTurtle();
	}

	turtArray[numOfTurtles] = newTurtle;
	numOfTurtles++;
	cashBalance -= newTurtle.getAnimalCost();
}

/*This function generates a random number to pick which animal dies
It checks if the number of the animals is 1 or greater and removes 1*/
void Zoo::sickness()
{
	int animalType;
	animalType = (rand() % 3 + 1);

	if (animalType == 1)
	{
		if (numOfTigers >= 1)
		{
			numOfTigers--;
			cout << "A tiger got sick and died" << endl;
		}
	}

	if (animalType == 2)
	{
		if (numOfPenguins >= 1)
		{
			numOfPenguins--;
			cout << "A penguin got sick and died" << endl;
		}
	}

	if (animalType == 3)
	{
		if (numOfTurtles >= 1)
		{
			numOfTurtles--;
			cout << "A turtle got sick and died" << endl;
		}
	}
}
// Attedance function to be called from random event
void Zoo::attendance()
{
	// Generates a cash bonus amount
	int randomBonus;
	randomBonus = (rand() % 250 + 250);

	//checks for the number of tigers and adds a bonus for each
	for (int i = 0; i < numOfTigers; i++)
	{
		tigArray[i].setAnimalPayoff(tigArray[i].getAnimalPayoff() 
			+ randomBonus);
	}
	cout << "Zoo attendance has increased significantly." << endl;
	cout << "A $" << randomBonus << " bonus was earned." << endl;
}

/*This function generates a random number to pick which animal reproduces*/
void Zoo::addBabies()
{
	//Declare variables
	
	int babyType;
	// Generate random number
	babyType = (rand() % 3 + 1);

	// If the number is 1, the tigers reproduces
	if (babyType == 1)
	{
		// Loop checks the age of all tigers
		for (int i = 0; i < numOfTigers; i++)
		{
			// Checks if any tiger is 3 or older
			if (tigArray[i].getAnimalAge() >= 3)
			{
				// adds one baby
				tigArray[i].setNumberOfBabies(tigArray[i].getNumberOfBabies() + 1);
			}
		}
		cout << "A baby tiger was born" << endl;
	}

	// If the number is 2, then the penguins reproduces
	//Checks Age of each penguins and adds babies
	else if (babyType == 2)
	{
		for (int i = 0; i < numOfPenguins; i++)
		{
			if (pengArray[i].getAnimalAge() >= 3)
			{
				
				pengArray[i].setNumberOfBabies(pengArray[i].getNumberOfBabies() + 5);
			}
			
		}
		cout << "5 baby penguins were hatched" << endl;
	}

	// If the Number is 3 then the turtles reproduces
	//checks age of each turtle and adds babies
	else if (babyType == 3)
	{
		for (int i = 0; i < numOfTurtles; i++)
		{
			if (turtArray[i].getAnimalAge() >= 3)
			{
				
				turtArray[i].setNumberOfBabies(turtArray[i].getNumberOfBabies() + 10);
			}
		}
		cout << "10 baby turtles were hatched" << endl;
	}
}

/*This fuction selects an event randomly and then calls that event function*/
void Zoo::randomEvent()
{
	int event;
	event = (rand() % 4 + 1);

	// If the random number is 1 call the sickness function
	if (event == 1)
	{
		sickness();
	}

	// If the random number is 2 call the attendance function
	else if (event == 2)
	{
		attendance();
	}

	//If the random number is 3 call the add babies function
	else if (event == 3)
	{
		addBabies();
	}

	// If the random number is 4 nothing happened
	else if (event == 4)
	{
		cout << "Nothing Happened" << endl;
	}
}

