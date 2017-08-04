/***********************************************************
* Author:				Taylor Caldwell
* Date Created:			4/5/2013
* Last Modification Date:	4/9/13
* Lab Number:			CST 211 Lab 1
* Filename:				main.cpp
*
* Overview:
*	This program emulates the classic windows Minesweeper
*	game with Ascii - based graphics. The user navigates
*	their way through the minefield by using the numbers  
*	as indications of where the bombs are on the field.
*	if the user chooses a mine as their cell to reveal,
*	they lose. If the user uncovers all cells that do not 
*	contain mines, they win. The game has easy, medium, 
*	and hard difficulty levels.
*
* Input:
*	The input for the game is a series of menu choices
*	input by the user. This includes game difficulty,
*	and the users x and y axis coordinates for their move.
*
* Output:
*	The output is based on the real minesweeper application.
*	A grid is drawn out and bombs are randomly placed. The
*	user inputs their move, and the game board is updated
*	based upon their input.
*
************************************************************/
#include <iostream>
#include "Minesweeper.h"
#include "Cell.h"
#include "Board.h"
#include "Array.h"
#include "Array2D.h"
#include "Exceptions.h"
#include <crtdbg.h> 
#define _CRTDBG_MAP_ALLOC

using std::cout;
using std::endl;
using std::cin;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Minesweeper M;
	M.Driver();

	return 0;
}