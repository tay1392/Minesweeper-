#include "Board.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::endl;

/**************************************************************
* Purpose:  No arg constructor - base member
*                 
* Entry:  none
*
* Exit:  constructed Board object
****************************************************************/
Board::Board()
	:m_XGRID(0), m_YGRID(0), V(179), H(196), TL(218),
	TR(191), BL(192), BR(217), TI(194), BI(193),
	MI(197), RI(180), LI(195), GameArray(0,0)
{
	//cout << "No Arg Board constructed." << endl;
}

/**************************************************************
* Purpose:  2 arg constructor - base member
*                 
* Entry:  none
*
* Exit:  constructed Board object
****************************************************************/
Board::Board(int rows, int cols)
		:m_XGRID(cols), m_YGRID(rows), V(179), H(196), TL(218), //correct
	TR(191), BL(192), BR(217), TI(194), BI(193),
	MI(197), RI(180), LI(195), GameArray(rows, cols)
{
	if(rows == 10 && cols == 10)
	{
		SpacesLeft = 90;
	}
	else if(rows == 16 && cols == 16)
	{
		SpacesLeft = 216;
	}
	else if(rows == 16 && cols == 30)
	{
		SpacesLeft = 380;
	}
	//cout << "2 Arg board Constructed." << endl;
}
/**************************************************************
* Purpose:  Display a game grid with each square
*           showing corresponding 2Darray element      
*			
* Entry:  none
*
* Exit:  Game board displayed to screen
****************************************************************/
void Board::Display()
{
	int x_cord = 0;
	int count = 0;
	int spacecount = 0;
	int j = 0;
	int midend = 0;
	//displaying index
	cout << "    ";
	for(int i = 0; i < m_XGRID; i++)
	{
		if(x_cord < 10)
		{
		cout << x_cord << "  ";
		x_cord++;
		}
		else
		{
		cout << x_cord << " ";
		x_cord++;
		}
	}
	//top left
	cout << endl;
	cout << "   " << (TL);
	//one row
	for(int i = 0; i < m_XGRID - 1; i++)
	{
		//top
		cout << H <<  H  <<  TI ;
	}
	//end top right
	cout <<  H <<  H<<  TR << endl;
	//middle
	for(j = 0; j < m_YGRID - 1; j++)
	{
		cout << j;
		for(int i = 0; i < m_XGRID; i++)
		{
			//middle
			if (j < 10)
			{

				if(spacecount >= 1)
				{
					GameArray[j][i -1].Display();
					cout << " " << V ; // if >= 10!! one less space // use original display	
				}
				else
				{
				cout << "  " << V ; // if >= 10!! one less space
				spacecount++;
				}
				midend = i;
			}
			else if(j >= 10)
			{
				if(count >= 1)
				{
					GameArray[j][i -1].Display();
					cout << " " << V ;
				}
				else
				{
					cout << " " << V ;
					count++;
				}
			}
		}
		count = 0;
		//end middle
		GameArray[j][midend].Display();
		 cout << " " << V << endl;
		//middle intersection
		cout << "   " <<  (LI);
		for(int i = 0; i < m_XGRID - 1; i++)
		{
			cout <<  H <<  H <<  MI;
		}
		cout <<  H <<  H <<  RI << endl;
		spacecount = 0;
	}
	//bottom middle
	midend = 0;
	int sc = 0;
	cout << j;
	for(int i = 0; i < m_XGRID + 1; i++)
	{
		if( j > 10)
		{
			if(sc >= 1)
			{
				GameArray[j][midend].Display();
				cout << " " << V;
				midend++;
			}
			else
			{
				cout << " " <<  V;
				sc++;
			}
		}
		else
		{
			if(sc >= 1)
			{
				GameArray[j][midend].Display();
				cout << " " << V ;// >than 10 condition
				midend++;
			}
			else
			{
				cout << "  " << V ;// >than 10 condition
				sc++;
			}
		}
	}
	cout << endl << "   "<<  BL;

	//bottom
	for(int i = 0; i < m_XGRID - 1; i++)
	{
		cout <<  H <<  H<<  BI;
	}
	//bottom right
	cout <<  H <<  H <<  BR << endl;
}
/**************************************************************
* Purpose:  Randomly place bombs throughout minefield
*                 
* Entry:  rows, cols, number of mines to be placed
*
* Exit:  Bombs placed all around minefield
****************************************************************/
void Board::PlaceBombs(int rows, int cols, int mines)
{
	cout << "Placing bombs!" << endl;

	srand(time(0));
	int Rand_x;
	int Rand_y;
	bool end = false;

	for(int i = 0; i < mines; i++)
	{

		Rand_x = rand() % rows;
		Rand_y = rand() % cols;

		if(GameArray[Rand_x][Rand_y].IsBomb() == false)
		{
			GameArray[Rand_x][Rand_y].SetBomb();
		}
		else
		{
			i--;
		}
	}
}

