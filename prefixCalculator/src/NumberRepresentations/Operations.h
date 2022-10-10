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

		/// <summary>
		/// Contains all available operaitions
		/// </summary>
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

		/// <summary>
		/// Finds index of an operator.
		/// </summary>
		/// <param name="str:">Operator as string.</param>
		/// <returns>Position of operator.</returns>
		int findString(std::string& str);

		/// <summary>
		/// Gets code of given operation.
		/// </summary>
		/// <param name="str:">Operation in string.</param>
		/// <returns>Operation code</returns>
		opCode getCode(std::string& str);

		/// <summary>
		/// Checks if operator is AllOperator.
		/// </summary>
		/// <param name="str:">Operator in string.</param>
		/// <returns>True if it's AllOperator, otherwise false.</returns>
		bool isAllOperator(std::string& str);

		/// <summary>
		/// Checks if operator is binary operator.
		/// </summary>
		/// <param name="str:">Operator in string.</param>
		/// <returns>True if it's binary operator, otherwise false.</returns>
		bool isOperator(std::string& str);

		/// <summary>
		/// Checks if operator is unary operator.
		/// </summary>
		/// <param name="str:">Operator in string.</param>
		/// <returns>True if it's unary operator, otherwise false.</returns>
		bool isSingleOperator(std::string& str);
	}
}