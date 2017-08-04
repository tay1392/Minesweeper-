#include "Minesweeper.h"
#include <iostream>
#include <Windows.h>

HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
const int MYCOLOR = 15;

using std::cout;
using std::cin;
using std::endl;

/**************************************************************
* Purpose:  no arg constructor 
*                 
* Entry:  none
*
* Exit:  constructed Minesweeper object
****************************************************************/
Minesweeper::Minesweeper()
	:m_Xmove(0), m_Ymove(0), DriverMenu(0)
{

}
/**************************************************************
* Purpose:  3 arg constructor
*                 
* Entry:  none
*
* Exit:  constructed Minesweeper object
****************************************************************/
Minesweeper::Minesweeper(int rows, int cols, int mines)
	:m_Xmove(0), m_Ymove(0), m_NumMines(mines),
	m_rows(rows), m_cols(cols), GameBoard(rows, cols)
{

}
/**************************************************************
* Purpose: Driver file to handle Game difficulty 
*		   and Play again or exit cases 
*
* Entry:  none
*
* Exit: starts a game or exits
****************************************************************/
void Minesweeper::Driver()
{
	SetConsoleTextAttribute(handle, MYCOLOR);
	char choice = '\0';
	bool again = false;

	while(again == false)
	{
		system("CLS");
		cout << "***********************" << endl;
		cout << "WELCOME TO MINESWEEPER!" << endl;
		cout << "***********************" << endl;
		cout << "\n1. Easy 10 x 10, 10 mines"
			 << "\n2. Intermediate 16 x 16, 40 mines" 
			 << "\n3. Hard 16 x 30, 100 mines" << endl;
		cout << "\nEnter your selection: ";
		cin >> DriverMenu;

		if(DriverMenu >= 1 || DriverMenu <= 3)
		{
			if(DriverMenu == 1)
			{
				//easy 10 x 10 10 mines
				Minesweeper Easy(10, 10, 10);
				Easy.PlayGame();
			}
			else if(DriverMenu == 2)
			{
				//medium 16 x 16 40 mines
				Minesweeper Intermediate(16, 16, 30);
				Intermediate.PlayGame();
			}
			else if(DriverMenu == 3)
			{
				//hard 16 x 30 100 mines
				Minesweeper Hard(16, 30, 100);
				Hard.PlayGame();
			}
		}
		else
		{
			cout << "Invalid choice. Please try again: ";
			cin >> DriverMenu;
			again = false;
		}

		system("CLS");
		cout << "Would you like to play again (Y/N) ?" << endl;
		cin >> choice;
		if(choice == 'y' || choice == 'Y')
		{
			again = false;
		}
		else
		{
			again = true;
		}
	}
	cout << "\nGoodbye!" << endl;
}

/**************************************************************
* Purpose: controls the flow of one game playthrough,
*			determines win/lose situations and
*			when to call which function
*
* Entry:  none
*
* Exit: One completed game
****************************************************************/
void Minesweeper::PlayGame()
{	
	bool done = false;

	try
	{
		//Place bombs on board
		GameBoard.PlaceBombs(m_rows, m_cols, m_NumMines);
		system("CLS");

		//calculate number of mines each cell is touching
		GameBoard.CountAdjacent(m_rows, m_cols);

		//display game board
		GameBoard.Display();
		
		//protect from out of bounds choice
		while(done == false)
		{
			if(GameBoard.CheckWin(m_NumMines) == true)
			{
				this->DisplayWin();
				done = true;
			}
			cout << "\nSPACES LEFT TO REVEAL: " << GameBoard.GetSpacesLeft() << endl;
			//ask user for first move
			cout << "Enter your Y - Coordinate (Row) : ";
			cin >> m_Xmove;
			cout << "Enter your X - Coordinate (Column) : ";
			cin >> m_Ymove;
			char f_or_s = '\0';
			//check if valid
			if(m_Xmove >= 0 && m_Xmove < m_rows && m_Ymove >= 0 && m_Ymove < m_cols)
			{  
				cout << "Do you want to flag or select the cell (F/S): ?";
				cin >> f_or_s;

				if(f_or_s == 'F' || f_or_s == 'f')
				{
					GameBoard.Flag(m_Xmove, m_Ymove);
					system("CLS");
					GameBoard.Display();
				}
				else
				{
					//check if bomb - if true - exit loop and call LOSE
					if(GameBoard.CheckBomb(m_Xmove, m_Ymove) == true)
					{
						this->DisplayBoom();
						done = true;
					}
					//check if win - if true - exit loop and call WIN
					if (GameBoard.CheckWin(m_NumMines) == true)
					{
						this->DisplayWin();
						done = true;
					}
					//check if single - Reveal Single Cell
					if(GameBoard.CheckSingle(m_Xmove, m_Ymove) == true)
					{
						system("CLS");
						GameBoard.Display();
					}
					else
					{   //Call reveal if not single
						GameBoard.Reveal(m_Xmove, m_Ymove);
						system("CLS");
						GameBoard.Display();
					}
				}
			}
			else
			{
				cout << "Invalid Coordinates! Try again: " << endl;
				cout << "Enter your Y - Coordinate (Row) : ";
				cin >> m_Xmove;
				cout << "Enter your X - Coordinate (Column) : ";
				cin >> m_Ymove;
			}
		}
	}	
	catch(Exception ex)
	{
		cout << ex << endl;
	}
}

/**************************************************************
* Purpose:  Display winning message
*                 
* Entry:  none
*
* Exit: none
****************************************************************/
void Minesweeper::DisplayWin()
{
	cout << "*****************************" << endl;
	cout << "YOU SURVIVED THE MINEFIELD!!!" << endl;
	cout << "*****************************" << endl;
	cout << "\nTo play again, press any key" << endl;
	system("Pause");
	this->Driver();
}
/**************************************************************
* Purpose:  Display losing message
*                 
* Entry:  none
*
* Exit: none
****************************************************************/
void Minesweeper::DisplayBoom()
{
	system ("CLS");
	GameBoard.Display();
	cout << "***********************" << endl;
	cout << "BOOM!!! YOU HIT A MINE!" << endl;
	cout << "***********************" << endl;

	cout << "\nTo play again, press any key" << endl;
	system("Pause");
	this->Driver();
}
/**************************************************************
* Purpose:  Destructor
*                 
* Entry:  none
*
* Exit: none
****************************************************************/
Minesweeper::~Minesweeper()
{
	//Dtor
}