#include "Fraction.h"

namespace numRep
{
	Fraction::Fraction(int32_t num, int32_t den)
	{
		if (num < 0 && den < 0 || den < 0)
		{
			num *= -1;
			den *= -1;
		}
		int32_t div = greatestCommonDivisor(num, den);
		if (div != 1)
		{
			numerator = num / div;
			denominator = den / div;
		}
		else
		{
			numerator = num;
			denominator = den;
		}
	}

	Fraction::Fraction(const std::string& num, const std::string& den)
	{
		int32_t a = std::stoi(num);
		int32_t b = std::stoi(den);
		if (a < 0 && b < 0 || b < 0)
		{
			a *= -1;
			b *= -1;
		}
		int32_t div = greatestCommonDivisor(a, b);
		if (div == 1)
		{
			numerator = a / div;
			denominator = b / div;
		}
		else
		{
			numerator = a;
			denominator = b;
		}
	}

	Fraction Fraction::operator+(const Fraction& frac) const
	{
		int32_t denom = denominator * frac.getDenominator();
		int32_t num = denom / denominator * numerator + denom / frac.getDenominator() * frac.getNumerator();
		return Fraction(num, denom);
	}

	Fraction Fraction::operator-(const Fraction& frac) const
	{
		int32_t denom = denominator * frac.getDenominator();
		int32_t num = denom / denominator * numerator - denom / frac.getDenominator() * frac.getNumerator();
		return Fraction(num, denom);
	}

	Fraction Fraction::operator*(const Fraction& frac) const
	{
		return Fraction(numerator * frac.numerator, denominator * frac.denominator);
	}

	Fraction Fraction::operator/(const Fraction& frac) const
	{
		return Fraction(numerator * frac.denominator, denominator * frac.numerator);
	}

	// Returns -1 when lhs < rhs
	//			1 when lhs > rhs
	//			0 when lhs = rhs
	std::strong_ordering Fraction::operator<=>(const Fraction& frac) const
	{
		int32_t commonMultiple = this->denominator * frac.getDenominator();
		int32_t dividedThis = commonMultiple / this->denominator;
		int32_t dividedFrac = commonMultiple / frac.getDenominator();

		if (dividedThis * this->numerator < dividedFrac * frac.getNumerator())
			return std::strong_ordering::less;
		else if (dividedThis * this->numerator > dividedFrac * frac.getNumerator())
			return std::strong_ordering::greater;
		else
			return std::strong_ordering::equal;
	}

	int32_t Fraction::greatestCommonDivisor(int32_t a, int32_t b)
	{
		int32_t tmp;
		if (a < b)
		{
			tmp = a;
			a = b;
			b = tmp;
		}

		while (b != 0)
		{
			tmp = b;
			b = a % b;
			a = tmp;
		}
		return a;
	}

	void Fraction::setDenominator(int32_t num)
	{
		this->denominator = num;
	}

	void Fraction::setDenominator(const std::string& num)
	{
		this->denominator = std::stoi(num);
	}

	void Fraction::setNumerator(int32_t num)
	{
		this->numerator = num;
	}

	void Fraction::setNumerator(const std::string& num)
	{
		this->numerator = std::stoi(num);
	}

	std::ostream& operator<<(std::ostream& stream, const Fraction& frac)
	{
		stream << frac.getNumerator() << '/' << frac.getDenominator();
		return stream;
	}

	Fraction stringToFrac(const std::string& str)
	{
		std::size_t pos = str.find("/");
		int32_t num = std::stoi(str.substr(0, pos));
		int32_t den = std::stoi(str.substr(pos + 1));
		return Fraction(num, den);
	}
}