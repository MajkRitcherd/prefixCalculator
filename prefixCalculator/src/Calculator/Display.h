#pragma once

#include "../Queue/LifoQueue.h"

#include <iostream>

namespace prefixCalculator
{
	// Represents display of the calculator
	class Display
	{
	public:
		Display();
		~Display();


		void displayResult(double_t& number);
		void displayInfo();
		void displayOperators();
		void showHistory(Queue::LifoQueue<double_t>* history);
		void showFirstHelp();

	private:
		std::string m_separationLine;
		double_t* m_result;
	};
}