/**************************************************************
* Purpose: to recursively display all blank squares adjacent to
*		   the one uncovered by user input
*                 
* Entry:  x and y coordinates
*
* Exit:  All adjacent blank squares revealed
****************************************************************/
void Board::Reveal(int x, int y)
{
	GameArray[x][y].SetUncovered();
	SpacesLeft--;

    for(int i = x - 1; i < x +2; i++)
	{
		for(int j = y -1; j < y +2; j++)
		{    //to uncover the surround cells with Number of mines touching it > 0
			if(i >= 0 && i < m_YGRID && j >= 0 && j < m_XGRID 
			   &&GameArray[i][j].GetNumTouching() > 0  
			   && GameArray[i][j].IsCovered() == true)
			{
				GameArray[i][j].SetUncovered();
				SpacesLeft--;
			}
		}
	} 

	//system("CLS");
	//this->Display();
	if(GameArray[x][y].GetNumTouching() < 1)
	{
		for(int r = x - 1; r < x + 2; r++)
		{
			for(int c = y - 1; c < y + 2; c++)
			{       //within bounds
				if(r >= 0 && r < m_YGRID && c >= 0 && c < m_XGRID 
					&& GameArray[r][c].IsCovered() == true //must be covered
					&& GameArray[r][c].IsFlag() == false// must not be flagged
					&& GameArray[r][c].GetNumTouching() < 1) 
				{
					Reveal(r, c); //actual recursive call
				}
			}
		}
	}
}

/**************************************************************
* Purpose: Sets Flag at given square
*                 
* Entry: x and y coordinates
*
* Exit: Flagged square
****************************************************************/
void Board::Flag(int x, int y)
{
	GameArray[x][y].SetFlag();
}

/**************************************************************
* Purpose: counts the number of mines adjacent to non-mine cells
*                 
* Entry:  rows and columns
*
* Exit: all adjacent cells are incremented
****************************************************************/
void Board::CountAdjacent(int rows, int cols)
{
	for (int x = 0; x < m_YGRID; x++) //changed from xgrid
	{
		for (int y = 0; y < m_XGRID; y++) //changed from ygrid
		{
			if (GameArray[x][y].IsBomb() == false) 
			{
			   //TOP LEFT
				if(x > 0 && y > 0) 
				{
					if(GameArray[x-1][y-1].IsBomb() == true)
					{
						GameArray[x][y].IncTouching();
					}
				}
				//TOP
				if(x > 0) 
				{
					if(GameArray[x-1][y].IsBomb() == true)
					{
						GameArray[x][y].IncTouching();
					}
				}
				//TOP RIGHT
				if(y < cols - 1 && x > 0) 
				{
					if(GameArray[x-1][y+1].IsBomb() == true)
					{
						GameArray[x][y].IncTouching();
					}
				}
				//RIGHT
				if(y < cols - 1)
				{
					if(GameArray[x][y+1].IsBomb() == true)
					{
						GameArray[x][y].IncTouching();
					}
				}
				//BOTTOM RIGHT
				if(x < rows - 1 && y < cols -1)
				{
					if(GameArray[x+1][y+1].IsBomb() == true)
					{
						GameArray[x][y].IncTouching();
					}
				}
				//BOTTOM
				if(x < rows - 1)
				{
					if(GameArray[x+1][y].IsBomb() == true)
					{
						GameArray[x][y].IncTouching();
					}
				}
				//BOTTOM LEFT
				if(y > 0 && x < rows -1) 
				{
					if(GameArray[x+1][y-1].IsBomb() == true)
					{
						GameArray[x][y].IncTouching();
					}
				}
				//LEFT
				if(y > 0) 
				{
					if(GameArray[x][y-1].IsBomb() == true)
					{
						GameArray[x][y].IncTouching();
					}
				}
			}
		}
	}
}

/**************************************************************
* Purpose: to determine if the player has won
*                 
* Entry:  number of mines
*
* Exit:  true or false win conclusion
****************************************************************/
bool Board::CheckWin(int mines)
{
	if(SpacesLeft < 1) //offset
	{
		return true;
	}
	else
	{
		return false;
	}
}
/**************************************************************
* Purpose: to determine if the given x and y coordinates
*		   contains a bomb          
*
* Entry:  x and y coordinates
*
* Exit:  returns true or false 
****************************************************************/
bool Board::CheckBomb(int x, int y)
{
	if(GameArray[x][y].IsBomb() == true)
	{
		this->SetAllBombs();
		return true;
	}
	else
	{
		return false;
	}
}
/**************************************************************
* Purpose: to determine if the cells Adjacent mine 
*		   counter is > 0.
*
* Entry:  none
*
* Exit:  returns a true or false
****************************************************************/
bool Board::CheckSingle(int x, int y)
{
	if(GameArray[x][y].GetNumTouching() > 0)
	{
		GameArray[x][y].SetUncovered();
		SpacesLeft--;
		return true;
	}
	else
	{
		return false;
	}
}
/**************************************************************
* Purpose: to obtain the number of spaces left for a win
*                 
* Entry:  none
*
* Exit:  returns integer of spaces left
****************************************************************/
int Board::GetSpacesLeft()
{
	return SpacesLeft;
}
/**************************************************************
* Purpose:  destructor
*                 
* Entry:  none
*
* Exit:  destructor for board object
****************************************************************/
Board::~Board()
{

}
void Board::SetAllBombs()
{
	for(int i = 0; i < m_YGRID; i++)
	{
		for(int j = 0; j < m_XGRID; j++)
		{
			if(GameArray[i][j].IsBomb() == true)
			{
				GameArray[i][j].SetShowBombs();
			}
		}
	}
}