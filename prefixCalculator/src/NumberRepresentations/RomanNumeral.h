#pragma once

#include "../Pch.h"

namespace numRep
{
//========================================================================
//																		  
//		Class representing roman numerals with operations
//        ! be aware of dividing, it rounds the result !					  
//																		  
//========================================================================
	class RomanNumeral
	{
	public:
		RomanNumeral();
		RomanNumeral(uint32_t number);
		RomanNumeral(std::string& str);

		RomanNumeral operator+(RomanNumeral& num);
		RomanNumeral operator-(RomanNumeral& num);
		RomanNumeral operator*(RomanNumeral& num);
		RomanNumeral operator/(RomanNumeral& num);
		int32_t operator<=>(RomanNumeral & num);

		uint32_t getRomanNumeral() { return m_number; }

	private:
		uint32_t p_getNumber(std::string& str);
		uint32_t p_getDigit(char c);

	private:
		uint32_t m_number;
	};

	uint32_t stringToRoman(std::string& str);
}