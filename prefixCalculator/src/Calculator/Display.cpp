#include "Display.h"
#include <iomanip>

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
		std::cout << std::setprecision(15) << *m_result << std::endl;
	}

	void Display::displayInfo()
	{
		cout << m_separationLine << endl;
		cout << "|                                    INFO                                      |" << endl;
		cout << "|------------------------------------------------------------------------------|\n" \
				"|                                                                              |\n"
				"|  - To see history of results, enter '-h/-H'                                  |\n" \
				"|  - To clear the history, enter '-c/-C'                                       |\n" \
				"|  - To show mathematical operations, enter '-io/-IO'                          |\n" \
				"|  - To save result, enter '-s/-S'                                             |\n" \
				"|  - To show saved results and their positions, enter '-ssr/-SSR'              |\n" \
				"|  - To update currency exchanges, enter '-u/-U'                               |\n" \
				"|  - Usage of saved results: '+ s0 s1' sums saved number at                    |\n" \
				"|      position s0 and s1                                                      |\n";
		cout << "|                                                                              |\n" \
				"|                                                                              |\n" \
				"| Input can be any real number, positive or negative, e.g. 5, -2.123, etc.     |\n" \
				"| Alse it can be Fraction, positive or negative, e.g. 4/5, -2/3, etc.          |\n" \
				"| Binary number, only positive, e.g. 0b01101                                   |\n" \
				"| Hexadecimal number, only positive, e.g. 0xF1A                                |\n" \
				"| Roman numeral, only positive exists, e.g. I, X, L, etc.                      |\n" \
				"|                                                                              |\n";
		cout << m_separationLine << endl;
	}

	void Display::displayOperators()
	{
		cout << endl << m_separationLine << endl;
		cout << "|                                  OPERATOR                                    |" << endl;
		cout << "|------------------------------------------------------------------------------|\n" \
				"|                                                                              |\n";
		cout << "| All possible operations are:                                                 |\n" \
				"|    - Arithmetic: +, -, *, /                                                  |\n" \
				"|    - Algebra: pow, abs, sqrt, cbrt, fac                                      |\n" \
				"|    - Goniometric: sin, cos, tan, cotan                                       |\n" \
				"|    - Currency: cz-eu, cz-do, cz-po, eu-cz, eu-do                             |\n" \
				"|                eu-po, do-cz, do-eu, do-po, po-cz                             |\n" \
				"|                po-eu, po-do                                                  |\n" \
				"|    - Other: sum, prod                                                        |\n" \
				"| For further information, check documentation!                                |\n" \
				"|                                                                              |\n";
		cout << m_separationLine << endl;
	}

	void Display::showHistory(Queue::LifoQueue<double_t>* history)
	{
		cout << endl << m_separationLine << endl;
		cout << "|                                  HISTORY                                     |\n" \
				"|------------------------------------------------------------------------------|\n" \
				"|                                                                              |\n";
		for (int i = 0; i < MAX_HISTORY; i++)
		{
			if(i != 0)
				cout << "|------------------                                                            |" << endl;
			if ((*history)[i] == std::numeric_limits<double_t>::max())
				cout << "| NaN                                                                          |" << endl;
			else
				cout << "| " << std::left << std::setfill(' ') << std::setw(77) << (*history)[i] << "|\n";
		}
		cout << "|                                                                              |\n";
		cout << m_separationLine << endl;
	}

	void Display::showFirstHelp()
	{
		cout << m_separationLine << endl;
		cout << "|                         Welcome to prefixCalculator!                         |\n" \
				"|------------------------------------------------------------------------------|\n" \
				"|                                                                              |\n" \
				"| This calculator works with these number types:                               |\n" \
				"|    - Whole numbers (can be negative)                                         |\n" \
				"|    - Fractions (can be negative), e.g. 4/5, -2/3                             |\n" \
				"|    - Roman numerals, e.g. XVII                                               |\n" \
				"|    - Binary numbers, e.g. 0b0101                                             |\n" \
				"|    - Hexadecimal numbers, e.g. 0xA5                                          |\n" \
				"|    - Saved numbers, e.g. s0, s1, s2, ... (as many as you wish)               |\n" \
				"| Be aware of case sensitivity!! ('a' isn't same as 'A')                       |\n" \
				"|                                                                              |\n" \
				"| For more information, enter '-i/-I'                                          |\n" \
				"| To quit enter '-q/-Q'                                                        |\n" \
				"|                                                                              |\n";
		cout << m_separationLine << endl;
	}

	void Display::showSavedResults(std::vector<double_t>& vec)
	{	
		cout << m_separationLine << endl;
		cout << "|                                Saved results!                                |\n" \
				"|------------------------------------------------------------------------------|\n" \
				"|                                                                              |\n";

		for (auto i = 0; i < vec.size(); i++)
			cout << "|  s" << i << ": " << std::left << std::setfill(' ') << std::setw(72) << vec[i] << "|\n";

		cout << "|                                                                              |\n";
		cout << m_separationLine << endl;
	}
}