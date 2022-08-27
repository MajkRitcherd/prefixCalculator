#include "CalcBrain.h"
#include "../NumberRepresentations/Fraction.h"
#include "../NumberRepresentations/RomanNumeral.h"


namespace prefixCalculator
{
	bool isRomanNumeral(char c);
	bool isHexadecimalCharacter(char c);

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
		float_t res = 0.0;
		opCode code = p_getCode(op);

		switch (code)
		{
		case plus:
			res = num1 + num2;
			break;
		case minus:
			res = num1 - num2;
			break;
		case multiply:
			res = num1 * num2;
			break;
		case divide:
			res = num1 / num2;
			break;
		case absolute:
			res = abs(num1);
			break;
		case power:
			res = pow(num2, num1);
			break;
		case squareRoot:
			res = sqrt(num1);
			break;
		case cubicRoot:
			res = cbrt(num1);
		case factorial:
			res = fac(num1);
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

		if (i == 0)
			if (str[0] >= 0 && str[0] <= 255)
				return false;

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
					if (number == "+" || number == "-" || number == "*" || number == "/" || 
						number == "abs" || number == "pow" || number == "sqrt" || number == "cbrt" ||
						number == "fac" || number == "sin" || number == "cos" || number == "tan" || number == "cotan")
					{
						if (start == 0 && m_stack->size() == 2)
							p_stackComputation(number);
						else if (m_stack->size() < 2 && number != "abs" && number != "sqrt" && number != "cbrt" &&
							number != "fac" && number != "sin" && number != "cos" && number != "tan" && number != "cotan")
							return false;
						else
						{
							p_stackComputation(number);
						}

						if (start == 0 && m_stack->size() > 1)
							return false;
					}
					else if ((!(number == "+" || number == "-" || number == "*" || number == "/") && isINegative))
						return false;
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
			else if (p_checkConditions(c))
			{
				size++;
				i--;
				continue;
			}
			else if (p_checkBinOrHex(c, str[i - 1]))
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
		float_t num1 = 0, num2 = 0;

		if (p_getCode(op) != absolute && p_getCode(op) != squareRoot && p_getCode(op) != cubicRoot && p_getCode(op) != factorial &&
			p_getCode(op) != sinus && p_getCode(op) != cosinus && p_getCode(op) != tangent && p_getCode(op) != cotangent)
		{
			num2 = m_stack->top();
			m_stack->pop();
		}

		num1 = m_stack->top();
		m_stack->pop();
		float_t res = p_calculate(num1, num2, op);
		m_stack->push(res);
	}

	bool CalcBrain::p_checkConditions(char& c) const
	{
		char allowedChars[20] = { 'a', 'b', 'c', 'e', 'f', 'h', 'i', 'n', 'o', 'p', 'q', 'r', 's', 't', 'w', '+', '-', '*', '/', '.' };
		for (int i = 0; i < 20; i++)
			if (c == allowedChars[i])
				return true;
		return isdigit(c) || prefixCalculator::isHexadecimalCharacter(c) ||
			prefixCalculator::isRomanNumeral(c) || false;
	}

	bool CalcBrain::p_checkBinOrHex(char& c, char& num) const
	{
		return (c == 'b' || c == 'x') && num == '0';
	}

	float_t CalcBrain::p_stringToFloat(std::string& str, const std::string& key)
	{
		float_t res = 0;
		int type = 0;
		auto patterns = m_regexCheck->getKeys();
		numberRepresentations::Fraction fraction;
		numberRepresentations::RomanNumeral roman;

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
			fraction = numberRepresentations::stringToFrac(str);
			res = (float_t)fraction.getNumerator() / fraction.getDenominator();
			break;
		case 4: // Convert hexadecimal string number to number
			str = str.substr(2);
			res = (float_t)std::stoi(str, nullptr, 16);
			break;
		case 5: // leave operation
			break;
		case 6: // Convert roman numeral string to number
			roman = numberRepresentations::RomanNumeral(str);
			res = (float_t)numberRepresentations::stringToRoman(str);
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

	CalcBrain::opCode CalcBrain::p_getCode(std::string& str)
	{
		if (str == "+") return plus;
		if (str == "-") return minus;
		if (str == "*") return multiply;
		if (str == "/") return divide;
		if (str == "abs") return absolute;
		if (str == "pow") return power;
		if (str == "sqrt") return squareRoot;
		if (str == "cbrt") return cubicRoot;
		if (str == "fac") return factorial;
		if (str == "sin") return sinus;
		if (str == "cos") return cosinus;
		if (str == "tan") return tangent;
		if (str == "cotan") return cotangent;
		else
			throw std::runtime_error("This operation is not implemented yet!!");
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