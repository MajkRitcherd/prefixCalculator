#pragma once

#include "../Pch.h"

namespace prefixCalculator
{
	// Represents display of the calculator
	class Display
	{
	public:
		Display();
		~Display();


		void displayResult(float_t& number);
		void displayInfo();
		void showFirstHelp();

	private:
		std::string m_separationLine;
		float_t* m_result;
	};
}