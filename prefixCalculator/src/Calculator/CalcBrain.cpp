#include "CalcBrain.h"
#include "../NumberRepresentations/Fraction.h"
#include "../NumberRepresentations/RomanNumeral.h"


namespace prefixCalculator
{
// TO-DO
// Check input for roman numerals, no more than 3 same digits

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

		// Main loop of the application
		while (!m_stopRunning)
		{
			std::getline(std::cin, input);
			copyOfInput = input;
			copyOfInput.erase(remove(copyOfInput.begin(), copyOfInput.end(), ' '), copyOfInput.end());
			copyOfInput.erase(remove(copyOfInput.begin(), copyOfInput.end(), '\t'), copyOfInput.end());
			std::transform(copyOfInput.begin(), copyOfInput.end(), copyOfInput.begin(), [](unsigned char c) {return std::tolower(c); });

			// Checks for control commands, otherwise calculates
			if (copyOfInput == "-i")
			{
				m_display->displayInfo();
				continue;
			}
			else if (copyOfInput == "-io")
			{
				m_display->displayOperators();
				continue;
			}
			else if (copyOfInput == "-h")			{
				m_display->showHistory(m_history);
				continue;
			}
			else if (copyOfInput == "-c")
			{
				m_history->clear();
				std::cout << "History cleared" << std::endl;
				continue;
			}
			else if (copyOfInput == "-q")
			{
				p_stop();
				continue;
			}
			else if (!p_extractComponents(input))
			{
				this->p_clearStack();
				std::cout << "\nYou've entered wrong input!" << std::endl;
			}
		}
	}

	void CalcBrain::p_stop()
	{
		delete m_regexCheck;
		m_stopRunning = !m_stopRunning;
	}

	float_t CalcBrain::p_calculate(float_t num1, float_t num2, std::string& op)
	{
		using namespace numRep::oper;
		float_t res = 0.0;
		opCode code = getCode(op);

		switch (code)
		{
		case plus:
			res = num2 + num1;
			break;
		case minus:
			res = num2 - num1;
			break;
		case multiply:
			res = num2 * num1;
			break;
		case divide:
			res = num2 / num1;
			break;
		case power:
			res = pow(num2, num1);
			break;
		case modulo:
			res = fmod(num2, num1);
			break;
		case absolute:
			res = abs(num1);
			break;
		case squareRoot:
			res = sqrt(num1);
			break;
		case cubicRoot:
			res = cbrt(num1);
			break;
		case factorial:
			res = fac(num1);
			break;
		case logarithm:
			res = log10(num1);
			break;
		case nLogarithm:
			res = log(num1);
			break;
		case sinus:
			res = sin(num1);
			break;
		case cosinus:
			res = cos(num1);
			break;
		case tangent:
			res = tan(num1);
			break;
		case cotangent:
			res = cos(num1) / sin(num1);
			break;
		default:
			throw std::runtime_error("Operation is unknown!!");
		}

		return res;
	}

	bool CalcBrain::p_extractComponents(std::string& str)
	{
		char c = 0;
		std::string number;
		int start, size = 0;
		int i = (int)str.length() - 1;

		//if (i == 0)
		//	if (str[0] >= 0 && str[0] <= 47 && str[0] >= 58 && str[0] <= 255)
		//		return false;

		// Checks string and calculates the result
		while (i >= -1)
		{
			bool isINegative = (i == -1);
			if (i >= 0)
				c = str[i];

			// Add it to stack (may be operator or number)
			if (isINegative || isspace(c))
			{
				if (isINegative)
					start = 0;
				else
					start = i + 1;

				number = str.substr(start, size);
				auto iter = m_regexCheck->checkPattern(number);
				if (!m_regexCheck->isEnd(iter))
				{
					if (numRep::oper::isOperator(number) || numRep::oper::isSingleOperator(number) || (numRep::oper::isAllOperator(number) && isINegative))
					{
						if (start == 0 && m_stack->size() == 2)
							p_stackComputation(number);
						else if (m_stack->size() < 2 && !(numRep::oper::isSingleOperator(number) || numRep::oper::isAllOperator(number)))
							return false;
						else
						{
							p_stackComputation(number);
						}

						if (start == 0 && m_stack->size() > 1)
							return false;
					}
					//else if ((!(numRep::oper::isOperator(number) || numRep::oper::isSingleOperator(number) || numRep::oper::isAllOperator(number)) && isINegative))
						//return false;
					else if (numRep::oper::isAllOperator(number) && !isINegative)
					{
						return false;
					}
					else
					{
						m_stack->push(p_stringToFloat(number, iter->first));
					}
				}
				else
					return false;

				size = 0;
				i--;
				continue;
			}
			else if (checkConditions(c))
			{
				size++;
				i--;
				continue;
			}
			else if (checkBinOrHex(c, str[i - 1]))
			{
				size += 2;
				i -= 2;
				continue;
			}
			return false;
		}
		m_history->push(m_stack->top());
		m_display->displayResult(m_stack->top());
		this->p_clearStack();

		return true;
	}

	void CalcBrain::p_stackComputation(std::string& op)
	{
		using namespace numRep::oper;
		float_t num1 = 0, num2 = 0, res = 0;

		if (!isAllOperator(op))
		{
			if (!isSingleOperator(op))
			{
				num2 = m_stack->top();
				m_stack->pop();
			}

			num1 = m_stack->top();
			m_stack->pop();
			res = p_calculate(num1, num2, op);
			m_stack->push(res);
		}
		else
		{
			bool isSum = getCode(op) == summation;

			if (!isSum)
				res = 1;

			while (!m_stack->empty())
			{
				if (isSum)
					res += m_stack->top();
				else
					res *= m_stack->top();

				m_stack->pop();
			}

			m_stack->push(res);
		}
	}

	float_t CalcBrain::p_stringToFloat(std::string& str, const std::string& key)
	{
		float_t res = 0;
		int type = 0;
		auto patterns = m_regexCheck->getKeys();
		numRep::Fraction fraction;
		numRep::RomanNumeral roman;

		for (auto it = patterns.begin(); it != patterns.end(); it++)
		{
			if (*it == key)
				break;
			type++;
		}
		switch (type)
		{
		case 0: // Convert binary string number to number
			str = str.substr(2);
			res = (float_t)std::stoi(str, nullptr, 2);
			break;
		case 1: // Convert constant to number
			if (str == "pi")
			{
				res = (float_t)std::numbers::pi;
				break;
			}
			else if (str == "e")
			{
				res = (float_t)std::numbers::e;
				break;
			}
			else
			{
				res = (float_t)std::numbers::phi; // Golden ratio constant
				break;
			}
		case 2: 
			res = std::stof(str);
			break;
		case 3: // Convert fraction string to number
			fraction = numRep::stringToFrac(str);
			res = (float_t)fraction.getNumerator() / fraction.getDenominator();
			break;
		case 4: // Convert hexadecimal string number to number
			str = str.substr(2);
			res = (float_t)std::stoi(str, nullptr, 16);
			break;
		case 5: // leave operation
			break;
		case 6: // Convert roman numeral string to number
			roman = numRep::RomanNumeral(str);
			res = (float_t)numRep::stringToRoman(str);
			break;
		case 7:
			res = (float_t)std::stoi(str);
			break;
		default:
			break;
		}

		return res;
	}

	void CalcBrain::p_clearStack()
	{
		while (!m_stack->empty())
			m_stack->pop();
	}


	// Useful functions

	bool checkConditions(char& c)
	{
		char allowedChars[25] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'w', '+', '-', '*', '/', '.'};
		for (int i = 0; i < 25; i++)
			if (c == allowedChars[i])
				return true;
		return isdigit(c) || prefixCalculator::isHexadecimalCharacter(c) ||
			prefixCalculator::isRomanNumeral(c) || false;
	}

	bool checkBinOrHex(char& c, char& num)
	{
		return (c == 'b' || c == 'x') && num == '0';
	}

	bool isRomanNumeral(char c)
	{
		return c == 'I' || c == 'V' || c == 'X' || c == 'L' || c == 'C' || c == 'D' || c == 'M';
	}

	bool isHexadecimalCharacter(char c)
	{
		return c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F';
	}

	float_t fac(float_t num)
	{
		if (num == 0)
			return 1;
		return num * fac(num - 1);
	}
}