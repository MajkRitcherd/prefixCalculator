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

	void Display::displayResult(double_t& number)
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
				"\nTo show mathematical operations, enter '-io/-IO'" \
				"\nInput can be any real number, positive or negative, e.g. 5, -2.123, etc." \
				"\nAlse it can be Fraction, positive or negative, e.g. 4/5, -2/3, etc." \
				"\nBinary number, only positive, e.g. 0b01101" \
				"\nHexadecimal number, only positive, e.g. 0xF1A" \
				"\nRoman numeral, only positive exists, e.g. I, X, L, etc." << endl;
		cout << m_separationLine << endl;
	}

	void Display::displayOperators()
	{
		cout << endl << m_separationLine << endl;
		cout << "All possible operations:" \
			"\n  Arithmetic: +, -, *, /" \
			"\n  Algebra: pow, abs, sqrt, cbrt, fac" \
			"\n  Goniometric: sin, cos, tan, cotan" \
			"\n  Other: sum, prod" \
			"\n For further information, check documentation!" << endl;
		cout << m_separationLine << endl;
	}

	void Display::showHistory(Queue::LifoQueue<double_t>* history)
	{
		cout << endl << m_separationLine << endl;
		cout << "History is:\n";
		for (int i = 0; i < MAX_HISTORY; i++)
		{
			cout << "---" << endl;
			if ((*history)[i] == std::numeric_limits<double_t>::max())
				cout << "NaN" << endl;
			else
				cout << (*history)[i] << '\n';
		}
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