/************************************************************************
* Class: Exceptions
*
* Constructors:	
*	Exceptions() 
*		no arg constructor
*	Exceptions(char * msg)
*		2 arg ctor that allocates room for a message
*	Exception (const Exception & obj)
*		copy contructor allows copy's of obj's to be made
*
* Mutators:
*	void SetMessage (char * msg)
*		This mutator initializes the message to the char * msg
*	char * GetMsg()
*		This mutator returns a char * msg data member
*
* Methods:		
*	operator<<(ostream & os, const Exception & obj)
*		overloads extraction operator to allwo to cout Exception obj's
*	operator=(const Exception & obj)
*		 to allow statements like Exception1 = Exception2
*************************************************************************/

#ifndef EXCEPTIONS
#define EXCEPTIONS
#include <iostream>
using std::ostream;
class Exception
{
	public:
		Exception();
		Exception(char * msg);
		Exception(const Exception & obj);
		~Exception();
		Exception & operator=(const Exception & rhs);
		const char * GetMessage();
		void SetMessage(char * msg);
		friend ostream & operator<<(ostream & os, const Exception & obj);
	private:
		char * m_Message;
};
#endif