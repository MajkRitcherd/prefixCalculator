#include "CalcBrain.h"
#include "../NumberRepresentations/Fraction.h"
//#include "HelpFunctions.h"


namespace prefixCalculator
{
	bool isFraction(char chars[]);
	bool isRomanNumeral(char c);
	bool isHexadecimalCharacter(char c);


	CalcBrain::CalcBrain()
	{
		m_history = new Queue::LifoQueue<float_t>;
		float_t limit = std::numeric_limits<float_t>::max();
		for (int i = 0; i < MAX_HISTORY; i++)
			m_history->push(limit);

		m_result = 0;
		m_stack = new std::stack<float_t>;
		m_stopRunning = true;
		
		m_regexCheck = new RegexCheck();
	}

	CalcBrain::~CalcBrain()
	{
	}

	void CalcBrain::run(Display* display)
	{
		m_display = display;
		m_display->showFirstHelp();
		std::string input, copyOfInput;
		if (m_stopRunning)
			m_stopRunning = !m_stopRunning;

		while (!m_stopRunning)
		{
			std::getline(std::cin, input);
			copyOfInput = input;
			copyOfInput.erase(remove(copyOfInput.begin(), copyOfInput.end(), ' '), copyOfInput.end());
			copyOfInput.erase(remove(copyOfInput.begin(), copyOfInput.end(), '\t'), copyOfInput.end());

			if (copyOfInput == "-i" || copyOfInput == "-I")
			{
				m_display->displayInfo();
				continue;
			}
			else if (copyOfInput == "-h" || copyOfInput == "-H")
			{
				std::cout << "History is:\n";
				for (int i = 0; i < MAX_HISTORY; i++)
				{
					std::cout << "---" << std::endl;
					if ((*m_history)[i] == std::numeric_limits<float_t>::max())
						std::cout << "NaN" << std::endl;
					else
						std::cout << (*m_history)[i] << '\n';

				}
				continue;
			}
			else if (copyOfInput == "-c" || copyOfInput == "-C")
			{
				m_history->clear();
				std::cout << "History cleared" << std::endl;
				continue;
			}
			else if (copyOfInput == "-q" || copyOfInput == "-Q")
			{
				p_stop();
				continue;
			}
			else if (!p_extractComponents(input))
				std::cout << "\nYou've entered wrong input!" << std::endl;
		}
	}

	void CalcBrain::p_stop()
	{
		delete m_regexCheck;
		m_stopRunning = !m_stopRunning;
	}

	float_t CalcBrain::p_calculate(float_t num1, float_t num2, char op)
	{
		float_t res = 0.0;

		switch (op)
		{
		case '+':
			res = num1 + num2;
			break;
		case '-':
			res = num1 - num2;
			break;
		case '*':
			res = num1 * num2;
			break;
		case '/':
			res = num1 / num2;
			break;
		default:
			throw std::runtime_error("Operation is unknown!!");
		}

		return res;
	}

	bool CalcBrain::p_extractComponents(std::string& str)
	{
		char c = 0, op = 0, operand = 0;
		std::string number;
		int start, size;
		int i = (int)str.length() - 1;
		size = 0;

		// Checks string and calculates the result
		while (i >= -1)
		{
			if (i >= 0)
				c = str[i];

			// Add it to stack (may be operator or number)
			if (i == -1 || isspace(c))
			{
				if (i == -1)
					start = 0;
				else
					start = i + 1;

				number = str.substr(start, size);
				auto iter = m_regexCheck->checkPattern(number);
				if (!m_regexCheck->isEnd(iter))
				{
					if (number == "+" || number == "-" || number == "*" || number == "/")
					{
						op++;
						if (i == -1 && operand != op + 1)
							return false;
						else
						{
							float_t num1, num2;
							num1 = m_stack->top();
							m_stack->pop();
							num2 = m_stack->top();
							m_stack->pop();
							float_t res = p_calculate(num1, num2, number[0]);
							m_stack->push(res);
						}
					}
					else if ((!(number == "+" || number == "-" || number == "*" || number == "/") && i == -1))
						return false;
					else
					{
						m_stack->push(p_stringToFloat(number, iter->first));
						operand++;
					}
				}
				else
					return false;

				size = 0;
				i--;
				continue;
			}
			else if (p_checkConditions(c))
			{
				size++;
				i--;
				continue;
			}
			else if ((c == 'b' || c == 'x') && str[i - 1] == '0')
			{
				size += 2;
				i -= 2;
				continue;
			}
			return false;
		}
		m_history->push(m_stack->top());
		m_display->displayResult(m_stack->top());

		return true;
	}

	bool CalcBrain::p_checkConditions(char& c) const
	{
		return isdigit(c) || prefixCalculator::isHexadecimalCharacter(c) ||
			prefixCalculator::isRomanNumeral(c) || (c == '+' || c == '-' || c == '*' || c == '/' || c == '.');
	}

	float_t CalcBrain::p_stringToFloat(std::string& str, const std::string& key)
	{
		float_t res;
		int type = 0;
		auto patterns = m_regexCheck->getKeys();
		numberRepresentations::Fraction fraction;

		for (auto it = patterns.begin(); it != patterns.end(); it++)
		{
			if (*it == key)
				break;
			type++;
		}
		switch (type)
		{
		case 0: // Convert from string binary number to int
			str = str.substr(2);
			res = (float_t)std::stoi(str, nullptr, 2);
			break;
		case 1:
			res = std::stof(str);
			break;
		case 2: // Convert from string fraction to int
			fraction = numberRepresentations::stringToFrac(str);
			res = (float_t)fraction.getNumerator() / fraction.getDenominator();
			break;
		case 3: // Convert from string hexadecimal number to int
			str = str.substr(2);
			res = (float_t)std::stoi(str, nullptr, 16);
			break;
		case 4: // leave operation
			break;
		case 5: // Convert from string roman numeral to int
			// TO-DO
			break;
		case 6:
			res = (float_t)std::stoi(str);
			break;
		default:
			break;
		}
		return res;
	}

	bool isFraction(char chars[])
	{
		return isdigit(chars[1]) && isdigit(chars[2]);
	}

	bool isRomanNumeral(char c)
	{
		return c == 'I' || c == 'V' || c == 'X' || c == 'L' || c == 'C' || c == 'D' || c == 'M';
	}

	bool isHexadecimalCharacter(char c)
	{
		return c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F';
	}
}

bool isFraction(char chars[])
{
	return false;
}
