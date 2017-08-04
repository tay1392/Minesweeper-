/************************************************************************
* Class: Minesweeper
*
* Constructors:	
*	Minesweeper() 
*		no arg constructor
*	Minesweeper(int rows, int cols, int mines)
*		3 arg constructor
*	Minesweeper(const Minesweeper & obj)
*		copy constructor
*
* Mutators:
*	None
*
* Methods:		
*	void PlayGame()
*		Handles general flow of gameplay
*	void Driver()
*		Handles main menu and play/exit conditions
*	void DisplayWin
*		displays win message
*	void DisplayBoom
*		displays bomb message
*************************************************************************/
#ifndef MINESWEEPER_H
#define MINESWEEPER_H
#include "Board.h"
class Minesweeper
{
	public:
		Minesweeper();
		Minesweeper(int row, int col, int mines);
		void PlayGame();
		void Driver();
		void DisplayWin();
		void DisplayBoom();
		Minesweeper(const Minesweeper & obj);
		Minesweeper & operator=(const Minesweeper & rhs);
		~Minesweeper();

	private:
		Board GameBoard;
		int m_Xmove;
		int m_Ymove;
		int DriverMenu;
		int m_rows;
		int m_cols;
		int m_NumMines;
};
#endif