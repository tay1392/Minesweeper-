/************************************************************************
* Class: Board
*
* Constructors:	
*	Board() 
*		no arg constructor
*	Board(int rows, int cols)
*		2 arg ctor that initializes a 2dArray of cell objects
*		the size of (rows * columns
*	Board(const Board & obj)
*		copy contructor to create copies of board objects
*
* Mutators:
*	int GetSpacesLeft()
*		returns the number of spaces left for a win
*
* Methods:		
*	void PlaceBombs()
*		Randomly places a pre-determined number of bombs throughout
*		the 2DArray of cells
*	void CountAdjacent(int rows, int cols)
*		Counts the nmber of bombs touching the cell
*	void Reveal(int x, int y)
*		sets a given cell to revealed state
*	bool CheckWin(int mines)
*		Determines if the player has won the game
*	bool CheckBomb(int x, int y)
*		determines if the users input is a bomb
*	bool CheckSingle(int x, int y)
*		determines if the users input will display only that cell
*	void Flag(int x, int y)
*		Flags a cell with given coordinates
*	void Display(int x, int y)
*		Displays the 2D array inside a grid system the size of the
*		2D array and the cells current state
*	Board & operator=(const Board & rhs)
*		overloaded = for assigning Boards = to board objects
*************************************************************************/
#ifndef BOARD_H
#define BOARD_H
#include "Array2D.h"
#include "Cell.h"
class Board
{
	public:
		Board();
		void PlaceBombs(int rows, int cols, int mines);
		void CountAdjacent(int rows, int cols);
		void Reveal(int x, int y);
		bool CheckWin(int mines);
		bool CheckBomb(int x, int y);
		bool CheckSingle(int x, int y);
		void SetAllBombs();
		void Flag(int x, int y);
		void Display();
		int GetSpacesLeft();
		Board(int rows, int cols);
		Board(const Board & obj);
		Board & operator=(const Board & obj);
		~Board();

	private:
		Array2D <Cell> GameArray;
		int SpacesLeft;
		int m_XGRID;
		int m_YGRID;
		char V; // 179;
		char H; // 196;
		char TL; // 218;
		char TR; // 191;
		char BL; // 192;
		char BR; // 217;
		char TI; // 194;
		char BI; // 193;
		char MI; // 197;
		char RI; // 180;
		char LI; // 195;
};
#endif