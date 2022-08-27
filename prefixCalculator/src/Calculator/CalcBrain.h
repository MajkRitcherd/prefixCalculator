#pragma once

#include "../Pch.h"
#include "Display.h"
#include "RegexCheck.h"
#include "../Queue/LifoQueue.h"

namespace prefixCalculator
{
	float_t fac(float_t num);

	// Computes the result of a given string
	class CalcBrain
	{
	public:
		CalcBrain();
		~CalcBrain();

		void run(Display* display);
	private:
		enum opCode
		{
			// MAYBE Boolean logic?
			// 
			// Arithmetic
			plus, minus, multiply, divide, 

			// Algebra - TODO Logarithm, Modulus and maybe Summation and Product operators
			absolute, power, squareRoot, cubicRoot, factorial,

			// Goniometric
			sinus, cosinus, tangent, cotangent
		};


		void p_stop();

		bool p_extractComponents(std::string& str);
		float_t p_calculate(float_t num1, float_t num2, std::string& op);
		bool p_checkConditions(char& c) const;
		bool p_checkBinOrHex(char& c, char& num) const;
		float_t p_stringToFloat(std::string& str, const std::string& key);
		void p_stackComputation(std::string& op);
		void p_clearStack();
		opCode p_getCode(std::string& str);

	private:
		float_t m_result;
		bool m_stopRunning = false;
		std::stack<float_t>* m_stack = nullptr;
	
		Queue::LifoQueue<float_t>* m_history;
		Display* m_display = nullptr;
		RegexCheck* m_regexCheck = nullptr;
	};
}

