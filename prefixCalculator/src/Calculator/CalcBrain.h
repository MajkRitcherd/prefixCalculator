#pragma once

#include "Display.h"
#include "RegexCheck.h"
#include "../Queue/LifoQueue.h"
#include "../NumberRepresentations/Operations.h"
#include "../Utilities/JsonUtil.h"

#include <stack>

namespace prefixCalculator
{
	// Computes the result of a given string
	class CalcBrain
	{
	public:
		CalcBrain();
		~CalcBrain();

		void run(Display* display);
	private:

		void p_stop();

		bool p_extractComponents(std::string& str);
		double_t p_calculate(double_t num1, double_t num2, std::string& op);
		double_t p_stringToFloat(std::string& str, const std::string& key);
		void p_stackComputation(std::string& op);
		void p_clearStack();

	private:
		double_t m_result;
		bool m_stopRunning = false;
		std::stack<double_t>* m_stack = nullptr;
	
		Queue::LifoQueue<double_t>* m_history;
		Display* m_display = nullptr;
		RegexCheck* m_regexCheck = nullptr;
	};



	// Useful functions
	bool checkConditions(char& c);
	bool checkRomanNumeral(RegexCheck* regCheck, std::string& str);
	bool isRomanNumeralChar(char c);
	bool isHexadecimalChar(char c);
	bool isBinOrHex(char& c, char& num);
	double_t fac(double_t num);
}

