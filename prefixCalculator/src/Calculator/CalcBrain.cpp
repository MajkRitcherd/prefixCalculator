#include "CalcBrain.h"
#include "../NumberRepresentations/Fraction.h"
#include "../NumberRepresentations/RomanNumeral.h"
#include <numbers>


namespace prefixCalculator
{
	CalcBrain::CalcBrain()
	{
		m_result = 0;
		m_stopRunning = true;
		
		m_history = new Queue::LifoQueue<double_t>;
		m_history->clear();

		m_deque = new std::deque<double_t>;
		m_regexCheck = new RegexCheck();
	}

	CalcBrain::~CalcBrain()
	{
	
	}

	void CalcBrain::run(Display* display, bool education)
	{
		m_education = education;
		m_firstEducCalculation = true;
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
			cc(copyOfInput);
			copyOfInput = input;
			copyOfInput.erase(remove(copyOfInput.begin(), copyOfInput.end(), ' '), copyOfInput.end());
			copyOfInput.erase(remove(copyOfInput.begin(), copyOfInput.end(), '\t'), copyOfInput.end());
			std::transform(copyOfInput.begin(), copyOfInput.end(), copyOfInput.begin(), [](unsigned char c) { return std::tolower(c); });

			// This is not needed, I can do it with input
			//
			//std::string copyOfInput2;
			//copyOfInput2 = input;
			//copyOfInput2.erase(remove(copyOfInput2.begin(), copyOfInput2.end(), ' '), copyOfInput2.end());
			//copyOfInput2.erase(remove(copyOfInput2.begin(), copyOfInput2.end(), '\t'), copyOfInput2.end());
			//for (auto it = copyOfInput2.begin() + 1; it != copyOfInput2.end(); it += 2)
			//	copyOfInput2.insert(it, ' ');

			m_firstEducCalculation = true;

			// Checks for control commands, otherwise calculates
			if (copyOfInput == "-c")
			{
				m_history->clear();
				std::cout << "History cleared!!" << std::endl;
				continue;
			}
			else if (copyOfInput == "-h")			{
				m_display->showHistory(m_history);
				continue;
			}
			else if (copyOfInput == "-i")
			{
				m_display->displayInfo();
				continue;
			}
			else if (copyOfInput == "-io")
			{
				m_display->displayOperators();
				continue;
			}
			else if (copyOfInput == "-s")
			{
				m_savedResults.push_back(m_result);
				continue;
			}
			else if (copyOfInput == "-ssr")
			{
				m_display->showSavedResults(m_savedResults);
				continue;
			}
			else if (copyOfInput == "-u")
			{
				std::cout << "Updating";
				utilities::UpdateJson();
				std::cout << "Currencies were updated!" << std::endl;
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

	double_t CalcBrain::p_calculate(double_t num1, double_t num2, std::string& op)
	{
		using namespace numRep::oper;
		std::string curr[4] = { "eur", "czk", "gbp", "usd" };
		std::string rate = "rate";
		std::string inverseRate = "inverseRate";
		double_t res = 0.0;
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
		case czToEu:
			res = utilities::getRate(curr[0], curr[1], inverseRate) * num1;
			break;
		case czToDo:
			res = utilities::getRate(curr[1], curr[3], rate) * num1;
			break;
		case czToPo:
			res = utilities::getRate(curr[1], curr[2], rate) * num1;
			break;
		case euToCz:
			res = utilities::getRate(curr[0], curr[1], rate) * num1;
			break;
		case euToDo:
			res = utilities::getRate(curr[0], curr[3], rate) * num1;
			break;
		case euToPo:
			res = utilities::getRate(curr[0], curr[2], rate) * num1;
			break;
		case doToCz:
			res = utilities::getRate(curr[1], curr[3], inverseRate) * num1;
			break;
		case doToEu:
			res = utilities::getRate(curr[0], curr[3], inverseRate) * num1;
			break;
		case doToPo:
			res = utilities::getRate(curr[3], curr[2], rate) * num1;
			break;
		case poToCz:
			res = utilities::getRate(curr[1], curr[2], inverseRate)* num1;
			break;
		case poToEu:
			res = utilities::getRate(curr[0], curr[2], inverseRate) * num1;
			break;
		case poToDo:
			res = utilities::getRate(curr[3], curr[2], inverseRate)* num1;
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
						if (start == 0 && m_deque->size() == 2)
						{
							if (m_education)
								p_showStack();

 							p_stackComputation(number);
						}
						else if (m_deque->size() < 2 && !(numRep::oper::isSingleOperator(number) || numRep::oper::isAllOperator(number)))
							return false;
						else
						{
							if (m_education)
								p_showStack();

							p_stackComputation(number);
						}

						if (start == 0 && m_deque->size() > 1)
							return false;
					}
					else if ((numRep::oper::isAllOperator(number) && !isINegative) || !checkRomanNumeral(m_regexCheck, number))
					{
						return false;
					}
					else
					{
						if (number[0] == 's') // If input number is savedResult
						{
							int pos = std::stoi(number.substr(1));
							if (pos < 0 || pos > m_savedResults.size() - 1 || m_savedResults.empty())
								return false;
						}

						if (m_education && m_firstEducCalculation)
						{
							if (m_firstEducCalculation)
							{
								std::cout << "-----------------------------------------" << std::endl;
								std::cout << "Evaluating expression: \"" << str  << '\"' << std::endl << std::endl;
								m_firstEducCalculation = !m_firstEducCalculation;
							}

							std::cout << std::setprecision(15) << " - Push \'" << number << "\' to stack." << std::endl;
						}

						m_deque->push_front(p_stringToFloat(number, iter->first));
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
			else if (isBinOrHex(c, str[i - 1]))
			{
				size += 2;
				i -= 2;
				continue;
			}
			return false;
		}

		m_result = m_deque->at(0);
		m_history->push(m_result);
		m_display->displayResult(m_deque->at(0));
		this->p_clearStack();
		this->m_lastExpression = str;

		return true;
	}

	void CalcBrain::p_stackComputation(std::string& op)
	{
		using namespace numRep::oper;
		double_t num1 = 0, num2 = 0, res = 0;

		if (!isAllOperator(op))
		{
			if (!isSingleOperator(op))
			{
				num2 = m_deque->at(0);
				m_deque->pop_front();
			}

			num1 = m_deque->at(0);
			m_deque->pop_front();


			res = p_calculate(num1, num2, op);

			if (m_education)
			{
				if(!isSingleOperator(op))
					std::cout << std::setprecision(15) << "- Apply operator \'" << op << "\' on \'" << num2 << "\' and \'" << num1 \
						<< "\'.\n - The result is: \'" << res << "\' and add it to the stack.\n" << std::endl;
				else
					std::cout << std::setprecision(15) << "- Apply operator \'" << op << "\' on \'" << num1 \
						<< "\'.\n - The result is: \'" << res << "\' and add it to the stack.\n" << std::endl;
			}

			m_deque->push_front(res);

			if(m_education)
				p_showStack();
		}
		else
		{
			bool isSum = getCode(op) == summation;

			if (!isSum)
				res = 1;

			while (!m_deque->empty())
			{
				if (!isSum)
					res *= m_deque->at(0);
				else
					res += m_deque->at(0);

				m_deque->pop_front();
			}

			m_deque->push_front(res);
		}
	}

	double_t CalcBrain::p_stringToFloat(std::string& str, const std::string& key)
	{
		double_t res = 0;
		int type = 0, pos = -1;
		auto patterns = m_regexCheck->getKeys();
		numRep::Fraction fraction;
		numRep::RomanNumeral roman;
		std::string changedStr = str.substr(1);

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
			res = (double_t)std::stoi(str, nullptr, 2);
			break;
		case 1: // Convert constant to number
			if (str == "pi")
			{
				res = (double_t)std::numbers::pi;
				break;
			}
			else if (str == "e")
			{
				res = (double_t)std::numbers::e;
				break;
			}
			else
			{
				res = (double_t)std::numbers::phi; // Golden ratio constant
				break;
			}
		case 2: 
			res = std::stof(str);
			break;
		case 3: // Convert fraction string to number
			fraction = numRep::stringToFrac(str);
			res = (double_t)fraction.getNumerator() / fraction.getDenominator();
			break;
		case 4: // Convert hexadecimal string number to number
			str = str.substr(2);
			res = (double_t)std::stoi(str, nullptr, 16);
			break;
		case 5: // leave operation
			break;
		case 6: // Convert roman numeral string to number
			roman = numRep::RomanNumeral(str);
			res = (double_t)numRep::stringToRoman(str);
			break;
		case 7: // Returns savedResult at given position
			pos = std::stoi(changedStr);
			res = m_savedResults[pos];
			m_savedResults.erase(m_savedResults.begin() + pos);
			break;
		case 8:
			res = (double_t)std::stoi(str);
			break;
		default:
			break;
		}

		return res;
	}

