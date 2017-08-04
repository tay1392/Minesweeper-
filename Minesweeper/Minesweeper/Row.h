/************************************************************************
* Class: Array
*
* Constructors:	
*	Row()
*		no arg constructor
*	Row(const Row & obj);
*		copy constructor
*	Row(Array2D<T> & obj, int row);
*		2 arg constructor passed an Array2d obj and rows
*
* Mutators:
*	none
*
* Methods:		
*	T & operator[] (int column)
*		overloads subscript operator to check if index is within bounds
*
*************************************************************************/
#ifndef ROW_H
#define ROW_H

template <typename T>
class Array2D;

template <typename T>
class Row
{
	public:
		Row();
		Row(const Row & obj);
		Row(Array2D<T> & obj, int row);
	    T & operator[] (int column);
		T & operator[] (int column) const;
	private:
	    Array2D<T> & m_array2D; 
		int m_row;
};


template<typename T>
Row<T>::Row():m_row(0)
{
	//cout << "No arg Row class Ctor." << endl;
}

template <typename T>
Row<T>::Row(Array2D<T> & obj, int row)
	:m_row(row), m_array2D(obj)
{
	//cout << "2 arg Row Ctor" << endl;
}

template <typename T>
Row<T>::Row(const Row & obj)
	:m_row(obj.m_row), m_array2D(obj.m_array2D)
{
	//cout << "Row copy ctor" << endl;
}

template <typename T>
T & Row<T>::operator[] (int column)
{
	//cout << "Overloaded [ ] operator ROW called." << endl;
	return m_array2D.Select(m_row, column);
}

template <typename T>
T & Row<T>::operator[] (int column) const
{
	//cout << "Overloaded [ ] operator ROW called." << endl;
	return m_array2D.Select(m_row, column);
}
#endif