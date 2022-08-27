#include "Display.h"

using std::cout, std::endl;

namespace prefixCalculator
{
	Display::Display()
	{
		m_separationLine = "================================================================================";
	}

	Display::~Display()
	{
	}

	void Display::displayResult(float_t& number)
	{
		m_result = &number;
		std::cout << *m_result << std::endl;
	}

	void Display::displayInfo()
	{
		// to show history enter h
		cout << endl << m_separationLine << endl;
		cout << "To see history of results, enter '-h/-H'" \
				"\nTo clear the history, enter '-c/-C'" \
				"\nInput can be any real number, positive or negative, e.g. 5, -2.123, etc." \
				"\nAlse it can be Fraction, positive or negative, e.g. 4/5, -2/3, etc." \
				"\nBinary number, only positive, e.g. 0b01101" \
				"\nHexadecimal number, only positive, e.g. 0xF1A" \
				"\nRoman numeral, only positive exists, e.g. I, X, L, etc." \
				"\nList of operations: +, -, *, /, abs, pow, sqrt, cbrt, fac, sin, cos, tan, cotan" \
				"\n+, -, *, /, pow require 2 numbers, others require 1 number." << endl;
		cout << m_separationLine << endl;
	}

	void Display::showFirstHelp()
	{
		cout << m_separationLine << endl;
		cout << "\t    Welcome to prefixCalculator!" << endl;
		cout << m_separationLine << endl;
		cout << "This calculator can work only with:" << endl;
		cout << "\tWhole numbers (can be negative),\n\tFractions (can be negative), e.g. 4/5,\n\tRoman numerals, e.g. XVII,\
			\n\tBinary numbers, e.g. 0b0101,\n\tHexadecimal numbers, e.g. 0xA5" << endl;
		cout << "Be aware of Case sensitivity!! ('a' isn't same as 'A')" << endl;
		cout << "\nFor more information enter '-i/-I'" << endl;
		cout << "\nTo quit enter '-q/-Q'" << endl;
		cout << m_separationLine << endl;
	}
}