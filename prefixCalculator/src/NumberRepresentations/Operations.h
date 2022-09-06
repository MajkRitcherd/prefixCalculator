#pragma once

#include "../Pch.h"

#ifndef SINGLECOUNT
#define SINGLECOUNT 10
#endif // !OPERCOUNTSINGLE

#ifndef TWOCOUNT
#define TWOCOUNT 6
#endif // !OPERCOUNT

#ifndef ALLCOUNT
#define ALLCOUNT 2
#endif // !ALLCOUNT

namespace numRep
{
	// Contains all available mathematical operations
	namespace oper
	{
		const std::string str1Code[SINGLECOUNT] = { "abs", "sqrt", "cbrt", "fac", "log", "ln", "sin", "cos", "tan", "cotan" };

		const std::string str2Code[TWOCOUNT] = { "+", "-", "*", "/", "pow", "mod" };

		const std::string strAllCode[ALLCOUNT] = { "sum", "prod" };

		enum opCode
		{
			// MAYBE Boolean logic?
			// 
			// Arithmetic
			plus, minus, multiply, divide,

			// Algebra
			power, modulo, absolute, squareRoot, cubicRoot, factorial, logarithm, nLogarithm,

			// Goniometric operation
			sinus, cosinus, tangent, cotangent,

			summation, product
		};

		opCode getCode(std::string& str);
		int findString(std::string& str);
		bool isSingleOperator(std::string& str);
		bool isOperator(std::string& str);
		bool isAllOperator(std::string& str);
	}
}