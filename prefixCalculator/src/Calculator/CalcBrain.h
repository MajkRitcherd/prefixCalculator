#pragma once

#include "Display.h"
#include "RegexCheck.h"
#include "../Queue/LifoQueue.h"
#include "../NumberRepresentations/Operations.h"
#include "../Utilities/JsonUtil.h"

#include <stack>

namespace prefixCalculator
{
#pragma region CalcBrainClass
//========================================================================
//																		  
//		    Class representing the backend of the calculator				  
//																		  
//========================================================================
	class CalcBrain
	{
	#pragma region PublicMethods

		public:
			/// <summary>
			/// Creates calculator's brain.
			/// </summary>
			CalcBrain();

			/// <summary>
			/// Destroys calculator's brain.
			/// </summary>
			~CalcBrain();

			/// <summary>
			/// Starts the calculator's brain.
			/// </summary>
			/// <param name="display:">Calculator's display.</param>
			/// <param name="education:">True for educational purposes.</param>
			void run(Display* display, bool education);

	#pragma endregion

	#pragma region PrivateMethods

		private:

			/// <summary>
			/// Computes the result of operation applied to numbers.
			/// </summary>
			/// <param name="num1:">Double number.</param>
			/// <param name="num2:">Double number.</param>
			/// <param name="op:">Operator.</param>
			/// <returns>Result of operation applied to numbers.</returns>
			double_t p_calculate(double_t num1, double_t num2, std::string& op);

			/// <summary>
			/// Clears the stack.
			/// </summary>
			void p_clearStack();

			/// <summary>
			/// Gets numbers, operators from expression.
			/// </summary>
			/// <param name="str">Expression.</param>
			/// <returns>True if succesful, otherwise false.</returns>
			bool p_extractComponents(std::string& str);

			// Only used for educational purposes.
			/// <summary>
			/// Shows content of the stack.
			/// </summary>
			void p_showStack();

			/// <summary>
			/// Computation on the stack with passed operator.
			/// </summary>
			/// <param name="op:">Operator represented by a string.</param>
			void p_stackComputation(std::string& op);

			/// <summary>
			/// Stops the calculator's brain.
			/// </summary>
			void p_stop();

			/// <summary>
			/// Converts number from string to double.
			/// </summary>
			/// <param name="str:">Number in string.</param>
			/// <param name="key:">Key to regexCheck.</param>
			/// <returns>Double number converted from string.</returns>
			double_t p_stringToFloat(std::string& str, const std::string& key);

	#pragma endregion

	#pragma region PrivateMembers

		private:
			double_t m_result;
			bool m_stopRunning = false, m_education = false, m_firstEducCalculation = false;
			std::deque<double_t>* m_deque = nullptr;
			std::string m_lastExpression;
			std::vector<double_t> m_savedResults;
	
			Queue::LifoQueue<double_t>* m_history;
			Display* m_display = nullptr;
			RegexCheck* m_regexCheck = nullptr;

	#pragma endregion

	};

#pragma endregion

#pragma region OtherFunctions

	/// <summary>
	/// Checks whether a character is allowed.
	/// </summary>
	/// <param name="c:">Character to check.</param>
	/// <returns>True if character is allowed, otherwise false.</returns>
	bool checkConditions(char& c);

	/// <summary>
	/// Checks if roman numeral is followed by rules. <see href="https://www.cuemath.com/numbers/roman-numerals/"/>
	/// </summary>
	/// <param name="regCheck:">Instance of regex check.</param>
	/// <param name="str:">String with roman numeral.</param>
	/// <returns>True if roman numeral follows rules, otherwise false.</returns>
	bool checkRomanNumeral(RegexCheck* regCheck, std::string& str);

	/// <summary>
	/// Checks whether whitespace is not followed by another one.
	/// </summary>
	/// <param name="str:">Expression to check.</param>
	/// <returns>True if it's not followed, otherwise false.</returns>
	bool checkWhitespaces(std::string& str);

	/// <summary>
	/// Clears all whitespaces from a string.
	/// </summary>
	/// <param name="str:">Expression to clear whitespaces from.</param>
	void clearWhitespaces(std::string& str);

	/// <summary>
	/// Calculates factorial of a number.
	/// </summary>
	/// <param name="num:">Number.</param>
	/// <returns>Factorial of a given number.</returns>
	double_t fac(double_t num);

	/// <summary>
	/// Checks whether those 2 character creates 0x or 0b.
	/// </summary>
	/// <param name="c:">Character to check.</param>
	/// <param name="num:">Number character to check.</param>
	/// <returns>True if it's, otherwise false.</returns>
	bool isBinOrHex(char& c, char& num);

	/// <summary>
	/// Checks whether character is hexadecimal character.
	/// </summary>
	/// <param name="c:">Character to check.</param>
	/// <returns>True if it's, otherwise false.</returns>
	bool isHexadecimalChar(char c);

	/// <summary>
	/// Checks whether character is one of roman nural characters.
	/// </summary>
	/// <param name="c:">Character to check.</param>
	/// <returns>True if it's, otherwise false.</returns>
	bool isRomanNumeralChar(char c);

#pragma endregion
}

