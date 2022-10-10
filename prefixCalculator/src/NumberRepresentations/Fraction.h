#pragma once

#include <cstdint>
#include <string>

namespace numRep
{
//========================================================================
//																		  
//			Class representing fraction with operations			          
//																		  
//========================================================================
#pragma region FractionClass

	class Fraction
	{

	#pragma region PublicMethods

		public:
			/// <summary>
			/// Creates Fraction with default value 1 if unspecified.
			/// </summary>
			/// <param name="num:">Numerator.</param>
			/// <param name="den:">Denominator</param>
			Fraction(int32_t num = 1, int32_t den = 1);

			/// <summary>
			/// Creates Fraction from string.
			/// </summary>
			/// <param name="num:">Number of numerator in string.</param>
			/// <param name="den:">Number of denominator in string.</param>
			Fraction(const std::string& num, const std::string& den);

			/// <summary>
			/// Destroys Fraction.
			/// </summary>
			~Fraction() {};

			/// <summary>
			/// Gets denominator.
			/// </summary>
			/// <returns>Number of denominator.</returns>
			int32_t getDenominator() const { return denominator; }

			/// <summary>
			/// Gets numerator.
			/// </summary>
			/// <returns>Number of numerator.</returns>
			int32_t getNumerator() const { return numerator; }

			Fraction operator+(const Fraction& frac) const;
			Fraction operator-(const Fraction& frac) const;
			Fraction operator*(const Fraction& frac) const;
			Fraction operator/(const Fraction& frac) const;
			std::strong_ordering operator<=>(const Fraction& frac1) const;

	#pragma endregion

	#pragma region PrivateMethods

		private:
			/// <summary>
			/// Calculates greatest common divisor between number a and b.
			/// </summary>
			/// <returns>Number of the result.</returns>
			int32_t greatestCommonDivisor(int32_t a, int32_t b);

			/// <summary>
			/// Sets denominator.
			/// </summary>
			/// <param name="num:">Number represented as int32_t.</param>
			void setDenominator(int32_t num);

			/// <summary>
			/// Sets denominator.
			/// </summary>
			/// <param name="num:">Number represented as string.</param>
			void setDenominator(const std::string& num);

			/// <summary>
			/// Sets numerator.
			/// </summary>
			/// <param name="num:">Number represented as int32_t.</param>
			void setNumerator(int32_t num);

			/// <summary>
			/// Sets numerator.
			/// </summary>
			/// <param name="num:">Number represented as string.</param>
			void setNumerator(const std::string& num);

	#pragma endregion

	#pragma region PrivateMembers

		private:
			int32_t numerator;
			int32_t denominator;

	#pragma endregion
	};

#pragma endregion

//========================================================================
//																		  
//			Other functions related to the Fraction class		          
//																		  
//========================================================================

	std::ostream& operator<<(std::ostream& stream, const Fraction& frac);

	/// <summary>
	/// Converts fraction in string to Fraction.
	/// </summary>
	/// <param name="str:">Fraction represented by a string.</param>
	/// <returns>Fraction.</returns>
	Fraction stringToFrac(const std::string& str);
}