#pragma once

#include <cstdint>
#include <string>

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

		RomanNumeral operator+(RomanNumeral& num) const;
		RomanNumeral operator-(RomanNumeral& num) const;
		RomanNumeral operator*(RomanNumeral& num) const;
		RomanNumeral operator/(RomanNumeral& num) const;
		int32_t operator<=>(RomanNumeral & num) const;

		uint32_t getRomanNumeral() const { return m_number; }

	private:
		uint32_t p_getNumber(std::string& str) const;
		uint32_t p_getDigit(char c) const;

	private:
		uint32_t m_number;
	};

	uint32_t stringToRoman(std::string& str);
}