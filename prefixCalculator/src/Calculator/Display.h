#pragma once

#include "../Queue/LifoQueue.h"

#include <iostream>
#include <vector>

namespace prefixCalculator
{
//========================================================================
//																		  
//		Class representing diplay of a calculator				  
//																		  
//========================================================================
#pragma region DisplayClass

	class Display
	{
	#pragma region PublicMethods

		public:
			/// <summary>
			/// Creates Display.
			/// </summary>
			Display();

			/// <summary>
			/// Destroys Display.
			/// </summary>
			~Display();

			/// <summary>
			/// Displays error to the console.
			/// </summary>
			/// <param name="error:">Error string.</param>
			void displayError(const char* error) const;

			/// <summary>
			/// Displays information about calculator to the console.
			/// </summary>
			void displayInfo() const;

			/// <summary>
			/// Displays all available operators to the console.
			/// </summary>
			void displayOperators() const;

			/// <summary>
			/// Displays result to the console.
			/// </summary>
			/// <param name="number:">Number to display.</param>
			void displayResult(const double_t& number) const;

			/// <summary>
			/// Displays introduction when app starts.
			/// </summary>
			void showFirstHelp() const;

			/// <summary>
			/// Displays history of results.
			/// </summary>
			/// <param name="history:">Queue with history.</param>
			void showHistory(Queue::LifoQueue<double_t>* history) const;

			/// <summary>
			/// Displays all saved numbers.
			/// </summary>
			/// <param name="vec:">Vector of saved numbers.</param>
			void showSavedResults(const std::vector<double_t>& vec) const;

	#pragma endregion

	#pragma region PrivateMembers
	
		private:
			std::string m_separationLine;

	#pragma endregion
	};

#pragma endregion

	namespace education
	{
		/// <summary>
		/// Displays message for expression.
		/// </summary>
		/// <param name="expression:">Expression that is evaluated.</param>
		void displayFirstEvaluation(std::string& expression);

		/// <summary>
		/// Displays number.
		/// </summary>
		/// <param name="num:">Number to display.</param>
		void displayNumber(double_t& num);

		/// <summary>
		/// Displays message about applying operator.
		/// </summary>
		/// <param name="op:">Operator.</param>
		/// <param name="num1:">Number.</param>
		/// <param name="num2:">Number.</param>
		/// <param name="res:">Result of execution.</param>
		/// <param name="isSingle:">Whether operator is unary or not.</param>
		void displayOperationExecution(std::string& op, double_t& num1, double_t& num2, double_t& res, bool isSingle);
		
		/// <summary>
		/// Displays message about pushing number to the stack.
		/// </summary>
		/// <param name="number:">Number to push.</param>
		void displayStackPush(std::string& number);

	}
}