	void CalcBrain::p_clearStack()
	{
		while (!m_deque->empty())
			m_deque->pop_front();
	}

	void CalcBrain::p_showStack()
	{
		int i = m_deque->size() - 1;
		std::cout << std::endl << " --STACK-- " << std::endl;
		while (i >= 0)
		{
			std::cout << "     " << m_deque->at(i) << std::endl;
			i--;
		}
		std::cout << std::endl;
	}



	// Useful functions

	bool checkConditions(char& c)
	{
		char allowedChars[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'w', 'z', '+', '-', '*', '/', '.'};
		for (int i = 0; i < 26; i++)
			if (c == allowedChars[i])
				return true;
		return isdigit(c) || prefixCalculator::isHexadecimalChar(c) ||
			prefixCalculator::isRomanNumeralChar(c) || false;
	}

	bool checkRomanNumeral(RegexCheck *regCheck, std::string& str)
	{
		auto iter = regCheck->checkPattern(str);
		if (regCheck->isEnd(iter))
			return false;

		return std::regex_match(str, iter->second);
	}

	bool isRomanNumeralChar(char c)
	{
		return c == 'I' || c == 'V' || c == 'X' || c == 'L' || c == 'C' || c == 'D' || c == 'M';
	}

	bool isHexadecimalChar(char c)
	{
		return c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F';
	}

	bool isBinOrHex(char& c, char& num)
	{
		return (c == 'b' || c == 'x') && num == '0';
	}

	double_t fac(double_t num)
	{
		if (num == 0)
			return 1;
		return num * fac(num - 1);
	}

	void cc(std::string& str)
	{
		str.erase(remove(str.begin()), str.end());
	}
}