/******************************************************************************
** Program name : Project 2
** Author : Jeffrey Ngo
** Date : 10 / 27 / 2019
** Description : Main function call to start game
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

int main()
{
	Zoo startGame;
	startGame.start();
	return 0;
}