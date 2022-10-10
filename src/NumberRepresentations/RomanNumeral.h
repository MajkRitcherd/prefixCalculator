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

#pragma region RomanNumralClass

	class RomanNumeral
	{
		#pragma region PublicMethods

			public:
				/// <summary>
				/// Creates roman numeral with value 1.
				/// </summary>
				RomanNumeral();

				/// <summary>
				/// Creates roman numeral from number.
				/// </summary>
				/// <param name="number:">Number represented by uint_32t.</param>
				RomanNumeral(uint32_t number);

				/// <summary>
				/// Creates roman numeral from string.
				/// </summary>
				/// <param name="str">Number represented by string.</param>
				RomanNumeral(std::string& str);

				RomanNumeral operator+(const RomanNumeral& num) const;
				RomanNumeral operator-(const RomanNumeral& num) const;
				RomanNumeral operator*(const RomanNumeral& num) const;
				RomanNumeral operator/(const RomanNumeral& num) const;
				std::strong_ordering operator<=>(const RomanNumeral& num) const;

				/// <summary>
				/// Gets value of roman numeral.
				/// </summary>
				/// <returns>Value of roman numeral.</returns>
				uint32_t getRomanNumeral() const { return m_number; }

		#pragma endregion

		#pragma region PrivateMethods
	
			private:
				/// <summary>
				/// Converts character to a number.
				/// </summary>
				/// <param name="c:">Character to convert.</param>
				/// <returns>Value of converted character represented by number.</returns>
				uint32_t p_getDigit(char c) const;

				/// <summary>
				/// Gets number from roman numeral string.
				/// </summary>
				/// <param name="str:">Roman numeral represented by a string.</param>
				/// <returns>Value of roman numeral string.</returns>
				uint32_t p_getNumber(std::string& str) const;

		#pragma endregion

		#pragma region PrivateMembers

			private:
				uint32_t m_number;

		#pragma endregion
	};

#pragma endregion

//========================================================================
//																		  
//		Other function related to the RomanNumeral class					  
//																		  
//========================================================================

	/// <summary>
	/// Converts string to roman numeral.
	/// </summary>
	/// <param name="str:">Number, represented by string, to convert.</param>
	/// <returns>Value of roman numeral.</returns>
	uint32_t stringToRoman(std::string& str);
}