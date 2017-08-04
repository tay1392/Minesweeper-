#include "Cell.h"
#include <iostream>
#include <Windows.h>

HANDLE text = GetStdHandle(STD_OUTPUT_HANDLE);
const int MYCOLOR = 15;

using std::cout;
using std::endl;

/**************************************************************
* Purpose:  No arg constructor
*                 
* Entry:  none
*
* Exit:  constructed Cell object
****************************************************************/
Cell::Cell()
	:Bomb(false), Flag(false), Uncovered(false), 
	NumTouching(0), Covered(true), DisplayBombs(false)
{

}
void Cell::SetShowBombs()
{
	DisplayBombs = true;
}
/**************************************************************
* Purpose:  Cell Destructor
*                 
* Entry:  none
*
* Exit:  destructed cell object
****************************************************************/
Cell::~Cell()
{
	//destructor
}
/**************************************************************
* Purpose:  Copy constructor
*                 
* Entry: const ref cell object
*
* Exit:  copied cell object
****************************************************************/
Cell::Cell(const Cell & obj)
	:Bomb(obj.Bomb), Flag(obj.Flag), Uncovered(obj.Uncovered),
	Covered(obj.Covered), NumTouching(obj.NumTouching)
{

}

/**************************************************************
* Purpose:  Cell overloaded equals
*                 
* Entry:  const red cell object
*
* Exit:  returns * this 
****************************************************************/
Cell & Cell::operator=(const Cell & rhs)
{
	if(this != &rhs)
	{
		NumTouching = rhs.NumTouching;
		Bomb =rhs.Bomb;
		Flag = rhs.Flag;
		Uncovered = rhs.Uncovered;
		Covered = rhs.Covered;	
	}
	return * this;
}

/**************************************************************
* Purpose: sets bomb data member to true
*                 
* Entry:  none
*
* Exit:  Bomb data member set to true
****************************************************************/
void Cell::SetBomb()
{
	Bomb = true;
}

/**************************************************************
* Purpose:  Sets flag data member
*                 
* Entry:  none
*
* Exit:  flagged data member
****************************************************************/
void Cell::SetFlag()
{
	Flag = true;
}

/**************************************************************
* Purpose:  Sets uncovered = true and covered = false
*                 
* Entry:  none
*
* Exit:  uncovered cell 
****************************************************************/
void Cell::SetUncovered()
{
	Uncovered = true;
	Covered = false;
}

/**************************************************************
* Purpose: Increments the # of adjacent mines
*                 
* Entry:  none
*
* Exit:  incremented numtouching data member
****************************************************************/
void Cell::IncTouching()
{
	NumTouching++;
}

/**************************************************************
* Purpose:  sets cell as covered
*                 
* Entry:  none
*
* Exit:  covered cell
****************************************************************/
void Cell::SetCovered()
{
	Covered = true;
}

/**************************************************************
* Purpose:  Displays current state of a cell
*                 
* Entry:  none
*
* Exit:  cout statement to display current state
****************************************************************/
void Cell::Display()
{
	if(DisplayBombs == true)
	{
		SetConsoleTextAttribute(text, 192);
		cout << "X";
	}
	else if(Bomb == true && Flag == false)
	{
		cout << "?";
	}
	else if(Covered == true && Bomb == false && Flag == true)
	{
		SetConsoleTextAttribute(text, 12);
		cout << "F";
	}
	else if(Bomb == true && Flag == true && Covered == true)
	{
		SetConsoleTextAttribute(text, 12);
		cout << "F";
	}
	else if(Covered == true && Uncovered == false && Flag == false)
	{
		cout << "?";
	}
	else if(NumTouching > 0 && Uncovered == true && Flag == false)
	{
		for(int i = 9; i < 16; i++)
		{
			if((NumTouching + 8) == i)
			{
				SetConsoleTextAttribute(text, i);
				cout << NumTouching;
				i = 20;
			}
			else
			{
				SetConsoleTextAttribute(text, 7);
			}
		}
		
	}
	else if(Uncovered == true && NumTouching < 1)
	{
		cout << " ";
	}
	else if(Flag == false && Uncovered == true && NumTouching < 1)
	{
		cout << " ";
	}
	else if(Flag == true && Uncovered == true && NumTouching < 1)
	{
		SetConsoleTextAttribute(text, 12);
		cout << "F";
	}
	else if(Flag == true && Uncovered == true && NumTouching > 0)
	{
		SetConsoleTextAttribute(text, 12);
		cout << "F";
	}
	SetConsoleTextAttribute(text, MYCOLOR);
}

/**************************************************************
* Purpose: checks if cell's bomb is = true
*                 
* Entry:  none
*
* Exit:  true or false 
****************************************************************/
bool Cell::IsBomb()
{
	if(Bomb == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/**************************************************************
* Purpose: checks if cell's covered is = true
*                 
* Entry:  none
*
* Exit:  true or false 
****************************************************************/
bool Cell::IsCovered()
{
	if(Covered == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/**************************************************************
* Purpose: checks if cell's uncovered = true
*                 
* Entry:  none
*
* Exit:  true or false 
****************************************************************/
bool Cell::IsUncovered()
{
	if(Uncovered == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/**************************************************************
* Purpose: checks if cell's flag is = true
*                 
* Entry:  none
*
* Exit:  true or false 
****************************************************************/
bool Cell::IsFlag()
{
	if(Flag == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/**************************************************************
* Purpose: gets the data member numtouching
*                 
* Entry:  none
*
* Exit:  returns integer data member
****************************************************************/
int Cell::GetNumTouching()
{
	return NumTouching;
}
