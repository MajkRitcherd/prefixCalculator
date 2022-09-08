#include "RomanNumeral.h"

namespace numRep
{
	RomanNumeral::RomanNumeral()
		: m_number(1) {};

	RomanNumeral::RomanNumeral(uint32_t number)
		: m_number(number) {};
	
	RomanNumeral::RomanNumeral(std::string& str)
		: m_number(p_getNumber(str)) {};

	uint32_t RomanNumeral::p_getNumber(std::string& str)
	{
		uint32_t res = 0;

		for (size_t i = 0; i < str.length(); i++)
		{
			uint32_t num1 = p_getDigit(str[i]);

			if (i + 1 < str.length())
			{
				uint32_t num2 = p_getDigit(str[i + 1]);

				if (num1 >= num2)
					res += num1;
				else
				{
					res = res + num2 - num1;
					i++;
				}
			}
			else
				res += num1;
		}

		return res;
	}

	uint32_t RomanNumeral::p_getDigit(char c)
	{
		uint32_t res = 0;

		switch (c)
		{
		case 'I':
			res += 1;
			break;
		case 'V':
			res += 5;
			break;
		case 'X':
			res += 10;
			break;
		case 'L':
			res += 50;
			break;
		case 'C':
			res += 100;
			break;
		case 'D':
			res += 500;
			break;
		case 'M':
			res += 1000;
			break;
		default:
			break;
		}

		return res;
	}

	RomanNumeral RomanNumeral::operator+(RomanNumeral& num)
	{
		return RomanNumeral(this->m_number + num.m_number);
	}

	RomanNumeral RomanNumeral::operator-(RomanNumeral& num)
	{
		return RomanNumeral(this->m_number - num.m_number);
	}

	RomanNumeral RomanNumeral::operator*(RomanNumeral& num)
	{
		return RomanNumeral(this->m_number * num.m_number);
	}

	RomanNumeral RomanNumeral::operator/(RomanNumeral& num)
	{
		return RomanNumeral((uint32_t)round(this->m_number / num.m_number));
	}

	int32_t RomanNumeral::operator<=>(RomanNumeral& num)
	{
		if (this->m_number < num.m_number)
			return -1;
		else if (this->m_number > num.m_number)
			return 1;
		else
			return 0;
	}

	uint32_t stringToRoman(std::string& str)
	{
		RomanNumeral rn(str);
		return rn.getRomanNumeral();
	}
}