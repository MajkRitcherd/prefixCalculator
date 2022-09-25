#pragma once

#include "../Queue/LifoQueue.h"

#include <iostream>
#include <vector>

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
		void showSavedResults(std::vector<double_t>& vec);

	private:
		std::string m_separationLine;
		double_t* m_result;
	};
}