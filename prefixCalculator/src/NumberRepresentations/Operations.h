#pragma once

#include <string>

#ifndef SINGLECOUNT
#define SINGLECOUNT 22
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
		const std::string str1Code[SINGLECOUNT] = { "abs", "sqrt", "cbrt", "fac", "log", "ln", "sin", "cos", "tan", \
													"cotan", "cz-eu", "cz-do", "cz-po", "eu-cz", "eu-do", "eu-po", \
													"do-cz", "do-eu", "do-po", "po-cz", "po-eu", "po-do"};

		const std::string str2Code[TWOCOUNT] = { "+", "-", "*", "/", "pow", "mod"};

		const std::string strAllCode[ALLCOUNT] = { "sum", "prod" };

		enum opCode
		{
			// Arithmetic
			plus, minus, multiply, divide,

			// Algebra
			power, modulo, absolute, squareRoot, cubicRoot, factorial, logarithm, nLogarithm,

			// Goniometric operation
			sinus, cosinus, tangent, cotangent,

			// Currency convertion
			czToEu, czToDo, czToPo, euToCz, euToDo, euToPo, doToCz, doToEu, doToPo, poToCz, poToEu, poToDo,
			
			// Others
			summation, product
		};

		opCode getCode(std::string& str);
		int findString(std::string& str);
		bool isSingleOperator(std::string& str);
		bool isOperator(std::string& str);
		bool isAllOperator(std::string& str);
	}
}