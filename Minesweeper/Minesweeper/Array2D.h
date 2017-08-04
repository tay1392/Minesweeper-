/************************************************************************
* Class: Array2D
*
* Constructors:	
*	Array2D() 
*		no arg constructor
*	Array2D(int row, int col)
*		2 arg ctor dynmically allocates 2D array length (rows * columns)
*	Array2D(const Array & obj)
*		copy contructor. Copies Array2D object
*
* Mutators:
*	void SetRow
*		This mutator changes the number of rows in the 2D array
*	void SetCol
*		This mutator changes the number of columns in the 2D array
*	int Getrows()
*		returns the number of rows
*	int Getcols()
*		returns the number of columns
*
* Methods:		
*	Row<T> & operator[](int index)
*		overloads subscript operator to check if index is within bounds
*	operator=(const Array & rhs)
*		 destroys old 2Darray and allocates a new one size of rhs
*   T & Select(int row, int col)
*		returns m_array member subscript [rows * cols + cols]
*
*************************************************************************/
#ifndef ARRAY2D_H
#define ARRAY2D_H
#include "Row.h"
#include "Array.h"
template <typename T>
class Array;

template <typename T>
class Array2D
{
	public:
		Array2D();
		Array2D(int row, int col);
		Array2D(const Array2D & obj);
		~Array2D();
		Array2D & operator=(const Array2D & rhs);
		Row<T> operator[](int index);
		Row<T> operator[](int index) const;
		int GetRow();
		int GetCol();
		void SetCol(int columns);
		void SetRow(int rows);
		T & Select(int row, int col);
		T & Select(int row, int col) const;

	private:
		int m_row;
		int m_col;
		Array<T> m_array;
};

template <typename T>
Array2D<T>::Array2D()
	:m_row(0), m_col(0), m_array(m_row * m_col)
{

}

template <typename T>
Array2D<T>::Array2D(int row = 0, int col = 0) 
	:m_col(col), m_row(row), m_array(row * col)
{

}

template <typename T>
Array2D<T>::Array2D(const Array2D & obj)
	:m_col(obj.m_col), m_row(obj.m_row), m_array(obj.m_array)
{
	
}

template <typename T>
int Array2D<T>::GetRow()
{
	return m_row;
}

template <typename T>
int Array2D<T>::GetCol()
{
	return m_col;
}

template <typename T>
Array2D<T>::~Array2D()
{
	m_col = 0;
	m_row = 0;
}

template <typename T>
Array2D<T> & Array2D<T>::operator=(const Array2D & rhs)
{
	m_col = rhs.m_col;
	m_row = rhs.m_row;
	m_array = rhs.m_array;
	return * this;
}

template <typename T>
void Array2D<T>::SetRow(int rows)
{   
	Array <T> temp;
	temp.ChangeLength(m_array, (rows * m_col));
	m_row = rows;
}

template <typename T>
Row<T> Array2D<T>::operator[](int index)
{
	return Row<T>(*this, index);
}

template <typename T>
T & Array2D<T>::Select(int row, int col)
{
	return m_array[(row * m_col) + col];
}

template <typename T>
void Array2D<T>::SetCol(int col)
{
	Array<T> temp(m_array);

	Array <T> temp2;
	temp2.ChangeLength(m_array, (m_row * m_col));

	if( m_col > col )
	{
		for( int i(0),j(0),r(0); i < temp.GetLength(); i++,j++,r++ )
		{
			if( j < m_col )
			{
				if( j < col )
					m_array[r] = temp[i];
				else
				{
					r--;
					j = -1;
				}
			}
		}
	}
	else
	{
		for( int i(0),j(0),r(0); i < m_array.GetLength(); i++,j++,r++ )
		{
			if( j < col )
			{
				if( j < m_col )
					m_array[i] = temp[r];
				else
				{
					m_array[i] = T();
					r--;
				}
			}
			else
			{
				j = -1;
				r--;
				i--;
			}
		}
	}
	m_col = col;
}

template <typename T>
Row<T> Array2D<T>::operator[](int index) const
{
	return Row<T>(*this, index);
}

template <typename T>
T & Array2D<T>::Select(int row, int col) const
{
	return m_array[(row * m_col) + col];
}
#endif