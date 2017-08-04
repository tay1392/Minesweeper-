#include "Exceptions.h"
#include <iostream>
using std::endl;
using std::cout;

/**************************************************************
* Purpose:  No arg constructor
*                 
* Entry:  none
*
* Exit:  constructed Exception object
****************************************************************/
Exception::Exception():m_Message('\0')
{
	//cout << "No arg Exception Ctor called." << endl;
}

/**************************************************************
* Purpose: 1 Arg Ctor to create an Exception object
*                 
* Entry: char * msg string
*
* Exit:	constructed exception obj with char * msg allocated
****************************************************************/
Exception::Exception(char * msg)
{
	//cout << "1 arg exception Ctor called." << endl;
	m_Message = new char[strlen(msg) + 1];
	strcpy(m_Message, msg);
}

/**************************************************************
* Purpose: 1 Arg Ctor to create an Exception object
*                 
* Entry: char * msg string
*
* Exit:	constructed exception obj with char * msg allocated
****************************************************************/
Exception::Exception(const Exception & obj)
{
	//cout << "Exception copy Ctor called." << endl;

	m_Message = new char [strlen (obj.m_Message) + 1];
	strcpy(m_Message, obj.m_Message);
}

/**************************************************************
* Purpose: Destructor
*                 
* Entry: none
*
* Exit:	Destructed Exception obj
****************************************************************/
Exception::~Exception()
{
	delete [] m_Message;
	//cout << "Exception Dtor called" << endl;
}
/**************************************************************
* Purpose: allow ability to be equal to another exception obj
*                 
* Entry: const Exception obj by reference
*
* Exit:	returns a *this to left hand object that called the =
****************************************************************/
Exception & Exception::operator=(const Exception & rhs)
{
	//cout << "Exception assignment operator called." << endl;

	if(this != & rhs)
	{
		if(strlen(rhs.m_Message) != strlen(m_Message))
		{
			delete [] m_Message;
			m_Message = new char[strlen(rhs.m_Message) + 1];
		}
		strcpy(m_Message, rhs.m_Message);
	}
	return * this;
}

/**************************************************************
* Purpose: to receive the m_Message
*                 
* Entry:none
*
* Exit:	returns a char * message
****************************************************************/
const char * Exception::GetMessage()
{
	//cout << "Exception Getter called." << endl;
	return m_Message;
}

/**************************************************************
* Purpose: Set the m_message to the char * msg
*                 
* Entry: char * msg 
*
* Exit:	m_message set to msg
****************************************************************/
void Exception::SetMessage(char * msg)
{
	//cout << "Exception Setter called." << endl;
	if(strlen(m_Message) != strlen(msg))
	{
		delete [] m_Message;
		m_Message = new char[strlen(msg) + 1];
	}
	strcpy(m_Message, msg);
}

/**************************************************************
* Purpose: to cout << Exception objects
*                 
* Entry: ostream os, const red exception obj
*
* Exit:	return os 
****************************************************************/
ostream & operator<<(ostream & os, const Exception & obj)
{
	//cout << "Overloaded << called." << endl;
	os << obj.m_Message << endl;
	return os;
}