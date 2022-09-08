#pragma once

#include "../Pch.h"
#include "Display.h"
#include "RegexCheck.h"
#include "../Queue/LifoQueue.h"
#include "../NumberRepresentations/Operations.h"

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
		float_t p_calculate(float_t num1, float_t num2, std::string& op);
		float_t p_stringToFloat(std::string& str, const std::string& key);
		void p_stackComputation(std::string& op);
		void p_clearStack();

	private:
		float_t m_result;
		bool m_stopRunning = false;
		std::stack<float_t>* m_stack = nullptr;
	
		Queue::LifoQueue<float_t>* m_history;
		Display* m_display = nullptr;
		RegexCheck* m_regexCheck = nullptr;
	};



	// Useful functions
	bool isRomanNumeral(char c);
	bool isHexadecimalCharacter(char c);
	bool checkBinOrHex(char& c, char& num);
	bool checkConditions(char& c);
	float_t fac(float_t num);
}

