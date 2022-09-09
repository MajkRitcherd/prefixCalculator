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
	class Fraction
	{
	public:
		Fraction(int32_t num = 1, int32_t den = 1);
		Fraction(const std::string& num, const std::string& den);
		~Fraction() {};
		int32_t getNumerator() const { return numerator; }
		int32_t getDenominator() const { return denominator; }

		Fraction operator+(const Fraction& frac) const;
		Fraction operator-(const Fraction& frac) const;
		Fraction operator*(const Fraction& frac) const;
		Fraction operator/(const Fraction& frac) const;
		std::strong_ordering operator<=>(const Fraction& frac1) const;

	private:
		void setNumerator(int32_t num);
		void setNumerator(const std::string& num);
		void setDenominator(int32_t num);
		void setDenominator(const std::string& num);
		int32_t greatestCommonDivisor();
		int32_t greatestCommonDivisor(int32_t a, int32_t b);

	private:
		int32_t numerator;
		int32_t denominator;
	};

	std::ostream& operator<<(std::ostream& stream, const Fraction& frac);
	Fraction stringToFrac(const std::string& str);
}