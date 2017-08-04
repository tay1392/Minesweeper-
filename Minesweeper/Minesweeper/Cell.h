/************************************************************************
* Class: Cell
*
* Constructors:	
*	Cell()
*		no arg constructor
*	Cell(const Cell & obj)
*		copy contructor allows copy's of obj's to be made
*	~Cell();
*		dtor
*
*	Mutators:
*		void SetBomb();
*			Sets bomb state = true
*		void SetFlag();
*			sets flagged condition = true
*		void SetUncovered();
*			sets uncovered state = true
*		void IncTouching();
*			Increments the NumTouching data member
*		void SetCovered();
*			Sets the covered state = true
*		int GetNumTouching();
*			returns the number of mines the cell is touching
*		//methods
*
*		void Display();
*			displays the current state of the cell object
*		bool IsBomb();
*			Determines if the bomb state = true or false
*		bool IsCovered();
*			Determines if the covered state = true or false
*		bool IsUncovered();
*			Determines if the uncovered state = true or false
*		bool IsFlag();
*			Determines if the cells flag state = true or false
*************************************************************************/
#ifndef CELL_H
#define CELL_H
#include <iostream>
using std::ostream;
class Cell
{
	public:
		Cell();
		Cell(const Cell & obj);
		Cell & operator=(const Cell & obj);
		void SetBomb();
		void SetFlag();
		void SetUncovered();
		void SetShowBombs();
		void IncTouching();
		void SetCovered();
		int GetNumTouching();
		void Display();
		bool IsBomb();
		bool IsCovered();
		bool IsUncovered();
		bool IsFlag();
		~Cell();

	private:
		bool Bomb;
		bool DisplayBombs;
		bool Flag;
		bool Uncovered;
		bool Covered;
		int NumTouching;
};
#endif
